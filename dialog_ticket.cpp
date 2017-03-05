#include "dialog_ticket.h"
#include "ui_dialog_ticket.h"
#include "res.h"
#include<QDebug>
//界面的构造函数
Dialog_ticket::Dialog_ticket(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_ticket)
{
    ui->setupUi(this);//绑定界面
    QStringList strList;//表投信息
    //绑定表头信息
    strList.append("ID of ticket");
    strList.append("User ID");
    strList.append("plane ID");
    strList.append("Status");

    //设置列数
     ui->tw_ticket->setColumnCount(4);
      //设置行数
     ui->tw_ticket->setRowCount(pu->count_ticket-1);
     //加载表头
    ui->tw_ticket->setHorizontalHeaderLabels(strList);
    //遍历所有订单寻找
    for(int i=1;i<pu->count_ticket;i++){
    //将航班信息加载进tablewiget的一行中
    ui->tw_ticket->setItem(i-1,0,new QTableWidgetItem(QString::number(pu->info_ticket[i].id)));
    ui->tw_ticket->setItem(i-1,1,new QTableWidgetItem(QString::number(pu->info_ticket[i].user_id)));
    ui->tw_ticket->setItem(i-1,2,new QTableWidgetItem(QString::number(pu->info_ticket[i].plane_id)));
    //判断当前订单的状态
    if(pu->info_ticket[i].valid==0){
    ui->tw_ticket->setItem(i-1,3,new QTableWidgetItem("Finished"));
    }
    else if(pu->info_ticket[i].valid==1){
    ui->tw_ticket->setItem(i-1,3,new QTableWidgetItem("Preparing"));
      }else{
         ui->tw_ticket->setItem(i-1,3,new QTableWidgetItem("abandoned"));
    }

//设置属性
    ui->tw_ticket->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
    ui->tw_ticket->setSelectionBehavior(QAbstractItemView::SelectRows);//按行选中
    ui->tw_ticket->setSelectionMode(QAbstractItemView::SingleSelection);//只能单选
    ui->tw_ticket->resizeColumnsToContents();//自动根据内容匹配大小
    ui->tw_ticket->show();//显示
}
}
//界面的析构函数
Dialog_ticket::~Dialog_ticket()
{
    delete ui;
}
