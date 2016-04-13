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

bool MainWindow::update_CONST()
{

    QString strExec ;
    QSqlQuery sqlQuery;

#if 1
    strExec =  QString("INSERT INTO MT_CONST_MET_CONC values(  '%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12','%13','%14','%15','%16','%17','%18','%19','%20','%21','%22','%23','%24','%25','%26','%27','%28','%29','%30','%31','%32','%33','%34','%35','%36')")
            .arg("3915071337300813")
            .arg("01")
            .arg("402")
            .arg("")
            .arg("")
            .arg("")
            .arg("4230001001000016254452")
            .arg("2015-07-17 08:59:00")
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
            .arg("")
            .arg("")
            .arg("")
            .arg("2015-07-17 08:59:00")
            .arg("0")
            .arg("2015-07-17 08:59:00")
            .arg("")
            .arg("")
            .arg("")
            .arg("")//10
            .arg("")
            .arg("")
            .arg("")
            .arg("")
            .arg("")
            .arg("");
#endif

 //qDebug()<<strExec;
#if 1
    if(!sqlQuery.exec(strExec))
    {
        qDebug()<<sqlQuery.lastError();
        showInformationBox(QString::fromUtf8("数据不规范"));
        return false;
    }
    else
    {
        showInformationBox(QString::fromUtf8("成功插入"));
        return true;
    }
#endif

}





