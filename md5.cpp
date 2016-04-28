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


bool MainWindow:: create_MD5()
{
    QString username="admin";
    QString password="admin123";
    QString fileName="e:/pwd.txt";
    QFile file(fileName);

    if(!file.open(QIODevice::ReadWrite|QIODevice::Text))
    {
       QMessageBox::warning(this,"warning","文件操作错误",QMessageBox::Yes);
    }

    QTextStream in(&file);
    /**********加密开始***********/
    QString usernamemd5;
    QString pwdmd5;
    QByteArray bb;
    bb = QCryptographicHash::hash(password.toAscii(),QCryptographicHash::Md5);
    pwdmd5.append(bb.toHex());
    bb=QCryptographicHash::hash(username.toAscii(),QCryptographicHash::Md5);
    usernamemd5.append(bb.toHex());
    //***********加密结束****************/
    //QMessageBox::warning(this,"warning",usernamemd5,QMessageBox::Yes);

    in<<usernamemd5+"\n";
    in<<pwdmd5+"\n";
    file.close();//到文件里看结果吧~当然用上面的消息框也可以哦

    return true;
}
