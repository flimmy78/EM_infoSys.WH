#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
//校验圈数  标识\t值\t描述\n
QString MainWindow:: indexOfTable(QString strSou,QString strKey)
{
    QString strRe;
    int intStart,intEnd,intlength;

    intlength =strKey.length();
    intStart=strSou.indexOf(strKey);
    intEnd=strSou.indexOf(QString::fromUtf8("\n"),intStart);
    strRe=strSou.mid(intStart+intlength,intEnd-intStart-intlength);
    if(intStart<0)
    {
        return "";
    }
    //qDebug()<<QString::number(intStart);
    return strRe.remove("\t");
}

QString MainWindow:: get_itemFromSql(QString strSou,QString strKey,QString strName)
{
    QString strRe;
    int intStart,intEnd,intlength;

    intlength =strKey.length();
    intStart=strSou.indexOf(strKey);
    intEnd=strSou.indexOf(QString::fromUtf8("\n"),intStart);
    strRe=strSou.mid(intStart+intlength,intEnd-intStart-intlength);
    if(intStart<0)
    {
        return "";
    }
    strRe.remove(strName);
    strRe.remove("\t");
    strRe.remove("%");
    strRe.remove("\n");
    strRe.remove(QString::fromUtf8("度"));

    //qDebug()<<QString::number(intStart);
    return strRe;
}

//启动测试
QString MainWindow:: indexOfotherText (QString strSou,QString strKey)
{
    QString strRe,strEnd;
    strEnd = QString::fromUtf8("合格");
    int intStart,intEnd;

    intStart=strSou.indexOf(strKey);
    intEnd=strSou.indexOf(strEnd,intStart);

    strRe=strSou.mid(intStart+strKey.length(),intEnd-intStart-strKey.length()+strEnd.length());
    if(intStart<0)
    {
        return "0";
    }
    //qDebug()<<strRe;
    return strRe;
}

//影响量
QString MainWindow:: indexOfInfluence (QString strSou,QString strKey)
{
    QString strRe,strEnd;
    strEnd = QString::fromUtf8("合格");
    int intStart,intEnd;

    intStart=strSou.indexOf(strKey);
    intEnd=strSou.indexOf(strEnd,intStart);

    //strRe=strSou.mid(intStart+strKey.length(),intEnd-intStart-strKey.length()+strEnd.length());
     strRe=strSou.mid(intStart,intEnd-intStart+strEnd.length());
    if(intStart<0)
    {
        return "0";
    }
    //qDebug()<<strRe;
    return strRe;
}

//0：正向有功，1：反向有功，2：正向无功，3：反向无功
QString MainWindow::GLFXDM_index(QString strTemp)
{
    if (strTemp ==QString::fromUtf8("有功_正向"))
    {
        return  "0";
    }
    else if (strTemp ==QString::fromUtf8("有功_反向"))
    {
        return  "1";
    }
    else if (strTemp ==QString::fromUtf8("无功_正向"))
    {
        return  "2";
    }
    else
    {
        return  "3";
    }
}

QString MainWindow::GLYSDM_index(QString strTemp)
{
    if (strTemp ==QString::fromUtf8("1.0"))
    {
        return  "01";
    }
    else if (strTemp ==QString::fromUtf8("0.2L"))
    {
        return  "02";
    }
    else if (strTemp ==QString::fromUtf8("0.25L"))
    {
        return  "03";
    }
    else if (strTemp ==QString::fromUtf8("0.25C"))
    {
        return  "04";
    }
    else if (strTemp ==QString::fromUtf8("0.3L"))
    {
        return  "05";
    }
    else if (strTemp ==QString::fromUtf8("0.3C"))
    {
        return  "06";
    }
    else if (strTemp ==QString::fromUtf8("0.5L"))
    {
        return  "07";
    }
    else if (strTemp ==QString::fromUtf8("0.5C"))
    {
        return  "08";
    }
    else if (strTemp ==QString::fromUtf8("0.8C"))
    {
        return  "09";
    }
    else if (strTemp ==QString::fromUtf8("1.0L"))
    {
        return  "10";
    }
    else
    {
        return  "11";
    }
}

//1	0.05Ib  2	0.1Ib  3	0.2Ib  4	0.5Ib  5	Ib   6	Imax   7	0.5Imax    8	4Ib   9	3Ib  10	2Ib  11	0.02Ib   12	0.01Ib
QString MainWindow::FZDLDM_index(QString strTemp)
{

    if (strTemp ==QString::fromUtf8("Imax")){
        return  "00";
    }
    else if (strTemp ==QString::fromUtf8("0.5Imax")){
        return  "01";
    }
    else if (strTemp ==QString::fromUtf8("3.0Ib")){
        return  "02";
    }
    else if (strTemp ==QString::fromUtf8("2.0Ib")) {
        return  "03";
    }
    else if (strTemp ==QString::fromUtf8("1.5Ib")){
        return  "04";
    }
    else if ((strTemp ==QString::fromUtf8("Ib"))||(strTemp ==QString::fromUtf8("1Ib"))||(strTemp ==QString::fromUtf8("1.0Ib"))){
        return  "05";
    }
    else if (strTemp ==QString::fromUtf8("0.5Ib")){
        return  "06";
    }
    else if (strTemp ==QString::fromUtf8("0.2Ib")) {
        return  "07";
    }
    else if (strTemp ==QString::fromUtf8("0.1Ib")){
        return  "08";
    }
    else if (strTemp ==QString::fromUtf8("0.05Ib")) {
        return  "09";
    }
    else if (strTemp ==QString::fromUtf8("0.03Ib")){
        return  "10";
    }
    else if (strTemp ==QString::fromUtf8("0.02Ib")) {
        return  "11";
    }
    else if (strTemp ==QString::fromUtf8("0.01Ib")){
        return  "12";
    }
    else if ((strTemp ==QString::fromUtf8("0.005Ib"))||(strTemp ==QString::fromUtf8("(Imax-Ib)/2"))) {
        return  "13";
    }
    else if (strTemp ==QString::fromUtf8("4.0Ib")){
        return  "14";
    }
    else if (strTemp ==QString::fromUtf8("5.0Ib")) {
        return  "15";
    }
    else if (strTemp ==QString::fromUtf8("6.0Ib")){
        return  "16";
    }
    else if (strTemp ==QString::fromUtf8("7.0Ib")) {
        return  "17";
    }
    else if (strTemp ==QString::fromUtf8("8.0Ib")){
        return  "18";
    }
    else if (strTemp ==QString::fromUtf8("9.0Ib")){
        return  "19";
    }
    else if (strTemp ==QString::fromUtf8("10.0Ib")){
        return  "20";
    }
    else if (strTemp ==QString::fromUtf8("11.0Ib")){
        return  "21";
    }
    else
    {
        return  "22";
    }

}

//01合元
//测试元组（A：A相，B：B相，C：C相，L：合组）
QString MainWindow::FYDM_index(QString strTemp)
{
    if(strTemp.startsWith("A"))
    {
        return  "A";
    }
    else if(strTemp.startsWith("B"))
    {
        return  "B";
    }
    else if(strTemp.startsWith("C"))
    {
        return  "C";
    }
    else
    {
        return  "L";
    }
}
//01合格  02 不合格 03未检查 04重新检定
QString MainWindow::JLDM_index(QString strTemp)
{
    if (strTemp ==QString::fromUtf8("合格"))
    {
        return  "1";
    }
    else if(strTemp ==QString::fromUtf8("不合格"))
    {
        return  "2";
    }
    else if(strTemp ==QString::fromUtf8("未检查"))
    {
        return  "3";
    }
    else
    {
        return  "4";
    }
}

QString MainWindow::JBWCSYJLDM_index(QString strTemp)
{
    if (strTemp ==QString::fromUtf8("合格"))
    {
        return  "1";
    }
    else
    {
        return  "0";
    }
}
#if 1

QString MainWindow::PLDM_index(QString strTemp)
{
    if (strTemp ==QString::fromUtf8("49"))
    {
        return  "01";
    }
    else if (strTemp ==QString::fromUtf8("50"))
    {
        return  "02";
    }
    else if (strTemp ==QString::fromUtf8("51"))
    {
        return  "03";
    }
    else
    {
        return "04";
    }
}
#endif

#if 1
QString MainWindow::DYDM_index(QString strTemp)
{
    if (strTemp ==QString::fromUtf8("50%Un"))
    {
        return  "00";
    }
    else if (strTemp ==QString::fromUtf8("60%Un"))
    {
        return  "01";
    }
    else if (strTemp ==QString::fromUtf8("70%Un"))
    {
        return  "02";
    }
    else if (strTemp ==QString::fromUtf8("80%Un"))
    {
        return  "03";
    }
    else if (strTemp ==QString::fromUtf8("100%Un"))
    {
        return  "04";
    }
    else if (strTemp ==QString::fromUtf8("110%Un"))
    {
        return  "05";
    }
    else if (strTemp ==QString::fromUtf8("115%Un"))
    {
        return  "06";
    }
    else if (strTemp ==QString::fromUtf8("120%Un"))
    {
        return  "07";
    }
    else if (strTemp ==QString::fromUtf8("90%Un"))
    {
        return  "08";
    }
    return  "04";

}
#endif


QString MainWindow::EFFECT_index(QString strTemp)
{
    if (strTemp.indexOf(QString::fromUtf8("电压影响"))>0)
    {
        return  "01";
    }
    else if (strTemp.indexOf(QString::fromUtf8("频率影响"))>0)
    {
        return  "02";
    }
    else if (strTemp.indexOf(QString::fromUtf8("逆相序影响"))>0)
    {
        return  "03";
    }
    else if (strTemp .indexOf(QString::fromUtf8("电压不平衡影响"))>0)
    {
        return  "04";
    }
    else if (strTemp.indexOf(QString::fromUtf8("电流线路和电压线"))>0)
    {
        return  "05";
    }
    else if (strTemp.indexOf(QString::fromUtf8("交流电流线路中直流")>0))
    {
        return  "06";
    }
    else if (strTemp.indexOf(QString::fromUtf8("交流电流线路中奇次"))>0)
    {
        return  "07";
    }
    else if (strTemp.indexOf(QString::fromUtf8("交流电流线路中次谐波"))>0)
    {
        return  "08";
    }
    else if (strTemp.indexOf(QString::fromUtf8("外磁场影响试"))>0)
    {
        return  "09";
    }
    else if (strTemp.indexOf(QString::fromUtf8("0.5mT工频磁场带负"))>0)
    {
        return  "10";
    }
    else
    {
        return "11";
    }
}

