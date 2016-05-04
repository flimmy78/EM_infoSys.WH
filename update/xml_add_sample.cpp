#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSqlQuery"
#include "QDebug"
#include "QSqlRecord"
#include "QSqlError"

//总结论
bool MainWindow::addNode_sample(QString nodeName, QDomDocument &domDoc)
{
    QDomElement  domElement,sampleElement,projectsElement;

    int rowCount,columnCount;
    rowCount = ui->EM_RSLT_TabWidget->rowCount();
    columnCount = ui->EM_RSLT_TabWidget->columnCount();

    if(rowCount <= 0)
    {
        return false ;
    }

    for(int j=0;j<rowCount;j++)
    {
        for(int i=0;i<columnCount;i++)
        {
            if(!ui->EM_RSLT_TabWidget->item(j,i))
            ui->EM_RSLT_TabWidget->setItem(j,i, new QTableWidgetItem(""));
        }
    }
    sampleElement = domDoc.createElement( nodeName );
    domDoc.documentElement().appendChild( sampleElement );

    projectsElement = domDoc.documentElement().firstChild().toElement();
    domElement = domDoc.createElement("projects");
    projectsElement.appendChild( domElement );

    for(int i =0;i<rowCount;i++)//
    {
    #if 1
        sampleElement.setAttribute("sampleNo",ui->EM_RSLT_TabWidget->item(i,0)->text());
        sampleElement.setAttribute("checkResult",ui->EM_RSLT_TabWidget->item(i,1)->text());
        sampleElement.setAttribute("checkDate",ui->EM_RSLT_TabWidget->item(i,2)->text());
        sampleElement.setAttribute("testMan",ui->EM_RSLT_TabWidget->item(i,3)->text());
        sampleElement.setAttribute("checkMan",ui->EM_RSLT_TabWidget->item(i,4)->text());

        sampleElement.setAttribute("checkTemp",ui->EM_RSLT_TabWidget->item(i,5)->text());
        sampleElement.setAttribute("checkWet",ui->EM_RSLT_TabWidget->item(i,6)->text());
        sampleElement.setAttribute("checkVolt",ui->EM_RSLT_TabWidget->item(i,7)->text());
        sampleElement.setAttribute("checkCurr",ui->EM_RSLT_TabWidget->item(i,8)->text());
        sampleElement.setAttribute("checkRate",ui->EM_RSLT_TabWidget->item(i,9)->text());

        sampleElement.setAttribute("checkClass",ui->EM_RSLT_TabWidget->item(i,10)->text());
        sampleElement.setAttribute("factory",ui->EM_RSLT_TabWidget->item(i,11)->text());
        sampleElement.setAttribute("metConst",ui->EM_RSLT_TabWidget->item(i,12)->text());
        sampleElement.setAttribute("metVarConst",ui->EM_RSLT_TabWidget->item(i,13)->text());
        sampleElement.setAttribute("metClass",ui->EM_RSLT_TabWidget->item(i,14)->text());

        sampleElement.setAttribute("metVarClass",ui->EM_RSLT_TabWidget->item(i,15)->text());
        sampleElement.setAttribute("metPhase",ui->EM_RSLT_TabWidget->item(i,16)->text());
        sampleElement.setAttribute("redSeal",ui->EM_RSLT_TabWidget->item(i,17)->text());
        sampleElement.setAttribute("pf",ui->EM_RSLT_TabWidget->item(i,18)->text());
        sampleElement.setAttribute("firstCurr",ui->EM_RSLT_TabWidget->item(i,19)->text());

        sampleElement.setAttribute("secondCurr",ui->EM_RSLT_TabWidget->item(i,20)->text());
        sampleElement.setAttribute("ratedLoad",ui->EM_RSLT_TabWidget->item(i,21)->text());
        sampleElement.setAttribute("securityFactor",ui->EM_RSLT_TabWidget->item(i,22)->text());
#endif
    }
    return true;
}

