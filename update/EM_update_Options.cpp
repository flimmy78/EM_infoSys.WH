#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "stdio.h"
#include "QDebug"
#include "QTime"




//将数据插入到中间库
void MainWindow::on_EM_update_insertDestSql_PsBtn_clicked()
{
    on_EM_update_deleteDestSql_PsBtn_clicked();

    setCursor(QCursor(Qt::WaitCursor));

#if 1
       if(!update_INTUIT())//c1
       {
            setCursor(QCursor(Qt::ArrowCursor));
             return;
       }
       if(!update_BASICERR())//c2
       {
            setCursor(QCursor(Qt::ArrowCursor));
             return;
       }
       if(!update_MEASURE_REPEAT())//c2
       {
            setCursor(QCursor(Qt::ArrowCursor));
             return;
       }
       if(!update_STARTING())//C4
       {
            setCursor(QCursor(Qt::ArrowCursor));
             return;
       }
       if(!update_CREEPING())//C5
       {
            setCursor(QCursor(Qt::ArrowCursor));
            return;
       }
       if(!update_INFLUENCE_QTY())//C25
       {
            setCursor(QCursor(Qt::ArrowCursor));
            return;
       }
#endif

       if(!update_DETECT_RSLT())//C34
       {
            setCursor(QCursor(Qt::ArrowCursor));
            return;
       }
      setCursor(QCursor(Qt::ArrowCursor));
      showInformationBox(QString::fromUtf8("成功各分项添加到中间库"));


}


void MainWindow::on_EM_update_deleteDestSql_PsBtn_clicked()
{
    QString strTaskNO,str1,strBarCode;
    setCursor(QCursor(Qt::WaitCursor));

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

                     delete_destSql_tableItem("MT_INTUIT_MET_CONC",strBarCode);
                     delete_destSql_tableItem("MT_BASICERR_MET_CONC",strBarCode);
                     delete_destSql_tableItem("MT_CONST_MET_CONC",strBarCode);
                     delete_destSql_tableItem("MT_STARTING_MET_CONC",strBarCode);
                     delete_destSql_tableItem("MT_CREEPING_MET_CONC",strBarCode);
                     delete_destSql_tableItem("MT_DAYERR_MET_CONC",strBarCode);
                     delete_destSql_tableItem("MT_INFLUENCE_QTY_MET_CONC",strBarCode);
                     delete_destSql_tableItem("MT_DETECT_RSLT",strBarCode);
                     delete_destSql_tableItem("MT_MEASURE_REPEAT_MET_CONC",strBarCode);

                 }
             }

        }
    }

    setCursor(QCursor(Qt::ArrowCursor));

}



