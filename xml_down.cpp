#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QDebug"
#include "QMessageBox"
#include "QTextStream"
#include "QCryptographicHash"

void MainWindow::on_EM_down_XML_PsBtn_clicked()
{
    if(false == getSampleInfo())
    {
//         showInformationBox(QString::fromUtf8("error"));
//         return;
    }

//    MD5_down();
    qDebug()<< error_info("1010");
}

 bool MainWindow:: getSampleInfo()
 {
     QString sampleNo,sysParams;

     sampleNo  = "";//样品编号 “SGCM011620130018-01”
     sysParams = "";//系统参数，组成方式：AppKey|date|Appsign，如“169827|2012-5-17 13:42:17|9865747FB8EBBB00F6C036A4185287F7”

     //qDebug()<<currentTime();
 }

 void MainWindow::analyse_down_xml(QString strTemp)
 {
     QString tagName ="sampleNo";
     if(!search_domNode(tagName))
     {
         showInformationBox("no sample");
         return;
     }

 #if 1
      QStringList tagNameList = g_map.keys();

      foreach (QString str, tagNameList)
      {
          qDebug()  << str;
          qDebug() << g_map.value(str);
      }
 #endif
 }

 //获取下载平台信息,需要加密匹配
 bool MainWindow:: MD5_down()
{
     QString  strTemp ,Appsecret,strInfo,filename,errorStr,strID;
     QDomDocument doc;
     int errorLine,errorColumn;


     filename = "e:/config.xml";
     QFile file(filename);

     if(!file.open(QIODevice::ReadOnly | QFile::Text))
     {
         showInformationBox(QString::fromUtf8("读取失败"));
          return  false;
     }

     if (!doc.setContent(&file, false, &errorStr, &errorLine, &errorColumn))
     {
         showInformationBox("doc："+errorStr);
         file.close();
         return  false;
     }

     file.close();

     strTemp = doc.toString();
     //qDebug()<<strTemp<<"1111";
     strID = "XX";
     strInfo=QString("sampleNo%1tableType%2phaseType%3nominalVoltage%4nominalCurrent%5sampleType%6nominalConstant%7reactiveConstant%8activeLevel%9reactiveLevel%10"
                    "freq%11inputMode%12isEmulator%13measurementDirection%14sampleName%15redSeal%16producer%17sampleUserName%18sampleManuNo%19sampleSeal%20")
                    .arg(strID)
                    .arg(strID)
                    .arg(strID)
                    .arg(strID)
                    .arg(strID)
                    .arg(strID)
                    .arg(strID)
                    .arg(strID)
                    .arg(strID)
                    .arg(strID)

                    .arg(strID)
                    .arg(strID)
                    .arg(strID)
                    .arg(strID)
                    .arg(strID)
                    .arg(strID)
                    .arg(strID)
                    .arg(strID)
                    .arg(strID)
                    .arg(strID);
     qDebug()<<strInfo;
 }

