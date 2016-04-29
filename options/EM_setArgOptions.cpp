#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSqlQuery"
#include "QDebug"
#include "QSqlRecord"
#include "QMessageBox"
#include "QSqlError"
//链接MDS的中间库
void MainWindow::on_EM_options_cnt_RdBtn_clicked()
{
   setCursor(QCursor(Qt::WaitCursor));
   QString sIp,iPort,sDbNm,sUserNm,sPwd;

   sIp      = ui->EM_options_setArg_IP_LnEdit->text();
   iPort    = ui->EM_options_setArg_Port_LnEdit->text();
   sUserNm  = ui->EM_options_setArg_UserName_LnEdit->text();
   sPwd     = ui->EM_options_setArg_PassWord_LnEdit->text();
   sDbNm    = ui->EM_options_setArg_SID_LnEdit->text();


//WH
//  connect_destSql("10.229.255.180", 1521,  "pmcpdp", "sxykjd", "sxykjd");//cs库
//  connect_destSql("10.229.255.178", 1521,  "pmcpdp2", "sxykjd", "sxykjd@jd");//zs库

//JN
//  connect_destSql("10.158.249.97", 1521,"jldjz", "sxykjd", "sxykjd");//cs库
//  connect_destSql("10.158.244.87", 1521,"jldb1", "sxykjd", "SXYKJD2014");//zs库

   connect_destSql(sIp, iPort.toInt(0,10),sDbNm,sUserNm,sPwd);//zs库

   setCursor(QCursor(Qt::ArrowCursor));
}

void MainWindow::connect_destSql(QString sIp, int iPort,  QString sDbNm, QString sUserNm, QString sPwd)
{
  // qDebug()<<sPwd;
#if 1
    QSqlDatabase db  = QSqlDatabase::addDatabase("QOCI");
    db.setHostName(sIp);
    db.setPort(iPort);
    db.setDatabaseName(sDbNm);
    db.setUserName(sUserNm);
    db.setPassword(sPwd);

    //qDebug()<<sIp<<iPort<<sDbNm<<sUserNm<<sPwd;
    if (db.open())
    {
         ui->EM_options_cnt_RdBtn->setChecked(true);
    }
    else
    {
         //qDebug()<<db.lastError().text();
         ui->stackedWidget->setCurrentIndex(2);
         on_EM_options_Act_triggered();
         showInformationBox(QString(db.lastError().text()));
         ui->EM_options_cnt_RdBtn->setChecked(false);

         //sqlQuery.lastError().databaseText()
    }
#endif

 //  db.close();
}


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
            strTemp = ui->EM_options_setArg_IP_LnEdit->text();
            writeIni("Oracle/IP",strTemp);
            strTemp = ui->EM_options_setArg_Port_LnEdit->text();
            writeIni("Oracle/Port",strTemp);
            strTemp = ui->EM_options_setArg_UserName_LnEdit->text();
            writeIni("Oracle/UserName",strTemp);
            strTemp = ui->EM_options_setArg_PassWord_LnEdit->text();
            writeIni("Oracle/Password",strTemp);
            strTemp = ui->EM_options_setArg_SID_LnEdit->text();
            writeIni("Oracle/SID",strTemp);
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

                #if 0
                strExec ="delete from  MT_P_CODE";
                intResult= sql_exec(strExec.toLatin1().data());

                if(intResult!=SQLITE_OK)
                {
                     showInformationBox(QString::fromUtf8("delete MT_P_CODE error"));
                     return;
                }

                strExec ="delete from  MT_METER";
                intResult= sql_exec(strExec.toLatin1().data());

                if(intResult!=SQLITE_OK)
                {
                    showInformationBox(QString::fromUtf8("delete MT_METER error"));
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

