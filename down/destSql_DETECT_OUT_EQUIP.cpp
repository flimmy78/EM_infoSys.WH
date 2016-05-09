#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSettings"
#include "QDebug"
#include "QMessageBox"
#include "QSqlQuery"
#include "QSqlRecord"
#include "QSqlError"

/******************************************************************************************
 *通过条形码读取中间库的最新的writedate数据
 *****************************************************************************************/
void MainWindow::dwon_DETECT_OUT_EQUIP(QString strBarCode)
{
    QSqlRecord sqlRec;
    QSqlQuery  sqlQuery;
    QString    strExec;
    int rowCount;
    strExec = QString("select * from  MT_DETECT_OUT_EQUIP where BAR_CODE ='%1' order by  WRITE_DATE desc").arg(strBarCode);

    if(!sqlQuery.exec(strExec))
    {
        showInformationBox(sqlQuery.lastError().databaseText());
        return ;
    }

    sqlRec  = sqlQuery.record();

    if(!sqlQuery.next())
    {
        showInformationBox(QString::fromUtf8("没有下发检定任务单"));
        return;
    }
    sqlQuery.previous();

    while(sqlQuery.next())
    {
        if(isTaskNoExist(strBarCode,ui->EM_DETECT_OUT_EQUIP_TblWidget,3))
        {
            rowCount = ui->EM_DETECT_OUT_EQUIP_TblWidget->rowCount();
            ui->EM_DETECT_OUT_EQUIP_TblWidget->insertRow(rowCount);
            my_DOWN_INFO.DETECT_TASK_NO =sqlQuery.value(0).toString();
            my_DOWN_INFO.BAR_CODE =strBarCode;

            for(int i=0;i<sqlRec.count();i++)//98
            {
                ui->EM_DETECT_OUT_EQUIP_TblWidget->setItem(rowCount,i,new QTableWidgetItem(sqlQuery.value(i).toString()));
            }
            return;//因为任务单最新是唯一的，所以返回
         }
    }
}

void MainWindow:: save_MT_DETECT_OUT_EQUIP()
{

    QString strExec;
    QByteArray byteArray;

    int rowCount ,columnCount,intResult;
    rowCount= ui->EM_DETECT_OUT_EQUIP_TblWidget->rowCount();
    columnCount = ui->EM_DETECT_OUT_EQUIP_TblWidget->columnCount();

    for(int j=0;j<rowCount;j++)
    {
        for(int i=0;i<columnCount;i++)
        {
            if(!ui->EM_DETECT_OUT_EQUIP_TblWidget->item(j,i))
            ui->EM_DETECT_OUT_EQUIP_TblWidget->setItem(j,i, new QTableWidgetItem(""));
        }
    }

    for(int  i =0;i<rowCount;i++)
    {
        #if 1
            strExec =  QString("INSERT INTO MT_DETECT_OUT_EQUIP values( '%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12','%13','%14','%15')")
                        .arg(ui->EM_DETECT_OUT_EQUIP_TblWidget->item(i,0)->text())
                        .arg(ui->EM_DETECT_OUT_EQUIP_TblWidget->item(i,1)->text())
                        .arg(ui->EM_DETECT_OUT_EQUIP_TblWidget->item(i,2)->text())
                        .arg(ui->EM_DETECT_OUT_EQUIP_TblWidget->item(i,3)->text())
                        .arg(ui->EM_DETECT_OUT_EQUIP_TblWidget->item(i,4)->text())
                        .arg(ui->EM_DETECT_OUT_EQUIP_TblWidget->item(i,5)->text())
                        .arg(ui->EM_DETECT_OUT_EQUIP_TblWidget->item(i,6)->text())
                        .arg(ui->EM_DETECT_OUT_EQUIP_TblWidget->item(i,7)->text())
                        .arg(ui->EM_DETECT_OUT_EQUIP_TblWidget->item(i,8)->text())
                        .arg(ui->EM_DETECT_OUT_EQUIP_TblWidget->item(i,9)->text())//10
                        .arg(ui->EM_DETECT_OUT_EQUIP_TblWidget->item(i,10)->text())
                        .arg(ui->EM_DETECT_OUT_EQUIP_TblWidget->item(i,11)->text())
                        .arg(ui->EM_DETECT_OUT_EQUIP_TblWidget->item(i,12)->text())
                        .arg(ui->EM_DETECT_OUT_EQUIP_TblWidget->item(i,13)->text())
                        .arg(ui->EM_DETECT_OUT_EQUIP_TblWidget->item(i,14)->text());
        #endif
            byteArray = strExec.toLocal8Bit();
            intResult= sql_exec(byteArray.data());
            if(intResult!=SQLITE_OK)
            {
                qDebug()<<"insert MT_DETECT_OUT_EQUIP error";
            }
    }
}



void MainWindow::fill_DETECT_OUT_EQUIP()
{
#if 0
    my_MT_DETECT_OUT_EQUIP.DETECT_TASK_NO = strArray[15][0];
    my_MT_DETECT_OUT_EQUIP.IO_TASK_NO     = strArray[15][1];
    my_MT_DETECT_OUT_EQUIP.EQUIP_CATEG    = strArray[15][2];
    my_MT_DETECT_OUT_EQUIP.BAR_CODE       = strArray[15][3];
    my_MT_DETECT_OUT_EQUIP.BOX_BAR_CODE   = strArray[15][4];
    my_MT_DETECT_OUT_EQUIP.PILE_NO        = strArray[15][5];
    my_MT_DETECT_OUT_EQUIP.PLATFORM_NO    = strArray[15][6];
    my_MT_DETECT_OUT_EQUIP.SYS_NO         = strArray[15][7];
    my_MT_DETECT_OUT_EQUIP.WRITE_DATE     = strArray[15][8];
    my_MT_DETECT_OUT_EQUIP.HANDLE_FLAG    = strArray[15][9];
    my_MT_DETECT_OUT_EQUIP.HANDLE_DATE    = strArray[15][10];
    my_MT_DETECT_OUT_EQUIP.ARRIVE_BATCH_NO= strArray[15][11];
    my_MT_DETECT_OUT_EQUIP.REDETECT_FLAG  = strArray[15][12];
    my_MT_DETECT_OUT_EQUIP.EMP_NO         = strArray[15][13];//SDJLFNG
    my_MT_DETECT_OUT_EQUIP.PLATFORM_TYPE  = strArray[15][14];
    //qDebug()<<my_MT_DETECT_OUT_EQUIP.EMP_NO ;
#endif
}





