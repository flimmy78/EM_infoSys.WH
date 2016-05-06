#-------------------------------------------------
#
# Project created by QtCreator 2015-05-08T17:19:05
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       +=xml
TARGET = EM_infoSys.WH
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    gsoap/stdsoap2.cpp \
    gsoap/soapC.cpp \
    update/sqlite3.c \
    down/destSql_simulate.cpp \
    update/LocalSql_RSLT.cpp \
    down/otherTables.cpp \
    gsoap/soapSGCMSwitchProjectSoapBindingProxy.cpp \
    down/destSql_CONST.cpp \
    down/destSql_DETECT_RSLT.cpp \
    down/destSql_DAYERR.cpp \
    down/destSql_DETECT_OUT_EQUIP.cpp \
    down/EM_P_CODE.cpp \
    down/EM_METER.cpp \
    down/EM_DETECT_TASK.cpp \
    down/EM_down_Options.cpp \
    update/EM_update_Options.cpp \
    transform/transform.cpp \
    update/EM_localSql_Options.cpp \
    update/get_localSqlData.cpp \
    options/EM_setArgOptions.cpp \
    down/EM_BASICERR.cpp \
    down/EM_INFLUENCE_QTY.cpp \
    down/EM_STARTING.cpp \
    down/EM_INTUIT.cpp \
    down/EM_CREEPING.cpp \
    update/EM_MEASURE_REPEAT.cpp \
    xml/xml_fun.cpp \
    md5.cpp \
    down/EM_sampleInfo.cpp \
    xml/xml_server.cpp \
    xml/xml_err.cpp \
    update/xml_basicerrr.cpp \
    update/xml_starting.cpp \
    update/xml_influence.cpp \
    update/xml_sample.cpp \
    update/xml_measRepeat.cpp \
    update/xml_intuit.cpp \
    update/xml_creeping.cpp \
    xml/xml_ctl.cpp \
    update/EM_update_loadLocalSql.cpp

HEADERS  += mainwindow.h \
    gsoap/stdsoap2.h \
    gsoap/soapStub.h \
    gsoap/soapH.h \
    update/sqlite3.h \
    gsoap/soapSGCMSwitchProjectSoapBindingProxy.h \
    tableType.h

FORMS    += mainwindow.ui

LIBS     += -lws2_32

#LIBS += -L E:/sqldrivers

RESOURCES += \
    pic/pic.qrc

OTHER_FILES += \
    PS.txt \
    B.txt \
    update.txt \
    xml.txt \
    text.txt \
    WH.SQL \
    Àı–¥.txt
