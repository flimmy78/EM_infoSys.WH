#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include  <QMainWindow>
#include "update/sqlite3.h"
#include "QTableWidget"
#include "QSqlDatabase"
#include "QSqlTableModel"
#include "tableType.h"
#include "QDomNode"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void  showInformationBox(QString strTemp);
    void  remove_TblWdiget_Row(QTableWidget *TblWiget);
    bool  avoid_readVoidErr_TblWdiget(QTableWidget *TblWiget);
    void  init_TblWidget();
    QString  get_DB_FileName();

    void  writeIni(QString path,QString arg);
    bool  create_localDatabase();
    void  init_localDatabase();
    bool  insert_SGSE_QsqlDatabase_ptl(QStringList data);
    bool  save_SGSE_QsqlDatabase_ptl();
    void  GSE_SCL_ctlBlock_insert();
    void  GSE_SCL_ctlBlock_delete();
    bool  destSql_query(QSqlQuery query,QString strExec,QString strAct  );

    //localsqlite
    void  open_localSql();
    void  set_localSqlPath();

    void  clear_sqlTemp();
    int   sql_exec(const char *);
    void  get_checkParameter_detectTaskNo();
    QString get_isUpdate_from_sampleInfo(QString  sampleNo);
    bool  get_ID_from_checkParameter(QString  sampleNo,QString ID);
    bool  SqlTempToQstring(QString strExec,int ItemCount);

    void get_BASICERR_checkParameter(QString strID);
    void get_BASICERR_checkError(QString strID);
    void get_MEASURE_REPEAT_checkError(QString strID);
    void get_MEASURE_REPEAT_checkParameter(QString strID);

    QString indexOfTable(QString strSou,QString strKey);
    QString get_itemFromSql(QString strSou,QString strKey,QString strName);
    QString indexOfotherText(QString strSou,QString strKey);
    QString indexOfInfluence (QString strSou,QString strKey);
    QString getItemFromXML(QString strSou,QString strBegin,QString strEnd);
    bool  isTaskNoExist(QString strTaskNo,QTableWidget * tblWidget,int index);
    bool  isLocalBarCodeExist(QString strExec,QString strBarCode);
    QString GLFXDM_index(QString strTemp);//功率方向
    QString GLYSDM_index(QString strTemp);//功率因素
    QString FZDLDM_index(QString strTemp);//负载电流
    QString FYDM_index(QString strTemp);//分元代码
    QString JLDM_index(QString strTemp);//总检定代码
    QString JBWCSYJLDM_index(QString strTemp);//基本误差检定
    QString PLDM_index(QString strTemp);//频率代码
    QString DYDM_index(QString strTemp);//测试电压代码
    QString EFFECT_index(QString strTemp);

    //下载表格.
    void dwon_DETECT_OUT_EQUIP(QString barCode);
    void down_MT_METER( QString strBarCode);
    void down_MT_P_CODE(QString barCode ,QString strValue);
    void down_MT_DETECT_TASK(QString barCode,QString detectTaskNo);//b7

    //保存表格
    void save_sampleInfo();
    void save_MT_P_CODE();
    void save_MT_METER();
    void save_MT_DETECT_TASK();
    void save_MT_DETECT_OUT_EQUIP();

    void getDataFromLocalSqlToTblWidget(QString strExec,QTableWidget * tblWidget,int columnCount);
    bool sqlQueryExec(QString tabelName,QString BarCode,QString strExec,QString strImfo);
    bool delete_destSql_tableItem(QString tabelName,QString barCode);

    void  errorLog(QString strError);

    QString currentTime();
    QString compare_DateTime(QString str1,QString str2);

    void fill_INTUIT();
    bool fill_BASICERR(QString ID);
    bool fill_STARTING(int index);
    bool fill_CREEPING(int index);
    bool fill_INFLUENCE_QTY(int index);
    bool fill_DETECT_RSLT(QString ID);
    bool fill_MEASURE_REPEAT(QString ID);
    void fill_DETECT_OUT_EQUIP();
    void fill_DETECT_TASK();

    int  get_DETECT_RSLT_checkParameter(QString strID);

    QString get_RSLT_CONC();

    bool  appendNode(const QString &strFilePath, const QString &strNodeName, const QMap<QString,QString> &nodeMap);
    bool  prependNode(const QString &strFilePath, const QString &strNodeName, const QMap<QString,QString> &nodeMap);
    bool  removeNodeByTag(const QString &strFilePath, const QString &strTagName, const QString &strText);
    bool  load_xmlFile(const QString &strFilePath,  QDomDocument &domDoc);
    bool  save_xmlFile(const QString &strFilePath, const QDomDocument domDoc);
   QStringList get_errList(const QString strTemp );
    void  analyze_sampleInfo(const QDomDocument domDoc);

    bool  create_xml(const QString &strFilePath, const QString &strRoot);
    bool  read_xml(QString filename);
    bool  recurse_domNode(QDomNode ,QString);
    bool  recurse_Element(QDomElement element);//递归节点


    bool  open_xml(QString filename);
    bool  search_domNode(QString,const QDomDocument );
    bool  MU_creat_xml();

    void   addNode_sample(QString nodeName,QDomDocument &domDoc);
    void   addNode_MEASURE_REPEAT(QString nodeName, QDomDocument &domDoc);
    void   addNode_BASICERR(QString nodeName, QDomDocument &domDoc);
    void   addNode_INTUIT(QString nodeName, QDomDocument &domDoc);
    void   addNode_STARTING(QString nodeName, QDomDocument &domDoc);
    void   addNode_CREEPING(QString nodeName, QDomDocument &domDoc);
    void   addNode_INFLUENCE(QString nodeName, QDomDocument &domDoc);
    //
    QString  MD5_getSampleInfo(QString strSou);
    QString error_info(QString errInfo);
private slots:

    void on_EM_down_Act_triggered();

    void on_EM_update_Act_triggered();

    void on_EM_options_Act_triggered();

    void on_EM_options_check_PsBtn_clicked();

    void on_EM_options_setArg_localSqlPath_PsBtn_clicked();

    void on_EM_down_loadLocalSql_PsBtn_clicked();

    void on_EM_down_clean_PsBtn_clicked();

    void on_EM_down_saveLocalSql_PsBtn_clicked();

    void on_EM_options_deleteLocalSqlAll_PsBtn_clicked();

    void on_EM_down_deleteLocalSqlItem_PsBtn_clicked();

    void on_EM_update_loadLocalSql_PsBtn_clicked();

    void on_EM_update_loadDetectTaskNo_PsBtn_clicked();
    void on_EM_options_setArg_Oracle_PsBtn_clicked();

    void on_EM_options_detectEquipNo_PsBtn_clicked();

    void on_EM_save_XML_PsBtn_clicked();

    void on_EM_down_sampleInfo_PsBtn_clicked();

    void on_EM_update_results_PsBtn_clicked();

    void on_EM_update_searchBarCode_LnEdit_textChanged(const QString &arg1);


private:
    Ui::MainWindow *ui;

    sqlite3      *localsqliteDB;
    QString       strArrayTemp[10000];
    QString       strArray[16][10000];

    QSqlDatabase    *SGEE_SqlDatabase;
    QSqlTableModel  *SGEE_SqlTablemodel_ptl;  //protocol

    //STRUCT_MT_DETECT_OUT_EQUIP my_MT_DETECT_OUT_EQUIP;
    STRUCT_MT_DETECT_TASK      my_MT_DETECT_TASK;
    STRUCT_CONC_CODE           my_CONC_CODE;
    STRUCT_DOWN_INFO           my_DOWN_INFO;

    QDomDocument g_domDoc;   //导入的数据
    QMap<QString,QString>  g_map;
public:
//    char localSqlArrayTemp[1000][1000];
    int  LocalSqlSum;//每次执行sql_exec所产生的数目

    QString strUpdatePath,strDownPath;
};

#endif // MAINWINDOW_H
