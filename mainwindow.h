#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <planewindow.h>
#include"dialog_user.h"
#include"dialog_ticket.h"
#include"dialog_information.h"
#include<QLabel>
//主界面
 namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();//确认按钮

    void on_btn_user_clicked();//用户按钮

    void on_btn_ticket_clicked();//订单按钮

    void on_btn_m_clicked();//模拟飞机按钮

    void updateTime();//时间更新槽函数

    void on_tw_show_doubleClicked(const QModelIndex &index);//tabelwiget双击槽函数

private:
    void rebuild();//刷新订单

    Ui::MainWindow *ui;
    PlaneWindow *pw;//指向飞机界面的指针
    Dialog_user *du;//支线用户界面的指针
    Dialog_ticket *dt;//指向订单界面的指针
    Dialog_information *di;//指向信息界面的指针

     //起飞城市的x，y坐标
    int begin_x=0;
    int begin_y=0;
    //到达城市的x，y坐标
    int end_x=0;
    int end_y=0;
    //飞机运动距离百分比
    int percent=101;
    //城市坐标二维数组
    int** city;


};
#endif // MAINWINDOW_H
