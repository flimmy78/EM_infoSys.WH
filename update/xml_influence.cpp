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
    projectsElement.appendChild( projectElement );

    for(int i =0;i<rowCount;i++)//
    {
        projectElement.setAttribute("sampleNo",ui->EM_INFLUENCE_QTY_TblWidget->item(i,6)->text());                      //条形码
        projectElement.setAttribute("projectName",QString::fromUtf8("潜动试验"));      //项目名字

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
        domElement.setAttribute("refTime","");
        domElement.setAttribute("strSampleID","");
    }
}



