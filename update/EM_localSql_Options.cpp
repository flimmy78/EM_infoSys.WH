#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

//打开本地数据库并且创建自己从MDS上下载所需的表
void  MainWindow::open_localSql()
{
    QString strExec;
    int  intResult;

//  QString strFilebaseName =  QString::fromUtf8("./db/检定数据保存数据库.db");//
//  QString strFilebaseName =  get_DB_FileName(); //"检定数据保存数据库.db"

    QString strFilebaseName=ui->EM_options_setArg_localSqlPath_LnEdit->text();//QString::fromUtf8("E:/XL.Win.MDS_WH/XL.Win.MDS_WH/DBUpdate/检定数据保存数据库.db");

    if(strFilebaseName.isEmpty())
    {
       showInformationBox(QString::fromUtf8("数据数据库打开出错"));
       return;
    }

     intResult = sqlite3_open(strFilebaseName.toUtf8().data(),&localsqliteDB);

     if(intResult!=SQLITE_OK){
         ui->stackedWidget->setCurrentIndex(2);
         on_EM_options_Act_triggered();
         showInformationBox(QString::fromUtf8("数据数据库打开出错"));
         sqlite3_close(localsqliteDB);
         return;
     }

//武汉MDS 创建表格

     strExec ="CREATE TABLE if  not exists sampleInfo(sampleNo char(128) primary key,tableType char(128),phaseType char(128),nominalVoltage char(128),nominalCurrent char(128),sampleType char(128),nominalConstant char(128),reactiveConstant char(128),activeLevel char(128),reactiveLevel char(128),freq char(128),inputMode char(128),isEmulator char(128),measurementDirection char(128),sampleName char(128),redSeal char(128),producer char(128),sampleUserName char(128),sampleManuNo char(128),sampleSeal char(128));";
     intResult= sql_exec(strExec.toLatin1().data());
     if(intResult!=SQLITE_OK)
     {
         showInformationBox(QString::fromUtf8("create sampleInfo error"));
         return;
     }


    strExec ="CREATE TABLE if not exists MT_DETECT_OUT_EQUIP( DETECT_TASK_NO char(128),IO_TASK_NO char(128),EQUIP_CATEG char(128),BAR_CODE char(128) primary key,BOX_BAR_CODE char(128),PILE_NO char(128),PLATFORM_NO char(128),SYS_NO char(128),WRITE_DATE char(128),HANDLE_FLAG char(128),HANDLE_DATE char(128),ARRIVE_BATCH_NO char(128),REDETECT_FLAG char(128),EMP_NO char(128),PLATFORM_TYPE char(128));";
    intResult= sql_exec(strExec.toLatin1().data());

    if(intResult!=SQLITE_OK)
    {
        showInformationBox(QString::fromUtf8("create MT_DETECT_OUT_EQUIP error"));
        return;
    }

    strExec ="CREATE TABLE if  not exists MT_DETECT_TASK(BAR_CODE char(128) primary key,DETECT_TASK_NO char(128),TASK_PRIO char(128),DETECT_MODE char(128),SYS_NO char(128),ARRIVE_BATCH_NO char(128),EQUIP_CATEG char(128),MODEL_CODE char(128),SCHEMA_ID char(128),REDETECT_SCHEMA char(128),REDETECT_FLAG char(128),REDETECT_QTY char(128),EQUIP_QTY char(128),PILE_QTY char(128),TASK_STATUS char(128),HANDLE_DATE char(128),HANDLE_FLAG char(128),WRITE_DATE char(128),ERP_BATCH_NO char(128),TASK_TYPE char(128),EQUIP_STATUS_CODE char(128),EXEC_RESP_NAME char(128),APPR_NAME char(128),IS_AUTO_SEAL char(128),EQUIP_CODE_NEW char(128),PARAM_TYPE char(128));";
    intResult= sql_exec(strExec.toLatin1().data());
    if(intResult!=SQLITE_OK)
    {
        showInformationBox(QString::fromUtf8("create MT_DETECT_TASK error"));
        return;
    }

    strExec ="CREATE TABLE if  not exists MT_P_CODE(BAR_CODE char(128) primary key, CODE_ID char(128),CODE_SORT_ID char(128),P_CODE char(128),CODE_TYPE char(128),ORG_NO char(128),VALUE char(128),NAME char(128),DISP_SN char(128),CONTENT1 char(128),CONTENT2 char(128),CONTENT3 char(128),CONTENT4 char(128),CONTENT5 char(128),PROVINCE char(128),HANDLE_PROVINCE char(128),HANDLE_TYPE char(128),CONTENT9 char(128),CONTENT6 char(128),CONTENT7 char(128),CONTENT8 char(128));";
    intResult= sql_exec(strExec.toLatin1().data());
    if(intResult!=SQLITE_OK)
    {
        showInformationBox(QString::fromUtf8("create MT_P_CODE error"));
        return;
    }

    strExec ="CREATE TABLE if not exists MT_METER( METER_ID char(128),ERP_BATCH_NO char(128),BAR_CODE char(128) primary key,ASSET_NO char(128),MADE_NO char(128),LOT_NO char(128),ORG_NO char(128),ORG_TYPE char(128),PR_ORG char(128),BELONG_DEPT char(128),\n"
                    "CONTRACT_ID char(128),CONTRACT_NO char(128),RCV_ID char(128),ARRIVE_BATCH_NO char(128),AREA_CODE char(128),STORE_AREA_SORT char(128),WH_ID char(128),WH_AREA_ID char(128),STORE_AREA_ID char(128),\n"
                    "STORE_LOC_ID char(128),PALLET_BAR_CODE char(128),BOX_BAR_CODE char(128),SORT_CODE char(128),TYPE_CODE char(128),MODEL_CODE char(128),WIRING_MODE char(128),VOLT_CODE char(128),RATED_CURRENT char(128),OVERLOAD_FACTOR char(128),AP_PRE_LEVEL_CODE char(128),\n"
                    "RP_PRE_LEVEL_CODE char(128),METER_DIGITS char(128),TS_DIGITS char(128),CONST_CODE char(128),RP_CONSTANT char(128),MANUFACTURER char(128),MADE_DATE char(128),EQIP_PRC char(128),SELF_FACTOR char(128),BOTH_WAY_CALC char(128),\n"
                    "PREPAY_FLAG char(128),MULTIRATE_FALG char(128),DEMAND_METER_FLAG char(128),HARMONIC_MEAS_FALG char(128),CC_PREVENT_FLAG char(128),PULSE_CONSTANT_CODE char(128),PULSE_AMPLITUDE_CODE char(128),PULSE_SORT_CODE char(128),FREQ_CODE char(128),CON_MODE char(128),\n"
                    "READING_TYPE_CODE char(128),METER_USAGE char(128),MEAS_THEORY char(128),BEARING_STRUC char(128),CI char(128),RELAY_JOINT char(128),ELEC_MEAS_DISP_FLAG char(128),VL_FLAG char(128),CL_FLAG char(128),ANTI_PHASE_FLAG char(128),\n"
                    "SUPER_POWER_FLAG char(128),LOAD_CURVE_FLAG char(128),POWEROFF_MR_FLAG char(128),INFRARED_FLAG char(128),DOC_TYPE_CODE char(128),LATEST_CHK_DATE char(128),INST_DATE char(128),RMV_DATE char(128),ROTATE_CYCLE char(128),DISCARD_REASON char(128),\n"
                    "DESCARD_DATE char(128),PR_CODE char(128),HANDOVER_DEPT char(128),HANDOVER_DATE char(128),CUR_STATUS_CODE char(128),BORROW_FLAG char(128),NEW_FLAG char(128),DOC_CREATOR_NO char(128),DOC_CREATE_DATE char(128),BAUDRATE_CODE char(128),\n"
                    "METER_CLOSE_MODE char(128),REGISTER_MODE char(128),DISP_MODE char(128),HARD_VER char(128),SOFT_VER char(128),RS485_ROUTE_QTY char(128),COMM_PROT_CODE char(128),COMM_MODE char(128),ATTACHEQUIP_TYPE_CODE char(128),CARRIER_WAVE_ID char(128),\n"
                    "REMARK char(128),WRITE_DATE char(128),HANDLE_FLAG char(128),HANDLE_DATE char(128),LATEST_DETECT_DATE char(128),CHIP_MANUFACTURER char(128),CHIP_MODEL_CODE char(128),TARIFF_TYPE char(128));";
    intResult= sql_exec(strExec.toLatin1().data());
    if(intResult!=SQLITE_OK)
    {
        showInformationBox(QString::fromUtf8("create MT_METER error"));
        return;
    }
}
