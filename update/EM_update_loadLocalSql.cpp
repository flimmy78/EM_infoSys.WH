#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "stdio.h"
#include "QDebug"
#include "QTime"

//加载当前数据库里面的下载的条形码
void MainWindow::on_EM_update_searchBarCode_LnEdit_textChanged(const QString &arg1)
{
    QString sampleNo,ID;

    remove_TblWdiget_Row(ui->EM_update_loadDetectTaskNo_TblWidget);
    get_checkParameter_detectTaskNo();
    int rowCount;

    for(int i=0;i<LocalSqlSum;i++)
    {
        sampleNo = indexOfTable(strArray[1][i],QString::fromUtf8("BAR_CODE"));
        sampleNo.remove(QString::fromUtf8("条形码"));
        sampleNo.remove(QString::fromUtf8("\t"));
        sampleNo.remove(QString::fromUtf8("\r"));
        sampleNo.remove(QString::fromUtf8(" "));
        ID =strArray[0][i];

        if(arg1==sampleNo)
        {
            rowCount=ui->EM_update_loadDetectTaskNo_TblWidget->rowCount();
            ui->EM_update_loadDetectTaskNo_TblWidget->insertRow(rowCount);
            ui->EM_update_loadDetectTaskNo_TblWidget->setItem(rowCount,0, new QTableWidgetItem(sampleNo));
            ui->EM_update_loadDetectTaskNo_TblWidget->setItem(rowCount,1, new QTableWidgetItem(ID));
            ui->EM_update_loadDetectTaskNo_TblWidget->item(rowCount,0)->setCheckState(Qt::Unchecked);

        }
    }
}

//加载当前数据库里面的下载的所有条形码
void MainWindow::on_EM_update_loadDetectTaskNo_PsBtn_clicked()
{
    QString str1,ID;

    remove_TblWdiget_Row(ui->EM_update_loadDetectTaskNo_TblWidget);
    get_checkParameter_detectTaskNo();
    int rowCount=ui->EM_update_loadDetectTaskNo_TblWidget->rowCount();
    int sqlItemCount=LocalSqlSum;
    for(int i=0;i<sqlItemCount;i++)
    {
        str1 = indexOfTable(strArray[1][i],QString::fromUtf8("BAR_CODE"));
        ID   = strArray[0][i];
        //qDebug()<<strArray[1][i];
        str1.remove(QString::fromUtf8("条形码"));
        str1.remove(QString::fromUtf8("\t"));
        str1.remove(QString::fromUtf8("\r"));
        str1.remove(QString::fromUtf8(" "));
        //qDebug()<<str1;
        if(isTaskNoExist(str1,ui->EM_update_loadDetectTaskNo_TblWidget,0))
        {
           //qDebug()<<str1;
            ui->EM_update_loadDetectTaskNo_TblWidget->insertRow(rowCount);
            ui->EM_update_loadDetectTaskNo_TblWidget->setItem(rowCount,0, new QTableWidgetItem(str1));
            ui->EM_update_loadDetectTaskNo_TblWidget->setItem(rowCount,1, new QTableWidgetItem(ID));
            ui->EM_update_loadDetectTaskNo_TblWidget->item(rowCount,0)->setCheckState(Qt::Unchecked);
        }
    }
}

//根据任务单编号当前数据库里面的检定数据
void MainWindow::on_EM_update_loadLocalSql_PsBtn_clicked()
{
    QString sampleNo,ID,strExec;
    char intCheckCount =0;
    setCursor(QCursor(Qt::WaitCursor));

    remove_TblWdiget_Row(ui->EM_INTUIT_MET_TblWidget);
    remove_TblWdiget_Row(ui->EM_BASICERR_TblWidget);
    remove_TblWdiget_Row(ui->EM_RSLT_TabWidget);
    remove_TblWdiget_Row(ui->EM_STARTING_TblWidget);
    remove_TblWdiget_Row(ui->EM_CREEPING_TblWidget);
    remove_TblWdiget_Row(ui->EM_MEASURE_REPEAT_TblWidget);
    remove_TblWdiget_Row(ui->EM_INFLUENCE_QTY_TblWidget); //

    int rowCount=ui->EM_update_loadDetectTaskNo_TblWidget->rowCount();

    for(int i =0;i<rowCount;i++)//查找出勾选的条形码
    {
        if(ui->EM_update_loadDetectTaskNo_TblWidget->item(i,0)->checkState()==Qt::Checked)
        {
            if(intCheckCount++ >= 1)
            {
                showInformationBox(QString::fromUtf8("每次只能勾选一条条形码，当前超出"));
                setCursor(QCursor(Qt::ArrowCursor));
                return;
            }

            sampleNo = ui->EM_update_loadDetectTaskNo_TblWidget->item(i,0)->text();
            ID       = ui->EM_update_loadDetectTaskNo_TblWidget->item(i,1)->text();

            if(!get_ID_from_checkParameter(sampleNo,ID))
            {
                setCursor(QCursor(Qt::ArrowCursor));
                return;
            }

            strExec=QString("select * from sampleInfo where sampleNo ='%1';").arg(sampleNo);

             if(isLocalBarCodeExist(strExec,sampleNo)) //判断条形码是否有下载信息
             {
                #if 1
                if(SqlTempToQstring(strExec,20))//获取sampleInfo信息(数据库执行语句,数据库长度)
                {
                     int j=0;
                                                         //已经查到的信息直接导入
                     fill_DETECT_TASK();                 //填充信息
                     fill_INTUIT();                      //外观检查结论
                     fill_STARTING(j);                   //起动测试
                     fill_CREEPING(j);                   //潜动测试
                     fill_INFLUENCE_QTY(j);              //影响量

                                                         //信息需求复杂重新查找
                     fill_BASICERR(ID);                  //基本误差
                     fill_MEASURE_REPEAT(ID);            //测量重复性
                     fill_DETECT_RSLT((ID));             //检测总结论

                    // qDebug()<<my_MT_DETECT_TASK.BAR_CODE ;
                 }
                #endif
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


