#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QDebug"

void MainWindow::on_EM_creat_XML_PsBtn_clicked()
{

    QFile *file;
    QString  filename = "e:/config.xml";

    if(file->exists(filename))
    {
        read_xml(filename);
        qDebug()<<"exists";
    }
    else
    {
        createXmlFile(filename,"ipconfig");
        qDebug()<<"No exists";
        //showInformationBox(QString strTemp)
    }


    QMap<QString,QString> nodeMap1,nodeMap2 ;
    nodeMap1.insert("aa", "11"); //向map里添加一对“键-值”
    nodeMap1.insert("bb", "22"); //向map里添加一对“键-值”   //tagname  不能为纯数字

    if(!appendNode(filename,"remote",nodeMap1))
    {
        showInformationBox("appendNode error");
    }

    nodeMap2.insert("cc", "11");
    nodeMap2.insert("dd", "22");

    if(! prependNode(filename,"remote",nodeMap2))
    {
        showInformationBox("prependNode error");
    }

    showInformationBox(QString::fromUtf8("创建成功"));
}


void MainWindow::on_EM_insert_XML_PsBtn_clicked()
{
    QFile *file;
    QString  filename = "e:/config.xml";

    if(file->exists(filename))
    {
        read_xml(filename);
    }
    else
    {
        showInformationBox("No exists");
        return ;
    }

    QMap<QString,QString> nodeMap1 ;
    nodeMap1.insert("aa1", "11");               //向map里添加一对“键-值”
    nodeMap1.insert("bb1", "22");               //向map里添加一对“键-值”   //tagname  不能为纯数字

    if(!appendNode(filename,"remote",nodeMap1))
    {
        showInformationBox("appendNode error");
    }
    showInformationBox(QString::fromUtf8("添加成功"));
}

void MainWindow::on_EM_read_XML_PsBtn_clicked()
{
    QString tagName ="sample";
    if(!search_domNode(tagName))
    {
        showInformationBox("no sample");
        return;
    }

#if 1
     QStringList tagNameList = g_map.keys();

     foreach (QString str, tagNameList)
     {
         qDebug()  << str;
         qDebug() << g_map.value(str);
     }
#endif
}


void MainWindow::on_EM_delete_XML_PsBtn_clicked()
{
    QString  filename = "e:/config.xml";
    if(QFile::remove(filename))//刪除文件
    {
        showInformationBox(QString::fromUtf8("删除成功"));
    }
}
