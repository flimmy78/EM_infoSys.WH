#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSqlQuery"
#include "QDebug"
#include "QSqlRecord"
#include "QMessageBox"
#include "QSqlError"

//查看中间库的数据，需要将中间库链接
void MainWindow::on_EM_options_check_PsBtn_clicked()
{
    QString strTemp ;
    QSqlRecord sqlRec;

    ui->EM_options_check_TxtBrowser->setText("");
    strTemp = ui->EM_options_check_LnEdit->text();
    QSqlQuery sqlQuery(strTemp);
    sqlRec  = sqlQuery.record();
    while(sqlQuery.next())
    {
        for(int i=0;i<sqlRec.count();i++)
        {
          strTemp=QString::number(i)+" :  " +sqlQuery.value(i).toString();
          ui->EM_options_check_TxtBrowser->append(strTemp);
        }
    }
}


void MainWindow::on_EM_options_setArg_Oracle_PsBtn_clicked()
{
    QString  strTemp;
    switch(QMessageBox::question(this,QString::fromUtf8("信息提醒"),QString::fromUtf8("是否修改配置？"),
                                 QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes))
       {
          case QMessageBox::Yes:
         {
            strTemp = ui->EM_options_appKey_LnEdit->text();
            writeIni("sysParams/appKey",strTemp);
            strTemp = ui->EM_options_appSecret_LnEdit->text();
            writeIni("sysParams/appSecret",strTemp);
            showInformationBox(QString::fromUtf8("已经修改,重新启动软件生效"));
            break;
         }
          case QMessageBox::No: break;
          default:   break;
       }
}
//检定线台编号
void MainWindow::on_EM_options_detectEquipNo_PsBtn_clicked()
{
    QString strTemp=ui->EM_options_detectEquipNo_LnEdit->text();
    switch(QMessageBox::question(this,QString::fromUtf8("信息提醒"),QString::fromUtf8("是否修改编号？"),
                                 QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes))
       {
          case QMessageBox::Yes:
         {
            writeIni("localSql/DETECT_QEUIP_NO",strTemp);
            showInformationBox(QString::fromUtf8("已经修改,重新启动软件生效"));
            break;
         }
          case QMessageBox::No: break;
          default:   break;
       }
}
//保存校验数据库的地址
void MainWindow::on_EM_options_setArg_localSqlPath_PsBtn_clicked()
{
    QString strTemp=ui->EM_options_setArg_localSqlPath_LnEdit->text();
    strTemp=strTemp.replace("\\","/");
    switch(QMessageBox::question(this,QString::fromUtf8("信息提醒"),QString::fromUtf8("是否修改路径？"),
                                 QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes))
       {
          case QMessageBox::Yes:
         {
            writeIni("localSql/Path",strTemp);
            showInformationBox(QString::fromUtf8("已经修改,重新启动软件生效"));
            break;
         }
          case QMessageBox::No: break;
          default:   break;
       }
}

//清除 所有数据：MT_P_CODE
void MainWindow::on_EM_options_deleteLocalSqlAll_PsBtn_clicked()
{
    switch(QMessageBox::question(this,QString::fromUtf8("信息提醒"),QString::fromUtf8("是否清空从电能表获取的数据库？"),
                                 QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes))
       {
          case QMessageBox::Yes:
         {
                QString strExec;
                int intResult;

                strExec ="delete from  sampleInfo";
                intResult= sql_exec(strExec.toLatin1().data());

                if(intResult!=SQLITE_OK)
                {
                     showInformationBox(QString::fromUtf8("delete sampleInfo error"));
                     return;
                }

                strExec ="delete from  MT_METER";
                intResult= sql_exec(strExec.toLatin1().data());

                if(intResult!=SQLITE_OK)
                {
                    showInformationBox(QString::fromUtf8("delete MT_METER error"));
                    return;
                }


                #if 0
                strExec ="delete from  MT_P_CODE";
                intResult= sql_exec(strExec.toLatin1().data());

                if(intResult!=SQLITE_OK)
                {
                     showInformationBox(QString::fromUtf8("delete MT_P_CODE error"));
                     return;
                }



                strExec ="delete from  MT_DETECT_TASK";
                intResult= sql_exec(strExec.toLatin1().data());

                if(intResult!=SQLITE_OK)
                {
                    showInformationBox(QString::fromUtf8("delete MT_DETECT_TASK error"));
                    return;
                }


                strExec ="delete from  MT_DETECT_OUT_EQUIP";
                intResult= sql_exec(strExec.toLatin1().data());

                if(intResult!=SQLITE_OK)
                {
                    showInformationBox(QString::fromUtf8("delete TABLEMT_DETECT_OUT_EQUIP error"));
                    return;
                }
            #endif
             showInformationBox(QString::fromUtf8("已经清空"));
             break;
         }

           case QMessageBox::No: break;
           default:   break;

       }
}

