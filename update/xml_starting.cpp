#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QDomComment"

//启动试验
void MainWindow::addNode_STARTING(QString nodeName, QDomDocument &domDoc)
{
    QDomElement  domElement,projectsElement,projectElement;

    int rowCount,columnCount;
    rowCount = ui->EM_STARTING_TblWidget->rowCount();
    columnCount = ui->EM_STARTING_TblWidget->columnCount();

    if(rowCount <= 0)
    {
        return ;
    }

    for(int j=0;j<rowCount;j++)
    {
        for(int i=0;i<columnCount;i++)
        {
            if(!ui->EM_STARTING_TblWidget->item(j,i))
            ui->EM_STARTING_TblWidget->setItem(j,i, new QTableWidgetItem(""));
        }
    }

    projectsElement = domDoc.documentElement().firstChild().firstChild().toElement();
    projectElement = domDoc.createElement(nodeName);
    projectsElement.appendChild( projectElement );

    for(int i =0;i<rowCount;i++)//
    {
        projectElement.setAttribute("sampleNo",ui->EM_STARTING_TblWidget->item(i,6)->text());                      //条形码
        projectElement.setAttribute("projectName",QString::fromUtf8("启动试验"));      //项目名字

        projectElement.setAttribute("testResult",ui->EM_STARTING_TblWidget->item(i,17)->text());

        domElement = domDoc.createElement("testData");
        projectElement.appendChild( domElement );

        domElement.setAttribute("testPhase","");
        domElement.setAttribute("testGroup","");
        domElement.setAttribute("freq","");
        domElement.setAttribute("PF","");
        domElement.setAttribute("volt","");

        domElement.setAttribute("curr","");
        domElement.setAttribute("conclusion",ui->EM_STARTING_TblWidget->item(i,17)->text());
        domElement.setAttribute("refTime","");
        domElement.setAttribute("strSampleID","");
    }

}

