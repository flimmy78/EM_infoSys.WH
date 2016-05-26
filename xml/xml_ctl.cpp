#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QDebug"

bool MainWindow:: MU_creat_xml()
{
    QString  fileName =strUpdatePath;
    QFile *file;
    QDomDocument domDoc;

    if(file->exists(fileName))
    {
      file->remove(fileName);
    }

    QDomProcessingInstruction instruction = domDoc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"GB2312\"");
    domDoc.appendChild(instruction);
    QDomElement root = domDoc.createElement("samples"); //根节点
    domDoc.appendChild(root);

    addNode_sample("sample",domDoc);
    addNode_INTUIT("project",domDoc);
    addNode_BASICERR("project",domDoc);
    addNode_MEASURE_REPEAT("project",domDoc);
    addNode_CREEPING("project",domDoc);
    addNode_STARTING("project",domDoc);
    addNode_INFLUENCE("project",domDoc);

    g_domDoc=domDoc;

    if(!save_xmlFile(fileName, domDoc))
    {
       return  false;
    }

     return  true;
    //showInformationBox(QString::fromUtf8("创建成功"));

}


void MainWindow::on_EM_save_XML_PsBtn_clicked()
{
    QStringList strList;
    QDomDocument domDoc;
    QString  strTemp;
    if(!load_xmlFile("d:/down1.xml",domDoc))
    {
        save_xmlFile("d:/sampleInfo.xml",domDoc);
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


