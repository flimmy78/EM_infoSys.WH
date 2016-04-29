#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QMessageBox"
#include "QTimer"
#include "QSettings"
#include "QFileInfo"
#include "QFileDialog"

#include "QSqlQuery"
#include "QSqlRecord"
#include "QSqlError"
#include "QFile"
#include "QDateTime"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    init_TblWidget();
    set_localSqlPath();
    open_localSql();
    //on_EM_options_cnt_RdBtn_clicked();
    on_EM_down_clean_PsBtn_clicked();


//   create_localDatabase(); //测试用
//   create_c1ToC10();
//   init_localDatabase();

}

MainWindow::~MainWindow()
{
    delete ui;
}

//初始化tableWidget的界面
void MainWindow:: init_TblWidget()
{
    ui->EM_DETECT_TASK_TblWidget->horizontalHeader()->setResizeMode( QHeaderView::ResizeToContents);
//  ui->EM_DETECT_TASK_TblWidget->verticalHeader()->setHidden(true);

    ui->EM_DETECT_OUT_EQUIP_TblWidget->horizontalHeader()->setResizeMode( QHeaderView::ResizeToContents);
//    ui->EM_DETECT_OUT_EQUIP_TblWidget->verticalHeader()->setHidden(true);

    ui->EM_BASICERR_TblWidget->horizontalHeader()->setResizeMode( QHeaderView::ResizeToContents);
    ui->EM_RSLT_TabWidget->horizontalHeader()->setResizeMode( QHeaderView::ResizeToContents);

    ui->EM_INTUIT_MET_TblWidget->horizontalHeader()->setResizeMode( QHeaderView::ResizeToContents);
    ui->EM_BASICERR_TblWidget->horizontalHeader()->setResizeMode( QHeaderView::ResizeToContents);
    ui->EM_METER_TblWidget->horizontalHeader()->setResizeMode( QHeaderView::ResizeToContents);
    ui->EM_P_CODE_TblWidget->horizontalHeader()->setResizeMode( QHeaderView::ResizeToContents);

    ui->EM_INFLUENCE_QTY_TblWidget->horizontalHeader()->setResizeMode( QHeaderView::ResizeToContents);
    ui->EM_STARTING_TblWidget->horizontalHeader()->setResizeMode( QHeaderView::ResizeToContents);
    ui->EM_CREEPING_TblWidget->horizontalHeader()->setResizeMode( QHeaderView::ResizeToContents);
    ui->EM_MEASURE_REPEAT_TblWidget->horizontalHeader()->setResizeMode( QHeaderView::ResizeToContents);

    ui->EM_sampleInfo_TblWidget->horizontalHeader()->setResizeMode( QHeaderView::ResizeToContents);
    ui->EM_sampleInfo_TblWidget->verticalHeader()->setHidden(false);

}

//设置本地数据的路径
//  connect_destSql("10.158.244.87", 1521,"jldb1", "sxykjd", "SXYKJD2014");//zs库

void MainWindow:: set_localSqlPath()
{
    QString strTemp;
    QSettings *configIniRead = new QSettings("Sys.ini", QSettings::IniFormat);
    strTemp =configIniRead->value("localSql/Path").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("E:/检定数据保存数据库.db");
       writeIni("localSql/Path",strTemp);
    }
    ui->EM_options_setArg_localSqlPath_LnEdit->setText(strTemp);

    strTemp =configIniRead->value("Oracle/IP").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("10.229.255.178");
       writeIni("Oracle/IP",strTemp);
    }
    ui->EM_options_setArg_IP_LnEdit->setText(strTemp);

    strTemp =configIniRead->value("Oracle/Port").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("1521");
       writeIni("Oracle/Port",strTemp);
    }
     ui->EM_options_setArg_Port_LnEdit->setText(strTemp);

    strTemp =configIniRead->value("Oracle/UserName").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("sxykjd");
       writeIni("Oracle/UserName",strTemp);
    }
    ui->EM_options_setArg_UserName_LnEdit->setText(strTemp);

    strTemp =configIniRead->value("Oracle/PassWord").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("sxykjd@jd");
       writeIni("Oracle/Password",strTemp);
    }
    ui->EM_options_setArg_PassWord_LnEdit->setText(strTemp);

    strTemp =configIniRead->value("Oracle/SID").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("pmcpdp2");
       writeIni("Oracle/SID",strTemp);
    }
    ui->EM_options_setArg_SID_LnEdit->setText(strTemp);


    strTemp =configIniRead->value("localSql/DETECT_QEUIP_NO").toString();
    if(strTemp.isEmpty())
    {
       strTemp=QString::fromUtf8("20131206");
       writeIni("localSql/DETECT_QEUIP_NO",strTemp);
    }
    ui->EM_options_detectEquipNo_LnEdit->setText(strTemp);
}

void MainWindow::showInformationBox(QString strTemp)
{
    QMessageBox     *informationBox;
    informationBox= new QMessageBox(QMessageBox::Information,QString::fromUtf8("提醒"),QString::fromUtf8(""));  //
    informationBox->addButton(new QPushButton(QString::fromUtf8("确定")),QMessageBox::AcceptRole);
    informationBox->setText(strTemp);
    informationBox->show();
    QTimer::singleShot(10000,informationBox,SLOT(hide()));
}

void MainWindow::remove_TblWdiget_Row(QTableWidget *TblWiget)
{
    int numTemp=TblWiget->rowCount();

    for(int i=numTemp;i>=0;i--)
    {
       TblWiget->removeRow(i);
    }
}

void MainWindow::on_EM_down_Act_triggered()
{
  ui->stackedWidget->setCurrentIndex(0);
  ui->EM_down_Act->setChecked(true);
  ui->EM_update_Act->setChecked(false);
  ui->EM_options_Act->setChecked(false);
}

void MainWindow::on_EM_update_Act_triggered()
{
   ui->stackedWidget->setCurrentIndex(1);
   ui->EM_down_Act->setChecked(false);
   ui->EM_update_Act->setChecked(true);
   ui->EM_options_Act->setChecked(false);
}

void MainWindow::on_EM_options_Act_triggered()
{
  ui->stackedWidget->setCurrentIndex(2);
  ui->EM_down_Act->setChecked(false);
  ui->EM_update_Act->setChecked(false);
  ui->EM_options_Act->setChecked(true);
}


QString MainWindow:: get_DB_FileName()
{
   QString   strFileName;
   QFileInfo fileInfo;

   setCursor(QCursor(Qt::WaitCursor));

   if(1)
   {
       strFileName =QFileDialog::getOpenFileName(this, QString::fromUtf8("打开文件"),  "",tr("Images (*.db *.DB)"));
   }
   else
   {
       strFileName=":/pic/1.db";
   }

   //qDebug()<<strFileName.toUtf8();
   fileInfo = QFileInfo(strFileName);
   setCursor(QCursor(Qt::ArrowCursor));
   return fileInfo.fileName();

}


void MainWindow:: writeIni(QString path,QString arg)
{
    QSettings *configIniWrite = new QSettings("Sys.ini", QSettings::IniFormat);
    configIniWrite->setValue(path, arg);
    delete configIniWrite;
}

bool MainWindow::sqlQueryExec(QString tabelName,QString barCode,QString strExec,QString strImfo)
{
   // qDebug()<<strExec;
    QSqlQuery sqlQuery;
    QString strError;
    if(!sqlQuery.exec(strExec))
    {
        strError=  currentTime()+":"+tabelName+":"+barCode+":"+sqlQuery.lastError().databaseText();
        errorLog(strError);
        return false;
    }
    else
    {
        //showInformationBox(strImfo);
        return true;
    }

}



bool MainWindow::delete_destSql_tableItem(QString tabelName,QString barCode)
{
    bool IsSuccessful;
    QString strExec;

    strExec = QString("delete from  %1 where BAR_CODE ='%2'")
            .arg(tabelName)
            .arg(barCode);

    IsSuccessful=sqlQueryExec(tabelName,barCode, strExec,QString::fromUtf8("删除成功"));

    if(IsSuccessful)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MainWindow::errorLog(QString strError)
{
    QFile file("log.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Append);//| QIODevice::Append
    QTextStream text_stream(&file);
    text_stream <<strError+"\n\r";
    file.flush();
    file.close();
}

QString MainWindow:: currentTime()
{
    QDateTime myTime = QDateTime::currentDateTime();
    return myTime.toString("yyyy-MM-dd hh:mm:ss");
}

//返回最新的时间
QString MainWindow::compare_DateTime(QString str1,QString str2)
{
    QDateTime dateTime1, dateTime2;
    long long long1,long2;
    long1=dateTime1.fromString(str1,"yyyy-MM-dd hh:mm:ss").toTime_t();
    long2=dateTime2.fromString(str2,"yyyy-MM-dd hh:mm:ss").toTime_t();

    if(long1>long2)
    {
        return str1;
    }
    else
    {
        return str2;
    }
#if 0
    QDateTime dateTime = dateTime.fromString("2015-07-14 08:59:01","yyyy-MM-dd hh:mm:ss");
    qDebug()<<dateTime.toString("yyyy-MM-dd");
    qDebug()<<dateTime.toString("hh-mm-ss.zzz");
    qDebug()<<QString::number(dateTime.toTime_t());
#endif
}

