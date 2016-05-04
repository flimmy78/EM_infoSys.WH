#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QDebug"
#include "QMessageBox"
#include "QTextStream"
#include "QCryptographicHash"

//将数据加密返回,要求大写
QString MainWindow::MD5_getSampleInfo(QString strSou)
{
    QString secretKey;
    QByteArray byteArray;
    byteArray = QCryptographicHash::hash(strSou.toAscii(),QCryptographicHash::Md5);
    secretKey.append(byteArray.toHex());
    return secretKey.toUpper();
}
