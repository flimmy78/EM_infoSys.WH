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

    setCursor(QCursor(Qt::BusyCursor));
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

     QDomDocument domDoc;
     domDoc.setContent(strTemp);
     if(!save_xmlFile(strDownPath, domDoc))
     {
        showInformationBox(QString::fromUtf8("保存xml出错"));
        return  ;
     }

    if(strTemp.isEmpty())
    {
        setCursor(QCursor(Qt::ArrowCursor));
        showInformationBox(QString::fromUtf8("链接服务器异常"));
        return;
    }
    else if(strTemp.indexOf("sample")>10)//判断是否成功,含有sample节点
    {
        QDomDocument domDoc;
        domDoc.setContent(strTemp);
        analyze_sampleInfo(domDoc);
    }
    else
    {
        strList = get_errList(strTemp);
        if(strList.at(0) != "0000")//返回不成功
        {
           setCursor(QCursor(Qt::ArrowCursor));
           showInformationBox(strList.at(1));
           return;
        }
    }
    setCursor(QCursor(Qt::ArrowCursor));
}

///QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));

void MainWindow::on_EM_update_results_PsBtn_clicked()
{
    QString strExec;
    QByteArray byteArray;
    int rowCount ,columnCount,intResult;

    QStringList strList;
    QString sampleNo,sysParams,Appsecret,AppKey,date,Appsign,appsignBefore,strTemp;


    SGCMSwitchProjectSoapBindingProxy soap;
    soap_set_mode(&soap, SOAP_C_UTFSTRING);

    _ns1__sendProjectResults sendProjectResults;
    _ns1__sendProjectResultsResponse resp;

    char *endPoint = NULL;
    char *action = NULL;

    if(ui->EM_RSLT_TabWidget->rowCount()<=0)
    {
        showInformationBox(QString::fromUtf8("数据没有导入"));
        return;
    }

    if(!MU_creat_xml())
    {
      showInformationBox(QString::fromUtf8("创建上传XML数据异常.."));
      return;
    }
#if 1

    setCursor(QCursor(Qt::BusyCursor));
    sampleNo = ui->EM_RSLT_TabWidget->item(0,0)->text();//="JLXC-160425-1";
    AppKey = "169827";
    date =currentTime();
    Appsecret = "2e33edf32o34492uf58f233ksl3er60f";
    appsignBefore   = Appsecret+"sampleNo"+sampleNo;
    Appsign=MD5_getSampleInfo(appsignBefore);

    sysParams =AppKey+"|"+date+"|"+Appsign;

    //qDebug()<<sysParams;
    sendProjectResults.sampleNo=sampleNo.toStdString(); //样品编号
    sendProjectResults.sysParams=sysParams.toStdString();//系统参数
    sendProjectResults.checkResult= ui->EM_RSLT_TabWidget->item(0,1)->text().toStdString(); //总结论//0：合格；1：不合格
    sendProjectResults.checkDate=currentTime().toStdString();;//检验日期
    sendProjectResults.testMan=ui->EM_RSLT_TabWidget->item(0,3)->text().toStdString(); //检验员
    sendProjectResults.checkMan=ui->EM_RSLT_TabWidget->item(0,4)->text().toStdString();//校核员
    sendProjectResults.checkTemp=ui->EM_RSLT_TabWidget->item(0,6)->text().toStdString(); //检验温度
    sendProjectResults.checkWet=ui->EM_RSLT_TabWidget->item(0,5)->text().toStdString();//检验湿度


    sendProjectResults.projects=std::string(g_domDoc.toString().toUtf8());//g_domDoc
    soap.sendProjectResults(endPoint,action,&sendProjectResults, resp);
    strTemp = QString::fromUtf8(resp.sendProjectResultsReturn.c_str());

    if(strTemp.isEmpty())
    {
        setCursor(QCursor(Qt::ArrowCursor));
        showInformationBox(QString::fromUtf8("链接服务器异常"));
        return;
    }

    strList = get_errList(strTemp);
    showInformationBox(strList.at(1));
#endif
   //qDebug()<<QString::fromUtf8(resp.sendProjectResultsReturn.c_str());
//  showInformationBox(QString::fromUtf8(resp.sendProjectResultsReturn.c_str()));

 //插入数据库显示已经上传
  //sampleNo ="JLXC-160425-1";
#if 1
  strExec = QString("UPDATE sampleInfo SET isUpdate = '1' where sampleNo = '%1'").arg(sampleNo);
  byteArray = strExec.toLocal8Bit();
  intResult= sql_exec(byteArray.data());
  if(intResult!=SQLITE_OK)
  {
      setCursor(QCursor(Qt::ArrowCursor));
      showInformationBox(QString::fromUtf8("更新数据库出错.."));
      return ;
  }
#endif
    setCursor(QCursor(Qt::ArrowCursor));
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

