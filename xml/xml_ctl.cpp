#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QDebug"

//生成XML文件
void MainWindow::on_EM_creat_xml_PsBtn_clicked()
{
    QString  fileName = "e:/update.xml";
    QFile *file;
    QDomDocument domDoc;

    if(file->exists(fileName))
    {
      file->remove(fileName);
    }

    if(!create_xml(fileName,"samples"))
    {
        return ;
    }

    if(!load_xmlFile(fileName,domDoc))
    {
        return ;
    }

    addNode_sample("sample",domDoc);
    addNode_INTUIT("project",domDoc);
    addNode_BASICERR("project",domDoc);
    addNode_MEASURE_REPEAT("project",domDoc);
    addNode_CREEPING("project",domDoc);
    addNode_STARTING("project",domDoc);
    addNode_INFLUENCE("project",domDoc);

    if(!save_xmlFile(fileName, domDoc))
    {
       return ;
    }

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

    //strList = get_errList(domDoc.toString());//错误信息
    strTemp =domDoc.toString();
    //qDebug()<<strTemp;

#if 1
    QDomDocument domDoc2;
    domDoc2.setContent(strTemp);
    analyze_sampleInfo(domDoc2);
#endif

    //analyze_sampleInfo(domDoc);

}


