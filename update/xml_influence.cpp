#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QDomComment"
//影响量试验(多个选项只传总结论)

//影响量
bool MainWindow:: fill_INFLUENCE_QTY(int index)
{
    QString str1 ,str2,strItem,strCONC;

    bool T1=false,T2=false,T3=false,T4=false,T=true;
    int rowCount,columnCount,intParaIndex=0;

     //get_checkParameter_detectTaskNo();
    str1=strArray[2][index];
    //qDebug()<<str1;

 #if 1
    if(str1=="")
    {
        return true;
    }

    while(T)
    {
        T1=false;
        T2=false;
        T3=false;
        T4=false;

       strCONC="1";//默认合格
       if(str1.indexOf(QString::fromUtf8("电压影响"))!=-1)
       {
          str2 =indexOfInfluence(str1,QString::fromUtf8("电压影响"));
          strItem ="01";

          if(str2.indexOf(QString::fromUtf8("不"))!=-1)
          {
             strCONC="0";
          }

          str1.remove(str2);

          T1=true;
       }
       else if (str1.indexOf(QString::fromUtf8("频率影响"))!=-1)
       {
           str2 =indexOfInfluence(str1,QString::fromUtf8("频率影响"));
           strItem ="02";

           if(str2.indexOf(QString::fromUtf8("不"))!=-1)
           {
              strCONC="0";
           }

           str1.remove(str2);

           T2=true;
       }
       else if (str1.indexOf(QString::fromUtf8("逆相序影响"))!=-1)
       {
           str2 =indexOfInfluence(str1,QString::fromUtf8("逆相序影响"));
           strItem ="03";

           if(str2.indexOf(QString::fromUtf8("不"))!=-1)
           {
              strCONC="0";
           }

           str1.remove(str2);

           T3=true;

       }
       else if (str1.indexOf(QString::fromUtf8("电压不平衡影响"))!=-1)
       {
           str2 =indexOfInfluence(str1,QString::fromUtf8("电压不平衡影响"));
           strItem ="04";

           if(str2.indexOf(QString::fromUtf8("不"),QString::fromUtf8("电压不平衡影响").length())!=-1)//后面一个'不‘合格字符
           {
              strCONC="0";
           }

           str1.remove(str2);

           T4=true;
       }

       if(T1||T2||T3||T4)
       {
          T=true;

          #if 1
            rowCount =ui->EM_INFLUENCE_QTY_TblWidget->rowCount();
            columnCount =ui->EM_INFLUENCE_QTY_TblWidget->columnCount();

            ui->EM_INFLUENCE_QTY_TblWidget->insertRow(rowCount);

            for(int j =0;j<columnCount;j++)//初始化
            {
                ui->EM_INFLUENCE_QTY_TblWidget->setItem(rowCount,j, new QTableWidgetItem(""));
            }
            ui->EM_INFLUENCE_QTY_TblWidget->setItem(rowCount,0, new QTableWidgetItem(my_MT_DETECT_TASK.DETECT_TASK_NO));//检定任务单
            ui->EM_INFLUENCE_QTY_TblWidget->setItem(rowCount,1, new QTableWidgetItem(my_MT_DETECT_TASK.EQUIP_CATEG));                 //设备类别
            ui->EM_INFLUENCE_QTY_TblWidget->setItem(rowCount,2, new QTableWidgetItem(my_MT_DETECT_TASK.SYS_NO));                 //系统编号
            ui->EM_INFLUENCE_QTY_TblWidget->setItem(rowCount,3, new QTableWidgetItem( my_CONC_CODE.DETECT_EQUIP_NO));          //检定线台编号
            ui->EM_INFLUENCE_QTY_TblWidget->setItem(rowCount,4, new QTableWidgetItem(""));                 //检定单元编号
            ui->EM_INFLUENCE_QTY_TblWidget->setItem(rowCount,5, new QTableWidgetItem(""));                 //表位编号
            ui->EM_INFLUENCE_QTY_TblWidget->setItem(rowCount,6, new QTableWidgetItem(my_MT_DETECT_TASK.BAR_CODE));                 //设备条形码
            ui->EM_INFLUENCE_QTY_TblWidget->setItem(rowCount,7, new QTableWidgetItem(strArray[3][0]));     //检定时间
            ui->EM_INFLUENCE_QTY_TblWidget->setItem(rowCount,8, new QTableWidgetItem("1"));//序号
            ui->EM_INFLUENCE_QTY_TblWidget->setItem(rowCount,9, new QTableWidgetItem(QString::number(intParaIndex++)));//检定点序号
            ui->EM_INFLUENCE_QTY_TblWidget->setItem(rowCount,10, new QTableWidgetItem("1"));//是否有效
            my_CONC_CODE.INFLUENCE=strCONC;
            ui->EM_INFLUENCE_QTY_TblWidget->setItem(rowCount,11, new QTableWidgetItem(my_CONC_CODE.INFLUENCE));//合格？
            ui->EM_INFLUENCE_QTY_TblWidget->setItem(rowCount,12, new QTableWidgetItem(strItem));//影响量试验项目
            ui->EM_INFLUENCE_QTY_TblWidget->setItem(rowCount,13, new QTableWidgetItem(currentTime()));//wrietdate
            ui->EM_INFLUENCE_QTY_TblWidget->setItem(rowCount,14, new QTableWidgetItem("0"));
            ui->EM_INFLUENCE_QTY_TblWidget->setItem(rowCount,15, new QTableWidgetItem(currentTime()));//handle date
           #endif
       }
       else
       {
          T=false;
       }
   }
#endif
    return true;
}


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



