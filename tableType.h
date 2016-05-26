#ifndef TABLETYPE_H
#define TABLETYPE_H
#include "QString"
struct STRUCT_MT_DETECT_OUT_EQUIP  //b8
{
    QString DETECT_TASK_NO;
    QString IO_TASK_NO;
    QString EQUIP_CATEG;
    QString BAR_CODE;
    QString BOX_BAR_CODE;
    QString PILE_NO;
    QString PLATFORM_NO;
    QString SYS_NO;
    QString WRITE_DATE;
    QString HANDLE_FLAG;
    QString HANDLE_DATE;
    QString ARRIVE_BATCH_NO;
    QString REDETECT_FLAG;
    QString EMP_NO;
    QString PLATFORM_TYPE;
} ;


struct STRUCT_MT_DETECT_TASK  //b8
{
    QString BAR_CODE;
    QString DETECT_TASK_NO;
    QString TASK_PRIO;
    QString DETECT_MODE;
    QString SYS_NO;
    QString ARRIVE_BATCH_NO;
    QString EQUIP_CATEG;
    QString MODEL_CODE;
    QString SCHEMA_ID;
    QString REDETECT_SCHEMA;
    QString REDETECT_FLAG;
    QString REDETECT_QTY;
    QString EQUIP_QTY;
    QString PILE_QTY;
    QString TASK_STATUS;
    QString HANDLE_DATE;
    QString HANDLE_FLAG;
    QString WRITE_DATE;
    QString ERP_BATCH_NO;
    QString TASK_TYPE;
    QString EQUIP_STATUS_CODE;
    QString EXEC_RESP_NAME;
    QString APPR_NAME;
    QString IS_AUTO_SEAL;
    QString EQUIP_CODE_NEW;
    QString PARAM_TYPE;
} ;

struct STRUCT_CONC_CODE
{
    QString INTUIT;
    QString BASICERR;
    QString CONST;
    QString STARTING;
    QString CREEPING;
    QString INFLUENCE;
    QString MEASURE_REPEAT;
    QString DETECT_EQUIP_NO;
    QString TIME;
} ;

struct STRUCT_DOWN_INFO
{
    QString BAR_CODE;
    QString DETECT_TASK_NO;
    QString MANUFACTURER;
    QString VALUE;
} ;
#endif
