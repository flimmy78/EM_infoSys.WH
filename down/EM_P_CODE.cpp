#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSqlQuery"
#include "QDebug"
#include "QSqlRecord"
#include "QSqlError"

void MainWindow::down_MT_P_CODE(QString barCode ,QString strValue)
{
    QSqlRecord sqlRec;
    QSqlQuery  sqlQuery;
    QString    strExec;
    int rowCount ;

    strExec = QString("select * from mt_p_code t where t.value = '%1' and t.code_type = 'meterFacturer'").arg(strValue);

    if(!sqlQuery.exec(strExec))
    {
        showInformationBox(sqlQuery.lastError().databaseText());
        return ;
    }

    sqlRec  = sqlQuery.record();

    while(sqlQuery.next())
    {
        if(isTaskNoExist(barCode,ui->EM_P_CODE_TblWidget,0))
        {
            rowCount = ui->EM_P_CODE_TblWidget->rowCount();
            ui->EM_P_CODE_TblWidget->insertRow(rowCount);
            ui->EM_P_CODE_TblWidget->setItem(rowCount,0,new QTableWidgetItem(barCode));

            for(int i=0;i<sqlRec.count()+1;i++)//98
            {
                ui->EM_P_CODE_TblWidget->setItem(rowCount,i+1,new QTableWidgetItem(sqlQuery.value(i).toString()));
            }
        }
    }
}


void MainWindow:: save_MT_P_CODE()
{
    QString strExec;
    QByteArray byteArray;
    int rowCount ,columnCount,intResult;

    rowCount = ui->EM_P_CODE_TblWidget->rowCount();
    columnCount = ui->EM_P_CODE_TblWidget->columnCount();

    for(int j=0;j<rowCount;j++)
    {
        for(int i=0;i<columnCount;i++)
        {
            if(!ui->EM_P_CODE_TblWidget->item(j,i))
            ui->EM_P_CODE_TblWidget->setItem(j,i, new QTableWidgetItem(""));
        }
    }

    for(int i=0;i<rowCount;i++)
    {
        strExec =  QString("INSERT INTO MT_P_CODE values( '%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12','%13','%14','%15','%16','%17','%18','%19','%20','%21')")
                    .arg(ui->EM_P_CODE_TblWidget->item(i,0)->text())//bar_code;
                    .arg(ui->EM_P_CODE_TblWidget->item(i,1)->text())
                    .arg(ui->EM_P_CODE_TblWidget->item(i,2)->text())
                    .arg(ui->EM_P_CODE_TblWidget->item(i,3)->text())
                    .arg(ui->EM_P_CODE_TblWidget->item(i,4)->text())
                    .arg(ui->EM_P_CODE_TblWidget->item(i,5)->text())
                    .arg(ui->EM_P_CODE_TblWidget->item(i,6)->text())
                    .arg(ui->EM_P_CODE_TblWidget->item(i,7)->text())
                    .arg(ui->EM_P_CODE_TblWidget->item(i,8)->text())
                    .arg(ui->EM_P_CODE_TblWidget->item(i,9)->text())//10
                    .arg(ui->EM_P_CODE_TblWidget->item(i,10)->text())
                    .arg(ui->EM_P_CODE_TblWidget->item(i,11)->text())
                    .arg(ui->EM_P_CODE_TblWidget->item(i,12)->text())
                    .arg(ui->EM_P_CODE_TblWidget->item(i,13)->text())
                    .arg(ui->EM_P_CODE_TblWidget->item(i,14)->text())
                    .arg(ui->EM_P_CODE_TblWidget->item(i,15)->text())
                    .arg(ui->EM_P_CODE_TblWidget->item(i,16)->text())
                    .arg(ui->EM_P_CODE_TblWidget->item(i,17)->text())
                    .arg(ui->EM_P_CODE_TblWidget->item(i,18)->text())
                    .arg(ui->EM_P_CODE_TblWidget->item(i,19)->text())
                    .arg(ui->EM_P_CODE_TblWidget->item(i,20)->text());

        byteArray = strExec.toLocal8Bit();
        intResult= sql_exec(byteArray.data());
        if(intResult!=SQLITE_OK)
        {
            showInformationBox(QString::fromUtf8("insert mt_p_code error"));
            return;
        }

    }

}



