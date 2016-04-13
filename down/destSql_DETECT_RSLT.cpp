
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSqlQuery"
#include "QDebug"
#include "QSqlRecord"
#include "QSqlError"

/******************************************************************************************
 *
 *C34
 * .arg("to_date('2015-08-22 09:14:20','yyyy-mm-dd hh24:mi:ss')")//time  ;
 *****************************************************************************************/

#if 1
//WH
bool MainWindow::update_DETECT_RSLT()
{
    bool IsSuccessful;
    QString strExec,strTime;

    int rowCount,columnCount;
    rowCount = ui->EM_RSLT_TabWidget->rowCount();
    columnCount = ui->EM_RSLT_TabWidget->columnCount();

    for(int j=0;j<rowCount;j++)
    {
        for(int i=0;i<columnCount;i++)
        {
            if(!ui->EM_RSLT_TabWidget->item(j,i))
            ui->EM_RSLT_TabWidget->setItem(j,i, new QTableWidgetItem(""));
        }
    }

    for(int i =0;i<rowCount;i++)//
    {
        strTime = QString("to_date('%1','yyyy-mm-dd hh24:mi:ss')").arg(ui->EM_RSLT_TabWidget->item(i,50)->text());
        //qDebug()<<strTime;
        strExec =  QString("INSERT INTO MT_DETECT_RSLT values( '%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12','%13','%14','%15','%16','%17','%18','%19','%20','%21','%22','%23','%24','%25','%26','%27','%28','%29','%30','%31','%32','%33','%34','%35','%36','%37','%38','%39','%40','%41','%42','%43','%44','%45','%46','%47','%48','%49','%50','%51','%52','%53','%54','%55','%56','%57','%58','%59','%60','%61','%62','%63','%64','%65','%66','%67','%68','%69','%70','%71','%72','%73','%74','%75','%76','%77','%78','%79','%80','%81','%82','%83','%84','%85','%86','%87','%88','%89','%90')")
                .arg(ui->EM_RSLT_TabWidget->item(i,0)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,1)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,2)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,3)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,4)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,5)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,6)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,7)->text())
//                .arg("to_date('2015-08-22 ','yyyy-mm-dd ')")//time
                .arg(ui->EM_RSLT_TabWidget->item(i,8)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,9)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,10)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,11)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,12)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,13)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,14)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,15)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,16)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,17)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,18)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,19)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,20)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,21)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,22)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,23)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,24)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,25)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,26)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,27)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,28)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,29)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,30)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,31)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,32)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,33)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,34)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,35)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,36)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,37)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,38)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,39)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,40)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,41)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,42)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,43)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,44)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,45)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,46)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,47)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,48)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,49)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,50)->text())
//                .arg(strTime)//.arg("to_date('2015-08-22 09:14:20','yyyy-mm-dd hh24:mi:ss')")//time
                .arg(ui->EM_RSLT_TabWidget->item(i,51)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,52)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,53)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,54)->text())
//                .arg("to_date('2015-01-02','yyyy-mm-dd')")//time
                .arg(ui->EM_RSLT_TabWidget->item(i,55)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,56)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,57)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,58)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,59)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,60)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,61)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,62)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,63)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,64)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,65)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,66)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,67)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,68)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,69)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,70)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,71)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,72)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,73)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,74)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,75)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,76)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,77)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,78)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,79)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,80)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,81)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,82)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,83)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,84)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,85)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,86)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,87)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,88)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,89)->text());

         //qDebug()<<strExec;
#if 1

        IsSuccessful =sqlQueryExec("MT_DETECT_RSLT",ui->EM_RSLT_TabWidget->item(i,6)->text()+" Num:"+QString::number(i), strExec,QString::fromUtf8("成功添加"));

        if(IsSuccessful==false)
        {
            showInformationBox(QString::fromUtf8("出错,请查看当前log.txt记录"));
            return false;
        }
#endif
    }
    return true;
}

#endif

#if 0
//JN
bool MainWindow::update_DETECT_RSLT()
{
    bool IsSuccessful;
    QString strExec,strTime;
    int rowCount ,columnCount;

    rowCount = ui->EM_RSLT_TabWidget->rowCount();
    columnCount = ui->EM_RSLT_TabWidget->columnCount();

    for(int j=0;j<rowCount;j++)
    {
        for(int i=0;i<columnCount;i++)
        {
            if(!ui->EM_RSLT_TabWidget->item(j,i))
            ui->EM_RSLT_TabWidget->setItem(j,i, new QTableWidgetItem(""));
        }
    }

// .arg("to_date('2015-08-22 09:14:20','yyyy-mm-dd hh24:mi:ss')")//time  ;
    for(int i =0;i<rowCount;i++)//
    {
        strTime = QString("to_date('%1','yyyy-mm-dd hh24:mi:ss')").arg(ui->EM_RSLT_TabWidget->item(i,50)->text());
        //qDebug()<<strTime;
        strExec =  QString("INSERT INTO MT_DETECT_RSLT values( '%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12','%13','%14','%15','%16','%17','%18','%19','%20','%21','%22','%23','%24','%25','%26','%27','%28','%29','%30','%31','%32','%33','%34','%35','%36','%37','%38','%39','%40','%41','%42','%43','%44','%45','%46','%47','%48','%49','%50',%51,'%52','%53','%54','%55','%56','%57','%58','%59','%60','%61','%62','%63','%64','%65','%66','%67','%68','%69','%70','%71','%72','%73','%74','%75','%76','%77','%78','%79','%80','%81','%82','%83','%84','%85','%86','%87','%88','%89')")
                .arg(ui->EM_RSLT_TabWidget->item(i,0)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,1)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,2)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,3)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,4)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,5)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,6)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,7)->text())
//                .arg("to_date('2015-08-22 ','yyyy-mm-dd ')")//time
                .arg(ui->EM_RSLT_TabWidget->item(i,8)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,9)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,10)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,11)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,12)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,13)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,14)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,15)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,16)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,17)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,18)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,19)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,20)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,21)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,22)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,23)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,24)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,25)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,26)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,27)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,28)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,29)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,30)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,31)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,32)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,33)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,34)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,35)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,36)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,37)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,38)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,39)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,40)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,41)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,42)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,43)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,44)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,45)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,46)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,47)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,48)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,49)->text())
                .arg(strTime)//.arg("to_date('2015-08-22 09:14:20','yyyy-mm-dd hh24:mi:ss')")//time
                .arg(ui->EM_RSLT_TabWidget->item(i,51)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,52)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,53)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,54)->text())
//                .arg("to_date('2015-01-02','yyyy-mm-dd')")//time
                .arg(ui->EM_RSLT_TabWidget->item(i,55)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,56)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,57)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,58)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,59)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,60)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,61)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,62)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,63)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,64)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,65)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,66)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,67)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,68)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,69)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,70)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,71)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,72)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,73)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,74)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,75)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,76)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,77)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,78)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,79)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,80)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,81)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,82)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,83)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,84)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,85)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,86)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,87)->text())
                .arg(ui->EM_RSLT_TabWidget->item(i,88)->text());
         //qDebug()<<strExec;
#if 1

        IsSuccessful =sqlQueryExec("MT_DETECT_RSLT",ui->EM_RSLT_TabWidget->item(i,6)->text()+" Num:"+QString::number(i), strExec,QString::fromUtf8("成功添加"));

        if(IsSuccessful==false)
        {
            showInformationBox(QString::fromUtf8("出错,请查看当前log.txt记录"));
            return false;
        }
#endif
    }
    return true;
}

#endif

