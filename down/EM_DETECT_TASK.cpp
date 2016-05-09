#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSettings"
#include "QDebug"
#include "QMessageBox"
#include "QSqlQuery"
#include "QSqlRecord"
#include "QSqlError"
/******************************************************************************************
 *通过检定任务单号搜索检定任务
 *****************************************************************************************/
void MainWindow::down_MT_DETECT_TASK(QString barCode,QString detectTaskNo)
{
    QSqlRecord  sqlRec;
    QSqlQuery   sqlQuery;
    QString     strExec;
    int rowCount;

    strExec = QString("select * from  mt_detect_task where DETECT_TASK_NO ='%1' order by  WRITE_DATE desc").arg(detectTaskNo);

    if(!sqlQuery.exec(strExec))
    {
       showInformationBox(sqlQuery.lastError().databaseText());
        return ;
    }

    sqlRec  = sqlQuery.record();

    while(sqlQuery.next())
    {
        if(isTaskNoExist(barCode,ui->EM_DETECT_TASK_TblWidget,0))
        {
            rowCount = ui->EM_DETECT_TASK_TblWidget->rowCount();
            ui->EM_DETECT_TASK_TblWidget->insertRow(rowCount);
            ui->EM_DETECT_TASK_TblWidget->setItem(rowCount,0,new QTableWidgetItem(barCode));
            for(int i=0;i<sqlRec.count()+1;i++)
            {
                ui->EM_DETECT_TASK_TblWidget->setItem(rowCount,i+1,new QTableWidgetItem(sqlQuery.value(i).toString()));
            }
            return;
        }
    }
}

void MainWindow:: save_MT_DETECT_TASK()
{
    QString strExec;
    QByteArray byteArray;

    int rowCount ,columnCount,intResult;
    rowCount= ui->EM_DETECT_TASK_TblWidget->rowCount();
    columnCount = ui->EM_DETECT_TASK_TblWidget->columnCount();

    for(int j=0;j<rowCount;j++)
    {
        for(int i=0;i<columnCount;i++)
        {
            if(!ui->EM_DETECT_TASK_TblWidget->item(j,i))
            ui->EM_DETECT_TASK_TblWidget->setItem(j,i, new QTableWidgetItem(""));
        }
    }

    for(int  i =0;i<rowCount;i++)
    {
        #if 1
            strExec =  QString("INSERT INTO mt_detect_task values( '%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12','%13','%14','%15','%16','%17','%18','%19','%20','%21','%22','%23','%24','%25','%26')")
                        .arg(ui->EM_DETECT_TASK_TblWidget->item(i,0)->text())//bar_code
                        .arg(ui->EM_DETECT_TASK_TblWidget->item(i,1)->text())
                        .arg(ui->EM_DETECT_TASK_TblWidget->item(i,2)->text())
                        .arg(ui->EM_DETECT_TASK_TblWidget->item(i,3)->text())
                        .arg(ui->EM_DETECT_TASK_TblWidget->item(i,4)->text())
                        .arg(ui->EM_DETECT_TASK_TblWidget->item(i,5)->text())
                        .arg(ui->EM_DETECT_TASK_TblWidget->item(i,6)->text())
                        .arg(ui->EM_DETECT_TASK_TblWidget->item(i,7)->text())
                        .arg(ui->EM_DETECT_TASK_TblWidget->item(i,8)->text())
                        .arg(ui->EM_DETECT_TASK_TblWidget->item(i,9)->text())//10
                        .arg(ui->EM_DETECT_TASK_TblWidget->item(i,10)->text())
                        .arg(ui->EM_DETECT_TASK_TblWidget->item(i,11)->text())
                        .arg(ui->EM_DETECT_TASK_TblWidget->item(i,12)->text())
                        .arg(ui->EM_DETECT_TASK_TblWidget->item(i,13)->text())
                        .arg(ui->EM_DETECT_TASK_TblWidget->item(i,14)->text())
                        .arg(ui->EM_DETECT_TASK_TblWidget->item(i,15)->text())
                        .arg(ui->EM_DETECT_TASK_TblWidget->item(i,16)->text())
                        .arg(ui->EM_DETECT_TASK_TblWidget->item(i,17)->text())
                        .arg(ui->EM_DETECT_TASK_TblWidget->item(i,18)->text())
                        .arg(ui->EM_DETECT_TASK_TblWidget->item(i,19)->text())
                        .arg(ui->EM_DETECT_TASK_TblWidget->item(i,20)->text())
                        .arg(ui->EM_DETECT_TASK_TblWidget->item(i,21)->text())
                        .arg(ui->EM_DETECT_TASK_TblWidget->item(i,22)->text())
                        .arg(ui->EM_DETECT_TASK_TblWidget->item(i,23)->text())
                        .arg(ui->EM_DETECT_TASK_TblWidget->item(i,24)->text())
                        .arg(ui->EM_DETECT_TASK_TblWidget->item(i,25)->text());
        #endif
            byteArray = strExec.toLocal8Bit();
            intResult= sql_exec(byteArray.data());
            if(intResult!=SQLITE_OK)
            {
                qDebug()<<"insert MT_DETECT_TASK error";
            }
    }
}


void MainWindow::fill_DETECT_TASK()
{
    my_MT_DETECT_TASK.BAR_CODE          = strArray[15][0];
    my_MT_DETECT_TASK.DETECT_TASK_NO    = strArray[15][1];
    my_MT_DETECT_TASK.TASK_PRIO         = strArray[15][2];
    my_MT_DETECT_TASK.DETECT_MODE       = strArray[15][3];
    my_MT_DETECT_TASK.SYS_NO            = strArray[15][4];
    my_MT_DETECT_TASK.ARRIVE_BATCH_NO   = strArray[15][5];
    my_MT_DETECT_TASK.EQUIP_CATEG       = strArray[15][6];
    my_MT_DETECT_TASK.MODEL_CODE        = strArray[15][7];
    my_MT_DETECT_TASK.SCHEMA_ID         = strArray[15][8];
    my_MT_DETECT_TASK.REDETECT_SCHEMA   = strArray[15][9];
    my_MT_DETECT_TASK.REDETECT_FLAG     = strArray[15][10];

    my_MT_DETECT_TASK.REDETECT_QTY      = strArray[15][11];
    my_MT_DETECT_TASK.EQUIP_QTY         = strArray[15][12];
    my_MT_DETECT_TASK.PILE_QTY          = strArray[15][13];
    my_MT_DETECT_TASK.TASK_STATUS       = strArray[15][14];
    my_MT_DETECT_TASK.HANDLE_DATE       = strArray[15][15];//SDJLFNG
    my_MT_DETECT_TASK.HANDLE_FLAG       = strArray[15][16];
    my_MT_DETECT_TASK.WRITE_DATE        = strArray[15][17];
    my_MT_DETECT_TASK.ERP_BATCH_NO      = strArray[15][18];
    my_MT_DETECT_TASK.TASK_TYPE         = strArray[15][19];
    my_MT_DETECT_TASK.EQUIP_STATUS_CODE = strArray[15][20];

    my_MT_DETECT_TASK.EXEC_RESP_NAME    = strArray[15][21];
    my_MT_DETECT_TASK.APPR_NAME         = strArray[15][22];
    my_MT_DETECT_TASK.IS_AUTO_SEAL      = strArray[15][23];

    my_MT_DETECT_TASK.EQUIP_CODE_NEW    = strArray[15][24];
    my_MT_DETECT_TASK.PARAM_TYPE        = strArray[15][25];

    my_CONC_CODE.DETECT_EQUIP_NO=ui->EM_options_detectEquipNo_LnEdit->text();

    my_CONC_CODE.INTUIT     = "1";  //每一次都要默认为1(合格)
    my_CONC_CODE.BASICERR   = "1";
    my_CONC_CODE.CONST      = "1";
    my_CONC_CODE.STARTING   = "1";
    my_CONC_CODE.CREEPING   = "1";
    my_CONC_CODE.INFLUENCE  = "1";
    my_CONC_CODE.MEASURE_REPEAT="1";

}
