#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QDomComment"
//影响量试验(多个选项只传总结论)
void MainWindow::addNode_INFLUENCE(QString nodeName, QDomDocument &domDoc)
{
    QDomElement  domElement,projectsElement,projectElement;
    QString strConclusion="1";
    int rowCount,columnCount;
    rowCount = ui->EM_INFLUENCE_QTY_TblWidget->rowCount();
    columnCount = ui->EM_INFLUENCE_QTY_TblWidget->columnCount();

    if(rowCount <= 0)
    {
        return ;
    }

    for(int j=0;j<rowCount;j++)
    {
        for(int i=0;i<columnCount;i++)
        {
            if(!ui->EM_INFLUENCE_QTY_TblWidget->item(j,i))
            {
                ui->EM_INFLUENCE_QTY_TblWidget->setItem(j,i, new QTableWidgetItem(""));
            }
        }

        if(ui->EM_INFLUENCE_QTY_TblWidget->item(0,11)->text().toInt(0)!=1)
        {
            strConclusion = "0";
        }
    }

    projectsElement = domDoc.documentElement().firstChild().firstChild().toElement();
    projectElement = domDoc.createElement(nodeName);
    projectElement.setAttribute("sampleNo",my_MT_DETECT_TASK.BAR_CODE);
    projectElement.setAttribute("projectName",QString::fromUtf8("影响量试验"));
//  projectElement.setAttribute("testResult",my_CONC_CODE.INFLUENCE);
    projectsElement.appendChild( projectElement );

    for(int i =0;i<1;i++)//
    {
        projectElement.setAttribute("testResult",strConclusion);
        domElement = domDoc.createElement("testData");
        projectElement.appendChild( domElement );

        domElement.setAttribute("testPhase","");
        domElement.setAttribute("testGroup","");
        domElement.setAttribute("freq","");
        domElement.setAttribute("PF","");
        domElement.setAttribute("volt","");

        domElement.setAttribute("curr","");
        domElement.setAttribute("conclusion",strConclusion);
        domElement.setAttribute("refTime",ui->EM_INFLUENCE_QTY_TblWidget->item(0,7)->text());
        domElement.setAttribute("strSampleID","");
    }
}



