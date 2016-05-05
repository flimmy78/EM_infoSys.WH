#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QDomComment"

void MainWindow::addNode_INTUIT(QString nodeName, QDomDocument &domDoc)
{
    QDomElement  domElement,projectsElement,projectElement;

    int rowCount,columnCount;
    rowCount = ui->EM_INTUIT_MET_TblWidget->rowCount();
    columnCount = ui->EM_INTUIT_MET_TblWidget->columnCount();
    if(rowCount <= 0)
    {
        return ;
    }
    for(int j=0;j<rowCount;j++)
    {
        for(int i=0;i<columnCount;i++)
        {
            if(!ui->EM_INTUIT_MET_TblWidget->item(j,i))
            ui->EM_INTUIT_MET_TblWidget->setItem(j,i, new QTableWidgetItem(""));
        }
    }

    projectsElement = domDoc.documentElement().firstChild().firstChild().toElement();
    projectElement = domDoc.createElement(nodeName);
    projectElement.setAttribute("sampleNo",my_MT_DETECT_TASK.BAR_CODE);
    projectElement.setAttribute("projectName",QString::fromUtf8("外观试验"));
   // projectElement.setAttribute("testResult",my_CONC_CODE.INTUIT);
    projectsElement.appendChild( projectElement );

    for(int i =0;i<rowCount;i++)//
    {
        projectElement.setAttribute("testResult",ui->EM_INTUIT_MET_TblWidget->item(i,12)->text());

        domElement = domDoc.createElement("testData");
        projectElement.appendChild( domElement );

        domElement.setAttribute("testPhase","");
        domElement.setAttribute("testGroup","");
        domElement.setAttribute("freq","");
        domElement.setAttribute("PF","");
        domElement.setAttribute("volt","");

        domElement.setAttribute("curr","");
        domElement.setAttribute("conclusion",ui->EM_INTUIT_MET_TblWidget->item(i,12)->text());
        domElement.setAttribute("refTime","");
        domElement.setAttribute("strSampleID","");
    }
}

