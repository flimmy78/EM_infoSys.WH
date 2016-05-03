#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QDebug"

//删除在生成新文件
void MainWindow::on_EM_creat_XML_PsBtn_clicked()
{
    QString  filename = "e:/update.xml";
    QFile *file;
    QDomDocument domDoc;

   if(file->exists(filename))
   {
      file->remove(filename);
   }

    create_xml(filename,"samples");
    load_xmlFile(filename,domDoc);
    addNode_sample(domDoc);
   // addNode_INTUIT(filename);

#if 0
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
#endif
    showInformationBox(QString::fromUtf8("创建成功"));

}

void MainWindow::on_EM_save_XML_PsBtn_clicked()
{
    QStringList strList;
    QDomDocument domDoc;
    QString  strTemp;
    if(!load_xmlFile("e:/down1.xml",domDoc))
    {
        save_xmlFile("e:/sampleInfo.xml",domDoc);
        return;
    }

    //strList = get_errList(domDoc.toString());
    strTemp =domDoc.toString();
    //qDebug()<<strTemp;

#if 1
    QDomDocument domDoc2;
    domDoc2.setContent(strTemp);
    analyze_sampleInfo(domDoc2);
#endif

    //analyze_sampleInfo(domDoc);

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
    #if 0
    QString tagName ="sample";
    if(!search_domNode(tagName,domDoc))
    {
        showInformationBox("no sample");
        return;
    }


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
