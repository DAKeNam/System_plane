#ifndef PLANEWINDOW_H
#define PLANEWINDOW_H

#include <QMainWindow>
#include <QListView>
#include <QStandardItem>
#include <QModelIndex>
#include <QStringListModel>
#include <QStringList>
#include "dialog_ip_plane.h"
#include"dialog_ed_plane.h"

namespace Ui {
class PlaneWindow;
}
class PlaneWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlaneWindow(QWidget *parent = 0);
    ~PlaneWindow();
private slots:

    void on_tw_plane_doubleClicked(const QModelIndex &index);//tablewiget双击槽函数

    void on_pushButton_clicked();//确认按钮

    void on_btn_check_clicked();//查询航班按钮

    void on_btn_book_clicked();//订票按钮

    void on_tw_plane_clicked(const QModelIndex &index);//选择航班按钮

private:
    Ui::PlaneWindow *ui;
    Dialog_ip_plane *dip;
    Dialog_ed_plane *dep;

};

#endif // PLANEWINDOW_H
