#ifndef DIALOG_ED_PLANE_H
#define DIALOG_ED_PLANE_H

#include <QDialog>
//界面类
//飞机信息修改界面
namespace Ui {
class Dialog_ed_plane;
}

class Dialog_ed_plane : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_ed_plane(QWidget *parent = 0);
    ~Dialog_ed_plane();


private slots:
    void on_btn_fn_clicked();//修改航班号

    void on_btn_tc_clicked();//修改起飞城市

    void on_btn_lc_clicked();//修改登陆城市

    void on_btn_p_clicked();//修改价格

    void on_btn_d_clicked();//修改折扣

    void on_btn_tt_clicked();//修改起飞时间

    void on_btn_at_clicked();//修改到达时间

    void on_pushButton_clicked();//确认按钮

private:
    Ui::Dialog_ed_plane *ui;
};

#endif // DIALOG_ED_PLANE_H
