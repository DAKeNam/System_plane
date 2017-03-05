#ifndef DIALOG_TICKET_H
#define DIALOG_TICKET_H

#include <QDialog>
//界面类
//订单界面
namespace Ui {
class Dialog_ticket;
}

class Dialog_ticket : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_ticket(QWidget *parent = 0);
    ~Dialog_ticket();

private:
    Ui::Dialog_ticket *ui;
};

#endif // DIALOG_TICKET_H
