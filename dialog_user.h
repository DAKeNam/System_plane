#ifndef DIALOG_USER_H
#define DIALOG_USER_H

#include <QDialog>
//界面类
//用户界面
namespace Ui {
class Dialog_user;
}

class Dialog_user : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_user(QWidget *parent = 0);
    ~Dialog_user();

private slots:
    void on_btn_add_clicked();//添加用户按钮

private:
    Ui::Dialog_user *ui;
};

#endif // DIALOG_USER_H
