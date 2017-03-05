#include "dialog_ip_plane.h"
#include "ui_dialog_ip_plane.h"
#include<QMessageBox>
#include<res.h>
#include<qstring.h>
#include <QDebug>
#include<QTextEdit>
#include<iostream>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>
//时间字符串转时间戳
//注释与dialog_ed_plane中的转化函数相同
long toLong(char const *str)
{
    tm tm_;
    int year, month, day, hour, minute,second;
    sscanf(str,"%d/%d/%d %d:%d", &year, &month, &day, &hour, &minute);
    tm_.tm_year  = year-1900;
    tm_.tm_mon   = month-1;
    tm_.tm_mday  = day;
    tm_.tm_hour  = hour;
    tm_.tm_min   = minute;
    tm_.tm_sec   = second=0;
    tm_.tm_isdst = 0;


    time_t t_ = mktime(&tm_);
    return (long)t_;
}

//界面的构造函数
Dialog_ip_plane::Dialog_ip_plane(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_ip_plane)
{
    ui->setupUi(this);//绑定界面
}
//界面的析构函数
Dialog_ip_plane::~Dialog_ip_plane()
{
    delete ui;
}
//航班添加按钮
void Dialog_ip_plane::on_btn_add_clicked()
{
     bool ok;//用于是否添加成功
     bool success=false;
     //调用工具类的添加函数，参数从界面中获取
    success=pu->input_plane(ui->et_p_number->text().toInt(&ok),
                            toLong(ui->t_d->text().toStdString().c_str()),
                            toLong(ui->t_l->text().toStdString().c_str()),
                            ui->et_d_city->text().toInt(&ok),
                            ui->et_l_city->text().toInt(&ok),
                            ui->et_price->text().toInt(&ok),
                            ui->et_discount->text().toInt(&ok),
                            ui->et_people->text().toInt(&ok));


    if(success){//判断结果
        QMessageBox::about(NULL,"METION","添加成功");
    }else{
        QMessageBox::about(NULL,"METION","错误输入");
    }
}

//确认按钮
void Dialog_ip_plane::on_btn_decide_clicked()
{
    pw=new PlaneWindow();//生成飞机窗口
    pw->show();//显示
    this->close();//关闭此窗口
}
