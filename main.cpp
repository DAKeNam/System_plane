#include "mainwindow.h"
#include "planewindow.h"
#include"dialog_ip_plane.h"
#include <QApplication>
#include<stdio.h>
#include<iostream>
#include<fstream>
#include<planeUtil.h>
#include"res.h"

//主方法
int main(int argc, char *argv[])
{
    //声明一个QT的程序类
    QApplication a(argc, argv);
    //获得一个工具类的指针，赋值给res的全局变量
    pu=new planeUtil;
    //申明一个主窗口
    MainWindow w;
    //显示该主窗口
    w.show();
    //执行
    return a.exec();
}
