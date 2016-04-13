#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSqlQuery"
#include "QDebug"
#include "QSqlRecord"
#include "QSqlError"

/******************************************************************************************
 *C2起动试验*
 "潜动测试_1Ib_1000秒	0.97	不合格"
 *****************************************************************************************/

bool MainWindow:: fill_CREEPING(int index)
{
    QString str1,str2,strLoadCurrent;
    int rowCount,columnCount;

    str1 = indexOfotherText(strArray[2][index],QString::fromUtf8("潜动测试_"));

    if(str1 =="0")
    {
        return true;
    }

    rowCount =ui->EM_CREEPING_TblWidget->rowCount();
    columnCount =ui->EM_CREEPING_TblWidget->columnCount();

    ui->EM_CREEPING_TblWidget->insertRow(rowCount);

    for(int j =0;j<columnCount;j++)//初始化
    {
        ui->EM_CREEPING_TblWidget->setItem(rowCount,j, new QTableWidgetItem(""));
    }

    ui->EM_CREEPING_TblWidget->setItem(rowCount,0, new QTableWidgetItem(my_MT_DETECT_TASK.DETECT_TASK_NO));//检定任务单
    ui->EM_CREEPING_TblWidget->setItem(rowCount,1, new QTableWidgetItem(my_MT_DETECT_TASK.EQUIP_CATEG));                 //设备类别
    ui->EM_CREEPING_TblWidget->setItem(rowCount,2, new QTableWidgetItem(my_MT_DETECT_TASK.SYS_NO));                 //系统编号
    ui->EM_CREEPING_TblWidget->setItem(rowCount,3, new QTableWidgetItem(my_CONC_CODE.DETECT_EQUIP_NO));          //检定线台编号
    ui->EM_CREEPING_TblWidget->setItem(rowCount,4, new QTableWidgetItem(""));                 //检定单元编号
    ui->EM_CREEPING_TblWidget->setItem(rowCount,5, new QTableWidgetItem(""));                 //表位编号
    ui->EM_CREEPING_TblWidget->setItem(rowCount,6, new QTableWidgetItem(my_MT_DETECT_TASK.BAR_CODE));                 //设备条形码
    ui->EM_CREEPING_TblWidget->setItem(rowCount,7, new QTableWidgetItem(currentTime()));     //检定时间
    ui->EM_CREEPING_TblWidget->setItem(rowCount,8, new QTableWidgetItem("1"));//序号
    ui->EM_CREEPING_TblWidget->setItem(rowCount,9, new QTableWidgetItem("1"));//检定点序号

    ui->EM_CREEPING_TblWidget->setItem(rowCount,10, new QTableWidgetItem("1"));//是否有效
    ui->EM_CREEPING_TblWidget->setItem(rowCount,11, new QTableWidgetItem(DYDM_index("115%Un")));//电压负载 115%

    str2 = indexOfTable(strArray[1][index],QString::fromUtf8("校验圈数"));

    if(str2=="0")
    {
        ui->EM_CREEPING_TblWidget->setItem(rowCount,12,new QTableWidgetItem("5"));                      //校验圈数
    }
    else
    {
         ui->EM_CREEPING_TblWidget->setItem(rowCount,12,new QTableWidgetItem(str2));                      //校验圈数
    }


    str2=str1.left(str1.indexOf("_"));
    str1.remove(0,str1.indexOf("_")+1);

    if(str2.indexOf("-")>0)
    {
        ui->EM_CREEPING_TblWidget->setItem(rowCount,13, new QTableWidgetItem("2"));//功率方向
    }
    else
    {
        ui->EM_CREEPING_TblWidget->setItem(rowCount,13, new QTableWidgetItem("0"));
    }


    ui->EM_CREEPING_TblWidget->setItem(rowCount,14, new QTableWidgetItem(FZDLDM_index(str2)));//电流负载
    strLoadCurrent=str2;

    str2=str1.left(str1.indexOf(QString::fromUtf8("秒")));
    str1.remove(0,str1.indexOf(QString::fromUtf8("秒"))+1);

    //str1.remove(0,str1.indexOf("_")+1);
    ui->EM_CREEPING_TblWidget->setItem(rowCount,15, new QTableWidgetItem(str2));//测试时间
    ui->EM_CREEPING_TblWidget->setItem(rowCount,16, new QTableWidgetItem(str2));//实际时间

    str1.remove(0,str1.indexOf("\t")+1);
    str1.remove(0,str1.indexOf("\t")+1);

    my_CONC_CODE.CREEPING=JBWCSYJLDM_index(str1);
    ui->EM_CREEPING_TblWidget->setItem(rowCount,17, new QTableWidgetItem(my_CONC_CODE.CREEPING));//合格？

    ui->EM_CREEPING_TblWidget->setItem(rowCount,18, new QTableWidgetItem(currentTime()));//wrietdate
    ui->EM_CREEPING_TblWidget->setItem(rowCount,19, new QTableWidgetItem("0"));

    ui->EM_CREEPING_TblWidget->setItem(rowCount,20, new QTableWidgetItem(currentTime()));//handle date




    return true;
}


bool MainWindow::update_CREEPING()
{
    bool IsSuccessful;
    QString strExec;
    int rowCount,columnCount;

    rowCount = ui->EM_CREEPING_TblWidget->rowCount();
    columnCount = ui->EM_CREEPING_TblWidget->columnCount();

    for(int j=0;j<rowCount;j++)
    {
        for(int i=0;i<columnCount;i++)
        {
            if(!ui->EM_CREEPING_TblWidget->item(j,i))
            ui->EM_CREEPING_TblWidget->setItem(j,i, new QTableWidgetItem(""));
        }
    }

    for(int i =0;i<rowCount;i++)//
    {
            strExec = QString("INSERT INTO MT_CREEPING_MET_CONC values(  '%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12','%13','%14','%15','%16','%17','%18','%19','%20','%21')")
                    .arg(ui->EM_CREEPING_TblWidget->item(i,0)->text())
                    .arg(ui->EM_CREEPING_TblWidget->item(i,1)->text())
                    .arg(ui->EM_CREEPING_TblWidget->item(i,2)->text())
                    .arg(ui->EM_CREEPING_TblWidget->item(i,3)->text())
                    .arg(ui->EM_CREEPING_TblWidget->item(i,4)->text())
                    .arg(ui->EM_CREEPING_TblWidget->item(i,5)->text())
                    .arg(ui->EM_CREEPING_TblWidget->item(i,6)->text())
                    .arg(ui->EM_CREEPING_TblWidget->item(i,7)->text())
                    .arg(ui->EM_CREEPING_TblWidget->item(i,8)->text())
                    .arg(ui->EM_CREEPING_TblWidget->item(i,9)->text())
                    .arg(ui->EM_CREEPING_TblWidget->item(i,10)->text())

                    .arg(ui->EM_CREEPING_TblWidget->item(i,11)->text())
                    .arg(ui->EM_CREEPING_TblWidget->item(i,12)->text())
                    .arg(ui->EM_CREEPING_TblWidget->item(i,13)->text())
                    .arg(ui->EM_CREEPING_TblWidget->item(i,14)->text())
                    .arg(ui->EM_CREEPING_TblWidget->item(i,15)->text())
                    .arg(ui->EM_CREEPING_TblWidget->item(i,16)->text())
                    .arg(ui->EM_CREEPING_TblWidget->item(i,17)->text())
                    .arg(ui->EM_CREEPING_TblWidget->item(i,18)->text())
                    .arg(ui->EM_CREEPING_TblWidget->item(i,19)->text())
                    .arg(ui->EM_CREEPING_TblWidget->item(i,20)->text());

        IsSuccessful =sqlQueryExec("MT_CREEPING_MET_CONC",ui->EM_CREEPING_TblWidget->item(i,6)->text()+" Num:"+QString::number(i), strExec,QString::fromUtf8("成功添加"));

        if(IsSuccessful==false)
        {
            showInformationBox(QString::fromUtf8("出错,请查看当前log.txt记录"));
            return false;
        }
    }
     return true;
}
