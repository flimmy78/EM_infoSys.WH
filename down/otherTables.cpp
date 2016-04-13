#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QDebug"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QObject>
#include "unistd.h"
#include "QSqlError"


//bool MainWindow:: create_localDatabase().
//{


#if 0
//c1
        strExec ="CREATE TABLE MT_INTUIT_MET_CONC( Num  integer primary key autoincrement,DETECT_TASK_NO char(32),\n"
                "EQUIP_CATEG char(8),     SYS_NO   char(16),    DETECT_EQUIP_NO char(32),DETECT_UNIT_NO char(32),   POSITION_NO char(32),\n"
                "BAR_CODE char(32),       DETECT_DATE char(32), PARA_INDEX char(32),     DETECT_ITEM_POINT char(8),IS_VALID char(32),\n"
                "DETECT_CONTENT char(20), CONC_CODE char(32),   WRITE_DATE char(20),     HANDLE_FLAG char(20),      HANDLE_DATE char(20));";

        strAct ="CREATE TABLE MT_INTUIT_MET_CONC";

        destSql_query( myquery, strExec, strAct  );

        strExec ="INSERT INTO MT_INTUIT_MET_CONC(DETECT_TASK_NO, EQUIP_CATEG, SYS_NO, DETECT_EQUIP_NO,DETECT_UNIT_NO,\n"
                "POSITION_NO,  BAR_CODE,  DETECT_DATE,  PARA_INDEX,  DETECT_ITEM_POINT,  IS_VALID,   DETECT_CONTENT, CONC_CODE,  WRITE_DATE, HANDLE_FLAG,\n"
                "HANDLE_DATE)values('001','01','001','1','1','1','1','2015','1','1','1','020','01','2015','2','2015');";

        strAct ="INSERT INTO MT_INTUIT_MET_CONC";

        destSql_query( myquery, strExec, strAct  );

//c2
        strExec ="CREATE TABLE MT_BASICERR_MET_CONC( Num  integer primary key autoincrement,DETECT_TASK_NO char(32),\n"
                                                    "EQUIP_CATEG char(8),          SYS_NO   char(16),        DETECT_EQUIP_NO char(32),DETECT_UNIT_NO char(32),    POSITION_NO char(32),\n"
                                                    "BAR_CODE char(32),            DETECT_DATE char(32),     PARA_INDEX char(32),     DETECT_ITEM_POINT char(8),  IS_VALID char(32),\n"
                                                    "BOTH_WAY_POWER_FLAG char(20), IABCh char(32),           LOAD_CURRENT char(20),   LOAD_VOLTAGE char(20),      FREQ char(20),\n"
                                                    "PF char(20),                  DETECT_CIRCLE char(32),   SIMPLING char(20),       ERROR char(20),             AVE_ERR char(20),\n"
                                                    "INT_CONVERT_ERR char(8),     CONC_CODE char(20),        WRITE_DATE char(32),     HANDLE_FLAG char(20),       HANDLE_DATE char(20),ERR_UP char(20),ERR_DOWN char(20));";

        strAct ="CREATE TABLE MT_BASICERR_MET_CONC";

        destSql_query( myquery, strExec, strAct  );

        strExec ="INSERT INTO MT_BASICERR_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,\n"
                 "IS_VALID,BOTH_WAY_POWER_FLAG,IABCh,LOAD_CURRENT,LOAD_VOLTAGE,FREQ,PF,DETECT_CIRCLE,SIMPLING,ERROR,AVE_ERR,INT_CONVERT_ERR,CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE,ERR_UP,ERR_DOWN)\n"
                 "values('001','01','001','1','1', '1','1','2015','1','1',  '1','0','01','01','00', '01','01','5','1','0',  '0','0','1','2015','1', '2015','0','0');";

        strAct ="INSERT TABLE MT_BASICERR_MET_CONC";

        destSql_query( myquery, strExec, strAct  );

        strExec ="CREATE TABLE MT_CONST_MET_CONC( Num  integer primary key autoincrement , DETECT_TASK_NO char(8), EQUIP_CATEG char(8), SYS_NO char(8), DETECT_EQUIP_NO char(8), DETECT_UNIT_NO char(8), POSITION_NO char(8), BAR_CODE char(8), DETECT_DATE char(8), PARA_INDEX char(8), DETECT_ITEM_POINT char(8), IS_VALID char(8), LOAD_CURRENT char(8), BOTH_WAY_POWER_FLAG char(8), REAL_PULES char(8), START_READING char(8), END_READING char(8), DIFF_READING char(8), STANDARD_READING char(8), ERROR char(8), ERR_DOWN char(8), ERR_UP char(8), CONST_ERR char(8), VOLT char(8), FEE_START_TIME char(8), FEE_RATIO char(8), QUALIFIED_PULES char(8), DIVIDE_ELECTRIC_QUANTITY char(8), PF char(8), CONTROL_METHOD char(8), CONC_CODE char(8), WRITE_DATE char(8), HANDLE_FLAG char(8), HANDLE_DATE char(8), IR_LAST_READING char(8), READ_TYPE_CODE char(8));";
//c3
        strAct  ="CREATE TABLE MT_CONST_MET_CONC";

        destSql_query( myquery, strExec, strAct  );

        strExec ="INSERT INTO MT_CONST_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,LOAD_CURRENT,BOTH_WAY_POWER_FLAG,REAL_PULES,START_READING,END_READING,DIFF_READING,STANDARD_READING,ERROR,ERR_DOWN,ERR_UP,CONST_ERR,VOLT,FEE_START_TIME,FEE_RATIO,QUALIFIED_PULES,DIVIDE_ELECTRIC_QUANTITY,PF,CONTROL_METHOD,CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE,IR_LAST_READING,READ_TYPE_CODE)\n"
                "values('001','01','001','1','1', '1','1','2015','1','1',  '1','1','0','0','0', '0','0','0','0','0',  '0','0','0','0','0', '0','0','01', '02','1','2015','1','2015','0','11');";

        strAct ="INSERT TABLE MT_CONST_MET_CONC";

        destSql_query( myquery, strExec, strAct  );
//c4

        strExec ="CREATE TABLE MT_STARTING_MET_CONC( Num  integer primary key autoincrement  ,  DETECT_TASK_NO char(8), EQUIP_CATEG char(8), SYS_NO char(8), DETECT_EQUIP_NO char(8), DETECT_UNIT_NO char(8), POSITION_NO char(8), BAR_CODE char(8), DETECT_DATE char(8), PARA_INDEX char(8), DETECT_ITEM_POINT char(8), IS_VALID char(8), LOAD_VOLTAGE char(8), PULES char(8), BOTH_WAY_POWER_FLAG char(8), LOAD_CURRENT char(8), TEST_TIME char(8), REAL_TEST_TIME char(8), START_CURRENT char(8), CONC_CODE char(8), WRITE_DATE char(8), HANDLE_FLAG char(8), HANDLE_DATE char(8));";

        strAct  ="CREATE TABLE MT_STARTING_MET_CONC";

        destSql_query( myquery, strExec, strAct  );

        strExec ="INSERT INTO MT_STARTING_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,LOAD_VOLTAGE,PULES,BOTH_WAY_POWER_FLAG,LOAD_CURRENT,TEST_TIME,REAL_TEST_TIME,START_CURRENT,CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE)\n"
                "values('001','01','001','1','1', '1','1','2015','1','1',  '1','0','0','0','1', '2015','2015','0','1','2015','1','2015');";

        strAct ="INSERT TABLE MT_STARTING_MET_CONC";

        destSql_query( myquery, strExec, strAct  );

 //c5
        strExec ="CREATE TABLE MT_CREEPING_MET_CONC( Num  integer primary key autoincrement  ,   DETECT_TASK_NO char(8), EQUIP_CATEG char(8), SYS_NO char(8), DETECT_EQUIP_NO char(8), DETECT_UNIT_NO char(8), POSITION_NO char(8), BAR_CODE char(8), DETECT_DATE char(8), PARA_INDEX char(8), DETECT_ITEM_POINT char(8), IS_VALID char(8), LOAD_VOLTAGE char(8), PULES char(8), LOAD_CURRENT char(8), BOTH_WAY_POWER_FLAG char(8), TEST_TIME char(8), REAL_TEST_TIME char(8), CONC_CODE char(8), WRITE_DATE char(8), HANDLE_FLAG char(8), HANDLE_DATE char(8));";

        strAct  ="CREATE TABLE MT_CREEPING_MET_CONC";

        destSql_query( myquery, strExec, strAct  );

        strExec ="INSERT INTO MT_CREEPING_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,LOAD_VOLTAGE,PULES,LOAD_CURRENT,BOTH_WAY_POWER_FLAG,TEST_TIME,REAL_TEST_TIME,CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE)\n"
                "values('001','01','001','1','1', '1','1','2015','1','1',  '1','1','1','1','1',   '2015','2015','1','2015','1',  '2015');";

        strAct ="INSERT TABLE MT_CREEPING_MET_CONC";

        destSql_query( myquery, strExec, strAct  );

        //c6
        strExec ="CREATE TABLE MT_HUTCHISON_COMBINA_MET_CONC( Num  integer primary key autoincrement ,   DETECT_TASK_NO char(8), EQUIP_CATEG char(8), SYS_NO char(8), DETECT_EQUIP_NO char(8), DETECT_UNIT_NO char(8), POSITION_NO char(8), BAR_CODE char(8), DETECT_DATE char(8), PARA_INDEX char(8), DETECT_ITEM_POINT char(8), BOTH_WAY_POWER_FLAG char(8), LOAD_CURRENT char(8), PF char(8), FEE_RATIO char(8), CONTROL_METHOD char(8), IR_TIME char(8), IR_READING char(8), ERR_DOWN char(8), ERR_UP char(8), VOLTAGE char(8), TOTAL_READING_ERR char(8), TOTAL_INCREMENT char(8), SUMER_ALL_INCREMENT char(8), SHARP_INCREMENT char(8), PEAK_INCREMENT char(8), FLAT_INCREMENT char(8), VALLEY_INCREMENT char(8), VALUE_CONC_CODE char(8), CONC_CODE char(8), WRITE_DATE char(8), HANDLE_FLAG char(8), HANDLE_DATE char(8) );";

        strAct  ="CREATE TABLE MT_HUTCHISON_COMBINA_MET_CONC";

        destSql_query( myquery, strExec, strAct  );

        strExec ="INSERT INTO MT_HUTCHISON_COMBINA_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,BOTH_WAY_POWER_FLAG,LOAD_CURRENT,PF,FEE_RATIO,CONTROL_METHOD,IR_TIME,IR_READING,ERR_DOWN,ERR_UP,VOLTAGE,TOTAL_READING_ERR,TOTAL_INCREMENT,SUMER_ALL_INCREMENT,SHARP_INCREMENT,PEAK_INCREMENT,FLAT_INCREMENT,VALLEY_INCREMENT,VALUE_CONC_CODE,CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE)\n"
                "values('001','01','001','1','1', '1','1','2015','1','1',  '1','1','1','1','2',   '2015','0','0','0','0',  '0','0','0','0','0',  '0','0','0','1','2015','1','2015');";

        strAct ="INSERT TABLE MT_HUTCHISON_COMBINA_MET_CONC";

        destSql_query( myquery, strExec, strAct  );

        //c7
        strExec ="CREATE TABLE MT_DAYERR_MET_CONC( Num  integer primary key autoincrement ,   DETECT_TASK_NO char(8), EQUIP_CATEG char(8), SYS_NO char(8), DETECT_EQUIP_NO char(8), DETECT_UNIT_NO char(8), POSITION_NO char(8), BAR_CODE char(8), DETECT_DATE char(8), PARA_INDEX char(8), DETECT_ITEM_POINT char(8), IS_VALID char(8), SEC_PILES char(8), TEST_TIME char(8), SIMPLING char(8), ERR_ABS char(8), LOAD_VOLTAGE char(8), ERROR char(8), AVG_ERR char(8), INT_CONVERT_ERR char(8), CONC_CODE char(8), WRITE_DATE char(8), HANDLE_FLAG char(8), HANDLE_DATE char(8));";

        strAct  ="CREATE TABLE MT_DAYERR_MET_CONC";

        destSql_query( myquery, strExec, strAct  );

        strExec ="INSERT INTO MT_DAYERR_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,SEC_PILES,TEST_TIME,SIMPLING,ERR_ABS,LOAD_VOLTAGE,ERROR,AVG_ERR,INT_CONVERT_ERR,CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE)\n"
                "values('001','01','001','1','1', '1','1','2015','1','1',  '1','1','0','0','0',   '0','0','0','0','1',  '2015','1','2015');";

        strAct ="INSERT TABLE MT_DAYERR_MET_CONC";

        destSql_query( myquery, strExec, strAct  );

        //c8
        strExec ="CREATE TABLE MT_POWER_MET_CONC( Num  integer primary key autoincrement  ,   DETECT_TASK_NO char(8), EQUIP_CATEG char(8), SYS_NO char(8), DETECT_EQUIP_NO char(8), DETECT_UNIT_NO char(8), POSITION_NO char(8), BAR_CODE char(8), DETECT_DATE char(8), PARA_INDEX char(8), DETECT_ITEM_POINT char(8), IS_VALID char(8), ERR_ABS char(8), POWER_CONSUM_TYPE char(8), CONC_CODE char(8), WRITE_DATE char(8), HANDLE_FLAG char(8), HANDLE_DATE char(8));";

        strAct  ="CREATE TABLE MT_POWER_MET_CONC";


        destSql_query( myquery, strExec, strAct  );

        strExec ="INSERT INTO MT_POWER_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,ERR_ABS,POWER_CONSUM_TYPE,CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE)\n"
                "values('001','01','001','1','1',  '1','1','2015','1','1',  '1','0','1','1','1',   '2015','1','2015');";

        strAct ="INSERT TABLE MT_POWER_MET_CONC";

        destSql_query( myquery, strExec, strAct  );

//c9
        strExec ="CREATE TABLE MT_STANDARD_MET_CONC( Num  integer primary key autoincrement,    DETECT_TASK_NO char(8), EQUIP_CATEG char(8), SYS_NO char(8), DETECT_EQUIP_NO char(8), DETECT_UNIT_NO char(8), POSITION_NO char(8), BAR_CODE char(8), DETECT_DATE char(8), PARA_INDEX char(8), DETECT_ITEM_POINT char(8), IS_VALID char(8), DATA_FLAG char(8), DETECT_BASIS char(8), SETTING_VALUE char(8), READ_VALUE char(8), CONC_CODE char(8), WRITE_DATE char(8), HANDLE_FLAG char(8), HANDLE_DATE char(8));";

        strAct  ="CREATE TABLE MT_STANDARD_MET_CONC";


        destSql_query( myquery, strExec, strAct  );

        strExec ="INSERT INTO MT_STANDARD_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,DATA_FLAG,DETECT_BASIS,SETTING_VALUE,READ_VALUE,CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE)\n"
                "values('001','01','001','1','1',  '1','1','2015','1','1',  '1','1','0','0','0',   '1','2015','1','2015');";

        strAct ="INSERT TABLE MT_STANDARD_MET_CONC";

        destSql_query( myquery, strExec, strAct  );
//c10
        strExec ="CREATE TABLE MT_WAVE_MET_CONC( Num  integer primary key autoincrement  ,   DETECT_TASK_NO char(8), EQUIP_CATEG char(8), SYS_NO char(8), DETECT_EQUIP_NO char(8), DETECT_UNIT_NO char(8), POSITION_NO char(8), BAR_CODE char(8), DETECT_DATE char(8), PARA_INDEX char(8), DETECT_ITEM_POINT char(8), IS_VALID char(8), CONC_CODE char(8), WRITE_DATE char(8), HANDLE_FLAG char(8), HANDLE_DATE char(8) );";

        strAct  ="CREATE TABLE MT_WAVE_MET_CONC";


        destSql_query( myquery, strExec, strAct  );

        strExec ="INSERT INTO MT_WAVE_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE)\n"
                "values('001','01','001','1','1',  '1','1','2015','1','1',  '1','1','2015','1','2015');";

        strAct ="INSERT TABLE MT_WAVE_MET_CONC";

        destSql_query( myquery, strExec, strAct  );
//c11
        strExec ="CREATE TABLE MT_ERROR_MET_CONC( Num  integer primary key autoincrement , DETECT_TASK_NO char(8), EQUIP_CATEG char(8), SYS_NO char(8), DETECT_EQUIP_NO char(8), DETECT_UNIT_NO char(8), POSITION_NO char(8), BAR_CODE char(8), DETECT_DATE char(8), PARA_INDEX char(8), DETECT_ITEM_POINT char(8), IS_VALID char(8), BOTH_WAY_POWER_FLAG char(8), LOAD_VOLTAGE char(8), LOAD_CURRENT char(8), PF char(8), PULES char(8), SIMPLING char(8), ONCE_ERR char(8), AVG_ONCE_ERR char(8), INT_ONCE_ERR char(8), TWICE_ERR char(8), AVG_TWICE_ERR char(8), ERROR char(8), ERR_DOWN char(8), ERR_UP char(8), INT_TWICE_ERR char(8), CONC_CODE char(8),WRITE_DATE char(8), HANDLE_FLAG char(8), HANDLE_DATE char(8) );";

        strAct  ="CREATE TABLE MT_ERROR_MET_CONC";

        destSql_query( myquery, strExec, strAct  );

        strExec ="INSERT INTO MT_ERROR_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,BOTH_WAY_POWER_FLAG,LOAD_VOLTAGE,LOAD_CURRENT,PF,PULES,SIMPLING,ONCE_ERR,AVG_ONCE_ERR,INT_ONCE_ERR,TWICE_ERR,AVG_TWICE_ERR,ERROR,ERR_DOWN,ERR_UP,INT_TWICE_ERR,CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE)\n"
                "values('001','01','001','1','1',  '1','1','2015','1','1',  '1','0','0','1','1',  '0','0','0','0','0',  '0','0','0','0','0',  '0','1','2015','1','2015');";

        strAct ="INSERT TABLE MT_ERROR_MET_CONC";

        destSql_query( myquery, strExec, strAct  );
//c12

        strExec ="CREATE TABLE MT_CONSIST_MET_CONC( Num  integer primary key autoincrement , DETECT_TASK_NO char(8),EQUIP_CATEG char(8),SYS_NO char(8),DETECT_EQUIP_NO char(8),DETECT_UNIT_NO char(8),POSITION_NO char(8),BAR_CODE char(8),DETECT_DATE char(8),PARA_INDEX char(8),DETECT_ITEM_POINT char(8),IS_VALID char(8),BOTH_WAY_POWER_FLAG char(8),LOAD_VOLTAGE char(8),LOAD_CURRENT char(8),PF char(8),PULES char(8),SIMPLING char(8),ALL_ERROR char(8),AVG_ERROR char(8),INT_CONVERT_ERR char(8),ALL_AVG_ERROR char(8),ALL_INT_ERROR char(8),ERROR char(8),ERR_DOWN char(8),ERR_UP char(8),ONCE_ERR char(8),AVG_ONCE_ERR char(8),INT_ONCE_ERR char(8),TWICE_ERR char(8),AVG_TWICE_ERR char(8),INT_TWICE_ERR char(8),CONC_CODE char(8),WRITE_DATE char(8),HANDLE_FLAG char(8),HANDLE_DATE char(8));";

        strAct  ="CREATE TABLE MT_CONSIST_MET_CONC";

        destSql_query( myquery, strExec, strAct  );

        strExec ="INSERT INTO MT_CONSIST_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,BOTH_WAY_POWER_FLAG,LOAD_VOLTAGE,LOAD_CURRENT,PF,PULES,SIMPLING,ALL_ERROR,AVG_ERROR,INT_CONVERT_ERR,ALL_AVG_ERROR,ALL_INT_ERROR,ERROR,ERR_DOWN,ERR_UP,ONCE_ERR,AVG_ONCE_ERR,INT_ONCE_ERR,TWICE_ERR,AVG_TWICE_ERR,INT_TWICE_ERR,CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE)\n"
                "values('001','01','001','1','1',  '1','1','2015','1','1',  '1','1','0','1','1',  '0','0','0','0','0',  '0','0','0','0','0',  '0','0','0','0','0',  '0','1','2015','1','2015');";

        strAct ="INSERT TABLE MT_CONSIST_MET_CONC";

        destSql_query( myquery, strExec, strAct  );
//c13
        strExec = "CREATE TABLE MT_VARIATION_MET_CONC( Num  integer primary key autoincrement , DETECT_TASK_NO char(8),EQUIP_CATEG char(8),SYS_NO char(8),DETECT_EQUIP_NO char(8),DETECT_UNIT_NO char(8),POSITION_NO char(8),BAR_CODE char(8),DETECT_DATE char(8),PARA_INDEX char(8),DETECT_ITEM_POINT char(8),IS_VALID char(8),BOTH_WAY_POWER_FLAG char(8),LOAD_VOLTAGE char(8),LOAD_CURRENT char(8),IABC char(8),PF char(8),DETECT_CIRCLE char(8),SIMPLING char(8),WAIT_TIME char(8),UP_ERR1 char(8),UP_ERR2 char(8),AVG_UP_ERR char(8),INT_UP_ERR char(8),DOWN_ERR1 char(8),DOWN_ERR2 char(8),AVG_DOWN_ERR char(8),INT_DOWN_ERR char(8),VARIATION_ERR char(8),INT_VARIATION_ERR char(8),CONC_CODE char(8),WRITE_DATE char(8),HANDLE_FLAG char(8),HANDLE_DATE char(8));";

        strAct  = "CREATE TABLE MT_VARIATION_MET_CONC";

        destSql_query( myquery, strExec, strAct  );

        strExec ="INSERT INTO MT_VARIATION_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,BOTH_WAY_POWER_FLAG,LOAD_VOLTAGE,LOAD_CURRENT,IABC,PF,DETECT_CIRCLE,SIMPLING,WAIT_TIME,UP_ERR1,UP_ERR2,AVG_UP_ERR,INT_UP_ERR,DOWN_ERR1,DOWN_ERR2,AVG_DOWN_ERR,INT_DOWN_ERR,VARIATION_ERR,INT_VARIATION_ERR,CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE)\n"
                "values('001','01','001','1','1',  '1','1','2015','1','1',  '1','0','0','1','1',  '1','0','0','2015','0',  '0','0','0','0','0',  '0','0','0','0','1' ,'2015','1','2015');";

        strAct ="INSERT TABLE MT_VARIATION_MET_CONC";

        destSql_query( myquery, strExec, strAct  );
//c14
        strExec = "CREATE TABLE MT_OVERLOAD_MET_CONC( Num  integer primary key autoincrement , DETECT_TASK_NO char(8),EQUIP_CATEG char(8),SYS_NO char(8),DETECT_EQUIP_NO char(8),DETECT_UNIT_NO char(8),POSITION_NO char(8),BAR_CODE char(8),DETECT_DATE char(8),PARA_INDEX char(8),DETECT_ITEM_POINT char(8),IS_VALID char(8),LOAD_VOLTAGE char(8),LOAD_CURRENT char(8),PF char(8),PULES char(8),SIMPLING char(8),OVERLOAD_TIME char(8),WAIT_TIME char(8),ERROR char(8),ERR_DOWN char(8),ERR_UP char(8),AVG_ERR char(8),INT_CONVERTER_ERR char(8),CONC_CODE char(8),WRITE_DATE char(8),HANDLE_FLAG char(8),HANDLE_DATE char(8));";

        strAct  = "CREATE TABLE MT_OVERLOAD_MET_CONC";

        destSql_query( myquery, strExec, strAct  );

        strExec ="INSERT INTO MT_OVERLOAD_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,LOAD_VOLTAGE,LOAD_CURRENT,PF,PULES,SIMPLING,OVERLOAD_TIME,WAIT_TIME,ERROR,ERR_DOWN,ERR_UP,AVG_ERR,INT_CONVERTER_ERR,CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE)\n"
                "values('001','01','001','1','1',  '1','1','2015','1','1',  '1','0','1','1','0',  '0','0','0','0','0',  '0','0','0','1' ,'2015','1','2015');";

        strAct ="INSERT TABLE MT_OVERLOAD_MET_CONC";
//c15
        strExec = "CREATE TABLE MT_TS_MET_CONC( Num  integer primary key autoincrement , DETECT_TASK_NO char(8),EQUIP_CATEG char(8),SYS_NO char(8),DETECT_EQUIP_NO char(8),DETECT_UNIT_NO char(8),POSITION_NO char(8),BAR_CODE char(8),DETECT_DATE char(8),PARA_INDEX char(8),DETECT_ITEM_POINT char(8),IS_VALID char(8),TS_ERR_CONC_CODE char(8),CONC_CODE char(8),WRITE_DATE char(8),HANDLE_FLAG char(8),HANDLE_DATE char(8),VOLT char(8),TS_WAY char(8),START_TIME char(8),TS_START_TIME char(8),TS_ERR char(8),ERR_UP char(8),ERR_DOWM char(8),TS_REAL_TIME char(8),FEE char(8));";

       strAct  = "CREATE TABLE MT_TS_MET_CONC";

       destSql_query( myquery, strExec, strAct  );

       strExec ="INSERT INTO MT_TS_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,TS_ERR_CONC_CODE,CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE,VOLT,TS_WAY,START_TIME,TS_START_TIME,TS_ERR,ERR_UP,ERR_DOWM,TS_REAL_TIME,FEE)\n"
               "values('001','01','001','1','1',  '1','1','2015','1','1',  '1','0','1','2015','1',  '2015','0','0','0','0'  ,'0','0','0','2015','1');";

       strAct ="INSERT TABLE MT_TS_MET_CONC";

       destSql_query( myquery, strExec, strAct  );
//c16
       strExec = "CREATE TABLE MT_MEASURE_REPEAT_MET_CONC( Num  integer primary key autoincrement ,DETECT_TASK_NO char(8),EQUIP_CATEG char(8),SYS_NO char(8),DETECT_EQUIP_NO char(8),DETECT_UNIT_NO char(8),POSITION_NO char(8),BAR_CODE char(8),DETECT_DATE char(8),PARA_INDEX char(8),DETECT_ITEM_POINT char(8),IS_VALID char(8),VOLT char(8),BOTH_WAY_POWER_FLAG char(8),LOAD_CURRENT char(8),LOAD_VOLTAGE char(8),FREQ char(8),PF char(8),SIMPLING char(8),DEVIATION_LIMT char(8),CONC_CODE char(8),WRITE_DATE char(8),HANDLE_FLAG char(8),HANDLE_DATE char(8));";

       strAct  = "CREATE TABLE MT_MEASURE_REPEAT_MET_CONC";

       destSql_query( myquery, strExec, strAct  );

       strExec ="INSERT INTO MT_MEASURE_REPEAT_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,VOLT,BOTH_WAY_POWER_FLAG,LOAD_CURRENT,LOAD_VOLTAGE,FREQ,PF,SIMPLING,DEVIATION_LIMT,CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE)\n"
               "values('001','01','001','1','1',  '1','1','2015','1','1',  '1','0','0','1','0',  '1','1','0','0','1'  ,'2015','1','2015');";

       strAct ="INSERT TABLE MT_MEASURE_REPEAT_MET_CONC";

       destSql_query( myquery, strExec, strAct  );

//c17
       strExec = "CREATE TABLE MT_MAX_DEMAND_ERR_MET_CONC( Num  integer primary key autoincrement  ,DETECT_TASK_NO char(8),EQUIP_CATEG char(8),SYS_NO char(8),DETECT_EQUIP_NO char(8),DETECT_UNIT_NO char(8),POSITION_NO char(8),BAR_CODE char(8),DETECT_DATE char(8),PARA_INDEX char(8),DETECT_ITEM_POINT char(8),IS_VALID char(8),LOAD_CURRENT char(8),LOAD_VOLTAGE char(8),FREQ char(8),PF char(8),ERROR char(8),AVG_ERR char(8),INT_CONVERT_ERR char(8),CONC_CODE char(8),WRITE_DATE char(8),HANDLE_FLAG char(8),HANDLE_DATE char(8));";

       strAct  = "CREATE TABLE MT_MAX_DEMAND_ERR_MET_CONC";

       destSql_query( myquery, strExec, strAct  );

       strExec ="INSERT INTO MT_MAX_DEMAND_ERR_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,LOAD_CURRENT,LOAD_VOLTAGE,FREQ,PF,ERROR,AVG_ERR,INT_CONVERT_ERR,CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE)\n"
               "values('001','01','001','1','1',  '1','1','2015','1','1',  '1','1','0','1','1',  '0','0','0','0' ,'2015',  '1','2015');";

       strAct ="INSERT TABLE MT_MAX_DEMAND_ERR_MET_CONC";

       destSql_query( myquery, strExec, strAct  );
//c18
       strExec = "CREATE TABLE MT_ESAM_MET_CONC( Num  integer primary key autoincrement  ,DETECT_TASK_NO char(8),EQUIP_CATEG char(8),SYS_NO char(8),DETECT_EQUIP_NO char(8),DETECT_UNIT_NO char(8),POSITION_NO char(8),BAR_CODE char(8),DETECT_DATE char(8),PARA_INDEX char(8),DETECT_ITEM_POINT char(8),IS_VALID char(8),CONC_CODE char(8),WRITE_DATE char(8),HANDLE_FLAG char(8),HANDLE_DATE char(8),LOAD_VOLTAGE char(8),KEY_TYPE char(8),KEY_STATUS char(8),KEY_NUM char(8),KEY_VER char(8));";

       strAct  = "CREATE TABLE MT_ESAM_MET_CONC";

       destSql_query( myquery, strExec, strAct  );

       strExec ="INSERT INTO MT_ESAM_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE,LOAD_VOLTAGE,KEY_TYPE,KEY_STATUS,KEY_NUM,KEY_VER)\n"
               "values('001','01','001','1','1',  '1','1','2015','1','1',  '1','1','2015','1','2015',  '0','1','1','1' ,'1');";

       strAct ="INSERT TABLE MT_ESAM_MET_CONC";

       destSql_query( myquery, strExec, strAct  );
//c19
       strExec = "CREATE TABLE MT_EQ_MET_CONC( Num  integer primary key autoincrement  ,DETECT_TASK_NO char(8),EQUIP_CATEG char(8),SYS_NO char(8),DETECT_EQUIP_NO char(8),DETECT_UNIT_NO char(8),POSITION_NO char(8),BAR_CODE char(8),DETECT_DATE char(8),PARA_INDEX char(8),DETECT_ITEM_POINT char(8),IS_VALID char(8),TOTAL_EQ char(8),SURPLUS_EQ char(8),CURR_ELEC_PRICE char(8),LOAD_CURRENT char(8),PF char(8),CONC_CODE char(8),WRITE_DATE char(8),HANDLE_FLAG char(8),HANDLE_DATE char(8));";

       strAct  = "CREATE TABLE MT_EQ_MET_CONC";

       destSql_query( myquery, strExec, strAct  );

       strExec ="INSERT INTO MT_EQ_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,TOTAL_EQ,SURPLUS_EQ,CURR_ELEC_PRICE,LOAD_CURRENT,PF,CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE)\n"
       "values('001','01','001','1','1',  '1','1','2015','1','1',  '1','0','0','0','1',  '1','1','2015','1' ,'2015');";

       strAct ="INSERT TABLE MT_EQ_MET_CONC";

       destSql_query( myquery, strExec, strAct  );
//c20
       strExec = "CREATE TABLE MT_COMMINICATE_MET_CONC( Num  integer primary key autoincrement   ,DETECT_TASK_NO char(8),EQUIP_CATEG char(8),SYS_NO char(8),DETECT_EQUIP_NO char(8),DETECT_UNIT_NO char(8),POSITION_NO char(8),BAR_CODE char(8),DETECT_DATE char(8),PARA_INDEX char(8),DETECT_ITEM_POINT char(8),IS_VALID char(8),CONC_CODE char(8),WRITE_DATE char(8),HANDLE_FLAG char(8),HANDLE_DATE char(8));";

       strAct  = "CREATE TABLE MT_COMMINICATE_MET_CONC";

       destSql_query( myquery, strExec, strAct  );

       strExec ="INSERT INTO  MT_COMMINICATE_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE)\n"
       "values('001','01','001','1','1',  '1','1','2015','1','1',  '1','1','2015','1','2015');";

       strAct ="INSERT INTO  MT_COMMINICATE_MET_CONC";

       destSql_query( myquery, strExec, strAct  );

//c21
       strExec = "CREATE TABLE MT_ESAM_SECURITY_MET_CONC( Num  integer primary key autoincrement  ,DETECT_TASK_NO char(8),EQUIP_CATEG char(8),SYS_NO char(8),DETECT_EQUIP_NO char(8),DETECT_UNIT_NO char(8),POSITION_NO char(8),BAR_CODE char(8),DETECT_DATE char(8),PARA_INDEX char(8),DETECT_ITEM_POINT char(8),IS_VALID char(8),ESAM_ID char(8),CONC_CODE char(8),WRITE_DATE char(8),HANDLE_FLAG char(8),HANDLE_DATE char(8));";

       strAct  = "CREATE TABLE MT_ESAM_SECURITY_MET_CONC";

       destSql_query( myquery, strExec, strAct  );

       strExec ="INSERT INTO  MT_ESAM_SECURITY_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,ESAM_ID,CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE)\n"
               "values('001','01','001','1','1',  '1','1','2015','1','1',  '1','0','1','2015','1', '0');";

       strAct ="INSERT INTO  MT_ESAM_SECURITY_MET_CONC";

       destSql_query( myquery, strExec, strAct  );
//c22
       strExec = "CREATE TABLE MT_PRESETPARAM_MET_CONC( Num  integer primary key autoincrement  ,DATA_ITEM_NAME char(8),DATA_IDENTION char(8),CONTROL_CODE char(8),DATA_FORMAT char(8),IS_DATA_BLOCK char(8),STANDARD_VALUE char(8),DELAY_WAIT_TIME char(8),PASSWORD char(8),DETECT_TASK_NO char(8),EQUIP_CATEG char(8),SYS_NO char(8),DETECT_EQUIP_NO char(8),DETECT_UNIT_NO char(8),POSITION_NO char(8),BAR_CODE char(8),DETECT_DATE char(8),PARA_INDEX char(8),DETECT_ITEM_POINT char(8),IS_VALID char(8),CONC_CODE char(8),WRITE_DATE char(8),HANDLE_FLAG char(8),HANDLE_DATE char(8));";

       strAct  = "CREATE TABLE MT_PRESETPARAM_MET_CONC";

       destSql_query( myquery, strExec, strAct  );

       strExec ="INSERT INTO  MT_PRESETPARAM_MET_CONC(DATA_ITEM_NAME,DATA_IDENTION,CONTROL_CODE,DATA_FORMAT,IS_DATA_BLOCK,STANDARD_VALUE,DELAY_WAIT_TIME,PASSWORD,DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE)\n"
               "values('0','0','0','0','0',  '0','0','0','1','1',  '1','1','1','1','1', '2015','1','1','1','1', '2015','1','2015');";

       strAct ="INSERT INTO  MT_PRESETPARAM_MET_CONC";

       destSql_query( myquery, strExec, strAct  );
//c23
       strExec = "CREATE TABLE MT_VOLT_MET_CONC( Num  integer primary key autoincrement  ,DETECT_TASK_NO char(8),EQUIP_CATEG char(8),SYS_NO char(8),DETECT_EQUIP_NO char(8),DETECT_UNIT_NO char(8),POSITION_NO char(8),BAR_CODE char(8),DETECT_DATE char(8),PARA_INDEX char(8),DETECT_ITEM_POINT char(8),IS_VALID char(8),VOLT_TEST_VALUE char(8),VOLT_OBJ char(8),TEST_TIME char(8),CONC_CODE char(8),REMARK char(8),WRITE_DATE char(8),HANDLE_FLAG char(8),HANDLE_DATE char(8),LEAK_CURRENT_LIMIT char(8),POSITION_LEAK_LIMIT char(8));";

       strAct  = "CREATE TABLE MT_VOLT_MET_CONC";

       destSql_query( myquery, strExec, strAct  );

       strExec ="INSERT INTO  MT_VOLT_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,VOLT_TEST_VALUE,VOLT_OBJ,TEST_TIME,CONC_CODE,REMARK,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE,LEAK_CURRENT_LIMIT,POSITION_LEAK_LIMIT)\n"
               "values('001','01','001','1','1',  '1','1','2015','1','1',  '1','0','1','2015','1', '0','2015','1','2015','0',  '0');";

       strAct ="INSERT INTO  MT_VOLT_MET_CONC";

       destSql_query( myquery, strExec, strAct  );
//c24
       strExec = "CREATE TABLE MT_EVENT_RECORD_MET_CONC( Num  integer primary key autoincrement ,DETECT_TASK_NO char(8),EQUIP_CATEG char(8),SYS_NO char(8),DETECT_EQUIP_NO char(8),DETECT_UNIT_NO char(8),POSITION_NO char(8),BAR_CODE char(8),DETECT_DATE char(8),PARA_INDEX char(8),DETECT_ITEM_POINT char(8),IS_VALID char(8),LOAD_CURRENT char(8),PF char(8),SIMPLING char(8),OVERLOAD_TIME char(8),RECOVER_TIME char(8),ERR_UP char(8),ERR_DOWN char(8),CONC_CODE char(8),IR_PULES char(8),WRITE_DATE char(8),HANDLE_FLAG char(8),HANDLE_DATE char(8));";

       strAct  = "CREATE TABLE MT_EVENT_RECORD_MET_CONC";

       destSql_query( myquery, strExec, strAct  );

       strExec ="INSERT INTO  MT_EVENT_RECORD_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,LOAD_CURRENT,PF,SIMPLING,OVERLOAD_TIME,RECOVER_TIME,ERR_UP,ERR_DOWN,CONC_CODE,IR_PULES,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE)\n"
               "values('001','01','001','1','1',  '1','1','2015','1','1',  '1','0','1','0','0', '0','0','0','1','0',  '2015','1','2015');";

       strAct ="INSERT INTO  MT_EVENT_RECORD_MET_CONC";

       destSql_query( myquery, strExec, strAct  );
//c25
       strExec = "CREATE TABLE  MT_INFLUENCE_QTY_MET_CONC( Num  integer primary key autoincrement ,DETECT_TASK_NO char(8),EQUIP_CATEG char(8),SYS_NO char(8),DETECT_EQUIP_NO char(8),DETECT_UNIT_NO char(8),POSITION_NO char(8),BAR_CODE char(8),DETECT_DATE char(8),PARA_INDEX char(8),DETECT_ITEM_POINT char(8),IS_VALID char(8),CHK_CONC_CODE char(8),ORG_NO char(8),AREA_CODE char(8),EFFECT_TEST_ITEM char(8),WRITE_DATE char(8),HANDLE_FLAG char(8),HANDLE_DATE char(8));";

       strAct  = "CREATE TABLE  MT_INFLUENCE_QTY_MET_CONC";

       destSql_query( myquery, strExec, strAct  );

       strExec ="INSERT INTO  MT_INFLUENCE_QTY_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,CHK_CONC_CODE,ORG_NO,AREA_CODE,EFFECT_TEST_ITEM,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE)\n"
               "values('001','01','001','1','1',  '1','1','2015','1','1',  '1','1','0','0','1',  '2015','1','2015');";

       strAct ="INSERT INTO  MT_INFLUENCE_QTY_MET_CONC";

       destSql_query( myquery, strExec, strAct  );
//c26
       strExec = "CREATE TABLE  MT_PASSWORD_CHANGE_MET_CONC( Num  integer primary key autoincrement  ,PASSWORD_LEVEL char(8),OLD_PASSWORD char(8),NEW_PASSWORD char(8),DETECT_TASK_NO char(8),EQUIP_CATEG char(8),SYS_NO char(8),DETECT_EQUIP_NO char(8),DETECT_UNIT_NO char(8),POSITION_NO char(8),BAR_CODE char(8),DETECT_DATE char(8),PARA_INDEX char(8),DETECT_ITEM_POINT char(8),IS_VALID char(8),CONC_CODE char(8),WRITE_DATE char(8),HANDLE_FLAG char(8),HANDLE_DATE char(8));";

       strAct  = "CREATE TABLE  MT_PASSWORD_CHANGE_MET_CONC";


       destSql_query( myquery, strExec, strAct  );

       strExec ="INSERT INTO  MT_PASSWORD_CHANGE_MET_CONC(PASSWORD_LEVEL,OLD_PASSWORD,NEW_PASSWORD,DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE)\n"
               "values('0','0','0','0','0',  '0','0','0','0','0',  '2015','1','1','1','1',  '2015','1','2015');";

       strAct ="INSERT INTO  MT_PASSWORD_CHANGE_MET_CONC";

       destSql_query( myquery, strExec, strAct  );
//c27
       strExec = "CREATE TABLE  MT_FEE_MET_CONC( Num  integer primary key autoincrement  ,DETECT_TASK_NO char(8),EQUIP_CATEG char(8),SYS_NO char(8),DETECT_EQUIP_NO char(8),DETECT_UNIT_NO char(8),POSITION_NO char(8),BAR_CODE char(8),DETECT_DATE char(8),PARA_INDEX char(8),DETECT_ITEM_POINT char(8),IS_VALID char(8),CONC_CODE char(8),PF char(8),CUR_PHASE_CODE char(8),LOAD_CURRENT char(8),BOTH_WAY_POWER_FLAG char(8),WRITE_DATE char(8),HANDLE_FLAG char(8),HANDLE_DATE char(8));";

       strAct  = "CREATE TABLE  MT_FEE_MET_CONC";


       destSql_query( myquery, strExec, strAct  );

       strExec ="INSERT INTO  MT_FEE_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,CONC_CODE,PF,CUR_PHASE_CODE,LOAD_CURRENT,BOTH_WAY_POWER_FLAG,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE)\n"
               "values('001','01','001','1','1',  '1','1','2015','1','1', '1','1','1','1','0', '0','2015','1','2015');";

       strAct ="INSERT INTO  MT_FEE_MET_CONC";

       destSql_query( myquery, strExec, strAct  );
//c28
       strExec = "CREATE TABLE  MT_ESAM_READ_MET_CONC( Num  integer primary key autoincrement  ,DETECT_TASK_NO char(8),EQUIP_CATEG char(8),SYS_NO char(8),DETECT_EQUIP_NO char(8),DETECT_UNIT_NO char(8),POSITION_NO char(8),BAR_CODE char(8),DETECT_DATE char(8),PARA_INDEX char(8),DETECT_ITEM_POINT char(8),IS_VALID char(8),CONC_CODE char(8),WRITE_DATE char(8),HANDLE_FLAG char(8),HANDLE_DATE char(8),LOAD_VOLTAGE char(8),LOAD_CURRENT char(8),PF char(8),TEST_ITEM char(8),TEST_METHOD_DIFFER char(8),TRIP_DELAY_TIME char(8));";

       strAct  = "CREATE TABLE  MT_ESAM_READ_MET_CONC";


       destSql_query( myquery, strExec, strAct  );

       strExec ="INSERT INTO  MT_ESAM_READ_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE,LOAD_VOLTAGE,LOAD_CURRENT,PF,TEST_ITEM,TEST_METHOD_DIFFER,TRIP_DELAY_TIME)\n"
               "values('001','01','001','1','1',  '1','1','2015','1','1', '1','2015','1','1','1','1', '0','1','1','1','0');";

       strAct ="INSERT INTO  MT_ESAM_READ_MET_CONC";

       destSql_query( myquery, strExec, strAct  );
//c29
       strExec = "CREATE TABLE  MT_PRESETPARAM_CHECK_MET_CONC( Num  integer primary key autoincrement   ,DATA_ITEM_NAME char(8),DATA_IDENTION char(8),CONTROL_CODE char(8),DATA_FORMAT char(8),IS_DATA_BLOCK char(8),STANDARD_VALUE char(8),REAL_VALUE char(8),DETER_UPPER_LIMIT char(8),DETER_LOWER_LIMIT char(8),CONC_CODE char(8),WRITE_DATE char(8),HANDLE_FLAG char(8),HANDLE_DATE char(8),DETECT_TASK_NO char(8),EQUIP_CATEG char(8),SYS_NO char(8),DETECT_EQUIP_NO char(8),DETECT_UNIT_NO char(8),POSITION_NO char(8),BAR_CODE char(8),DETECT_DATE char(8),PARA_INDEX char(8),DETECT_ITEM_POINT char(8));";

       strAct  = "CREATE TABLE  MT_PRESETPARAM_CHECK_MET_CONC";


       destSql_query( myquery, strExec, strAct  );

       strExec ="INSERT INTO  MT_PRESETPARAM_CHECK_MET_CONC(DATA_ITEM_NAME,DATA_IDENTION,CONTROL_CODE,DATA_FORMAT,IS_DATA_BLOCK,STANDARD_VALUE,REAL_VALUE,DETER_UPPER_LIMIT,DETER_LOWER_LIMIT,CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE,DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT)\n"
               "values('0','0','0','0','0',  '0','0','0','0','1',  '2015','1','2015','1','1',  '1', '1','1','1','1', '2015','1','1');";

       strAct ="INSERT INTO  MT_PRESETPARAM_CHECK_MET_CONC";

       destSql_query( myquery, strExec, strAct  );

//c30

       strExec = "CREATE TABLE  MT_POWER_MEASURE_MET_CONC( Num  integer primary key autoincrement  ,DETECT_TASK_NO char(8),EQUIP_CATEG char(8),SYS_NO char(8),DETECT_EQUIP_NO char(8),DETECT_UNIT_NO char(8),POSITION_NO char(8),BAR_CODE char(8),DETECT_DATE char(8),PARA_INDEX char(8),DETECT_ITEM_POINT char(8),IS_VALID char(8),CONC_CODE char(8),CUR_PHASE_CODE char(8),CONSIST_DOWN char(8),CONSIST_UP char(8),VOLT_RATIO char(8),ERR_DOWN char(8),ERR_UP char(8),SIMPLING_SPACE char(8),SIMPLING char(8),PF char(8),LOAD_CURRENT char(8),BOTH_WAY_POWER_FLAG char(8),WRITE_DATE char(8),HANDLE_FLAG char(8),HANDLE_DATE char(8));";

       strAct  = "CREATE TABLE  MT_POWER_MEASURE_MET_CONC";


       destSql_query( myquery, strExec, strAct  );

       strExec ="INSERT INTO  MT_POWER_MEASURE_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,CONC_CODE,CUR_PHASE_CODE,CONSIST_DOWN,CONSIST_UP,VOLT_RATIO,ERR_DOWN,ERR_UP,SIMPLING_SPACE,SIMPLING,PF,LOAD_CURRENT,BOTH_WAY_POWER_FLAG,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE)\n"
               "values('001','01','001','1','1',  '1','1','2015','1','1',  '1','1','1','0','0',  '0','0','0','0','0',  '1','0','0','2015','0', '2015');";

       strAct ="INSERT INTO  MT_POWER_MEASURE_MET_CONC";

       destSql_query( myquery, strExec, strAct  );
//c31
       strExec = "CREATE TABLE  MT_DEMAND_MET_CONC( Num  integer primary key autoincrement  ,DETECT_TASK_NO char(8),EQUIP_CATEG char(8),SYS_NO char(8),DETECT_EQUIP_NO char(8),DETECT_UNIT_NO char(8),POSITION_NO char(8),BAR_CODE char(8),DETECT_DATE char(8),PARA_INDEX char(8),DETECT_ITEM_POINT char(8),IS_VALID char(8),DEMAND_PERIOD char(8),DEMAND_TIME char(8),DEMAND_INTERVAL char(8),REAL_DEMAND char(8),REAL_PERIOD char(8),DEMAND_PERIOD_ERR char(8),DEMAND_STANDARD char(8),DEMAND_PERIOD_ERR_ABS char(8),CLEAR_DATA_RST char(8),PERIOD_CONC_CODE char(8),BOTH_WAY_POWER_FLAG char(8),CONTROL_METHOD char(8),LOAD_CURRENT char(8),VOLTAGE char(8),FREQ char(8),PF char(8),ERR_UP char(8),ERR_DOWM char(8),INT_CONVERT_ERR char(8),CONC_CODE char(8),WRITE_DATE char(8),HANDLE_FLAG char(8),HANDLE_DATE char(8));";

       strAct  = "CREATE TABLE  MT_DEMAND_MET_CONC";


       destSql_query( myquery, strExec, strAct  );

       strExec ="INSERT INTO  MT_DEMAND_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,DEMAND_PERIOD,DEMAND_TIME,DEMAND_INTERVAL,REAL_DEMAND,REAL_PERIOD,DEMAND_PERIOD_ERR,DEMAND_STANDARD,DEMAND_PERIOD_ERR_ABS,CLEAR_DATA_RST,PERIOD_CONC_CODE,BOTH_WAY_POWER_FLAG,CONTROL_METHOD,LOAD_CURRENT,VOLTAGE,FREQ,PF,ERR_UP,ERR_DOWM,INT_CONVERT_ERR,CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE)\n"
               "values('001','01','001','1','1',  '1','1','2015','1','1',  '1','0','0','0','0',  '0','0','0','0','0',  '0','0','1','0','1', '1','1','0','0','0',  '1','2015','1','2015');";

       strAct ="INSERT INTO  MT_DEMAND_MET_CONC";

       destSql_query( myquery, strExec, strAct  );

//c32

       strExec = "CREATE TABLE  MT_DEMANDVALUE_MET_CONC( Num  integer primary key autoincrement  ,DETECT_TASK_NO char(8),EQUIP_CATEG char(8),SYS_NO char(8),DETECT_EQUIP_NO char(8),DETECT_UNIT_NO char(8),POSITION_NO char(8),BAR_CODE char(8),DETECT_DATE char(8),PARA_INDEX char(8),DETECT_ITEM_POINT char(8),IS_VALID char(8),DEMAND_PERIOD char(8),DEMAND_TIME char(8),DEMAND_INTERVAL char(8),REAL_DEMAND char(8),REAL_PERIOD char(8),DEMAND_VALUE_ERR char(8),DEMAND_STANDARD char(8),DEMAND_VALUE_ERR_ABS char(8),CLEAR_DATA_RST char(8),VALUE_CONC_CODE char(8),WRITE_DATE char(8),HANDLE_FLAG char(8),HANDLE_DATE char(8),BOTH_WAY_POWER_FLAG char(8),VOLTAGE char(8),LOAD_CURRENT char(8),PF char(8),CONTROL_METHOD char(8),ERR_UP char(8),ERR_DOWM char(8),CHK_CONC_CODE char(8));";

       strAct  = "CREATE TABLE  MT_DEMANDVALUE_MET_CONC";


       destSql_query( myquery, strExec, strAct  );

       strExec ="INSERT INTO  MT_DEMANDVALUE_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,DEMAND_PERIOD,DEMAND_TIME,DEMAND_INTERVAL,REAL_DEMAND,REAL_PERIOD,DEMAND_VALUE_ERR,DEMAND_STANDARD,DEMAND_VALUE_ERR_ABS,CLEAR_DATA_RST,VALUE_CONC_CODE,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE,BOTH_WAY_POWER_FLAG,VOLTAGE,LOAD_CURRENT,PF,CONTROL_METHOD,ERR_UP,ERR_DOWM,CHK_CONC_CODE)\n"
               "values('001','01','001','1','1',  '1','1','2015','1','1',  '1','2015','0','0','0',  '0','0','0','0','0',  '0','0','1','2015','0', '0','1','1','0','0', '0','1');";

       strAct ="INSERT INTO  MT_DEMANDVALUE_MET_CONC";

       destSql_query( myquery, strExec, strAct  );
//c33
       strExec = "CREATE TABLE  MT_MAX_DEMANDVALUE_MET_CONC( Num  integer primary key autoincrement   ,DETECT_TASK_NO char(8),EQUIP_CATEG char(8),SYS_NO char(8),DETECT_EQUIP_NO char(8),DETECT_UNIT_NO char(8),POSITION_NO char(8),BAR_CODE char(8),DETECT_DATE char(8),PARA_INDEX char(8),DETECT_ITEM_POINT char(8),IS_VALID char(8),CONC_CODE char(8),CUR_PHASE_CODE char(8),LOAD_CURRENT char(8),BOTH_WAY_POWER_FLAG char(8),WRITE_DATE char(8),HANDLE_FLAG char(8),HANDLE_DATE char(8));";

       strAct  = "CREATE TABLE  MT_MAX_DEMANDVALUE_MET_CONC";



       destSql_query( myquery, strExec, strAct  );

       strExec ="INSERT INTO  MT_MAX_DEMANDVALUE_MET_CONC(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,PARA_INDEX,DETECT_ITEM_POINT,IS_VALID,CONC_CODE,CUR_PHASE_CODE,LOAD_CURRENT,BOTH_WAY_POWER_FLAG,WRITE_DATE,HANDLE_FLAG,HANDLE_DATE)\n"
               "values('001','01','001','1','1',  '1','1','2015','1','1',  '1','1','1','1','0',  '2015','1','2015');";

       strAct ="INSERT INTO  MT_MAX_DEMANDVALUE_MET_CONC";

       destSql_query( myquery, strExec, strAct  );
//c34

       strExec = "CREATE TABLE  MT_DETECT_RSLT( Num  integer primary key autoincrement  ,DETECT_TASK_NO char(8),EQUIP_CATEG char(8),SYS_NO char(8),DETECT_EQUIP_NO char(8),DETECT_UNIT_NO char(8),POSITION_NO char(8),BAR_CODE char(8),DETECT_DATE char(8),CONC_CODE char(8),INTUIT_CONC_CODE char(8),BASICERR_CONC_CODE char(8),CONST_CONC_CODE char(8),STARTING_CONC_CODE char(8),CREEPING_CONC_CODE char(8),DAYERR_CONC_CODE char(8),POWER_CONC_CODE char(8),VOLT_CONC_CODE char(8),STANDARD_CONC_CODE char(8),WAVE_CONC_CODE char(8),ERROR_CONC_CODE char(8),CONSIST_CONC_CODE char(8),VARIATION_CONC_CODE char(8),OVERLOAD_CONC_CODE char(8),TS_CONC_CODE char(8),RUNING_CONC_CODE char(8),PERIOD_CONC_CODE char(8),VALUE_CONC_CODE char(8),KEY_CONC_CODE char(8),ESAM_CONC_CODE char(8),REMOTE_CONC_CODE char(8),EH_CONC_CODE char(8),EC_CONC_CODE char(8),SWITCH_ON_CONC_CODE char(8),SWITCH_OUT_CONC_CODE char(8),WARN_CONC_CODE char(8),WARN_CANCEL_CONC_CODE char(8),SURPLUS_CONC_CODE char(8),RESET_EQ_MET_CONC_CODE char(8),INFRARED_TEST_CONC_CODE char(8),RESET_DEMAND_MET_CONC_CODE char(8),TIMING_MET_CONC_CODE char(8),COMMINICATE_MET_CONC_CODE char(8),ADDRESS_MET_CONC_CODE char(8),MULTI_INTERFACE_MET_CONC_CODE char(8),LEAP_YEAR_MET_CONC char(8),PARA_READ_MET_CONC_CODE char(8),PARA_SET_MET_CONC char(8),SETTING_CONC_CODE char(8),DEVIATION_MET_CONC char(8),GPS_CONC char(8),DETECT_PERSON char(8),AUDIT_PERSON char(8),WRITE_DATE char(8),SEAL_HANDLE_FLAG char(8),SEAL_HANDLE_DATE char(8),HANDLE_FLAG char(8),HANDLE_DATE char(8),TEMP char(8),HUMIDITY char(8),PRESET_PARAMET_CHECK_CONC_CODE char(8),PASSWORD_CHANGE_CONC_CODE char(8),PRESET_PARAMETER_SET_CONC_CODE char(8),RELIABILITY_CONC_CODE char(8),MOVE_STABILITY_TEST_CONC_CODE char(8),ANTI_SEISMICTEST_CONC_CODE char(8),PRESET_PARAM2_CHECK_CONC_CODE char(8),PRESET_PARAM3_CHECK_CONC_CODE char(8),PRESET_PARAM2_SET_CONC_CODE char(8),PRESET_PARAM3_SET_CONC_CODE char(8),HARD_VERSION char(8),FAULT_TYPE char(8),EVENT_REC_FUNC_CONC_CODE char(8),INFLUENCE_QTY_CONC_CODE char(8),AUX_POW_CONC_CODE char(8),ALARM_FUNC_CONC_CODE char(8),RATE_TIME_FUNC_CONC_CODE char(8),ELE_ENERGY_FUNC_CONC_CODE char(8),EXPIRATION_DATE char(8),MEA_REP_CONC_CODE char(8),CERT_NO char(8),CERT_NO_PERIOD char(8),UNPASS_REASON char(8),COMM_MODE_CHG_CONC_CODE char(8),COMM_MODE_INT_CONC_CODE char(8),FROZEN_FUNC_CONC_CODE char(8));";

       strAct  = "CREATE TABLE  MT_DETECT_RSLT";

       destSql_query( myquery, strExec, strAct  );

       strExec ="INSERT INTO  MT_DETECT_RSLT(DETECT_TASK_NO,EQUIP_CATEG,SYS_NO,DETECT_EQUIP_NO,DETECT_UNIT_NO,POSITION_NO,BAR_CODE,DETECT_DATE,CONC_CODE,INTUIT_CONC_CODE,BASICERR_CONC_CODE,CONST_CONC_CODE,STARTING_CONC_CODE,CREEPING_CONC_CODE,DAYERR_CONC_CODE,POWER_CONC_CODE,VOLT_CONC_CODE,STANDARD_CONC_CODE,WAVE_CONC_CODE,ERROR_CONC_CODE,CONSIST_CONC_CODE,VARIATION_CONC_CODE,OVERLOAD_CONC_CODE,TS_CONC_CODE,RUNING_CONC_CODE,PERIOD_CONC_CODE,VALUE_CONC_CODE,KEY_CONC_CODE,ESAM_CONC_CODE,REMOTE_CONC_CODE,EH_CONC_CODE,EC_CONC_CODE,SWITCH_ON_CONC_CODE,SWITCH_OUT_CONC_CODE,WARN_CONC_CODE,WARN_CANCEL_CONC_CODE,SURPLUS_CONC_CODE,RESET_EQ_MET_CONC_CODE,INFRARED_TEST_CONC_CODE,RESET_DEMAND_MET_CONC_CODE,TIMING_MET_CONC_CODE,COMMINICATE_MET_CONC_CODE,ADDRESS_MET_CONC_CODE,MULTI_INTERFACE_MET_CONC_CODE,LEAP_YEAR_MET_CONC,PARA_READ_MET_CONC_CODE,PARA_SET_MET_CONC,SETTING_CONC_CODE,DEVIATION_MET_CONC,GPS_CONC,DETECT_PERSON,AUDIT_PERSON,WRITE_DATE,SEAL_HANDLE_FLAG,SEAL_HANDLE_DATE,HANDLE_FLAG,HANDLE_DATE,TEMP,HUMIDITY,PRESET_PARAMET_CHECK_CONC_CODE,PASSWORD_CHANGE_CONC_CODE,PRESET_PARAMETER_SET_CONC_CODE,RELIABILITY_CONC_CODE,MOVE_STABILITY_TEST_CONC_CODE,ANTI_SEISMICTEST_CONC_CODE,PRESET_PARAM2_CHECK_CONC_CODE,PRESET_PARAM3_CHECK_CONC_CODE,PRESET_PARAM2_SET_CONC_CODE,PRESET_PARAM3_SET_CONC_CODE,HARD_VERSION,FAULT_TYPE,EVENT_REC_FUNC_CONC_CODE,INFLUENCE_QTY_CONC_CODE,AUX_POW_CONC_CODE,ALARM_FUNC_CONC_CODE,RATE_TIME_FUNC_CONC_CODE,ELE_ENERGY_FUNC_CONC_CODE,EXPIRATION_DATE,MEA_REP_CONC_CODE,CERT_NO,CERT_NO_PERIOD,UNPASS_REASON,COMM_MODE_CHG_CONC_CODE,COMM_MODE_INT_CONC_CODE,FROZEN_FUNC_CONC_CODE)\n"
               "values('001','01','001','1','1',  '1','1','2015','1','1',  '1','1','1','1','1',  '1','1','1','1','1',  '1','1','1','1','1',       '1','1','1','1','1', \n"
               "'1','1','1','1','1',      '1','1','1','1','1',    '1','1','1','1','1',  '1','1','1','1','1',  '0',   '0','2015','1','2015','1', '2015','0','0','0','1',  '0','1','1','1','0',  '0','0','0','1','1', '1','1','1','1','1', '1','2015','0','1','1'  ,'0','1','1','1');";

       strAct ="INSERT INTO  MT_DETECT_RSLT";

       destSql_query( myquery, strExec, strAct  );
#endif

//}
