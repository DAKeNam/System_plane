#ifndef DIALOG_INFORMATION_H
#define DIALOG_INFORMATION_H

#include <QDialog>

//界面类
//用户详细信息
namespace Ui {
class Dialog_information;
}

class Dialog_information : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_information(QWidget *parent = 0);
    ~Dialog_information();

private slots:
    void on_btn_cancle_clicked();//取消订单按钮

private:
    Ui::Dialog_information *ui;
};

#endif // DIALOG_INFORMATION_H
