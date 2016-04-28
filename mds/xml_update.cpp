#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gsoap/SGCMSwitchProjectSoapBinding.nsmap"
#include "gsoap/soapH.h"
#include "gsoap/soapStub.h"
#include "gsoap/soapSGCMSwitchProjectSoapBindingProxy.h"
#include "QDebug"
#include "QDomDocument"
#include "QFile"
#include "QTextCodec"

void MainWindow::on_EM_test_XML_PsBtn_clicked()
{
    QString sampleNo,sysParams,Appsecret,strTemp,AppKey,date,Appsign,appsignBefore;
#if 1

    SGCMSwitchProjectSoapBindingProxy soap;
    soap_set_mode(&soap, SOAP_C_UTFSTRING);

    _ns1__getSampleInfo getSampleInfo;
    _ns1__getSampleInfoResponse resp;

    QString strItemValue;
    char *endPoint = NULL;
    char *action = NULL;

    setCursor(QCursor(Qt::WaitCursor));
    sampleNo ="JLXC-160425-1";
    AppKey = "169827";
    date =currentTime();
    Appsecret = "2e33edf32o34492uf58f233ksl3er60f";
    appsignBefore   = Appsecret+"sampleNo"+sampleNo;
    Appsign=MD5_getSampleInfo(appsignBefore);

    sysParams =AppKey+"|"+date+"|"+Appsign;

    getSampleInfo.sampleNo=sampleNo.toStdString(); //样品编号
    getSampleInfo.sysParams=sysParams.toStdString();//系统参数，组成方式：AppKey|date|Appsign

    qDebug()<<strTemp<<endl<<Appsign;
    //qDebug()<<QString::fromUtf8(getSampleInfo.sysParams.c_str());
    //std::cout<<*(getDETedTestData).in0<<std::endl;

    soap.getSampleInfo(endPoint,action,&getSampleInfo, resp);
    //strItemValue = getItemFromXML(QString(QString::fromUtf8((*resp.out).c_str())),"<ERROR_INFO>", "</ERROR_INFO>");
    //showInformationBox(strItemValue);
//    qDebug()<<QString(QString::fromUtf8((*resp.out).c_str()));
    strTemp = QString::fromUtf8(resp.getSampleInfoReturn.c_str());
    //qDebug()<<QString::fromUtf8(resp.getSampleInfoReturn.c_str());
    showInformationBox(strTemp);

    createXmlFile("e:/c1.xml",strTemp);
    //analyse_down_xml(strTemp);


    setCursor(QCursor(Qt::ArrowCursor));
#endif
}



///QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
void MainWindow::on_EM_test2_XML_PsBtn_clicked()
{
    QString sampleNo,sysParams,Appsecret,strTemp,AppKey,date,Appsign,appsignBefore;
#if 1
    SGCMSwitchProjectSoapBindingProxy soap;
    soap_set_mode(&soap, SOAP_C_UTFSTRING);

    _ns1__sendProjectResults sendProjectResults;
    _ns1__sendProjectResultsResponse resp;

    QString strItemValue;
    char *endPoint = NULL;
    char *action = NULL;

    setCursor(QCursor(Qt::WaitCursor));
    sampleNo ="JLXC-160425-1";
    AppKey = "169827";
    date =currentTime();
    Appsecret = "2e33edf32o34492uf58f233ksl3er60f";
    appsignBefore   = Appsecret+"sampleNo"+sampleNo;
    Appsign=MD5_getSampleInfo(appsignBefore);

    sysParams =AppKey+"|"+date+"|"+Appsign;

    //qDebug()<<sysParams;
    sendProjectResults.sampleNo=sampleNo.toStdString(); //样品编号
    sendProjectResults.sysParams=sysParams.toStdString();//系统参数
    sendProjectResults.checkResult="0"; //总结论//0：合格；1：不合格
    sendProjectResults.checkDate=currentTime().toStdString();;//检验日期
    sendProjectResults.testMan="星龙"; //检验员
    sendProjectResults.checkMan="jing2";//校核员
    sendProjectResults.checkTemp="100"; //检验温度
    sendProjectResults.checkWet="108";//检验湿度


    QDomDocument doc; //整个文档
    QString strFilePath = "c:/config.xml";
    QFile file(strFilePath); //xml文件

    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        return  ;
    }

    if(!doc.setContent(&file,true))
    {
        qDebug()<<"setContent error";
        file.close();
        return ;
    }
    file.close(); //读结束
    //qDebug()<<doc.toString();

   //QTextCodec *utf8 = QTextCodec::codecForName("UTF-8");
   //strTemp  = utf8->TO.

//std::string
#if 0
    strTemp = doc.toString();
    sendProjectResults.projects=std::string(strTemp.toUtf8());
#endif


//传递成功但是，中文乱码
#if 1
    strTemp = QString::fromUtf8(doc.toString().toLocal8Bit().data());
    sendProjectResults.projects=std::string(strTemp.toUtf8());
#endif


    soap.sendProjectResults(endPoint,action,&sendProjectResults, resp);
    //strItemValue = getItemFromXML(QString(QString::fromUtf8((*resp.out).c_str())),"<ERROR_INFO>", "</ERROR_INFO>");
    //showInformationBox(strItemValue);
//    qDebug()<<QString(QString::fromUtf8((*resp.out).c_str()));
    qDebug()<<QString::fromUtf8(resp.sendProjectResultsReturn.c_str());
    showInformationBox(QString::fromUtf8(resp.sendProjectResultsReturn.c_str()));
    //qDebug()<<QString::fromUtf8(resp.sendProjectResultsReturn.c_str());
    setCursor(QCursor(Qt::ArrowCursor));
#endif
}




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
#if 0
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
#endif
    return true;

}

bool MainWindow::  update_setResults(QString SYS_NO,QString DETECT_TASK_NO,QString VALID_QTY)
{
#if 0
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
#endif
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
