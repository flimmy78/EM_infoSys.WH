#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSqlQuery"
#include "QDebug"
#include "QSqlRecord"
#include "QSqlError"

/******************************************************************************************
 *
 *C2
 *
 *****************************************************************************************/

void MainWindow::update_DAYERR()
{

    QString strExec ;
    QSqlQuery sqlQuery;

#if 1
    strExec =  QString("INSERT INTO MT_DAYERR_MET_CONC values(  '%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12','%13','%14','%15','%16','%17','%18','%19','%20','%21','%22','%23')")
            .arg("3915071337300813")
            .arg("")
            .arg("")
            .arg("")
            .arg("")
            .arg("")
            .arg("4230001001000016254452")
            .arg("")
            .arg("1")
            .arg("1")//10
            .arg("")
            .arg("")
            .arg("")
            .arg("")
            .arg("")
            .arg("")
            .arg("")
            .arg("")
            .arg("")
            .arg("")//10
            .arg("0")
            .arg("")
            .arg("");
#endif

 //qDebug()<<strExec;
#if 1
    if(!sqlQuery.exec(strExec))
    {
        qDebug()<<sqlQuery.lastError();
        showInformationBox(QString::fromUtf8("数据不规范"));
        return;
    }
    else
    {
        showInformationBox(QString::fromUtf8("成功插入"));
    }
#endif

}



