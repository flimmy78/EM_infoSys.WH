#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QDebug"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QObject>
#include "unistd.h"
#include "QSqlError"
#include "QDateTime"

//模拟测试用的
bool MainWindow:: create_localDatabase()
{

    QString strExec,strAct;
    QSqlDatabase  destSqldb = QSqlDatabase::addDatabase("QSQLITE");
    if(access("goose.db",0))
    {
        destSqldb.setDatabaseName("goose.db");

        if(!destSqldb.open())
        {
             qDebug()<<"open error";
             return false;
        }

        QSqlQuery myquery;



#if 1
     strExec ="CREATE TABLE MT_DETECT_OUT_EQUIP( DETECT_TASK_NO char(32),IO_TASK_NO char(32),EQUIP_CATEG char(32),BAR_CODE char(32) primary key,BOX_BAR_CODE char(32),PILE_NO char(32),PLATFORM_NO char(32),SYS_NO char(32),WRITE_DATE char(32),HANDLE_FLAG char(32),HANDLE_DATE char(32),ARRIVE_BATCH_NO char(32),REDETECT_FLAG char(32),EMP_NO char(32),PLATFORM_TYPE char(32));";

     strAct  = "CREATE TABLE  TABLE";

     destSql_query( myquery, strExec, strAct );

#endif

    }
    else
    {
        return false;

        qDebug()<<"access error";
//        destSqldb.setDatabaseName("goose.db");
//        if(!destSqldb.open()) return false;
//        return true;
    }

    return true;
}

bool MainWindow:: destSql_query(QSqlQuery query,QString strExec,QString strAct  )
{
    if(!query.exec(strExec))
    {
        qDebug()<<strAct + " error："<<query.lastError().driverText();
        return false;
    }
    return true;
}
void MainWindow:: init_localDatabase()
{
    SGEE_SqlDatabase = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE", "SGEE_SqlDatabase"));
    SGEE_SqlDatabase->setDatabaseName("goose.db");

    if (!SGEE_SqlDatabase->open())
     {
        showInformationBox("init_localDatabase open error");
        SGEE_SqlDatabase->close();
        exit(1);
     }

    SGEE_SqlTablemodel_ptl = new QSqlTableModel(this, *SGEE_SqlDatabase);
    SGEE_SqlTablemodel_ptl->setTable("MT_DETECT_RSLT");
    SGEE_SqlTablemodel_ptl->setEditStrategy(QSqlTableModel::OnManualSubmit);
    SGEE_SqlTablemodel_ptl->select();
}

#if 1
void MainWindow::GSE_SCL_ctlBlock_insert()
{
    QString strTemp;
    int rowCount=SGEE_SqlTablemodel_ptl->rowCount()+1;

    QString ID         = QString::number(rowCount);
    QString namedesc    = "GSE发送#" + ID ;
    QString APPID       =  QString::number(2000 + rowCount -5) ;
    QString macDst      =  "01-0C-CD-01-20-01";
    QString vlanId      =  "0";
    QString priority    =  "4";
    QString version     =  "0";
    QString gocbRef     =  "gocbRef";
    QString dateSet     =  "dataSet";
    QString goId        =  "goId0";
    QString testBit        ="0";
    QString channelNum  =  "3";
    QString dataFormat   =  "0";//QString ::number(SGSE.ptlInf_dataformat_cbox->currentIndex());
    QString boolSelected = "0";  //off
    QStringList stringList;

    stringList<<ID<<namedesc<<APPID<<macDst<<vlanId<<priority<<version<<gocbRef<<
                dateSet<<goId<<testBit<<channelNum<<dataFormat<<boolSelected;

    for(int i =1;i<129;i++)
    {
        strTemp =  QObject::trUtf8("%1,%2,0,0000,-").arg(QString::number(i),dataFormat); //
        stringList<<strTemp;
       // qDebug()<<QString ::number(i);
     }

    if (insert_SGSE_QsqlDatabase_ptl(stringList) == false)
    {
        showInformationBox(QString::fromUtf8("数据插入出错"));

        return ;
    }

}
/******************************************************************************************
  *fun:删除模块
 *****************************************************************************************/
void MainWindow::GSE_SCL_ctlBlock_delete()
{

    int rowCount = SGEE_SqlTablemodel_ptl->rowCount()-1;
    if(SGEE_SqlTablemodel_ptl->removeRow(rowCount) == false)//row  0~  removeRow是从0开始算
    {
       showInformationBox(QString::fromUtf8("数据删除出错"));
        return ;
    }

    if (save_SGSE_QsqlDatabase_ptl() == false)
    {
       showInformationBox(QString::fromUtf8("数据保存出错"));
        return ;
    }
}


#endif
//GSE协议编辑.插入数据库
bool MainWindow::insert_SGSE_QsqlDatabase_ptl(QStringList data)
{
    int row = SGEE_SqlTablemodel_ptl->rowCount();
    if (SGEE_SqlTablemodel_ptl->insertRow(row) == false)
    {
        qDebug()<<"insertRow error ";
        return false;
    }

    for (int column = 0; column < data.count(); column++)
    {
        SGEE_SqlTablemodel_ptl->setData(SGEE_SqlTablemodel_ptl->index(row, column), data.at(column));
    }

    if (save_SGSE_QsqlDatabase_ptl() == false)
    {
        return false;
    }
    return true ;
}


bool MainWindow::save_SGSE_QsqlDatabase_ptl()//编辑保存
{
    if (!SGEE_SqlDatabase->isOpen())
     {
        qDebug()<<"isOpen error ";
         return false;
     }

     if (SGEE_SqlTablemodel_ptl->database().transaction() == false)
     {
         qDebug()<<"transaction error ";
         return false;
     }

     if (SGEE_SqlTablemodel_ptl->submitAll())
     {
         SGEE_SqlTablemodel_ptl->database().commit();
     }
     else
     {
         SGEE_SqlTablemodel_ptl->database().rollback();
         return false;
     }
     return true;
}




