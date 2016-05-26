#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QDomComment"

//外观
void MainWindow:: fill_INTUIT()
{
    int rowCount =ui->EM_INTUIT_MET_TblWidget->rowCount();
    ui->EM_INTUIT_MET_TblWidget->insertRow(rowCount);

    ui->EM_INTUIT_MET_TblWidget->setItem(rowCount,0, new QTableWidgetItem(my_MT_DETECT_TASK.DETECT_TASK_NO));         //检定任务单
    ui->EM_INTUIT_MET_TblWidget->setItem(rowCount,1, new QTableWidgetItem(my_MT_DETECT_TASK.EQUIP_CATEG));            //设备类别
    ui->EM_INTUIT_MET_TblWidget->setItem(rowCount,2, new QTableWidgetItem(my_MT_DETECT_TASK.SYS_NO));                 //系统编号
    ui->EM_INTUIT_MET_TblWidget->setItem(rowCount,3, new QTableWidgetItem(my_CONC_CODE.DETECT_EQUIP_NO));                                    //检定线台编号

    ui->EM_INTUIT_MET_TblWidget->setItem(rowCount,6, new QTableWidgetItem(my_MT_DETECT_TASK.BAR_CODE));               //设备条形码
    ui->EM_INTUIT_MET_TblWidget->setItem(rowCount,7, new QTableWidgetItem(my_CONC_CODE.TIME));                                 //检定时间

    my_CONC_CODE.INTUIT="1";
    ui->EM_INTUIT_MET_TblWidget->setItem(rowCount,12, new QTableWidgetItem(my_CONC_CODE.INTUIT));
    ui->EM_INTUIT_MET_TblWidget->setItem(rowCount,13, new QTableWidgetItem(currentTime()));
    ui->EM_INTUIT_MET_TblWidget->setItem(rowCount,15, new QTableWidgetItem(currentTime()));

}

void MainWindow::addNode_INTUIT(QString nodeName, QDomDocument &domDoc)
{
    QDomElement  domElement,projectsElement,projectElement;

    int rowCount,columnCount;
    rowCount = ui->EM_INTUIT_MET_TblWidget->rowCount();
    columnCount = ui->EM_INTUIT_MET_TblWidget->columnCount();

    if(!avoid_readVoidErr_TblWdiget(ui->EM_INTUIT_MET_TblWidget))
    {
        return ;
    }

    projectsElement = domDoc.documentElement().firstChild().firstChild().toElement();
    projectElement  = domDoc.createElement(nodeName);
    projectElement.setAttribute("projectNo","PJ0194");
    projectElement.setAttribute("projectName",QString::fromUtf8("外观试验"));
    projectElement.setAttribute("result",my_CONC_CODE.INTUIT);
    projectsElement.appendChild( projectElement );

    for(int i =0;i<rowCount;i++)
    {
        domElement = domDoc.createElement("testData");
        projectElement.appendChild( domElement );

        domElement.setAttribute("testNum","0");
        domElement.setAttribute("testPhase","");
        domElement.setAttribute("testGroup","");
        domElement.setAttribute("freq","");
        domElement.setAttribute("PF","");
        domElement.setAttribute("volt","");

        domElement.setAttribute("curr","");
        domElement.setAttribute("conclusion",ui->EM_INTUIT_MET_TblWidget->item(i,12)->text());
        domElement.setAttribute("refTime",ui->EM_INTUIT_MET_TblWidget->item(i,7)->text());
        domElement.setAttribute("strSampleID","");
    }
}

