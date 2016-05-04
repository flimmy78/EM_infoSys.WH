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
//通过任务单号获取基本误差信息
bool MainWindow::fill_BASICERR(int index)
{
    get_BASICERR_checkError("'"+strArray[0][index]+"'");
    for(int i =0;i<20000;i++)
    {
        //延时
    }
    get_BASICERR_checkParameter("'"+strArray[0][index]+"'");
    return true;
}

//获取checkParameter相关内容
int MainWindow:: get_BASICERR_checkParameter(QString strID)
{
    QString strExec,str2,str3;
    int rowCount;

    strExec=QString("select * from checkParameter where id =%1").arg(strID);

    if(!SqlTempToQstring(strExec,11))
    {
        return 0;
    }

    rowCount =ui->EM_BASICERR_TblWidget->rowCount();
    for(int i=0;i<rowCount;i++)
    {
        if(strArray[15][0]==ui->EM_BASICERR_TblWidget->item(i,28)->text())//strArray[15][0]为本地localsql key标识符号
        {
            ui->EM_BASICERR_TblWidget->setItem(i,7,new QTableWidgetItem(strArray[15][2]));                //检定日期
            ui->EM_BASICERR_TblWidget->setItem(i,14,new QTableWidgetItem("100%Un"));//(DYDM_index("100%Un")          //电压百分百

            str2 = strArray[15][10];
            str3 = indexOfTable(str2,QString::fromUtf8("校验圈数"));
            //qDebug()<<str2;
            if(str3=="")
            {
                ui->EM_BASICERR_TblWidget->setItem(i,17,new QTableWidgetItem("5"));                      //校验圈数
            }
            else
            {
                 ui->EM_BASICERR_TblWidget->setItem(i,17,new QTableWidgetItem(str3));                     //校验圈数
            }
        }
    }

    return 0;
}

bool MainWindow::update_BASICERR()
{

    bool IsSuccessful;
    QString strExec;

    int rowCount,columnCount;

    rowCount = ui->EM_BASICERR_TblWidget->rowCount();
    columnCount = ui->EM_BASICERR_TblWidget->columnCount();

    for(int j=0;j<rowCount;j++)
    {
        for(int i=0;i<columnCount;i++)
        {
            if(!ui->EM_BASICERR_TblWidget->item(j,i))
            ui->EM_BASICERR_TblWidget->setItem(j,i, new QTableWidgetItem(""));
        }
    }

    for(int i =0;i<rowCount;i++)//
    {
            strExec = QString("INSERT INTO MT_BASICERR_MET_CONC values(  '%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12','%13','%14','%15','%16','%17','%18','%19','%20','%21','%22','%23','%24','%25','%26','%27','%28')")
                    .arg(ui->EM_BASICERR_TblWidget->item(i,0)->text())
                    .arg(ui->EM_BASICERR_TblWidget->item(i,1)->text())
                    .arg(ui->EM_BASICERR_TblWidget->item(i,2)->text())
                    .arg(ui->EM_BASICERR_TblWidget->item(i,3)->text())
                    .arg(ui->EM_BASICERR_TblWidget->item(i,4)->text())
                    .arg(ui->EM_BASICERR_TblWidget->item(i,5)->text())
                    .arg(ui->EM_BASICERR_TblWidget->item(i,6)->text())
                    .arg(ui->EM_BASICERR_TblWidget->item(i,7)->text())
                    .arg(ui->EM_BASICERR_TblWidget->item(i,8)->text())
                    .arg(ui->EM_BASICERR_TblWidget->item(i,9)->text())
                    .arg(ui->EM_BASICERR_TblWidget->item(i,10)->text())

                    .arg(ui->EM_BASICERR_TblWidget->item(i,11)->text())
                    .arg(ui->EM_BASICERR_TblWidget->item(i,12)->text())
                    .arg(ui->EM_BASICERR_TblWidget->item(i,13)->text())
                    .arg(ui->EM_BASICERR_TblWidget->item(i,14)->text())
                    .arg(ui->EM_BASICERR_TblWidget->item(i,15)->text())
                    .arg(ui->EM_BASICERR_TblWidget->item(i,16)->text())
                    .arg(ui->EM_BASICERR_TblWidget->item(i,17)->text())
                    .arg(ui->EM_BASICERR_TblWidget->item(i,18)->text())
                    .arg(ui->EM_BASICERR_TblWidget->item(i,19)->text())
                    .arg(ui->EM_BASICERR_TblWidget->item(i,20)->text())

                    .arg(ui->EM_BASICERR_TblWidget->item(i,21)->text())
                    .arg(ui->EM_BASICERR_TblWidget->item(i,22)->text())
                    .arg(ui->EM_BASICERR_TblWidget->item(i,23)->text())
                    .arg(ui->EM_BASICERR_TblWidget->item(i,24)->text())
                    .arg(ui->EM_BASICERR_TblWidget->item(i,25)->text())
                    .arg(ui->EM_BASICERR_TblWidget->item(i,26)->text())
                    .arg(ui->EM_BASICERR_TblWidget->item(i,27)->text());

        IsSuccessful =sqlQueryExec("MT_BASICERR_MET_CONC",ui->EM_BASICERR_TblWidget->item(i,6)->text()+" Num:"+QString::number(i), strExec,QString::fromUtf8("成功添加"));

        if(IsSuccessful==false)
        {
            showInformationBox(QString::fromUtf8("出错,请查看当前log.txt记录"));
            return false;
        }
    }
     return true;
}

