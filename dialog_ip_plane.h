#ifndef DIALOG_IP_PLANE_H
#define DIALOG_IP_PLANE_H

#include <QDialog>
#include<QAbstractButton>

//界面类
//航班添加界面
namespace Ui {
class Dialog_ip_plane;
};
class Dialog_ip_plane : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_ip_plane(QWidget *parent = 0);
    ~Dialog_ip_plane();

private slots:
    void on_btn_add_clicked();//添加航班按钮


    void on_btn_decide_clicked();//确认按钮

private:
    Ui::Dialog_ip_plane *ui;
};

#endif // DIALOG_IP_PLANE_H
