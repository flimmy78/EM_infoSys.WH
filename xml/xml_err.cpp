#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QDebug"
#include "QMessageBox"
#include "QTextStream"
#include "QCryptographicHash"

QString MainWindow::error_info(QString errInfo)
{
    qDebug()<<errInfo;
    QString strRet;
    //strRet.endsWith();
    if(errInfo.endsWith("0000")){
        strRet =QString::fromUtf8("成功");
    }else if(errInfo.endsWith("0001")){
        strRet =QString::fromUtf8("非法的接口服务KEY");
    }else if(errInfo.endsWith("0002")){
        strRet =QString::fromUtf8("签名校验错误");
    }else if(errInfo.endsWith("0003")){
        strRet =QString::fromUtf8("参数缺失,文件流缺失");
    }else if(errInfo.endsWith("0004")){
        strRet =QString::fromUtf8("参数缺失,xml拼写错误");
    }else if(errInfo.endsWith("8001")){
        strRet =QString::fromUtf8("网络连接失败");
    }else if(errInfo.endsWith("8002")){
        strRet =QString::fromUtf8("数据库连接失败");
    }else if(errInfo.endsWith("8003")){
        strRet =QString::fromUtf8("请求超时");
    }else if(errInfo.endsWith("9999")){
        strRet =QString::fromUtf8("其他未知错误");
    }else if(errInfo.endsWith("1001")){
        strRet =QString::fromUtf8("样品不存在");
    }else if(errInfo.endsWith("1002")){
        strRet =QString::fromUtf8("无法获取检定样品参数信息");
    }else if(errInfo.endsWith("1003")){
        strRet =QString::fromUtf8("样品编号不合法");
    }else if(errInfo.endsWith("1004")){
        strRet =QString::fromUtf8("样品编号字符长度不正确");
    }else if(errInfo.endsWith("1005")){
        strRet =QString::fromUtf8("样品编号查询出多条记录 请联系管理员解决该问题");
    }else if(errInfo.endsWith("1006")){
        strRet =QString::fromUtf8("样品编号字符格式不正确");
    }else if(errInfo.endsWith("1007")){
        strRet =QString::fromUtf8("此样品暂无工作令信息");
    }else if(errInfo.endsWith("1008")){
        strRet =QString::fromUtf8("执行插入试验数据失败");
    }else if(errInfo.endsWith("1009")){
        strRet =QString::fromUtf8("该样品所有项目均已提交，试验数据上传失败！");
    }else if(errInfo.endsWith("1010")){
        strRet =QString::fromUtf8("项目编号对应错误！");
    }else if(errInfo.endsWith("1011")){
        strRet =QString::fromUtf8("无法获得上传的项目数据");
    }else if(errInfo.endsWith("1012")){
        strRet =QString::fromUtf8("样品暂无对应的检验任务信息");
    }else if(errInfo.endsWith("1013")){
        strRet =QString::fromUtf8("以下上传的项目在信息化平台中无法获得对应信息,不能上传");
    }else if(errInfo.endsWith("1014")){
        strRet =QString::fromUtf8("以下上传的项目在信息化平台中未派发,不能上传");
    }else if(errInfo.endsWith("1015")){
        strRet =QString::fromUtf8("以下上传的项目在信息化平台中已提交,不能再次上传");
    }else if(errInfo.endsWith("1016")){
        strRet =QString::fromUtf8("以下上传的项目在信息化平台中未领取,不能上传");
    }else if(errInfo.endsWith("8989")){
        strRet =QString::fromUtf8("更新状态表失败");
    }else if(errInfo.endsWith("9999")){
        strRet =QString::fromUtf8("其他未知错误");
    }else if(errInfo.endsWith("1102")){
        strRet =QString::fromUtf8("样品编号字符长度不正确");
    }
    return strRet;
}

