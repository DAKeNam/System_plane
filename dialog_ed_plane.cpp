#include "dialog_ed_plane.h"
#include "ui_dialog_ed_plane.h"
#include "planewindow.h"
#include "res.h"
#include<ctime>
#include<QString>
#include<QDebug>
#include<QPushButton>
#include<QInputDialog>


//时间字符串转化为Long
long toLongs(char const *str)
{
    tm tm_;
    int year, month, day, hour, minute,second;
    sscanf(str,"%d/%d/%d %d:%d", &year, &month, &day, &hour, &minute);//按预定格式读取字符串
    tm_.tm_year  = year-1900;//因为tm的年份默认是从1900开始
    tm_.tm_mon   = month-1;//month是0-11 所以减去1
    tm_.tm_mday  = day;
    tm_.tm_hour  = hour;
    tm_.tm_min   = minute;
    tm_.tm_sec   = second=0;//没有精确到秒所以设为0
    tm_.tm_isdst = 0;//表示关闭夏令时


    time_t t_ = mktime(&tm_); //创建time_t
    return (long)t_; //强制类型转化为long
}
//时间戳转化为时间字符串
char* toChars(long l){
    static char str[20];//默认字符串最大为20
    std::time_t t = (std::time_t) l;//强制类型转化为long
    struct tm* ti = localtime(&t);//按照格式tm默认的创建ti
    strftime(str, 20, "%Y/%m/%d %H:%M", ti);//格式化ti
    return str;
}

//界面的构造方法
Dialog_ed_plane::Dialog_ed_plane(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_ed_plane)
{
    ui->setupUi(this);//绑定界面
    setWindowFlags(Qt::WindowStaysOnTopHint);//设置窗口在顶层
    int row=edit_row;//设置需要编辑的行

    //下面的代码都是修改按钮的值使其位待修改的值
    //info是飞机数组
    //pu指向工具类的指针
    ui->btn_fn->setText(QString::number(pu->info[row+1].number_of_plane));
       qDebug()<<row;
    ui->btn_tc->setText(QString::number(pu->info[row+1].take_off_city));
    ui->btn_lc->setText(QString::number(pu->info[row+1].arrive_city));
    ui->btn_tt->setText(toChars(pu->info[row+1].take_off_time));
    ui->btn_at->setText(toChars(pu->info[row+1].arrive_time));
    ui->btn_p->setText(QString::number(pu->info[row+1].cost));
    ui->btn_d->setText(QString::number(pu->info[row+1].discount));

}
//析构函数，关闭界面
Dialog_ed_plane::~Dialog_ed_plane()
{
    delete ui;

}

//航班信息修改按钮
//下面的几个方法结构完全一样，都是打开一个对话框，修改其中的内容，关闭对话框
void Dialog_ed_plane::on_btn_fn_clicked()
{

    bool ok;//判断是否先改成功
    //打开一个对话框，用于编辑航班号
    int number=QInputDialog::getInt(this,tr("Message box"),tr("Flight number"),
                                 pu->info[edit_row+1].number_of_plane,0,9999,1,&ok);
    if(ok){//如果修改成功
        ui->btn_fn->setText(QString::number(number));//修改按钮文字
          pu->info[edit_row+1].number_of_plane=number;//修改航班的航班号
    }
}



//修改起飞城市
void Dialog_ed_plane::on_btn_tc_clicked()
{
    bool ok;
    int number=QInputDialog::getInt(this,tr("Message box"),tr("Take off city"),
                                 pu->info[edit_row+1].take_off_city,0,9999,1,&ok);
    if(ok){
        ui->btn_tc->setText(QString::number(number));
          pu->info[edit_row+1].take_off_city=number;
    }
}

//修改到达城市
void Dialog_ed_plane::on_btn_lc_clicked()
{
    bool ok;
    int number=QInputDialog::getInt(this,tr("Message box"),tr("Land city"),
                                 pu->info[edit_row+1].arrive_city,0,9999,1,&ok);
    if(ok){
        ui->btn_lc->setText(QString::number(number));
          pu->info[edit_row+1].arrive_city=number;
    }
}
//修改价格
void Dialog_ed_plane::on_btn_p_clicked()
{
    bool ok;
    int number=QInputDialog::getInt(this,tr("Message box"),tr("Price"),
                                 pu->info[edit_row+1].cost,0,9999,1,&ok);
    if(ok){
        ui->btn_p->setText(QString::number(number));
          pu->info[edit_row+1].cost=number;
    }
}
//修改折扣
void Dialog_ed_plane::on_btn_d_clicked()
{
    bool ok;
    int number=QInputDialog::getInt(this,tr("Message box"),tr("Discount"),
                                 pu->info[edit_row+1].discount,0,9999,1,&ok);
    if(ok){
        ui->btn_d->setText(QString::number(number));
          pu->info[edit_row+1].discount=number;
    }
}
//修改起飞时间
void Dialog_ed_plane::on_btn_tt_clicked()
{
    bool ok;
    int number=QInputDialog::getInt(this,tr("Message box"),tr("Take off time"),
                                 pu->info[edit_row+1].take_off_time,0,9999,1,&ok);
    if(ok){
        ui->btn_tt->setText(QString::number(number));
          pu->info[edit_row+1].take_off_time=number;
    }
}
//修改达到时间
void Dialog_ed_plane::on_btn_at_clicked()
{
    bool ok;
    int number=QInputDialog::getInt(this,tr("Message box"),tr("Land time"),
                                 pu->info[edit_row+1].arrive_time,0,9999,1,&ok);
    if(ok){
        ui->btn_at->setText(QString(tr("%1")).arg(number));
          pu->info[edit_row+1].arrive_time=number;
    }
}





void Dialog_ed_plane::on_pushButton_clicked()
{
    pw=new PlaneWindow();
    pw->show();
    this->close();
}
