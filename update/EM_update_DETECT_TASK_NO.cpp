#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "stdio.h"
#include "QDebug"
#include "QTime"

//加载当前数据库里面的下载的所有检定任务编号
void MainWindow::on_EM_update_loadDetectTaskNo_PsBtn_clicked()
{
    QString str1;

    remove_TblWdiget_Row(ui->EM_update_loadDetectTaskNo_TblWidget);
    get_checkParameter_detectTaskNo();
    int rowCount=ui->EM_update_loadDetectTaskNo_TblWidget->rowCount();
    int sqlItemCount=LocalSqlSum;
    for(int i=0;i<sqlItemCount;i++)
    {
        str1 = indexOfTable(strArray[1][i],QString::fromUtf8("TASK_PRIO"));
        str1.remove(QString::fromUtf8("任务单号"));
        str1.remove(QString::fromUtf8("\t"));
        str1.remove(QString::fromUtf8("\r"));
        str1.remove(QString::fromUtf8(" "));
        //qDebug()<<str1;
        if(isTaskNoExist(str1,ui->EM_update_loadDetectTaskNo_TblWidget,0))
        {
           //qDebug()<<str1;
            ui->EM_update_loadDetectTaskNo_TblWidget->insertRow(rowCount);
            ui->EM_update_loadDetectTaskNo_TblWidget->setItem(rowCount,0, new QTableWidgetItem(str1));
            ui->EM_update_loadDetectTaskNo_TblWidget->item(rowCount,0)->setCheckState(Qt::Unchecked);
        }
    }
}

//根据任务单编号当前数据库里面的检定数据
void MainWindow::on_EM_update_loadLocalSql_PsBtn_clicked()
{
    QString strTaskNO,str1,strBarCode;
    setCursor(QCursor(Qt::WaitCursor));

    remove_TblWdiget_Row(ui->EM_INTUIT_MET_TblWidget);
    remove_TblWdiget_Row(ui->EM_BASICERR_TblWidget);
    remove_TblWdiget_Row(ui->EM_RSLT_TabWidget);
    remove_TblWdiget_Row(ui->EM_STARTING_TblWidget);
    remove_TblWdiget_Row(ui->EM_CREEPING_TblWidget);
    remove_TblWdiget_Row(ui->EM_MEASURE_REPEAT_TblWidget);
    remove_TblWdiget_Row(ui->EM_INFLUENCE_QTY_TblWidget); //

    int rowCount=ui->EM_update_loadDetectTaskNo_TblWidget->rowCount();

    for(int i =0;i<rowCount;i++)
    {

        if(ui->EM_update_loadDetectTaskNo_TblWidget->item(i,0)->checkState()==Qt::Checked)
        {
             strTaskNO =ui->EM_update_loadDetectTaskNo_TblWidget->item(i,0)->text();

             get_checkParameter_detectTaskNo();

             int sqlItemCount=LocalSqlSum;

             for(int j=0;j<sqlItemCount;j++)
             {
                 str1 = indexOfTable(strArray[1][j],QString::fromUtf8("TASK_PRIO"));
                 str1.remove(QString::fromUtf8("任务单号"));
                 str1.remove(QString::fromUtf8("\t"));
                 str1.remove(QString::fromUtf8("\r"));
                 str1.remove(QString::fromUtf8(" "));

                 if(str1==strTaskNO)             //拿到相同的任务单号的数据
                 {
                     strBarCode = indexOfTable(strArray[1][j],QString::fromUtf8("BAR_CODE"));
                     strBarCode.remove(QString::fromUtf8("条形码"));
                     strBarCode.remove(QString::fromUtf8("\t"));
                     strBarCode.remove(QString::fromUtf8("\r"));
                     strBarCode.remove(QString::fromUtf8(" "));

                     QString strExec=QString("select * from MT_DETECT_TASK where BAR_CODE ='%1';").arg(strBarCode);

                     if(isLocalBarCodeExist(strExec,strBarCode)) //判断条形码是否有下载信息
                     {
                        #if 1
                        if(SqlTempToQstring(strExec,26))//填入检定任务信息
                        {
                        // fill_DETECT_OUT_EQUIP();

                             fill_DETECT_TASK();              //检定任务单
                             fill_INTUIT();                   //外观检查结论
                             fill_BASICERR(j);                //基本误差
                             fill_STARTING(j);                //起动测试
                             fill_CREEPING(j);                //潜动测试
                             fill_MEASURE_REPEAT(j);          //测量重复性
                             fill_INFLUENCE_QTY(j);           //影响量
                             fill_DETECT_RSLT(j);             //检测总结论
                         }
                        #endif
                     }
                 }
             }
        }
    }

    setCursor(QCursor(Qt::ArrowCursor));

}



//加入已经存在任务单编号，则返回错
bool  MainWindow:: isTaskNoExist(QString strTaskNo,QTableWidget * tblWidget,int index)
{
    int rowCount =tblWidget->rowCount();

    if((rowCount==0)&&(strTaskNo!=""))
    {
        return true;
    }

    if(strTaskNo=="")
    {
        return false;
    }

    for(int i=0;i<rowCount;i++)
    {
        if(strTaskNo==tblWidget->item(i,index)->text())
        {
            return false;
        }
    }

    return true;
}


