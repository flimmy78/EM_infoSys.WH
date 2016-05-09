#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "stdio.h"
#include "QDebug"
#include "QTime"


bool MainWindow:: fill_DETECT_RSLT(QString ID)
{
   get_DETECT_RSLT_checkParameter("'"+ID+"'");
   return true;
}

//01合格 02不合格
QString MainWindow:: get_RSLT_CONC()
{
    if((my_CONC_CODE.INTUIT.toInt(0,10)==0)|(my_CONC_CODE.BASICERR.toInt(0,10)==0)|(my_CONC_CODE.STARTING.toInt(0,10)==0)|(my_CONC_CODE.CREEPING.toInt(0,10)==0)
            |(my_CONC_CODE.INFLUENCE.toInt(0,10)==0) |(my_CONC_CODE.MEASURE_REPEAT.toInt(0,10)==0))
        return "0";
    else
        return "1";
}

