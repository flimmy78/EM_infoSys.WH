#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QDomComment"


bool MainWindow::addNode_sample(QDomDocument &domDoc)
{

    qDebug()<< domDoc.toString();

}

void MainWindow::addNode_INTUIT(QString filename)
{
    QMap<QString,QString> nodeMap1,nodeMap2 ;
    nodeMap1.insert("aa", "11"); //向map里添加一对“键-值”
    nodeMap1.insert("bb", "22"); //向map里添加一对“键-值”   //tagname  不能为纯数字

    if(!appendNode(filename,"remote",nodeMap1))
    {
        showInformationBox("appendNode error");
    }
}
