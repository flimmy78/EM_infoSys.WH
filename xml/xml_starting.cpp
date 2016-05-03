#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QDomComment"

//启动试验
void MainWindow::addNode_STARTING(QString nodeName, QDomDocument &domDoc)
{
    QDomElement  domElement,sampleElement,projectsElement,projectElement;
    sampleElement = domDoc.documentElement().firstChild().toElement();
    domElement = domDoc.createElement("projects");
    sampleElement.appendChild( domElement );

    projectsElement =sampleElement.firstChild().toElement();
    domElement = domDoc.createElement("project");
    projectsElement.appendChild( domElement );

   // qDebug()<<projectsElement.firstChild().toElement().tagName();
    domElement.setAttribute("sampleNo","JLXC-160425-1");                      //条形码
    domElement.setAttribute("projectName",QString::fromUtf8("起动试验"));      //项目名字
    domElement.setAttribute("testResult","1");

    projectElement =projectsElement.firstChild().toElement();
    domElement = domDoc.createElement("testData");
    projectElement.appendChild( domElement );//检定结果

    domElement.setAttribute("testPhase","0");
    domElement.setAttribute("testGroup","L");
    domElement.setAttribute("freq","50Hz");
    domElement.setAttribute("PF","1.0");
    domElement.setAttribute("volt","1Un");

    domElement.setAttribute("curr","0.004Ib");
    domElement.setAttribute("conclusion","0");
    domElement.setAttribute("refTime",QString::fromUtf8("10分13秒"));
    domElement.setAttribute("strSampleID","160311025630");

}
