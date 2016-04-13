#-------------------------------------------------
#
# Project created by QtCreator 2015-05-08T17:19:05
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       +=xml
TARGET = XML.WH
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    gsoap/stdsoap2.cpp \
    gsoap/soapC.cpp \
    update/sqlite3.c \
    down/test.cpp \
    down/destSql_simulate.cpp \
    mds/mds_update.cpp \
    update/LocalSql_RSLT.cpp \
    down/otherTables.cpp \
    gsoap/soapDetectServiceHttpBindingProxy.cpp \
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
    update/EM_update_DETECT_TASK_NO.cpp \
    down/EM_BASICERR.cpp \
    down/EM_INFLUENCE_QTY.cpp \
    down/EM_STARTING.cpp \
    down/EM_INTUIT.cpp \
    down/EM_CREEPING.cpp \
    update/EM_MEASURE_REPEAT.cpp \
    xml/xml_fun.cpp \
    xml/xml_test.cpp \
    md5.cpp

HEADERS  += mainwindow.h \
    gsoap/stdsoap2.h \
    gsoap/soapStub.h \
    gsoap/soapH.h \
    update/sqlite3.h \
    gsoap/soapDetectServiceHttpBindingProxy.h \
    tableType.h

FORMS    += mainwindow.ui

LIBS     += -lws2_32

LIBS += -L E:/sqldrivers

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
