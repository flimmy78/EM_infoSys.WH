#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QSqlQuery"
#include "QDebug"
#include "QSqlRecord"
#include "QSqlError"

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


bool MainWindow::update_INFLUENCE_QTY()
{
    bool IsSuccessful;
    QString strExec;
    int rowCount,columnCount;

    rowCount = ui->EM_INFLUENCE_QTY_TblWidget->rowCount();
    columnCount = ui->EM_INFLUENCE_QTY_TblWidget->columnCount();

    for(int j=0;j<rowCount;j++)
    {
        for(int i=0;i<columnCount;i++)
        {
            if(!ui->EM_INFLUENCE_QTY_TblWidget->item(j,i))
            ui->EM_INFLUENCE_QTY_TblWidget->setItem(j,i, new QTableWidgetItem(""));
        }
    }

    for(int i =0;i<rowCount;i++)//
    {
            strExec = QString("INSERT INTO MT_INFLUENCE_QTY_MET_CONC values(  '%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11','%12','%13','%14','%15','%16')")
                    .arg(ui->EM_INFLUENCE_QTY_TblWidget->item(i,0)->text())
                    .arg(ui->EM_INFLUENCE_QTY_TblWidget->item(i,1)->text())
                    .arg(ui->EM_INFLUENCE_QTY_TblWidget->item(i,2)->text())
                    .arg(ui->EM_INFLUENCE_QTY_TblWidget->item(i,3)->text())
                    .arg(ui->EM_INFLUENCE_QTY_TblWidget->item(i,4)->text())
                    .arg(ui->EM_INFLUENCE_QTY_TblWidget->item(i,5)->text())
                    .arg(ui->EM_INFLUENCE_QTY_TblWidget->item(i,6)->text())
                    .arg(ui->EM_INFLUENCE_QTY_TblWidget->item(i,7)->text())
                    .arg(ui->EM_INFLUENCE_QTY_TblWidget->item(i,8)->text())
                    .arg(ui->EM_INFLUENCE_QTY_TblWidget->item(i,9)->text())
                    .arg(ui->EM_INFLUENCE_QTY_TblWidget->item(i,10)->text())

                    .arg(ui->EM_INFLUENCE_QTY_TblWidget->item(i,11)->text())
                    .arg(ui->EM_INFLUENCE_QTY_TblWidget->item(i,12)->text())
                    .arg(ui->EM_INFLUENCE_QTY_TblWidget->item(i,13)->text())
                    .arg(ui->EM_INFLUENCE_QTY_TblWidget->item(i,14)->text())
                    .arg(ui->EM_INFLUENCE_QTY_TblWidget->item(i,15)->text());

        IsSuccessful =sqlQueryExec("MT_INFLUENCE_QTY_MET_CONC",ui->EM_INFLUENCE_QTY_TblWidget->item(i,6)->text()+" Num:"+QString::number(i), strExec,QString::fromUtf8("成功添加"));

        if(IsSuccessful==false)
        {
            showInformationBox(QString::fromUtf8("出错,请查看当前log.txt记录"));
            return false;
        }
    }
     return true;
}


