#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QDomComment"

//通过任务单号获取基本误差信息
bool MainWindow::fill_MEASURE_REPEAT(QString ID)
{
    get_MEASURE_REPEAT_checkError("'"+ID+"'");
//    for(int i =0;i<20000;i++)
//    {
//        //延时
//    }
//    get_MEASURE_REPEAT_checkParameter("'"+ID+"'");
    return true;
}

//获取checkParameter相关内容
void MainWindow:: get_MEASURE_REPEAT_checkParameter(QString strID)
{
    QString strExec;
    int rowCount;

    strExec=QString("select * from checkParameter where id =%1").arg(strID);

    if(!SqlTempToQstring(strExec,11))
    {
        return ;
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

}

//测量重复性
void MainWindow::addNode_MEASURE_REPEAT(QString nodeName, QDomDocument &domDoc)
{
    QDomElement  domElement,projectsElement,projectElement,testDataElement;
    QString str1 ,str2;
    QDomText textNode;
    int index, rowCount,columnCount,simplingCount;
    rowCount = ui->EM_MEASURE_REPEAT_TblWidget->rowCount();
    columnCount = ui->EM_MEASURE_REPEAT_TblWidget->columnCount();

    if(!avoid_readVoidErr_TblWdiget(ui->EM_MEASURE_REPEAT_TblWidget))
    {
        return ;
    }

    projectsElement = domDoc.documentElement().firstChild().firstChild().toElement();
    projectElement = domDoc.createElement(nodeName);
    projectElement.setAttribute("projectNo","PJ0197");
    projectElement.setAttribute("projectName",QString::fromUtf8("测量重复性"));
    projectElement.setAttribute("result",my_CONC_CODE.MEASURE_REPEAT);
    projectsElement.appendChild( projectElement );

    for(int i =0;i<rowCount;i++)
    {
        testDataElement  = domDoc.createElement("testData");
        projectElement.appendChild(testDataElement);

        testDataElement.setAttribute("testNum","0");
        testDataElement.setAttribute("testPhase",ui->EM_MEASURE_REPEAT_TblWidget->item(i,12)->text());
        testDataElement.setAttribute("testGroup","");
        testDataElement.setAttribute("freq","");
        testDataElement.setAttribute("PF",ui->EM_MEASURE_REPEAT_TblWidget->item(i,14)->text());
        testDataElement.setAttribute("volt","");
        testDataElement.setAttribute("curr",ui->EM_MEASURE_REPEAT_TblWidget->item(i,13)->text());
        testDataElement.setAttribute("conclusion",ui->EM_MEASURE_REPEAT_TblWidget->item(i,20)->text());
        testDataElement.setAttribute("refTime",ui->EM_MEASURE_REPEAT_TblWidget->item(i,7)->text());
        testDataElement.setAttribute("strSampleID","");
        testDataElement.setAttribute("stdErr",ui->EM_MEASURE_REPEAT_TblWidget->item(i,9)->text());//标准偏差
        testDataElement.setAttribute("intErr",ui->EM_MEASURE_REPEAT_TblWidget->item(i,8)->text());//化整误差

        str1= ui->EM_MEASURE_REPEAT_TblWidget->item(i,10)->text(); //误差次数

        simplingCount = str1.count("|")+1;
        for(int j =0;j<simplingCount;j++)
        {
            index=str1.indexOf("|");

            if(index>0)
            {
               str2 = str1.left(index);
            }
            else
            {
               str2 = str1;
            }

            str1.remove(0,(index+1));
            textNode = domDoc.createTextNode(str2);
            domElement = domDoc.createElement("error");
            domElement.appendChild(textNode);
            testDataElement.appendChild( domElement );
        }

        for(int j =simplingCount;j<5;j++)//默认至少5个,小于则补充为'/'
        {
            QDomText textNodeTemp = domDoc.createTextNode("/");
            QDomElement DomElementTemp = domDoc.createElement("error");
            DomElementTemp.appendChild(textNodeTemp);
            testDataElement.appendChild( DomElementTemp );
        }
    }

}
