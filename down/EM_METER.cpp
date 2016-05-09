#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSettings"
#include "QDebug"
#include "QMessageBox"
#include "QSqlQuery"
#include "QSqlRecord"
#include "QSqlError"

void MainWindow::down_MT_METER(QString strBarCode)
{
    QSqlRecord sqlRec;
    QSqlQuery  sqlQuery;
    QString    strExec;
    int rowCount;
    strExec = QString("select * from  MT_METER where BAR_CODE ='%1' order by  WRITE_DATE desc").arg(strBarCode);

    //qDebug()<<strExec;
    if(!sqlQuery.exec(strExec))
    {
        showInformationBox(sqlQuery.lastError().databaseText());
        return ;
    }

    sqlRec  = sqlQuery.record();

    if(!sqlQuery.next())
    {
        showInformationBox(QString::fromUtf8("条形码不存在"));
        return;
    }
    sqlQuery.previous();
    while(sqlQuery.next())
    {
        //qDebug()<<"=="<<sqlQuery.value(2).toString();
        if(isTaskNoExist(sqlQuery.value(2).toString(),ui->EM_METER_TblWidget,2))
        {
            rowCount = ui->EM_METER_TblWidget->rowCount();
            ui->EM_METER_TblWidget->insertRow(rowCount);
            ui->EM_METER_TblWidget->setItem(rowCount,0,new QTableWidgetItem(strBarCode));
            my_DOWN_INFO.VALUE =sqlQuery.value(35).toString();
            for(int i=0;i<sqlRec.count()+1;i++)
            {
                ui->EM_METER_TblWidget->setItem(rowCount,i,new QTableWidgetItem(sqlQuery.value(i).toString()));
            }

            down_MT_P_CODE(strBarCode, my_DOWN_INFO.VALUE );
            dwon_DETECT_OUT_EQUIP(strBarCode);
            down_MT_DETECT_TASK(strBarCode, my_DOWN_INFO.DETECT_TASK_NO);
        }
    }
}

void MainWindow:: save_MT_METER()
{
     QByteArray byteArray;
    QString strExec;
    int rowCount ,columnCount,intResult;
    rowCount= ui->EM_METER_TblWidget->rowCount();
    columnCount = ui->EM_METER_TblWidget->columnCount();

    for(int j=0;j<rowCount;j++)
    {
        for(int i=0;i<columnCount;i++)
        {
            if(!ui->EM_METER_TblWidget->item(j,i))
            ui->EM_METER_TblWidget->setItem(j,i, new QTableWidgetItem(""));
        }
    }

    for(int  i =0;i<rowCount;i++)
    {
        #if 1
            strExec =  QString("INSERT INTO MT_METER values( '%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12','%13','%14','%15','%16','%17','%18','%19','%20','%21','%22','%23','%24','%25','%26','%27','%28','%29','%30','%31','%32','%33','%34','%35','%36','%37','%38','%39','%40','%41','%42','%43','%44','%45','%46','%47','%48','%49','%50','%51','%52','%53','%54','%55','%56','%57','%58','%59','%60','%61','%62','%63','%64','%65','%66','%67','%68','%69','%70','%71','%72','%73','%74','%75','%76','%77','%78','%79','%80','%81','%82','%83','%84','%85','%86','%87','%88','%89','%90','%91','%92','%93','%94','%95','%96','%97','%98')")
                        .arg(ui->EM_METER_TblWidget->item(i,0)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,1)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,2)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,3)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,4)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,5)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,6)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,7)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,8)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,9)->text())//10
                        .arg(ui->EM_METER_TblWidget->item(i,10)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,11)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,12)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,13)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,14)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,15)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,16)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,17)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,18)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,19)->text())//10
                        .arg(ui->EM_METER_TblWidget->item(i,20)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,21)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,22)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,23)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,24)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,25)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,26)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,27)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,28)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,29)->text())//10
                        .arg(ui->EM_METER_TblWidget->item(i,30)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,31)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,32)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,33)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,34)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,35)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,36)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,37)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,38)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,39)->text())//10
                        .arg(ui->EM_METER_TblWidget->item(i,40)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,41)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,42)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,43)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,44)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,45)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,46)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,47)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,48)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,49)->text())//10
                        .arg(ui->EM_METER_TblWidget->item(i,50)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,51)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,52)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,53)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,54)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,55)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,56)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,57)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,58)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,59)->text())//10
                        .arg(ui->EM_METER_TblWidget->item(i,60)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,61)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,62)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,63)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,64)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,65)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,66)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,67)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,68)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,69)->text())//10
                        .arg(ui->EM_METER_TblWidget->item(i,70)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,71)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,72)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,73)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,74)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,75)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,76)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,77)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,78)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,79)->text())//10
                        .arg(ui->EM_METER_TblWidget->item(i,80)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,81)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,82)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,83)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,84)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,85)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,86)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,87)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,88)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,89)->text())//10
                        .arg(ui->EM_METER_TblWidget->item(i,90)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,91)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,92)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,93)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,94)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,95)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,96)->text())
                        .arg(ui->EM_METER_TblWidget->item(i,97)->text());

        #endif
            byteArray = strExec.toLocal8Bit();
            intResult= sql_exec(byteArray.data());

            if(intResult!=SQLITE_OK)
            {
                qDebug()<<"insert MT_METER error";
            }
    }

}
