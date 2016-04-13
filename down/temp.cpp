


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

#if 0

        //c1
        if(!query.exec(QObject::trUtf8("CREATE TABLE MT_INTUIT_MET_CONC( Num  integer primary key autoincrement,DETECT_TASK_NO char(32),\n"
                                       "EQUIP_CATEG char(8),     SYS_NO   char(16),    DETECT_EQUIP_NO char(32),DETECT_UNIT_NO char(32),   POSITION_NO char(32),\n"
                                       "BAR_CODE char(20),       DETECT_DATE char(32), PARA_INDEX char(20),     DETECT_ITEM_POINT char(20),IS_VALID char(32),\n"
                                       "DETECT_CONTENT char(20), CONC_CODE char(32),   WRITE_DATE char(20),     HANDLE_FLAG char(20),      HANDLE_DATE char(20));")))
        {
            qDebug()<<"CREATE c1 error";
            return false;
        }


        if(!query.exec(QObject::trUtf8("INSERT INTO MT_INTUIT_MET_CONC(DETECT_TASK_NO, EQUIP_CATEG, SYS_NO, DETECT_EQUIP_NO,DETECT_UNIT_NO,\n"
                                       "POSITION_NO,  BAR_CODE,  DETECT_DATE,  PARA_INDEX,  DETECT_ITEM_POINT,  IS_VALID,   DETECT_CONTENT, CONC_CODE,  WRITE_DATE, HANDLE_FLAG,\n"
                                       "HANDLE_DATE)values('001','01','001','1','1','1','1','2015','1','1','1','020','01','2015','2','2015');")))
        {
            qDebug()<<"INSERT c1 error";
            return false;
        }

#endif

#if 0



#if 0

        //c1
        if(!query.exec(QObject::trUtf8("CREATE TABLE MT_INTUIT_MET_CONC( Num  integer primary key autoincrement,DETECT_TASK_NO char(32),\n"
                                       "EQUIP_CATEG char(8),     SYS_NO   char(16),    DETECT_EQUIP_NO char(32),DETECT_UNIT_NO char(32),   POSITION_NO char(32),\n"
                                       "BAR_CODE char(20),       DETECT_DATE char(32), PARA_INDEX char(20),     DETECT_ITEM_POINT char(20),IS_VALID char(32),\n"
                                       "DETECT_CONTENT char(20), CONC_CODE char(32),   WRITE_DATE char(20),     HANDLE_FLAG char(20),      HANDLE_DATE char(20));")))
        {
            qDebug()<<"CREATE c1 error";
            return false;
        }


        if(!query.exec(QObject::trUtf8("INSERT INTO MT_INTUIT_MET_CONC(DETECT_TASK_NO, EQUIP_CATEG, SYS_NO, DETECT_EQUIP_NO,DETECT_UNIT_NO,\n"
                                       "POSITION_NO,  BAR_CODE,  DETECT_DATE,  PARA_INDEX,  DETECT_ITEM_POINT,  IS_VALID,   DETECT_CONTENT, CONC_CODE,  WRITE_DATE, HANDLE_FLAG,\n"
                                       "HANDLE_DATE)values('001','01','001','1','1','1','1','2015','1','1','1','020','01','2015','2','2015');")))
        {
            qDebug()<<"INSERT c1 error";
            return false;
        }

#endif

        if(!query.exec(QObject::trUtf8("CREATE TABLE protocol( ID integer primary key autoincrement, namedesc char(20),APPID char(10),\n"
                                       "macDst char(20),vlanId char(20),priority char(20),version char(20),gocbRef char(20),\n"
                                       "dateSet char(20),goId char(20),testBit char(1),channelNum char(5),dataFormat char(1),boolSelected char(1),\n"
                                       "ch1   char(60),ch2   char(60),ch3  char(60), ch4   char(60),ch5   char(60), ch6  char(60),ch7   char(60),ch8   char(60),ch9   char(60),\n"
                                       "ch10  char(60),ch11  char(60),ch12  char(60),ch13  char(60),ch14  char(60),ch15  char(60),ch16  char(60),ch17  char(60),ch18  char(60),ch19  char(60),\n"
                                       "ch20  char(60),ch21  char(60),ch22  char(60),ch23  char(60),ch24  char(60),ch25  char(60),ch26  char(60),ch27  char(60),ch28  char(60),ch29  char(60),\n"
                                       "ch30  char(60),ch31  char(60),ch32  char(60),ch33  char(60),ch34  char(60),ch35  char(60),ch36  char(60),ch37  char(60),ch38  char(60),ch39  char(60),\n"
                                       "ch40  char(60),ch41  char(60),ch42  char(60),ch43  char(60),ch44  char(60),ch45  char(60),ch46  char(60),ch47  char(60),ch48  char(60),ch49  char(60),\n"
                                       "ch50  char(60),ch51  char(60),ch52  char(60),ch53  char(60),ch54  char(60),ch55  char(60),ch56  char(60),ch57  char(60),ch58  char(60),ch59  char(60),\n"
                                       "ch60  char(60),ch61  char(60),ch62  char(60),ch63  char(60),ch64  char(60),ch65  char(60),ch66  char(60),ch67  char(60),ch68  char(60),ch69  char(60),\n"
                                       "ch70  char(60),ch71  char(60),ch72  char(60),ch73  char(60),ch74  char(60),ch75  char(60),ch76  char(60),ch77  char(60),ch78  char(60),ch79  char(60),\n"
                                       "ch80  char(60),ch81  char(60),ch82  char(60),ch83  char(60),ch84  char(60),ch85  char(60),ch86  char(60),ch87  char(60),ch88  char(60),ch89  char(60),\n"
                                       "ch90  char(60),ch91  char(60),ch92  char(60),ch93  char(60),ch94  char(60),ch95  char(60),ch96  char(60),ch97  char(60),ch98  char(60),ch99  char(60),\n"
                                       "ch100 char(60),ch101 char(60),ch102 char(60),ch103 char(60),ch104 char(60),ch105 char(60),ch106 char(60),ch107 char(60),ch108 char(60),ch109 char(60),\n"
                                       "ch110 char(60),ch111 char(60),ch112 char(60),ch113 char(60),ch114 char(60),ch115 char(60),ch116 char(60),ch117 char(60),ch118 char(60),ch119 char(60),\n"
                                       "ch120 char(60),ch121 char(60),ch122 char(60),ch123 char(60),ch124 char(60),ch125 char(60),ch126 char(60),ch127 char(60),ch128 char(60),ch129 char(60)\n"
                                       ");")))
        {
            qDebug()<<"CREATE1 error";

            return false;
        }

        if(!query.exec(QObject::trUtf8( "INSERT INTO protocol(ID,namedesc,APPID,macDst,vlanId,priority,version,gocbRef,dateSet,goId,testBit,channelNum,dataFormat,boolSelected,\n"
                                        "ch1 ,ch2 ,ch3 ,ch4 ,ch5 ,ch6 ,ch7 ,ch8 ,ch9 ,ch10,ch11,ch12,ch13,ch14,ch15,ch16,ch17,ch18,ch19,ch20,ch21,ch22,ch23,ch24,ch25,ch26,ch27,ch28,ch29,\n"
                                        "ch30,ch31,ch32,ch33,ch34,ch35,ch36,ch37,ch38,ch39,ch40,ch41,ch42,ch43,ch44,ch45,ch46,ch47,ch48,ch49,ch50,ch51,ch52,ch53,ch54,ch55,ch56,ch57,ch58,ch59,\n"
                                        "ch60,ch61,ch62,ch63,ch64,ch65,ch66,ch67,ch68,ch69,ch70,ch71,ch72,ch73,ch74,ch75,ch76,ch77,ch78,ch79,ch80,ch81,ch82,ch83,ch84,ch85,ch86,ch87,ch88,ch89,\n"
                                        "ch90,ch91,ch92,ch93,ch94,ch95,ch96,ch97,ch98,ch99,ch100,ch101,ch102,ch103,ch104,ch105,ch106,ch107,ch108,ch109,ch110,ch111,ch112,ch113,ch114,ch115,ch116,ch117,ch118,ch119,\n"
                                        "ch120,ch121,ch122,ch123,ch124,ch125,ch126,ch127,ch128,ch129)\n"
                                        "values('0','GSE发送#0','2000','01-0C-CD-01-20-01','10','4','0','gocbRef','dataSet','goId','0','3','0','1',\n"
                                        "'1,0,0,0000,-', '2,0,0,0000,-','3,0,0,0000,-', '4,0,0,0000,-', '5,0,0,0000,-', '6,0,0,0000,-', '7,0,0,0000,-', '8,0,0,0000,-', '9,0,0,0000,-', \n"
                                        "'10,0,0,0000,-','11,0,0,0000,-','12,0,0,0000,-','13,0,0,0000,-','14,0,0,0000,-','15,0,0,0000,-','16,0,0,0000,-','17,0,0,0000,-','18,0,0,0000,-','19,0,0,0000,-',\n"
                                        "'20,0,0,0000,-','21,0,0,0000,-','22,0,0,0000,-','23,0,0,0000,-','24,0,0,0000,-','25,0,0,0000,-','26,0,0,0000,-','27,0,0,0000,-','28,0,0,0000,-','29,0,0,0000,-',\n"
                                        "'30,0,0,0000,-','31,0,0,0000,-','32,0,0,0000,-','33,0,0,0000,-','34,0,0,0000,-','35,0,0,0000,-','36,0,0,0000,-','37,0,0,0000,-','38,0,0,0000,-','39,0,0,0000,-',\n"
                                        "'40,0,0,0000,-','41,0,0,0000,-','42,0,0,0000,-','43,0,0,0000,-','44,0,0,0000,-','45,0,0,0000,-','46,0,0,0000,-','47,0,0,0000,-','48,0,0,0000,-','49,0,0,0000,-',\n"
                                        "'50,0,0,0000,-','51,0,0,0000,-','52,0,0,0000,-','53,0,0,0000,-','54,0,0,0000,-','55,0,0,0000,-','56,0,0,0000,-','57,0,0,0000,-','58,0,0,0000,-','59,0,0,0000,-',\n"
                                        "'60,0,0,0000,-','61,0,0,0000,-','62,0,0,0000,-','63,0,0,0000,-','64,0,0,0000,-','65,0,0,0000,-','66,0,0,0000,-','67,0,0,0000,-','68,0,0,0000,-','69,0,0,0000,-',\n"
                                        "'70,0,0,0000,-','71,0,0,0000,-','72,0,0,0000,-','73,0,0,0000,-','74,0,0,0000,-','75,0,0,0000,-','76,0,0,0000,-','77,0,0,0000,-','78,0,0,0000,-','79,0,0,0000,-',\n"
                                        "'80,0,0,0000,-','81,0,0,0000,-','82,0,0,0000,-','83,0,0,0000,-','84,0,0,0000,-','85,0,0,0000,-','86,0,0,0000,-','87,0,0,0000,-','88,0,0,0000,-','89,0,0,0000,-',\n"
                                        "'90,0,0,0000,-','91,0,0,0000,-','92,0,0,0000,-','93,0,0,0000,-','94,0,0,0000,-','95,0,0,0000,-','96,0,0,0000,-','97,0,0,0000,-','98,0,0,0000,-','99,0,0,0000,-',\n"
                                        "'100,0,0,0000,-','101,0,0,0000,-','102,0,0,0000,-','103,0,0,0000,-','104,0,0,0000,-','105,0,0,0000,-','106,0,0,0000,-','107,0,0,0000,-','108,0,0,0000,-','109,0,0,0000,-',\n"
                                        "'110,0,0,0000,-','111,0,0,0000,-','112,0,0,0000,-','113,0,0,0000,-','114,0,0,0000,-','115,0,0,0000,-','116,0,0,0000,-','117,0,0,0000,-','118,0,0,0000,-','119,0,0,0000,-',\n"
                                        "'120,0,0,0000,-','121,0,0,0000,-','112,0,0,0000,-','123,0,0,0000,-','124,0,0,0000,-','125,0,0,0000,-','126,0,0,0000,-','127,0,0,0000,-','128,0,0,0000,-','129,0,0,0000,-'\n"
                                        ");")))
        {//Readme.txt解释
            qDebug()<<"INSERT1 error";
            return false;
        }

        if(!query.exec(QObject::trUtf8("CREATE TABLE channel( Num  integer primary key autoincrement,ID char(4),APPID char(10), namedesc char(20),dataFormat char(1),stVal char(20),statusDate char(1),\n"
                                       "quality char(20),time char(20));")))
        {
            qDebug()<<"CREATE2 error";
            return false;
        }


        if(!query.exec(QObject::trUtf8("INSERT INTO channel(ID,APPID,namedesc,dataFormat,stVal,statusDate,quality,time)values('1','2001','ch1＃1','2','DA_1','0','0000','');")))
        {
            qDebug()<<"INSERT1 error";
            return false;
        }
        if(!query.exec(QObject::trUtf8("INSERT INTO channel(ID,APPID,namedesc,dataFormat,stVal,statusDate,quality,time)values('0','2002','ch2＃1','2','DA_1','0','0000','');")))
        {
            qDebug()<<"INSERT2 error";
            return false;
        }
#endif
