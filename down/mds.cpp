#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSettings"
#include "QDebug"


//void MainWindow::on_MDS_changeURL_PsBtn_clicked()
//{
//    QString str1 =ui->MDS_URL_LnEdit->text();
//    writeIni("Server/URL",str1);
//    str1 =ui->MDS_account_LnEdit->text();
//    writeIni("Server/account",str1);
//    str1 =ui->MDS_password_LnEdit->text();
//    writeIni("Server/password",str1);
//}
void MainWindow:: writeIni(QString path,QString arg)
{
    QSettings *configIniWrite = new QSettings("Sys.ini", QSettings::IniFormat);
    configIniWrite->setValue(path, arg);
    delete configIniWrite;
}

