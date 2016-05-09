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

//下载信息
void MainWindow::on_EM_down_sampleInfo_PsBtn_clicked()
{
    QStringList strList;
    QString sampleNo,sysParams,Appsecret,strTemp,AppKey,date,Appsign,appsignBefore;

    SGCMSwitchProjectSoapBindingProxy soap;
    soap_set_mode(&soap, SOAP_C_UTFSTRING);

    _ns1__getSampleInfo getSampleInfo;
    _ns1__getSampleInfoResponse resp;

    char *endPoint = NULL;
    char *action = NULL;

    setCursor(QCursor(Qt::WaitCursor));
    sampleNo  = ui->EM_down_barCode_LnEdit->text();  //"JLXC-160425-1";
    AppKey    = ui->EM_options_appKey_LnEdit->text();                     //"169827";
    date      = currentTime();
    Appsecret = ui->EM_options_appSecret_LnEdit->text();                  //"2e33edf32o34492uf58f233ksl3er60f";
    appsignBefore = Appsecret+"sampleNo"+sampleNo;

    Appsign = MD5_getSampleInfo(appsignBefore);
    sysParams =AppKey+"|"+date+"|"+Appsign;

    getSampleInfo.sampleNo=sampleNo.toStdString();                        //样品编号
    getSampleInfo.sysParams=sysParams.toStdString();                      //系统参数，组成方式：AppKey|date|Appsign

    soap.getSampleInfo(endPoint,action,&getSampleInfo, resp);
//  qDebug()<<QString(QString::fromUtf8((*resp.out).c_str()));

    strTemp = QString::fromUtf8(resp.getSampleInfoReturn.c_str());
    if(strTemp.isEmpty())
    {
        setCursor(QCursor(Qt::ArrowCursor));
        showInformationBox(QString::fromUtf8("链接服务器异常"));
        return;
    }

    strList = get_errList(strTemp);
    if(strList.at(0) != "0000")//返回不成功
    {
       setCursor(QCursor(Qt::ArrowCursor));
       showInformationBox(strList.at(1));
       return;
    }

#if 1
    QDomDocument domDoc;
    domDoc.setContent(strTemp);
    analyze_sampleInfo(domDoc);
#endif

    setCursor(QCursor(Qt::ArrowCursor));

}

///QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));

void MainWindow::on_EM_update_results_PsBtn_clicked()
{
    QString sampleNo,sysParams,Appsecret,AppKey,date,Appsign,appsignBefore;
#if 1
    SGCMSwitchProjectSoapBindingProxy soap;
    soap_set_mode(&soap, SOAP_C_UTFSTRING);

    _ns1__sendProjectResults sendProjectResults;
    _ns1__sendProjectResultsResponse resp;

    char *endPoint = NULL;
    char *action = NULL;

    if(ui->EM_RSLT_TabWidget->rowCount()<=0)
    {
        showInformationBox(QString::fromUtf8("检定综合结论为空"));
        return;
    }
    setCursor(QCursor(Qt::WaitCursor));
    sampleNo =ui->EM_RSLT_TabWidget->item(0,0)->text();
    AppKey = "169827";
    date =currentTime();
    Appsecret = "2e33edf32o34492uf58f233ksl3er60f";
    appsignBefore   = Appsecret+"sampleNo"+sampleNo;
    Appsign=MD5_getSampleInfo(appsignBefore);

    sysParams =AppKey+"|"+date+"|"+Appsign;

    //qDebug()<<sysParams;
    sendProjectResults.sampleNo=sampleNo.toStdString(); //样品编号
    sendProjectResults.sysParams=sysParams.toStdString();//系统参数
    sendProjectResults.checkResult=ui->EM_RSLT_TabWidget->item(0,1)->text().toStdString(); //总结论//0：合格；1：不合格
    sendProjectResults.checkDate=currentTime().toStdString();;//检验日期
    sendProjectResults.testMan=ui->EM_RSLT_TabWidget->item(0,3)->text().toStdString(); //检验员
    sendProjectResults.checkMan=ui->EM_RSLT_TabWidget->item(0,4)->text().toStdString();//校核员
    sendProjectResults.checkTemp=ui->EM_RSLT_TabWidget->item(0,6)->text().toStdString(); //检验温度
    sendProjectResults.checkWet=ui->EM_RSLT_TabWidget->item(0,5)->text().toStdString();//检验湿度

    QDomDocument domDoc;
    QString  strTemp;
    if(!load_xmlFile("./update.xml",domDoc)) //e:/update.xml
    {
        setCursor(QCursor(Qt::ArrowCursor));
        showInformationBox(QString::fromUtf8("当前目录找不到XML结论信息"));
        return;
    }
    //qDebug()<<domDoc.toString();


//    QTextCodec *gbk = QTextCodec::codecForName("GB18030");
//    QTextCodec *utf8 = QTextCodec::codecForName("UTF-8");
//    QString g2u = gbk->toUnicode(gbk->fromUnicode(inStr));              // gbk  convert utf8

//    QTextCodec *utf8 = QTextCodec::codecForName("UTF-8");
//    QString a= "鎴戞槸姹夊瓧UTF8";//UTF8格式下 写的“我是汉字UTF8”
//    a = utf8->toUnicode(a.toLatin1());

#if 0
       //const std::string &inStr
        QString str = QString::fromStdString(inStr);
        QTextCodec *gbk = QTextCodec::codecForName("GB18030");
        QTextCodec *utf8 = QTextCodec::codecForName("UTF-8");

        QString utf2gbk = gbk->toUnicode(inStr.toLocal8Bit());
        return utf2gbk;
#endif

//需要转成UTF-8格式
#if 0
    strTemp = domDoc.toString();
    sendProjectResults.projects=std::string(strTemp.toUtf8());
#endif


//传递成功但是，中文乱码
#if 1
    strTemp = QString::fromUtf8(domDoc.toString().toLocal8Bit().data());
    sendProjectResults.projects=std::string(strTemp.toUtf8());
#endif


    //soap.sendProjectResults(endPoint,action,&sendProjectResults, resp);
//  qDebug()<<QString(QString::fromUtf8((*resp.out).c_str()));
//  qDebug()<<QString::fromUtf8(resp.sendProjectResultsReturn.c_str());
    // showInformationBox(QString::fromUtf8(resp.sendProjectResultsReturn.c_str()));
    setCursor(QCursor(Qt::ArrowCursor));
#endif
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

