#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QDomComment"
//潜动试验
void MainWindow::addNode_CREEPING(QString nodeName, QDomDocument &domDoc)
{
    QDomElement  domElement,projectsElement,projectElement;

    int rowCount,columnCount;
    rowCount = ui->EM_CREEPING_TblWidget->rowCount();
    columnCount = ui->EM_CREEPING_TblWidget->columnCount();

    if(rowCount <= 0)
    {
        return ;
    }

    for(int j=0;j<rowCount;j++)
    {
        for(int i=0;i<columnCount;i++)
        {
            if(!ui->EM_CREEPING_TblWidget->item(j,i))
            ui->EM_CREEPING_TblWidget->setItem(j,i, new QTableWidgetItem(""));
        }
    }

    projectsElement = domDoc.documentElement().firstChild().firstChild().toElement();
    projectElement = domDoc.createElement(nodeName);
    projectElement.setAttribute("sampleNo",my_MT_DETECT_TASK.BAR_CODE);
    projectElement.setAttribute("projectName",QString::fromUtf8("潜动试验"));
    //projectElement.setAttribute("testResult",my_CONC_CODE.CREEPING);
    projectsElement.appendChild( projectElement );

    for(int i =0;i<rowCount;i++)
    {
        projectElement.setAttribute("testResult",ui->EM_CREEPING_TblWidget->item(i,17)->text());
        domElement = domDoc.createElement("testData");
        projectElement.appendChild( domElement );

        domElement.setAttribute("testPhase","");
        domElement.setAttribute("testGroup","");
        domElement.setAttribute("freq","");
        domElement.setAttribute("PF","");
        domElement.setAttribute("volt","");

        domElement.setAttribute("curr","");
        domElement.setAttribute("conclusion",ui->EM_CREEPING_TblWidget->item(i,17)->text());
        domElement.setAttribute("refTime","");
        domElement.setAttribute("strSampleID","");
    }
}


