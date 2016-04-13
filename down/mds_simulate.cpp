#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QDebug"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QObject>
#include "unistd.h"
#include "QSqlError"
bool MainWindow:: create_localDatabase()
{
    QString strExec,strAct;
    QSqlDatabase  destSqldb = QSqlDatabase::addDatabase("QSQLITE");
    if(access("goose.db",0))
    {
        destSqldb.setDatabaseName("goose.db");
        if(!destSqldb.open()) return false;
        QSqlQuery myquery;


    strExec = "CREATE TABLE  MT_DETECT_RSLT( Num  integer primary key autoincrement  ,DETECT_TASK_NO char(8),EQUIP_CATEG char(8),SYS_NO char(8),DETECT_EQUIP_NO char(8),DETECT_UNIT_NO char(8),POSITION_NO char(8),BAR_CODE char(8),DETECT_DATE char(8),CONC_CODE char(8),INTUIT_CONC_CODE char(8),BASICERR_CONC_CODE char(8),CONST_CONC_CODE char(8),STARTING_CONC_CODE char(8),CREEPING_CONC_CODE char(8),DAYERR_CONC_CODE char(8),POWER_CONC_CODE char(8),VOLT_CONC_CODE char(8),STANDARD_CONC_CODE char(8),WAVE_CONC_CODE char(8),ERROR_CONC_CODE char(8),CONSIST_CONC_CODE char(8),VARIATION_CONC_CODE char(8),OVERLOAD_CONC_CODE char(8),TS_CONC_CODE char(8),RUNING_CONC_CODE char(8),PERIOD_CONC_CODE char(8),VALUE_CONC_CODE char(8),KEY_CONC_CODE char(8),ESAM_CONC_CODE char(8),REMOTE_CONC_CODE char(8),EH_CONC_CODE char(8),EC_CONC_CODE char(8),SWITCH_ON_CONC_CODE char(8),SWITCH_OUT_CONC_CODE char(8),WARN_CONC_CODE char(8),WARN_CANCEL_CONC_CODE char(8),SURPLUS_CONC_CODE char(8),RESET_EQ_MET_CONC_CODE char(8),INFRARED_TEST_CONC_CODE char(8),RESET_DEMAND_MET_CONC_CODE char(8),TIMING_MET_CONC_CODE char(8),COMMINICATE_MET_CONC_CODE char(8),ADDRESS_MET_CONC_CODE char(8),MULTI_INTERFACE_MET_CONC_CODE char(8),LEAP_YEAR_MET_CONC char(8),PARA_READ_MET_CONC_CODE char(8),PARA_SET_MET_CONC char(8),SETTING_CONC_CODE char(8),DEVIATION_MET_CONC char(8),GPS_CONC char(8),DETECT_PERSON char(8),AUDIT_PERSON char(8),WRITE_DATE char(8),SEAL_HANDLE_FLAG char(8),SEAL_HANDLE_DATE char(8),HANDLE_FLAG char(8),HANDLE_DATE char(8),TEMP char(8),HUMIDITY char(8),PRESET_PARAMET_CHECK_CONC_CODE char(8),PASSWORD_CHANGE_CONC_CODE char(8),PRESET_PARAMETER_SET_CONC_CODE char(8),RELIABILITY_CONC_CODE char(8),MOVE_STABILITY_TEST_CONC_CODE char(8),ANTI_SEISMICTEST_CONC_CODE char(8),PRESET_PARAM2_CHECK_CONC_CODE char(8),PRESET_PARAM3_CHECK_CONC_CODE char(8),PRESET_PARAM2_SET_CONC_CODE char(8),PRESET_PARAM3_SET_CONC_CODE char(8),HARD_VERSION char(8),FAULT_TYPE char(8),EVENT_REC_FUNC_CONC_CODE char(8),INFLUENCE_QTY_CONC_CODE char(8),AUX_POW_CONC_CODE char(8),ALARM_FUNC_CONC_CODE char(8),RATE_TIME_FUNC_CONC_CODE char(8),ELE_ENERGY_FUNC_CONC_CODE char(8),EXPIRATION_DATE char(8),MEA_REP_CONC_CODE char(8),CERT_NO char(8),CERT_NO_PERIOD char(8),UNPASS_REASON char(8),COMM_MODE_CHG_CONC_CODE char(8),COMM_MODE_INT_CONC_CODE char(8),FROZEN_FUNC_CONC_CODE char(8));";

    strAct  = "CREATE TABLE  MT_DETECT_RSLT";



    destSql_query( myquery, strExec, strAct  );

    strExec ="INSERT INTO  MT_DETECT_RSLT(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,CONC_CODE,INTUIT_CONC_CODE,BASICERR_CONC_CODE,CONST_CONC_CODE,STARTING_CONC_CODE,CREEPING_CONC_CODE,DAYERR_CONC_CODE,POWER_CONC_CODE,VOLT_CONC_CODE,STANDARD_CONC_CODE,WAVE_CONC_CODE,ERROR_CONC_CODE,CONSIST_CONC_CODE,VARIATION_CONC_CODE,OVERLOAD_CONC_CODE,TS_CONC_CODE,RUNING_CONC_CODE,PERIOD_CONC_CODE,VALUE_CONC_CODE,KEY_CONC_CODE,ESAM_CONC_CODE,REMOTE_CONC_CODE,EH_CONC_CODE,EC_CONC_CODE,SWITCH_ON_CONC_CODE,SWITCH_OUT_CONC_CODE,WARN_CONC_CODE,WARN_CANCEL_CONC_CODE,SURPLUS_CONC_CODE,RESET_EQ_MET_CONC_CODE,INFRARED_TEST_CONC_CODE,RESET_DEMAND_MET_CONC_CODE,TIMING_MET_CONC_CODE,COMMINICATE_MET_CONC_CODE,ADDRESS_MET_CONC_CODE,MULTI_INTERFACE_MET_CONC_CODE,LEAP_YEAR_MET_CONC,PARA_READ_MET_CONC_CODE,PARA_SET_MET_CONC,SETTING_CONC_CODE,DEVIATION_MET_CONC,GPS_CONC,DETECT_PERSON,AUDIT_PERSON,WRITE_DATE,SEAL_HANDLE_FLAG,SEAL_HANDLE_DATE,HANDLE_FLAG,HANDLE_DATE,TEMP,HUMIDITY,PRESET_PARAMET_CHECK_CONC_CODE,PASSWORD_CHANGE_CONC_CODE,PRESET_PARAMETER_SET_CONC_CODE,RELIABILITY_CONC_CODE,MOVE_STABILITY_TEST_CONC_CODE,ANTI_SEISMICTEST_CONC_CODE,PRESET_PARAM2_CHECK_CONC_CODE,PRESET_PARAM3_CHECK_CONC_CODE,PRESET_PARAM2_SET_CONC_CODE,PRESET_PARAM3_SET_CONC_CODE,HARD_VERSION,FAULT_TYPE,EVENT_REC_FUNC_CONC_CODE,INFLUENCE_QTY_CONC_CODE,AUX_POW_CONC_CODE,ALARM_FUNC_CONC_CODE,RATE_TIME_FUNC_CONC_CODE,ELE_ENERGY_FUNC_CONC_CODE,EXPIRATION_DATE,MEA_REP_CONC_CODE,CERT_NO,CERT_NO_PERIOD,UNPASS_REASON,COMM_MODE_CHG_CONC_CODE,COMM_MODE_INT_CONC_CODE,FROZEN_FUNC_CONC_CODE)\n"
            "values('001','01','001','1','1',  '1','1','2015','1','1',  '1','1','1','1','1',  '1','1','1','1','1',  '1','1','1','1','1',       '1','1','1','1','1', \n"
            "'1','1','1','1','1',      '1','1','1','1','1',    '1','1','1','1','1',  '1','1','1','1','1',  '0',   '0','2015','1','2015','1', '2015','0','0','0','1',  '0','1','1','1','0',  '0','0','0','1','1', '1','1','1','1','1', '1','2015','0','1','1'  ,'0','1','1','1');";

    strAct ="INSERT INTO  MT_DETECT_RSLT";

    destSql_query( myquery, strExec, strAct  );

    }
    else
    {
        destSqldb.setDatabaseName("goose.db");
        if(!destSqldb.open()) return false;
        return true;
    }

    return true;
}

bool MainWindow:: destSql_query(QSqlQuery query,QString strExec,QString strAct  )
{
    if(!query.exec(strExec))
    {
        qDebug()<<strAct + " error："<<query.lastError().driverText();
        return false;
    }
}
void MainWindow:: init_localDatabase()
{
    SGEE_SqlDatabase = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE", "SGEE_SqlDatabase"));
    SGEE_SqlDatabase->setDatabaseName("goose.db");

    if (!SGEE_SqlDatabase->open())
     {
        showInformationBox("init_localDatabase open error");
        SGEE_SqlDatabase->close();
        exit(1);
     }

    SGEE_SqlTablemodel_ptl = new QSqlTableModel(this, *SGEE_SqlDatabase);
    SGEE_SqlTablemodel_ptl->setTable("protocol");
    SGEE_SqlTablemodel_ptl->setEditStrategy(QSqlTableModel::OnManualSubmit);
    SGEE_SqlTablemodel_ptl->select();
}

#if  0
void MainWindow::on_localSql_check_PsBtn_clicked()
{
    GSE_SCL_ctlBlock_insert();
    GSE_SCL_ctlBlock_delete();

    QString strTemp;
    int rowCount=SGEE_SqlTablemodel_ptl->rowCount();


    for(int i =0;i<rowCount;i++)
    {
      strTemp=SGEE_SqlTablemodel_ptl->data(SGEE_SqlTablemodel_ptl->index(i,1)).toString();
      qDebug()<<strTemp;
    }

}
#endif


#if 1
void MainWindow::GSE_SCL_ctlBlock_insert()
{
    QString strTemp;
    int rowCount=SGEE_SqlTablemodel_ptl->rowCount()+1;

    QString ID         = QString::number(rowCount);
    QString namedesc    = "GSE发送#" + ID ;
    QString APPID       =  QString::number(2000 + rowCount -5) ;
    QString macDst      =  "01-0C-CD-01-20-01";
    QString vlanId      =  "0";
    QString priority    =  "4";
    QString version     =  "0";
    QString gocbRef     =  "gocbRef";
    QString dateSet     =  "dataSet";
    QString goId        =  "goId0";
    QString testBit        ="0";
    QString channelNum  =  "3";
    QString dataFormat   =  "0";//QString ::number(SGSE.ptlInf_dataformat_cbox->currentIndex());
    QString boolSelected = "0";  //off
    QStringList stringList;

    stringList<<ID<<namedesc<<APPID<<macDst<<vlanId<<priority<<version<<gocbRef<<
                dateSet<<goId<<testBit<<channelNum<<dataFormat<<boolSelected;

    for(int i =1;i<129;i++)
    {
        strTemp =  QObject::trUtf8("%1,%2,0,0000,-").arg(QString::number(i),dataFormat); //
        stringList<<strTemp;
       // qDebug()<<QString ::number(i);
     }

    if (insert_SGSE_QsqlDatabase_ptl(stringList) == false)
    {
        showInformationBox("数据插入出错");

        return ;
    }

}
/******************************************************************************************
  *fun:删除模块
 *****************************************************************************************/
void MainWindow::GSE_SCL_ctlBlock_delete()
{

    int rowCount = SGEE_SqlTablemodel_ptl->rowCount()-1;
    if(SGEE_SqlTablemodel_ptl->removeRow(rowCount) == false)//row  0~  removeRow是从0开始算
    {
       showInformationBox("数据删除出错");
        return ;
    }

    if (save_SGSE_QsqlDatabase_ptl() == false)
    {
       showInformationBox("数据保存出错");
        return ;
    }
}


#endif
//GSE协议编辑.插入数据库
bool MainWindow::insert_SGSE_QsqlDatabase_ptl(QStringList data)
{
    int row = SGEE_SqlTablemodel_ptl->rowCount();
    if (SGEE_SqlTablemodel_ptl->insertRow(row) == false)
    {
        qDebug()<<"insertRow error ";
        return false;
    }

    for (int column = 0; column < data.count(); column++)
    {
        SGEE_SqlTablemodel_ptl->setData(SGEE_SqlTablemodel_ptl->index(row, column), data.at(column));
    }

    if (save_SGSE_QsqlDatabase_ptl() == false)
    {
        return false;
    }
    return true ;
}

//GSE协议编辑保存
bool MainWindow::save_SGSE_QsqlDatabase_ptl()
{
    if (!SGEE_SqlDatabase->isOpen())
     {
        qDebug()<<"isOpen error ";
         return false;
     }

     if (SGEE_SqlTablemodel_ptl->database().transaction() == false)
     {
         qDebug()<<"transaction error ";
         return false;
     }

     if (SGEE_SqlTablemodel_ptl->submitAll())
     {
         SGEE_SqlTablemodel_ptl->database().commit();
     }
     else
     {
         SGEE_SqlTablemodel_ptl->database().rollback();
         return false;
     }
     return true;
}



