#include "dialog_information.h"
#include "ui_dialog_information.h"
#include "res.h"
#include<qstring.h>
#include<ctime>
#include<qmessagebox.h>
//时间戳转时间字符串，注释与dialog_ed_plane中的方法一样
char* timetoChar(long l){
    static char str[20];
    std::time_t t = (std::time_t) l;
    struct tm* ti = localtime(&t);
    strftime(str, 20, "%Y/%m/%d %H:%M", ti);
    return str;
}
//界面的构造函数
Dialog_information::Dialog_information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_information)
{

    ui->setupUi(this);//绑定界面
    ui->label_ticket->setText(QString::number(ticket_id));//label显示订单号
    //判断订单状态，度过为0则显示完成
    //为1则显示准备中，为2则显示放弃
    if(pu->info_ticket[ticket_id].valid==0){
        ui->label_status->setText("Finished");
    }else if(pu->info_ticket[ticket_id].valid==1){
         ui->label_status->setText("Preparing");
    }else{
         ui->label_status->setText("abandoned");
    }

//根据用户id寻找此用户的内存位置
    for(int i=1;i<pu->count_user;i++){
        if(pu->info_user[i].id==user_id){
            //如果此地址的用户与需要寻找的用户的id相同
            //显示其id和姓名
            ui->label_userld->setText(QString::number( user_id));
            ui->label_user->setText(pu->info_user[i].name);
            break;

        }
    }

//根据航班号寻找航班
    for(int i=1;i<pu->count_plane;i++){
        if(pu->info[i].number_of_plane==plane_id){
              //如果此航班号与需要寻找的航班号相同
            //显示其航班号，起飞到达城市，时间
            ui->label_flight->setText(QString::number(plane_id));
            ui->label_tc->setText(QString::number(pu->info[i].take_off_city));
            ui->label_ac->setText(QString::number(pu->info[i].arrive_city));
            ui->label_tt->setText(timetoChar(pu->info[i].take_off_time));
            ui->label_at->setText(timetoChar(pu->info[i].arrive_time));
             break;

        }
    }


}

Dialog_information::~Dialog_information()
{
    delete ui;
}

void Dialog_information::on_btn_cancle_clicked()
{

    QMessageBox qb;
    if(pu->refund_booking(ticket_id)){
        qb.about(this,"Mention","Success");
        ui->label_status->setText("abandoned");
    }else{
        qb.about(this,"Mention","Fail");

    }


}
