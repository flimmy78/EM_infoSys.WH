
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileInfo"
#include "QDir"
#include "QDebug"
#include "QMessageBox"
#include "QFile"

//创建xml文件
bool MainWindow::create_xml(const QString &strFilePath, const QString &strRoot)
{
    QDomDocument domDoc; //整个文档
    QDomProcessingInstruction instruction = domDoc.createProcessingInstruction("xml","version=\"1.0\" encoding=\"GB2312\"");

    domDoc.appendChild(instruction);
    QDomElement root = domDoc.createElement(strRoot); //根节点
    domDoc.appendChild(root);
    return save_xmlFile(strFilePath,domDoc);

}
//加载XML内容
bool MainWindow::load_xmlFile(const QString &strFilePath,  QDomDocument &domDoc)
{
    QString errorStr;
    int errorLine,errorColumn;

    QFile file(strFilePath);

    if(!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        showInformationBox(QString::fromUtf8("error: load_xml open"));
        file.close();
        return  false ;
    }

    if (!domDoc.setContent(&file, false, &errorStr, &errorLine, &errorColumn))
    {
        showInformationBox("error: load_xml:"+errorStr);
        file.close();
        return false ;
    }

    file.close();

    return  true;

}

//将XML保存为文档形式.格式为UTF-8
bool MainWindow::save_xmlFile(const QString &strFilePath,  const QDomDocument domDoc)
{
    QFile file(strFilePath);

    if(!file.open(QIODevice::ReadWrite | QFile::Text))
    {
        showInformationBox(QString::fromUtf8("error ：save_xmlFile"));
        file.close();
        return  false;
    }

    QTextStream out(&file);
    out.setCodec("UTF-8");
    domDoc.save(out,4,QDomNode::EncodingFromTextStream);
    file.close();

    return  true;
}

//读取XML某个节点，tgt(target)
bool MainWindow::search_domNode(QString tgtNodeName,const QDomDocument domDoc)
{
   QDomElement root;
   QDomNode    node;
   root = domDoc.documentElement();
   node = root.firstChild();
   if(recurse_domNode(node,tgtNodeName))//遍历节点 tgtDomEle =
   {
        return true;
   }

   return false;
}

QStringList MainWindow::get_errList(const QString strTemp)
{
    QString errCode,errDesc;
    QStringList strList;
    errCode = getItemFromXML(strTemp,"<errCode>", "</errCode>");
    errDesc = getItemFromXML(strTemp,"<errDesc>", "</errDesc>");
    strList<<errCode<<errDesc;
    //qDebug()<<strList.at(0)<<strList.at(1);
    return  strList;
}

//节点最前插入
bool MainWindow::prependNode(const QString &strFilePath, const QString &strNodeName, const QMap<QString,QString> &nodeMap)
{
    QDomDocument doc; //整个文档
    QFile file(strFilePath); //xml文件

    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        return  false ;
    }

    if(!doc.setContent(&file,true))
    {
        file.close();
        return  false;
    }

    file.close(); //读结束

    QDomElement root = doc.documentElement(); //根节点
    QDomElement node = doc.createElement(strNodeName); //子节点

    if (root.hasChildNodes()) //具有子节点
    {
        QDomElement firstNode = root.firstChild().toElement(); //第一个子节点
        root.insertBefore(node,firstNode); //插在前面
    }
    else //不具有子节点
    {
        root.appendChild(node); //直接插入
    }

    QStringList tagNameList = nodeMap.keys(); //所有的tagName

    foreach(QString strTagName, tagNameList)
    {
        QString strTextNode = nodeMap.value(strTagName);
        QDomElement nodeElement = doc.createElement(strTagName);
        node.appendChild(nodeElement); //子节点的各节点(属性)
        QDomText textNode = doc.createTextNode(strTextNode);
        nodeElement.appendChild(textNode); //属性的内容
    }

    QFile file_w(strFilePath); //xml文件
    if (!file_w.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return  false;
    }
    QTextStream out(&file_w); //输出流
    out.setCodec("UTF-8");
    doc.save(out,4,QDomNode::EncodingFromTextStream); //写入
    file_w.close(); //写结束
    return true;
}

//节点最后插入
bool MainWindow::appendNode(const QString &strFilePath, const QString &strNodeName, const QMap<QString,QString> &nodeMap)
{
    QDomDocument doc; //整个文档
    QFile file(strFilePath); //xml文件

    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        return  false;
    }

    if(!doc.setContent(&file,true))
    {
        qDebug()<<"setContent error";
        file.close();
        return false;
    }
    file.close(); //读结束

    QDomElement root = doc.documentElement(); //根节点
    QDomElement node = doc.createElement(strNodeName); //子节点
    root.appendChild(node);

    QStringList tagNameList = nodeMap.keys(); //所有的tagName

     //qDebug()<<strNodeName;
    foreach(QString strTagName, tagNameList)
    {
        QString strTextNode = nodeMap.value(strTagName);
        QDomElement nodeElement = doc.createElement(strTagName);
        node.appendChild(nodeElement); //子节点的各节点(属性)
        QDomText textNode = doc.createTextNode(strTextNode);
        nodeElement.appendChild(textNode); //属性的内容
    }

    QFile file_w(strFilePath); //xml文件
    if (!file_w.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return false;
    }

    QTextStream out(&file_w); //输出流
    out.setCodec("UTF-8");
    doc.save(out,4,QDomNode::EncodingFromTextStream); //写入
    file_w.close(); //写结束

      return  true ;
}

//删除节点(根据节点内容)
bool MainWindow::removeNodeByTag(const QString &strFilePath, const QString &strTagName, const QString &strText)
{
    if(QFile::exists(strFilePath)) //文件存在
    {
        QFile file(strFilePath);//xml文件
        if (!file.open(QFile::ReadOnly | QFile::Text))
        {
            file.close();
            return  false ;
        }

    QDomDocument doc; //整个文档
    if (!doc.setContent(&file,true))
    {
        file.close();
        return  false;
    }
    file.close(); //读结束

    QDomElement root = doc.documentElement(); //根节点
    QDomNode docNode = root.firstChild(); //第一个子节点
    QString str = docNode.nodeName(); //节点名称


    while(!docNode.isNull()) //遍历文档，删除节点(只会删除一个)
    {
        if (docNode.isElement())
        {
            QDomElement e = docNode.toElement();
            QDomNodeList list = e.childNodes(); //子节点的子节点列表(属性列表)

            for(int i=0; i<list.count(); i++)
            {
                QDomNode node = list.at(i);
                QString strNodeTag = node.toElement().tagName(); //节点名称
                QString strNodeText = node.toElement().text(); //节点内容

                if (strTagName == strNodeTag && strText == strNodeText) //名称、内容都相符
                {
                    //root.re(docNode);
                    docNode.removeChild(node);//删除出现相同的节点
                }
            }
        }
        docNode = docNode.nextSibling(); //下一个节点
    }
        QFile file_w(strFilePath); //xml文件

        if (!file_w.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            return  false ;
        }
        QTextStream out(&file_w); //输出流
        out.setCodec("UTF-8");
        doc.save(out,4,QDomNode::EncodingFromTextStream); //写入
        file_w.close(); //写结束
    }

     return  true ;
}




  //加载XML内容
 bool MainWindow::open_xml(QString filename)
 {
     QString errorStr;
     int errorLine,errorColumn;

     QFile file(filename);

     if(!file.open(QIODevice::ReadOnly | QFile::Text))
     {
         showInformationBox(QString::fromUtf8("读取失败"));
         return  false;
     }

     if (!g_domDoc.setContent(&file, false, &errorStr, &errorLine, &errorColumn))
     {
         showInformationBox("doc："+errorStr);
         file.close();
         return  false;
     }

     file.close();
     return true;
 }

//遍历读取XML信息(待删除)
bool MainWindow::read_xml(QString filename)
{
    QString errorStr;
    QDomDocument doc;
    int errorLine,errorColumn;

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

    qDebug()<<doc.toString();
    QDomElement root = doc.documentElement();
    QDomNode    node = root.firstChild();

    while(!node.isNull())
    {
        if(node.isElement())
        {

            QDomElement element = node.toElement();
            //ui->plainTextEdit->appendPlainText(QString::number(elementNum)+" "+element.tagName());
            //qDebug()<<element.toElement().tagName();
            //qDebug()<<element.toElement().attribute("nominalConstant");
            QDomNodeList list = element.childNodes();
            for(int i = 0;i < list.count();i++)
            {
                QDomNode nodechild = list.at(i);
                if(nodechild.isElement())
                {
                    //qDebug()<<QString::number(i)+"  "+nodechild.toElement().tagName()+" -> "+nodechild.toElement().text();
                   // ui->plainTextEdit->appendPlainText("    "+QString::number(i)+"  "+nodechild.toElement().tagName()+" -> "+nodechild.toElement().text());
                }
            }
        }
        node = node.nextSibling();
    }
    return  true;
}

//递归查找节点
bool MainWindow:: recurse_domNode(QDomNode node,QString tgtNodeName)
{
    while(!node.isNull())
    {
        if(node.isElement())
        {
            //qDebug()<<"xxx"<<node.toElement().firstChild().toElement().tagName();
            QDomElement element = node.toElement();
            while(!element.isNull())
            {
                if(node.isElement())
                {
                    if(node.toElement().tagName() ==tgtNodeName )
                    {
                        if (recurse_Element(element))
                        {
                             return true;
                        }
                        else
                        {
                             return false;
                        }
                    }

                }
                 element = element.nextSiblingElement();
            }
        }
       node = node.nextSibling();
    }
    return  true;
}
//节点递归输出
bool MainWindow:: recurse_Element(QDomElement element)
{
    QString strNodeName,strNodeValue;
    g_map.clear();
    //qDebug()<<"hello"<<QString::number(element.attributes().count());
    for(int i = 0;i < element.attributes().count();i++)
    {
        //QDomNode nodechild = list.at(i);
       // qDebug()<<element.attributes().item(i).nodeName()<<element.attributes().item(i).nodeValue();
        strNodeName  = element.attributes().item(i).nodeName();
        strNodeValue = element.attributes().item(i).nodeValue();
        g_map.insert(strNodeName,strNodeValue);
    }

    if(element.attributes().count()>0)  //有节点才正确返回
    {
        return  true;
    }
    else
    {
      return  false;
    }
}

