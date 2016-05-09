#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QDomComment"

/******************************************************************************************
 *C4起动试验*
 "启动测试_1Ib_1000秒	0.97	合格"
 *****************************************************************************************/

bool MainWindow:: fill_STARTING(int index)
{
    QString str1,str2,strLoadCurrent;
    int rowCount,columnCount;

    str1 = indexOfotherText(strArray[2][index],QString::fromUtf8("启动测试_"));

    if(str1=="0")
    {
        return  true;
    }

    rowCount =ui->EM_STARTING_TblWidget->rowCount();
    columnCount =ui->EM_STARTING_TblWidget->columnCount();

    ui->EM_STARTING_TblWidget->insertRow(rowCount);

    for(int j =0;j<columnCount;j++)//初始化
    {
        ui->EM_STARTING_TblWidget->setItem(rowCount,j, new QTableWidgetItem(""));
    }

    ui->EM_STARTING_TblWidget->setItem(rowCount,0, new QTableWidgetItem(my_MT_DETECT_TASK.DETECT_TASK_NO));//检定任务单
    ui->EM_STARTING_TblWidget->setItem(rowCount,1, new QTableWidgetItem(my_MT_DETECT_TASK.EQUIP_CATEG));                 //设备类别
    ui->EM_STARTING_TblWidget->setItem(rowCount,2, new QTableWidgetItem(my_MT_DETECT_TASK.SYS_NO));                 //系统编号
    ui->EM_STARTING_TblWidget->setItem(rowCount,3, new QTableWidgetItem(my_CONC_CODE.DETECT_EQUIP_NO));          //检定线台编号
    ui->EM_STARTING_TblWidget->setItem(rowCount,4, new QTableWidgetItem(""));                 //检定单元编号
    ui->EM_STARTING_TblWidget->setItem(rowCount,5, new QTableWidgetItem(""));                 //表位编号
    ui->EM_STARTING_TblWidget->setItem(rowCount,6, new QTableWidgetItem(my_MT_DETECT_TASK.BAR_CODE));                 //设备条形码
    ui->EM_STARTING_TblWidget->setItem(rowCount,7, new QTableWidgetItem(strArray[3][0]));     //检定时间
    ui->EM_STARTING_TblWidget->setItem(rowCount,8, new QTableWidgetItem("1"));//序号
    ui->EM_STARTING_TblWidget->setItem(rowCount,9, new QTableWidgetItem("1"));//检定点序号

    ui->EM_STARTING_TblWidget->setItem(rowCount,10, new QTableWidgetItem("1"));//是否有效
    ui->EM_STARTING_TblWidget->setItem(rowCount,11, new QTableWidgetItem("100%Un"));//电压负载 100%

    str2 = indexOfTable(strArray[1][index],QString::fromUtf8("校验圈数"));

    if(str2=="0")
    {
        ui->EM_STARTING_TblWidget->setItem(rowCount,12,new QTableWidgetItem("5"));                      //校验圈数
    }
    else
    {
         ui->EM_STARTING_TblWidget->setItem(rowCount,12,new QTableWidgetItem(str2));                      //校验圈数
    }



    str2=str1.left(str1.indexOf("_"));
    str1.remove(0,str1.indexOf("_")+1);

    if(str2.indexOf("-")>0)
    {
        ui->EM_STARTING_TblWidget->setItem(rowCount,13, new QTableWidgetItem("2"));//功率方向 默认有功正向暂时只要一个
    }
    else
    {
        ui->EM_STARTING_TblWidget->setItem(rowCount,13, new QTableWidgetItem("0"));
    }


    ui->EM_STARTING_TblWidget->setItem(rowCount,14, new QTableWidgetItem(str2));//电流负载
    strLoadCurrent=str2;

    str2=str1.left(str1.indexOf(QString::fromUtf8("秒")));
    str1.remove(0,str1.indexOf(QString::fromUtf8("秒"))+1);

    //str1.remove(0,str1.indexOf("_")+1);
    ui->EM_STARTING_TblWidget->setItem(rowCount,15, new QTableWidgetItem(str2));//测试时间
    ui->EM_STARTING_TblWidget->setItem(rowCount,16, new QTableWidgetItem(str2));//实际时间

    str1.remove(0,str1.indexOf("\t")+1);
    str1.remove(0,str1.indexOf("\t")+1);

    my_CONC_CODE.STARTING=JBWCSYJLDM_index(str1);
    ui->EM_STARTING_TblWidget->setItem(rowCount,17, new QTableWidgetItem(my_CONC_CODE.STARTING));//合格？
    ui->EM_STARTING_TblWidget->setItem(rowCount,18, new QTableWidgetItem(currentTime()));//wrietdate
    ui->EM_STARTING_TblWidget->setItem(rowCount,19, new QTableWidgetItem("0"));

    ui->EM_STARTING_TblWidget->setItem(rowCount,20, new QTableWidgetItem(currentTime()));//handle date

    str1 = indexOfTable(strArray[1][index],QString::fromUtf8("电流量程"));


    //str1.remove("A");
   // str3 = strLoadCurrent.remove("Ib");
    //qDebug()<<strLoadCurrent;
    //int intTemp =str1.remove("A").toInt(0,10)*1000*str3.toInt();
    ui->EM_STARTING_TblWidget->setItem(rowCount,21, new QTableWidgetItem(strLoadCurrent));//启动电流

    return true;
}

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
    projectElement.setAttribute("sampleNo",my_MT_DETECT_TASK.BAR_CODE);
    projectElement.setAttribute("projectName",QString::fromUtf8("启动试验"));
    //projectElement.setAttribute("testResult",my_CONC_CODE.STARTING);
    projectsElement.appendChild( projectElement );

    for(int i =0;i<rowCount;i++)//
    {
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
        domElement.setAttribute("refTime",ui->EM_STARTING_TblWidget->item(i,7)->text());
        domElement.setAttribute("strSampleID","");
    }

}

