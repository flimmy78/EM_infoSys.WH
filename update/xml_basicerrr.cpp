#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QDomComment"

//基本误差
void MainWindow::addNode_BASICERR(QString nodeName, QDomDocument &domDoc)
{
    QDomElement  domElement,sampleElement,projectsElement,projectElement,errorElement;
    QDomText domText;
    sampleElement = domDoc.documentElement().firstChild().toElement();
    domElement = domDoc.createElement("projects");
    sampleElement.appendChild( domElement );

    projectsElement =sampleElement.firstChild().toElement();
    domElement = domDoc.createElement("project");
    projectsElement.appendChild( domElement );

   // qDebug()<<projectsElement.firstChild().toElement().tagName();
    domElement.setAttribute("sampleNo","JLXC-160425-1");                      //条形码
    domElement.setAttribute("projectName",QString::fromUtf8("基本误差"));      //项目名字
    domElement.setAttribute("testResult","1");

    projectElement =projectsElement.firstChild().toElement();
    domElement = domDoc.createElement("testData");
    projectElement.appendChild( domElement );//检定结果

    domElement.setAttribute("testPhase","0");
    domElement.setAttribute("testGroup","L");
    domElement.setAttribute("freq","50Hz");
    domElement.setAttribute("PF","1.0");
    domElement.setAttribute("volt","1Un");

    domElement.setAttribute("curr","-0.091");
    domElement.setAttribute("intErr","-0.091");
    domElement.setAttribute("intErr","-0.0");
    domElement.setAttribute("strSampleID","160311025630");
    domElement.setAttribute("conclusion","0");

    for(int i =0;i<2;i++)
    {
        errorElement =projectElement.firstChild().toElement();
        domElement = domDoc.createElement("error");
        domText = domDoc.createTextNode("-0.085");
        domElement.appendChild( domText );
        //domElement.toElement().setNodeValue("sdfsdf");
        errorElement.appendChild( domElement );
    }

}

