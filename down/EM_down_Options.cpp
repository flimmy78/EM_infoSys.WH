#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSqlQuery"
#include "QDebug"
#include "QSqlRecord"
#include "QSqlError"
#include "QFile"
#include "QDateTime"
#include "QMessageBox"

//清除表格
void MainWindow::on_EM_down_clean_PsBtn_clicked()
{
     remove_TblWdiget_Row(ui->EM_sampleInfo_TblWidget);
     remove_TblWdiget_Row(ui->EM_P_CODE_TblWidget);
     remove_TblWdiget_Row(ui->EM_METER_TblWidget);
     remove_TblWdiget_Row(ui->EM_DETECT_TASK_TblWidget);
     remove_TblWdiget_Row(ui->EM_DETECT_OUT_EQUIP_TblWidget);
}

//保存数据到当前数据库
void MainWindow::on_EM_down_saveLocalSql_PsBtn_clicked()
{
    setCursor(QCursor(Qt::BusyCursor));
    QString strExec ,strBarCode;
    strBarCode = ui->EM_down_barCode_LnEdit->text();

    strExec = QString("select * from  sampleInfo where sampleNo = '%1'").arg(strBarCode);

    if(isLocalBarCodeExist(strExec,strBarCode))
    {
        showInformationBox(QString::fromUtf8("当前条形码数据已存在，请删除原先数据再重新保存"));
        setCursor(QCursor(Qt::ArrowCursor));
        return ;
    }

    save_sampleInfo();
    save_MT_METER();

//    save_MT_P_CODE();
//    save_MT_DETECT_TASK();
//    save_MT_DETECT_OUT_EQUIP();
    //showInformationBox(QString::fromUtf8("保存成功"));
    setCursor(QCursor(Qt::ArrowCursor));
}

//查看以往的数据库
void MainWindow::on_EM_down_loadLocalSql_PsBtn_clicked()
{
    QString  strExec,strBarCode;
    setCursor(QCursor(Qt::BusyCursor));
    on_EM_down_clean_PsBtn_clicked();
    strBarCode = ui->EM_down_barCode_LnEdit->text();

    strExec = QString("select * from  sampleInfo where sampleNo = '%1'").arg(strBarCode);

    getDataFromLocalSqlToTblWidget(strExec,ui->EM_sampleInfo_TblWidget,ui->EM_sampleInfo_TblWidget->columnCount());

    strExec = QString("select * from  MT_METER where BAR_CODE = '%1'").arg(strBarCode);

    getDataFromLocalSqlToTblWidget(strExec,ui->EM_METER_TblWidget,ui->EM_METER_TblWidget->columnCount());

    setCursor(QCursor(Qt::ArrowCursor));
}



void MainWindow::on_EM_down_deleteLocalSqlItem_PsBtn_clicked()
{
    QString strExec,strBarCode;
    QByteArray byteArray;
    strBarCode = ui->EM_down_barCode_LnEdit->text();

    strExec=QString("delete  from sampleInfo where sampleNo ='%1'").arg(strBarCode);
    byteArray = strExec.toLocal8Bit();
    sql_exec(byteArray.data());

    strExec=QString("delete  from MT_METER where BAR_CODE ='%1'").arg(strBarCode);
    byteArray = strExec.toLocal8Bit();
    sql_exec(byteArray.data());

    showInformationBox(QString::fromUtf8("删除成功，请读查看以确认"));
    //on_EM_down_loadLocalSql_PsBtn_clicked();

}

