#include "dialog_user.h"
#include "ui_dialog_user.h"
#include"res.h"
#include<QString>
#include<QMessageBox>
//界面的构造函数
Dialog_user::Dialog_user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_user)
{
    ui->setupUi(this);//绑定界面
    QStringList strList;//设置表头信息
    strList.append("UserID");
    strList.append("User name");
    strList.append("Tickets");
//设置列数
     ui->tw_user->setColumnCount(3);
     //设置行数
    ui->tw_user->setRowCount(pu->count_user-1);
    //绑定表头
    ui->tw_user->setHorizontalHeaderLabels(strList);
    //遍历用户信息
    for(int i=1;i<pu->count_user;i++){
    //给tablewiget的item绑定信息，如用户id，用户名，用户订单号
    ui->tw_user->setItem(i-1,0,new QTableWidgetItem(QString::number(pu->info_user[i].id)));
    ui->tw_user->setItem(i-1,1,new QTableWidgetItem(pu->info_user[i].name));
    ui->tw_user->setItem(i-1,2,new QTableWidgetItem(QString::number(pu->info_user[i].number_of_ticket)));

      }
     //设置属性
    ui->tw_user->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
    ui->tw_user->setSelectionBehavior(QAbstractItemView::SelectRows);//行选择
    ui->tw_user->setSelectionMode(QAbstractItemView::SingleSelection);//只能单循
    ui->tw_user->resizeColumnsToContents();//自适应大小
    ui->tw_user->show();
}
//界面析构函数
Dialog_user::~Dialog_user()
{
    delete ui;


}
//添加用户按钮
void Dialog_user::on_btn_add_clicked()
{    //获取界面的输入信息
    QString userid=ui->et_userid->text();
    QString username=ui->et_username->text();
    //设置一个提醒框
    QMessageBox qb;
    bool ok;//用于判断修改是否成功
    if(pu->input_uer(userid.toInt(&ok),username.toStdString())){//调用工具类的添加用户函数
                qb.about(this,"Mention","success");//成功
    }else{
          qb.about(this,"Mention","User ID already exist");//失败
    }
    ui->tw_user->setRowCount(pu->count_user-1);//设置行数
    for(int i=1;i<pu->count_user;i++){
//遍历绑定信息
    ui->tw_user->setItem(i-1,0,new QTableWidgetItem(QString::number(pu->info_user[i].id)));
    ui->tw_user->setItem(i-1,1,new QTableWidgetItem(pu->info_user[i].name));
    ui->tw_user->setItem(i-1,2,new QTableWidgetItem(QString::number(pu->info_user[i].number_of_ticket)));
      }

    ui->tw_user->show();

}
