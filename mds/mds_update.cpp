#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gsoap/DetectServiceHttpBinding.nsmap"
#include "gsoap/soapH.h"
#include "gsoap/soapStub.h"
#include "gsoap/soapDetectServiceHttpBindingProxy.h"
#include "QDebug"
#include "QDomDocument"

//将分项录入MDS,可以覆盖

void MainWindow::on_EM_update_updateItems_PsBtn_clicked()
{
   QString SYS_NO, DETECT_TASK_NO,strExec;
    setCursor(QCursor(Qt::WaitCursor));

    int rowCount=ui->EM_update_loadDetectTaskNo_TblWidget->rowCount();

    for(int i =0;i<rowCount;i++)
    {

        if(ui->EM_update_loadDetectTaskNo_TblWidget->item(i,0)->checkState()==Qt::Checked)
        {
             DETECT_TASK_NO =ui->EM_update_loadDetectTaskNo_TblWidget->item(i,0)->text();

             strExec=QString("select * from MT_DETECT_TASK where DETECT_TASK_NO =%1").arg(DETECT_TASK_NO);

             if(!SqlTempToQstring(strExec,26))
             {
                 return ;
             }

             SYS_NO = strArray[15][4];//sys_no
             //qde
             update_getDETedTestData(SYS_NO, DETECT_TASK_NO);
        }
    }

    setCursor(QCursor(Qt::ArrowCursor));

}

//将总结论录入MDS,可以覆盖
void MainWindow::on_EM_update_updateRSLT_PsBtn_clicked()
{
    QString SYS_NO, DETECT_TASK_NO,VALID_QTY,strExec;

    int rowCount=ui->EM_update_loadDetectTaskNo_TblWidget->rowCount();

    for(int i =0;i<rowCount;i++)
    {
        if(ui->EM_update_loadDetectTaskNo_TblWidget->item(i,0)->checkState()==Qt::Checked)
        {
            DETECT_TASK_NO =ui->EM_update_loadDetectTaskNo_TblWidget->item(i,0)->text();
            strExec=QString("select * from MT_DETECT_TASK where DETECT_TASK_NO =%1").arg(DETECT_TASK_NO);

            if(!SqlTempToQstring(strExec,26))
            {
                return ;
            }

            SYS_NO = strArray[15][4];//sys_no
            VALID_QTY = strArray[15][12];
//          qDebug()<<SYS_NO<<VALID_QTY;
            if(update_setResults(SYS_NO, DETECT_TASK_NO,VALID_QTY))
            {
               // qDebug()<<"fasdf";
                on_EM_update_updateItems_PsBtn_clicked();
                return;
            }
          return;
        }
    }


}

bool MainWindow:: update_getDETedTestData(QString SYS_NO,QString DETECT_TASK_NO)
{

    DetectServiceHttpBindingProxy soap;
    soap_set_mode(&soap, SOAP_C_UTFSTRING);

    _ns1__getDETedTestData getDETedTestData;
    _ns1__getDETedTestDataResponse resp;

    QString strItemValue;
    char *endPoint = NULL;
    char *action = NULL;

    setCursor(QCursor(Qt::WaitCursor));

    QString str1=QString("<PARA><SYS_NO>%1</SYS_NO><DETECT_TASK_NO>%2</DETECT_TASK_NO></PARA>").arg(SYS_NO,DETECT_TASK_NO);

    getDETedTestData.in0=&str1.toStdString();

    //std::cout<<*(getDETedTestData).in0<<std::endl;

    soap.getDETedTestData(endPoint,action,&getDETedTestData, resp);
    strItemValue = getItemFromXML(QString(QString::fromUtf8((*resp.out).c_str())),"<ERROR_INFO>", "</ERROR_INFO>");
    showInformationBox(strItemValue);

  #if 0
    if(soap.getDETedTestData(endPoint,action,&getDETedTestData, resp) == SOAP_OK)
    {
       strItemValue = getItemFromXML(QString(QString::fromUtf8((*resp.out).c_str())),"<ERROR_INFO>", "</ERROR_INFO>");
       showInformationBox(strItemValue);
    }
    else
    {
        strItemValue = getItemFromXML(QString(QString::fromUtf8((*resp.out).c_str())),"<ERROR_INFO>", "</ERROR_INFO>");
        showInformationBox(strItemValue);
    }
   #endif
    setCursor(QCursor(Qt::ArrowCursor));
    return true;

}

bool MainWindow::  update_setResults(QString SYS_NO,QString DETECT_TASK_NO,QString VALID_QTY)
{
    DetectServiceHttpBindingProxy soap;
    soap_set_mode(&soap, SOAP_C_UTFSTRING);

    _ns1__setResults setResults;
    _ns1__setResultsResponse resp;

    QString strItemValue;
    char *endPoint = NULL;
    char *action = NULL;

    setCursor(QCursor(Qt::WaitCursor));

    QString str1=QString("<PARA><SYS_NO>%1</SYS_NO><DETECT_TASK_NO>%2</DETECT_TASK_NO><VALID_QTY>%3</VALID_QTY></PARA>").arg(SYS_NO,DETECT_TASK_NO,VALID_QTY);
    setResults.in0=&str1.toStdString();

    if(soap.setResults(endPoint,action,&setResults, resp) != SOAP_OK)
    {
        strItemValue = getItemFromXML(QString(QString::fromUtf8((*resp.out).c_str())),"<ERROR_INFO>", "</ERROR_INFO>");
        showInformationBox(strItemValue);
        setCursor(QCursor(Qt::ArrowCursor));
        return false;
     }
     setCursor(QCursor(Qt::ArrowCursor));
     return true;
}

QString MainWindow:: getItemFromXML(QString strSou,QString strBegin,QString strEnd)
{
    QString strRe;
    int intStart,intEnd,intlength;
    intlength =strBegin.length();
    intStart=strSou.indexOf(strBegin);
    intEnd=strSou.indexOf(strEnd);
    strRe=strSou.mid(intStart+intlength,intEnd-intStart-intlength);
    return strRe;
}
