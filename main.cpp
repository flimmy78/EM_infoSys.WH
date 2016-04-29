#include <QtGui/QApplication>
#include "mainwindow.h"
#include "QTextCodec"
#include "QDebug"
#include "QSqlDatabase"


//对方XML默认为内容UTF-8，其他的可能乱码，虽然返回成功，但是在数据库为乱码
int main(int argc, char *argv[])
{

#if 1
    QApplication a(argc, argv);
    MainWindow w;
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));   //linux 用GBK  GB2312
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));       //UTF-8 //GBK //GB2312
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    w.show();
    
    return a.exec();
#endif

}
