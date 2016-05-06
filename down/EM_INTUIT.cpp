/***********************************************************************************
 *外观检测，默认为01 合格
 *
 ***************************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSqlQuery"
#include "QDebug"
#include "QSqlRecord"
#include "QSqlError"

bool MainWindow::update_INTUIT()
{

    bool IsSuccessful;
    QString strExec;
    int rowCount,columnCount;

    rowCount = ui->EM_INTUIT_MET_TblWidget->rowCount();
    columnCount = ui->EM_INTUIT_MET_TblWidget->columnCount();

    for(int j=0;j<rowCount;j++)
    {
        for(int i=0;i<columnCount;i++)
        {
            if(!ui->EM_INTUIT_MET_TblWidget->item(j,i))
            ui->EM_INTUIT_MET_TblWidget->setItem(j,i, new QTableWidgetItem(""));
        }
    }


    for(int i =0;i<rowCount;i++)//
    {
            strExec = QString("INSERT INTO MT_INTUIT_MET_CONC values( '%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12','%13','%14','%15','%16')")
                    .arg(ui->EM_INTUIT_MET_TblWidget->item(i,0)->text())
                    .arg(ui->EM_INTUIT_MET_TblWidget->item(i,1)->text())
                    .arg(ui->EM_INTUIT_MET_TblWidget->item(i,2)->text())
                    .arg(ui->EM_INTUIT_MET_TblWidget->item(i,3)->text())
                    .arg(ui->EM_INTUIT_MET_TblWidget->item(i,4)->text())
                    .arg(ui->EM_INTUIT_MET_TblWidget->item(i,5)->text())
                    .arg(ui->EM_INTUIT_MET_TblWidget->item(i,6)->text())
                    .arg(ui->EM_INTUIT_MET_TblWidget->item(i,7)->text())
                    .arg(ui->EM_INTUIT_MET_TblWidget->item(i,8)->text())
                    .arg(ui->EM_INTUIT_MET_TblWidget->item(i,9)->text())
                    .arg(ui->EM_INTUIT_MET_TblWidget->item(i,10)->text())

                    .arg(ui->EM_INTUIT_MET_TblWidget->item(i,11)->text())
                    .arg(ui->EM_INTUIT_MET_TblWidget->item(i,12)->text())
                    .arg(ui->EM_INTUIT_MET_TblWidget->item(i,13)->text())
                    .arg(ui->EM_INTUIT_MET_TblWidget->item(i,14)->text())
                    .arg(ui->EM_INTUIT_MET_TblWidget->item(i,15)->text());

          //qDebug()<<strExec;



        IsSuccessful =sqlQueryExec("MT_INTUIT_MET_CONC",ui->EM_INTUIT_MET_TblWidget->item(i,6)->text()+" Num:"+QString::number(i), strExec,QString::fromUtf8("成功添加"));

        if(IsSuccessful==false)
        {
            showInformationBox(QString::fromUtf8("出错,请查看当前log.txt记录"));
            return false;
        }

    }
      return true;
}



void MainWindow:: fill_INTUIT()
{
    int rowCount =ui->EM_INTUIT_MET_TblWidget->rowCount();
    ui->EM_INTUIT_MET_TblWidget->insertRow(rowCount);

    ui->EM_INTUIT_MET_TblWidget->setItem(rowCount,0, new QTableWidgetItem(my_MT_DETECT_TASK.DETECT_TASK_NO));         //检定任务单
    ui->EM_INTUIT_MET_TblWidget->setItem(rowCount,1, new QTableWidgetItem(my_MT_DETECT_TASK.EQUIP_CATEG));            //设备类别
    ui->EM_INTUIT_MET_TblWidget->setItem(rowCount,2, new QTableWidgetItem(my_MT_DETECT_TASK.SYS_NO));                 //系统编号
    ui->EM_INTUIT_MET_TblWidget->setItem(rowCount,3, new QTableWidgetItem(my_CONC_CODE.DETECT_EQUIP_NO));                                    //检定线台编号
    ui->EM_INTUIT_MET_TblWidget->setItem(rowCount,4, new QTableWidgetItem(""));                                            //检定单元编号
    ui->EM_INTUIT_MET_TblWidget->setItem(rowCount,5, new QTableWidgetItem(""));                                            //表位编号

    ui->EM_INTUIT_MET_TblWidget->setItem(rowCount,6, new QTableWidgetItem(my_MT_DETECT_TASK.BAR_CODE));               //设备条形码
    ui->EM_INTUIT_MET_TblWidget->setItem(rowCount,7, new QTableWidgetItem(strArray[3][0]));                                 //检定时间
    ui->EM_INTUIT_MET_TblWidget->setItem(rowCount,8, new QTableWidgetItem("1"));                                           //第几次检定(序号)
    ui->EM_INTUIT_MET_TblWidget->setItem(rowCount,9, new QTableWidgetItem("1"));                                           //检定点序号

    ui->EM_INTUIT_MET_TblWidget->setItem(rowCount,10, new QTableWidgetItem("1"));                                          //见附录I：有效标志 0：否、1：是                                           //
    ui->EM_INTUIT_MET_TblWidget->setItem(rowCount,11, new QTableWidgetItem("#"));
    my_CONC_CODE.INTUIT="1";
    ui->EM_INTUIT_MET_TblWidget->setItem(rowCount,12, new QTableWidgetItem(my_CONC_CODE.INTUIT));
    ui->EM_INTUIT_MET_TblWidget->setItem(rowCount,13, new QTableWidgetItem(currentTime()));
    ui->EM_INTUIT_MET_TblWidget->setItem(rowCount,14, new QTableWidgetItem("0"));
    ui->EM_INTUIT_MET_TblWidget->setItem(rowCount,15, new QTableWidgetItem(currentTime()));

}



