#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QDomComment"

//通过任务单号获取基本误差信息
bool MainWindow::fill_MEASURE_REPEAT(QString ID)
{
    get_MEASURE_REPEAT_checkError("'"+ID+"'");
    for(int i =0;i<20000;i++)
    {
        //延时
    }
    get_MEASURE_REPEAT_checkParameter("'"+ID+"'");
    return true;
}

//获取checkParameter相关内容
int MainWindow:: get_MEASURE_REPEAT_checkParameter(QString strID)
{
    QString strExec;
    int rowCount;

    strExec=QString("select * from checkParameter where id =%1").arg(strID);

    if(!SqlTempToQstring(strExec,11))
    {
        return 0;
    }

    rowCount =ui->EM_MEASURE_REPEAT_TblWidget->rowCount();
    for(int i=0;i<rowCount;i++)
    {
        if(strArray[15][0]==ui->EM_MEASURE_REPEAT_TblWidget->item(i,24)->text())//strArray[15][0]为本地localsql key标识符号
        {
            ui->EM_MEASURE_REPEAT_TblWidget->setItem(i,7,new QTableWidgetItem(strArray[15][2]));                //检定日期
            ui->EM_MEASURE_REPEAT_TblWidget->setItem(i,21,new QTableWidgetItem(DYDM_index("100%Un")));          //电压百分百
        }
    }

    return 0;
}

//测量重复性
void MainWindow::addNode_MEASURE_REPEAT(QString nodeName, QDomDocument &domDoc)
{
    QDomElement  domElement,projectsElement,projectElement;

    int rowCount,columnCount;
    rowCount = ui->EM_MEASURE_REPEAT_TblWidget->rowCount();
    columnCount = ui->EM_MEASURE_REPEAT_TblWidget->columnCount();

    if(rowCount <= 0)
    {
        return ;
    }

    for(int j=0;j<rowCount;j++)
    {
        for(int i=0;i<columnCount;i++)
        {
            if(!ui->EM_MEASURE_REPEAT_TblWidget->item(j,i))
            ui->EM_MEASURE_REPEAT_TblWidget->setItem(j,i, new QTableWidgetItem(""));
        }
    }

    projectsElement = domDoc.documentElement().firstChild().firstChild().toElement();
    projectElement = domDoc.createElement(nodeName);
    projectElement.setAttribute("sampleNo",my_MT_DETECT_TASK.BAR_CODE);
    projectElement.setAttribute("projectName",QString::fromUtf8("测量重复性"));
//    projectElement.setAttribute("testResult",my_CONC_CODE.MEASURE_REPEAT);
    projectsElement.appendChild( projectElement );

    for(int i =0;i<rowCount;i++)//
    {
        projectElement.setAttribute("testResult",ui->EM_MEASURE_REPEAT_TblWidget->item(i,17)->text());

        domElement = domDoc.createElement("testData");
        projectElement.appendChild( domElement );

        domElement.setAttribute("testPhase","");
        domElement.setAttribute("testGroup","");
        domElement.setAttribute("freq","");
        domElement.setAttribute("PF","");
        domElement.setAttribute("volt","");

        domElement.setAttribute("curr","");
        domElement.setAttribute("conclusion",ui->EM_MEASURE_REPEAT_TblWidget->item(i,17)->text());
        domElement.setAttribute("refTime",ui->EM_MEASURE_REPEAT_TblWidget->item(i,7)->text());
        domElement.setAttribute("strSampleID","");
    }

}
