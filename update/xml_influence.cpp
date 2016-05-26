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
    int rowCount,columnCount;

     //get_checkParameter_detectTaskNo();
    str1=strArray[2][index];
    //qDebug()<<str1;

 #if 1
    if(str1 == "")
    {
        return false;
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

          str1.remove(0,str2.length()+2);//2为\n\r两个字节

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

          str1.remove(0,str2.length()+2);//2为\n\r两个字节

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

           str1.remove(0,str2.length()+2);//2为\n\r两个字节

           T3=true;

       }else if (str1.startsWith(QString::fromUtf8("电压不平衡影响")))
       {
          // qDebug()<<str1;
           str2 =indexOfInfluence(str1,QString::fromUtf8("电压不平衡影响"));
           strItem ="04";
           //qDebug()<<str2;

           if(str2.indexOf(QString::fromUtf8("不"),QString::fromUtf8("电压不平衡影响").length())!=-1)//后面一个'不‘合格字符
           {
              strCONC="0";
           }

           str1.remove(0,str2.length()+2);//2为\n\r两个字节
           //qDebug()<<str1;

           T4=true;
       }
      // qDebug()<<str1;
       if(T1||T2||T3||T4)//存在以上选项的时候才增加
       {
          T=true;

          #if 1
            rowCount =ui->EM_INFLUENCE_QTY_TblWidget->rowCount();
            columnCount =ui->EM_INFLUENCE_QTY_TblWidget->columnCount();
            ui->EM_INFLUENCE_QTY_TblWidget->insertRow(rowCount);

            ui->EM_INFLUENCE_QTY_TblWidget->setItem(rowCount,0, new QTableWidgetItem(my_MT_DETECT_TASK.DETECT_TASK_NO));//检定任务单
            ui->EM_INFLUENCE_QTY_TblWidget->setItem(rowCount,1, new QTableWidgetItem(my_MT_DETECT_TASK.EQUIP_CATEG));                 //设备类别
            ui->EM_INFLUENCE_QTY_TblWidget->setItem(rowCount,2, new QTableWidgetItem(my_MT_DETECT_TASK.SYS_NO));                 //系统编号
            ui->EM_INFLUENCE_QTY_TblWidget->setItem(rowCount,3, new QTableWidgetItem( my_CONC_CODE.DETECT_EQUIP_NO));          //检定线台编号
            ui->EM_INFLUENCE_QTY_TblWidget->setItem(rowCount,6, new QTableWidgetItem(my_MT_DETECT_TASK.BAR_CODE));                 //设备条形码
            ui->EM_INFLUENCE_QTY_TblWidget->setItem(rowCount,7, new QTableWidgetItem(my_CONC_CODE.TIME));     //检定时间

            my_CONC_CODE.INFLUENCE=strCONC;
            ui->EM_INFLUENCE_QTY_TblWidget->setItem(rowCount,11, new QTableWidgetItem(my_CONC_CODE.INFLUENCE));//合格？
            ui->EM_INFLUENCE_QTY_TblWidget->setItem(rowCount,12, new QTableWidgetItem(strItem));//影响量试验项目
            ui->EM_INFLUENCE_QTY_TblWidget->setItem(rowCount,13, new QTableWidgetItem(currentTime()));//wrietdate
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

    if(!avoid_readVoidErr_TblWdiget(ui->EM_INFLUENCE_QTY_TblWidget))
    {
        return ;
    }

    projectsElement = domDoc.documentElement().firstChild().firstChild().toElement();
    projectElement = domDoc.createElement(nodeName);
    projectElement.setAttribute("projectNo","PJ0198");
    projectElement.setAttribute("projectName",QString::fromUtf8("影响量试验"));
    projectElement.setAttribute("result",my_CONC_CODE.INFLUENCE);
    projectsElement.appendChild( projectElement );

    for(int i =0;i<rowCount;i++)
    {
        domElement = domDoc.createElement("testData");
        projectElement.appendChild( domElement );

        domElement.setAttribute("testPhase","");
        domElement.setAttribute("testGroup","");
        domElement.setAttribute("freq","");
        domElement.setAttribute("PF","");
        domElement.setAttribute("volt","");

        domElement.setAttribute("testNum","0");
        domElement.setAttribute("curr","");
        domElement.setAttribute("conclusion",strConclusion);
        domElement.setAttribute("refTime",ui->EM_INFLUENCE_QTY_TblWidget->item(0,7)->text());
        domElement.setAttribute("strSampleID","");
    }
}



