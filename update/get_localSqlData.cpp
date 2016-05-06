#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "stdio.h"
#include "QDebug"
#include "QTime"

int callback(void *datas,int ncols,char **values,char **headers);
char sqlTemp[4000][100][3000];//1.数目；2.内容个数3.长度
int  sqlite_RowCnt;  //一个表的行数
int  sqlite_tableCal;//表的数目

//将数据库数据读取出来到表格
void MainWindow::getDataFromLocalSqlToTblWidget(QString strExec,QTableWidget * tblWidget,int columnCount)
{
    int intResult,rowCount;
    intResult= sql_exec(strExec.toLatin1().data());
    if(intResult!=SQLITE_OK)
    {
       showInformationBox(strExec+QString::fromUtf8(":error"));
       return;
    }
    rowCount = tblWidget->rowCount();

    for(int i=0;i<sqlite_tableCal;i++)
    {
        tblWidget->insertRow(i);
        for(int j=0;j<columnCount;j++)
        {
           tblWidget->setItem(i,j, new QTableWidgetItem(QString::fromLocal8Bit(sqlTemp[i][j])));
        }
    }
}
//判断本地数据库是否存在要查的条形码
bool MainWindow::isLocalBarCodeExist(QString strExec,QString strBarCode)
{
    int intResult;
    intResult= sql_exec(strExec.toLatin1().data());
    if(intResult!=SQLITE_OK)
    {
       showInformationBox(strExec+QString::fromUtf8(":error"));
       return false;
    }

    for(int i=0;i<sqlite_tableCal;i++)//查找到了才返回正确
    {
        if(strBarCode ==QString(sqlTemp[i][0])) 
         return true;
    }

return false;
}

/*
id VARCHAR,				    // id，每个表同一次检定为同一个id
manufactoryNumber VARCHAR,	//出厂编号
checkDate VARCHAR,			//检定日期
nextCheckDate VARCHAr,		//下一次检定日期，即有效期
conclusion VARCHAR,			//总结论

voltageView VARCHAR,		//电压量程
currentView VARCHAR,		//电流量程
phaseCount INTERGER,		//未使用
maxCurrent VARCHAR,		    //最大电流倍数
otherText TEXT,				//其它测试数据,先不理。只上传基本误差数据看下先。
otherInformation TEXT);		//其它信息,
*/

//通过匹配信息监测信息里面的条形码获取条形码存放数据库的ID(条形码，返回值)
bool MainWindow::get_ID_from_checkParameter(QString  sampleNo,QString ID)
{
    QString str1;

    str1=QString("select * from checkParameter where id ='%1'").arg(ID);
    sql_exec(str1.toLatin1().data());

    for(int i=0;i<LocalSqlSum;i++)
    {
        strArray[0][0]=QString(sqlTemp[i][0]);  //ID
        strArray[1][0]=QString(sqlTemp[i][10]); //检测信息(电能表检测数据 条形码 厂家 这类信息)
        strArray[2][0]=QString(sqlTemp[i][9]);  //其它测试信息(重复性测试之类的)
        strArray[3][0]=QString(sqlTemp[i][2]);  //检定日期

        if(strArray[1][0].contains(sampleNo,Qt::CaseInsensitive))
        {
             //qDebug()<<strArray[2][0];
             return true;
        }
     }

    return false;
}

//获取本地数据库相关信息
void MainWindow:: get_checkParameter_detectTaskNo()
{
    memset(sqlTemp, 0,sizeof(0x4fff*3000));
    sql_exec("select * from checkParameter");
    for(int i=0;i<LocalSqlSum;i++)
    {
#if 1
        strArray[0][i]=QString(sqlTemp[i][0]);//key
        strArray[1][i]=QString(sqlTemp[i][10]);//任务编号

        strArray[2][i]=QString(sqlTemp[i][9]);//其它测试信息
        //qDebug()<<QString::number(i)<<strArray[1][i];
        //qDebug()<<QString::fromUtf8(sqlTemp[i][10]);
#endif
#if 0
        strArray[0][i]=QString(sqlTemp[i][0]);//key
        strArray[1][i]=QString(sqlTemp[i][1]);//
        strArray[2][i]=QString(sqlTemp[i][2]);//
        strArray[3][i]=QString(sqlTemp[i][3]);//
        strArray[4][i]=QString(sqlTemp[i][4]);//
        strArray[5][i]=QString(sqlTemp[i][5]);//
        strArray[6][i]=QString(sqlTemp[i][6]);//
        strArray[7][i]=QString(sqlTemp[i][7]);//
        strArray[8][i]=QString(sqlTemp[i][8]);//
        strArray[9][i]=QString(sqlTemp[i][9]);//其它测试信息
        strArray[10][i]=QString(sqlTemp[i][10]);//任务编号
#endif
    }
}


bool MainWindow::SqlTempToQstring(QString strExec,int ItemCount)
{
    if(sql_exec(strExec.toLatin1().data())!=SQLITE_OK)
    {
        return false;
    }

    for(int i=0;i<ItemCount;i++)
    {
        strArray[15][i]=QString(sqlTemp[0][i]);
        //qDebug()<<QString::number(i)<<QString(sqlTemp[0][i]);
    }

    return true;
}

//

int MainWindow:: get_MEASURE_REPEAT_checkError(QString strID)
{
    QString str1 ,str2;
    int rowCount;

    str1= QString("select * from checkError where id =%1;").arg(strID);
    sql_exec(str1.toLatin1().data());


    for(int j=0;j<sqlite_tableCal;j++)
    {
        rowCount = ui->EM_MEASURE_REPEAT_TblWidget->rowCount();

        //str1=QString::fromLocal8Bit(sqlTemp[j][4]);
        str2=str1.left(str1.indexOf("_",3));
        str1.remove(0,str1.indexOf("_",3)+1);

        //qDebug()<<str1;
        if(str1.startsWith("standard")==false)
        {
             continue;
        }
         //qDebug()<<str1;

        ui->EM_MEASURE_REPEAT_TblWidget->insertRow(rowCount);//ID
        ui->EM_MEASURE_REPEAT_TblWidget->setItem(rowCount,0, new QTableWidgetItem(my_MT_DETECT_TASK.DETECT_TASK_NO));//检定任务单
        ui->EM_MEASURE_REPEAT_TblWidget->setItem(rowCount,1, new QTableWidgetItem(my_MT_DETECT_TASK.EQUIP_CATEG));                 //设备类别
        ui->EM_MEASURE_REPEAT_TblWidget->setItem(rowCount,2, new QTableWidgetItem(my_MT_DETECT_TASK.SYS_NO));                 //系统编号
        ui->EM_MEASURE_REPEAT_TblWidget->setItem(rowCount,3, new QTableWidgetItem(my_CONC_CODE.DETECT_EQUIP_NO));          //检定线台编号
        ui->EM_MEASURE_REPEAT_TblWidget->setItem(rowCount,4, new QTableWidgetItem(""));                 //检定单元编号
        ui->EM_MEASURE_REPEAT_TblWidget->setItem(rowCount,5, new QTableWidgetItem(""));                 //表位编号
        ui->EM_MEASURE_REPEAT_TblWidget->setItem(rowCount,6, new QTableWidgetItem(my_MT_DETECT_TASK.BAR_CODE));                 //设备条形码
       // ui->EM_BASICERR_TblWidget->setItem(j,7, new QTableWidgetItem(currentTime()));                 //检定时间

        ui->EM_MEASURE_REPEAT_TblWidget->setItem(rowCount,8, new QTableWidgetItem("1"));                 //第几次检定(序号)
        ui->EM_MEASURE_REPEAT_TblWidget->setItem(rowCount,9, new QTableWidgetItem(QString::number(j)));  //序号
        ui->EM_MEASURE_REPEAT_TblWidget->setItem(rowCount,10,new QTableWidgetItem("1"));                //见附录I：有效标志 0：否、1：是

        ui->EM_MEASURE_REPEAT_TblWidget->setItem(rowCount,22,new QTableWidgetItem("01"));     //频率代码//PLDM_index("50")
        ui->EM_MEASURE_REPEAT_TblWidget->setItem(rowCount,24, new QTableWidgetItem(QString(sqlTemp[j][0])));//KEY


        ui->EM_MEASURE_REPEAT_TblWidget->setItem(rowCount,17,new QTableWidgetItem(currentTime()));            //检定线写入时间
        ui->EM_MEASURE_REPEAT_TblWidget->setItem(rowCount,18,new QTableWidgetItem("0"));                //见附录I：处理标记(0：未处理（默认）、1：处理中、2：已处理)
        ui->EM_MEASURE_REPEAT_TblWidget->setItem(rowCount,19,new QTableWidgetItem(currentTime()));             //处理时间
        ui->EM_MEASURE_REPEAT_TblWidget->setItem(rowCount,12,new QTableWidgetItem("0"));             //功率方向
//        ui->EM_MEASURE_REPEAT_TblWidget->setItem(rowCount,11,new QTableWidgetItem("0"));             //电压负载


 #if 1
        str2=str1.left(str1.indexOf("_"));

        if(str2.endsWith("."))//末尾是.
        {
            str2=str2.left(str2.indexOf('.',2));
        }
        str2.remove("standardWarp");
        str1.remove(0,str1.indexOf("_")+1);

//        qDebug()<<str2;
        ui->EM_MEASURE_REPEAT_TblWidget->setItem(rowCount,14,new QTableWidgetItem(GLYSDM_index(str2)));  //功率因素

        str1 = QString::fromLocal8Bit(sqlTemp[j][1]);
        str1 = str1.replace("\t","|");
        str1.remove(QString::fromUtf8("\r"));
        str1.remove(QString::fromUtf8("\n"));
        ui->EM_MEASURE_REPEAT_TblWidget->setItem(rowCount,15,new QTableWidgetItem(QString::number(str1.count("|")+1)));  //采样次数
//        ui->EM_MEASURE_REPEAT_TblWidget->setItem(rowCount,19,new QTableWidgetItem(str1));  //实际误差

//        ui->EM_MEASURE_REPEAT_TblWidget->setItem(rowCount,20,new QTableWidgetItem(QString::fromLocal8Bit(sqlTemp[j][2])));  //误差平均值
        ui->EM_MEASURE_REPEAT_TblWidget->setItem(rowCount,16,new QTableWidgetItem(QString::fromLocal8Bit(sqlTemp[j][3])));  //误差化整值

        str1=QString::fromLocal8Bit(sqlTemp[j][6]);

        ui->EM_MEASURE_REPEAT_TblWidget->setItem(rowCount,20,new QTableWidgetItem(JBWCSYJLDM_index(str1)));  //结论 JBWCSYJLDM_index(str1)

         my_CONC_CODE.MEASURE_REPEAT=JBWCSYJLDM_index(str1);
#endif


    }

    return 0;
}
/**************************************************************************
 *根据找出所有ID相同的项目
 *************************************************************************/
int MainWindow:: get_BASICERR_checkError(QString strID)
{
    QString str1 ,str2;
    float floatTemp;

    str1= QString("select * from checkError where id =%1;").arg(strID);
    sql_exec(str1.toLatin1().data());
    int rowCount ;

    for(int j=0;j<sqlite_tableCal;j++)
    {
        str1=QString::fromLocal8Bit(sqlTemp[j][4]);
        str2=str1.left(str1.indexOf("_",3));
        str1.remove(0,str1.indexOf("_",3)+1);

        //qDebug()<<str1;
        if(str1.startsWith("standardWarp"))
        {
              continue;
        }

        rowCount = ui->EM_BASICERR_TblWidget->rowCount();
       // qDebug()<<QStrowCount<<j;
        ui->EM_BASICERR_TblWidget->insertRow(rowCount);//ID
        ui->EM_BASICERR_TblWidget->setItem(rowCount,0, new QTableWidgetItem(my_MT_DETECT_TASK.DETECT_TASK_NO));//检定任务单
        ui->EM_BASICERR_TblWidget->setItem(rowCount,1, new QTableWidgetItem(my_MT_DETECT_TASK.EQUIP_CATEG));                 //设备类别
        ui->EM_BASICERR_TblWidget->setItem(rowCount,2, new QTableWidgetItem(my_MT_DETECT_TASK.SYS_NO));                 //系统编号
        ui->EM_BASICERR_TblWidget->setItem(rowCount,3, new QTableWidgetItem(my_CONC_CODE.DETECT_EQUIP_NO));          //检定线台编号
        ui->EM_BASICERR_TblWidget->setItem(rowCount,4, new QTableWidgetItem(""));                 //检定单元编号
        ui->EM_BASICERR_TblWidget->setItem(rowCount,5, new QTableWidgetItem(""));                 //表位编号
        ui->EM_BASICERR_TblWidget->setItem(rowCount,6, new QTableWidgetItem(my_MT_DETECT_TASK.BAR_CODE));                 //设备条形码
       // ui->EM_BASICERR_TblWidget->setItem(j,7, new QTableWidgetItem(currentTime()));                 //检定时间

      //  ui->EM_BASICERR_TblWidget->setItem(rowCount,8, new QTableWidgetItem("1"));                 //第几次检定(序号)
        ui->EM_BASICERR_TblWidget->setItem(rowCount,9, new QTableWidgetItem(QString::number(j)));  //序号
     //   ui->EM_BASICERR_TblWidget->setItem(rowCount,10,new QTableWidgetItem("1"));                //见附录I：有效标志 0：否、1：是


        ui->EM_BASICERR_TblWidget->setItem(rowCount,15,new QTableWidgetItem("50Hz"));     //频率代码 //PLDM_index("50")
        ui->EM_BASICERR_TblWidget->setItem(rowCount,23,new QTableWidgetItem(currentTime()));            //检定线写入时间
    //    ui->EM_BASICERR_TblWidget->setItem(rowCount,24,new QTableWidgetItem("0"));                //见附录I：处理标记(0：未处理（默认）、1：处理中、2：已处理)
        ui->EM_BASICERR_TblWidget->setItem(rowCount,25,new QTableWidgetItem(currentTime()));             //处理时间


        str1=QString::fromLocal8Bit(sqlTemp[j][4]);
        str2=str1.left(str1.indexOf("_",3));
        str1.remove(0,str1.indexOf("_",3)+1);
        ui->EM_BASICERR_TblWidget->setItem(rowCount,11,new QTableWidgetItem(GLFXDM_index(str2)));  //功率方向！

        str2=str1.left(str1.indexOf("_"));
        str1.remove(0,str1.indexOf("_")+1);
        //qDebug()<<str2;
        ui->EM_BASICERR_TblWidget->setItem(rowCount,12,new QTableWidgetItem(FYDM_index(str2)));  //电流相别

        str2=str1.left(str1.indexOf("_"));
        str1.remove(0,str1.indexOf("_")+1);
        ui->EM_BASICERR_TblWidget->setItem(rowCount,13,new QTableWidgetItem(str2));  //电流负载FZDLDM_index(str2)

        str2=str1.left(str1.indexOf("_"));

        if(str2.endsWith("."))//末尾是.
        {
            str2=str2.left(str2.indexOf('.',2));
        }
        str1.remove(0,str1.indexOf("_")+1);

        ui->EM_BASICERR_TblWidget->setItem(rowCount,16,new QTableWidgetItem(str2));  //功率因素GLYSDM_index(str2)

        str1 = QString::fromLocal8Bit(sqlTemp[j][1]);
        str1 = str1.replace("\t","|");
        str1.remove(QString::fromUtf8("\r"));
        str1.remove(QString::fromUtf8("\n"));
        ui->EM_BASICERR_TblWidget->setItem(rowCount,18,new QTableWidgetItem(QString::number(str1.count("|")+1)));  //采样次数
        ui->EM_BASICERR_TblWidget->setItem(rowCount,19,new QTableWidgetItem(str1));  //实际误差

        ui->EM_BASICERR_TblWidget->setItem(rowCount,20,new QTableWidgetItem(QString::fromLocal8Bit(sqlTemp[j][2])));  //误差平均值
        ui->EM_BASICERR_TblWidget->setItem(rowCount,21,new QTableWidgetItem(QString::fromLocal8Bit(sqlTemp[j][3])));  //误差化整值

        str1=QString::fromLocal8Bit(sqlTemp[j][6]);

        ui->EM_BASICERR_TblWidget->setItem(rowCount,22,new QTableWidgetItem(JBWCSYJLDM_index(str1)));  //结论 JBWCSYJLDM_index(str1)


        ui->EM_BASICERR_TblWidget->setItem(rowCount,26,new QTableWidgetItem(QString::fromLocal8Bit(sqlTemp[j][5])));  //误差上限

        floatTemp=QString::fromLocal8Bit(sqlTemp[j][5]).toFloat(0);
        ui->EM_BASICERR_TblWidget->setItem(rowCount,27,new QTableWidgetItem(QString::number(-floatTemp)));  //误差下限

        ui->EM_BASICERR_TblWidget->setItem(rowCount,28, new QTableWidgetItem(QString(sqlTemp[j][0])));//KEY

        if(JBWCSYJLDM_index(str1)== "0")
        {
            my_CONC_CODE.BASICERR = "0";
        }

    }

    return 0;
}
#if 1
int MainWindow:: get_DETECT_RSLT_checkParameter(QString strID)
{
    int rowCount,columnCount;
    QString strTemp,str1,str2,str3;
    str1=QString("select * from checkParameter where id =%1").arg(strID);
    sql_exec(str1.toLatin1().data());

    for(int i=0;i<sqlite_tableCal;i++)
    {
        rowCount =ui->EM_RSLT_TabWidget->rowCount();
        columnCount =ui->EM_RSLT_TabWidget->columnCount();

        ui->EM_RSLT_TabWidget->insertRow(rowCount);
        for(int j =0;j<columnCount;j++)//初始化
        {
            ui->EM_RSLT_TabWidget->setItem(rowCount,j, new QTableWidgetItem(""));
        }

        ui->EM_RSLT_TabWidget->setItem(rowCount,0, new QTableWidgetItem(my_MT_DETECT_TASK.BAR_CODE));//  //设备条形码
        ui->EM_RSLT_TabWidget->setItem(rowCount,1, new QTableWidgetItem(get_RSLT_CONC()));
        ui->EM_RSLT_TabWidget->setItem(rowCount,2, new QTableWidgetItem(QString(sqlTemp[0][2])));     //检定时间

        ui->EM_RSLT_TabWidget->setItem(rowCount,9, new QTableWidgetItem("50Hz"));
        str2 = QString::fromLocal8Bit(sqlTemp[0][10]);

        str3=get_itemFromSql(str2,QString::fromUtf8("fTemperature"),QString::fromUtf8("温度"));
        ui->EM_RSLT_TabWidget->setItem(rowCount,5,new QTableWidgetItem(str3));

        str3=get_itemFromSql(str2,QString::fromUtf8("fHumidity"),QString::fromUtf8("相对湿度"));
        ui->EM_RSLT_TabWidget->setItem(rowCount,6,new QTableWidgetItem(str3));

        str3=get_itemFromSql(str2,QString::fromUtf8("cClassGrade"),QString::fromUtf8("精度等级"));
        ui->EM_RSLT_TabWidget->setItem(rowCount,10,new QTableWidgetItem(str3));

        str3=get_itemFromSql(str2,QString::fromUtf8("cManufactory"),QString::fromUtf8("制造单位"));
        ui->EM_RSLT_TabWidget->setItem(rowCount,11,new QTableWidgetItem(str3));

        str3=get_itemFromSql(str2,QString::fromUtf8("脉冲常数"),QString::fromUtf8(""));
        ui->EM_RSLT_TabWidget->setItem(rowCount,12,new QTableWidgetItem(str3));
        ui->EM_RSLT_TabWidget->setItem(rowCount,13,new QTableWidgetItem(str3));

        str3=get_itemFromSql(str2,QString::fromUtf8("接线模式"),QString::fromUtf8(""));
        ui->EM_RSLT_TabWidget->setItem(rowCount,16,new QTableWidgetItem(str3));

        str3=get_itemFromSql(str2,QString::fromUtf8("二次电流"),QString::fromUtf8(""));
        ui->EM_RSLT_TabWidget->setItem(rowCount,20,new QTableWidgetItem(str3));
    }
    return 0;
}

#endif

int MainWindow::sql_exec(const char *sql)
{
    char *zErr;
    int intResult;
    sqlite_tableCal=0;
    memset(sqlTemp, 0,sizeof(1000*1000));
    intResult = sqlite3_exec(localsqliteDB,sql,callback,NULL,&zErr);

    LocalSqlSum = sqlite_tableCal;

    return intResult;

}

#if 1
 int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
  sqlite_RowCnt  =argc;

  for( int i = 0; i < argc; i++ )
  {
      if(argv[i]==NULL)
      {
          sqlTemp[sqlite_tableCal][i]=="0";
      }
      else
      {
          strcpy(sqlTemp[sqlite_tableCal][i], argv[i] );
      }
  }

    #if 0
      for(int i=0; i<argc; i++)
      {
          printf("%s = %s\n", azColName[i], sqlTemp[i][0] ?  sqlTemp[i][0] : "NULL");
      }
    #endif

    #if 0
      for(int i=0; i<argc; i++)
      {
          printf("i==%d %s = %s\n", i,azColName[i], sqlTemp[sqlite_tableCal][i] ?  sqlTemp[sqlite_tableCal][i] : "NULL");
      }
    #endif

//  printf("sqlite_RowCnt==%d \n",   sqlite_RowCnt);
//  printf("sqlite_tableCal==%d \n", sqlite_tableCal);
//  fflush ( stdout ) ;
  sqlite_tableCal++;
  return 0;
}
#endif


