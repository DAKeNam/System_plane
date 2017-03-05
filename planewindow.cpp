#include "planewindow.h"
#include "ui_planewindow.h"
#include <QDebug>
#include<iostream>
#include<QTableWidget>
#include<iostream>
#include<QString>
#include<ctime>
#include<res.h>
#include<QMessageBox>
#include<QInputDialog>

int row=0;//当前点击的行数
//时间戳转时间字符串，注释与dialog_ed_plane的函数相同
char* toChar(long l){
    static char str[20];
    std::time_t t = (std::time_t) l;
    struct tm* ti = localtime(&t);
    strftime(str, 20, "%Y/%m/%d %H:%M", ti);
    return str;
}

//界面的构造函数
PlaneWindow::PlaneWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlaneWindow)
{
      ui->setupUi(this);//绑定界面
      //加载表头
      QStringList strList;
      strList.append("Flight number");
      strList.append("Departure city");
      strList.append("Land city");
      strList.append("Departure time");
      strList.append("land time");
      strList.append("Price");
      strList.append("Discount");
      strList.append("People");
      //设置列数
       ui->tw_plane->setColumnCount(8);
      //设置行数
       ui->tw_plane->setRowCount(pu->count_plane-1);
       //绑定表头
      ui->tw_plane->setHorizontalHeaderLabels(strList);
      //循环加载航班信息
      for(int i=1;i<pu->count_plane;i++){
      //为每个item绑定航班信息
      ui->tw_plane->setItem(i-1,0,new QTableWidgetItem(QString::number(pu->info[i].number_of_plane)));
      ui->tw_plane->setItem(i-1,1,new QTableWidgetItem(QString::number(pu->info[i].take_off_city)));
      ui->tw_plane->setItem(i-1,2,new QTableWidgetItem(QString::number(pu->info[i].arrive_city)));
      //暂存时间字符串
      char* d_t = toChar(pu->info[i].take_off_time);
      ui->tw_plane->setItem(i-1,3,new QTableWidgetItem(d_t));
      //暂存时间字符串
      char* d_l= toChar(pu->info[i].arrive_time);
      ui->tw_plane->setItem(i-1,4,new QTableWidgetItem(d_l));
      ui->tw_plane->setItem(i-1,5,new QTableWidgetItem(QString::number(pu->info[i].cost)));
      ui->tw_plane->setItem(i-1,6,new QTableWidgetItem(QString::number(pu->info[i].discount)));
      ui->tw_plane->setItem(i-1,7,new QTableWidgetItem(QString::number(pu->info[i].remain_number)));
      }
      //设置属性
      ui->tw_plane->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
      ui->tw_plane->setSelectionBehavior(QAbstractItemView::SelectRows);//行选择
      ui->tw_plane->setSelectionMode(QAbstractItemView::SingleSelection);//选择模式为单选
      ui->tw_plane->resizeColumnsToContents();//自动适配大小
      ui->tw_plane->show();

}
//析构函数
PlaneWindow::~PlaneWindow()
{
    delete ui;
}

//双击函数
void PlaneWindow::on_tw_plane_doubleClicked(const QModelIndex &index)
{

 edit_row=index.row();//返回点击的行
 dep=new Dialog_ed_plane();//申明一个编辑界面
 dep->show();//显示编辑界面
 this->close();//关闭此界面
 delete ui;
}

//添加按钮
void PlaneWindow::on_pushButton_clicked()
{
    dip = new Dialog_ip_plane();//申明一个添加窗口
    dip->show();//显示添加窗口
    this->close();//关闭当前窗口
    delete ui;

}

//查询函数
void PlaneWindow::on_btn_check_clicked()
{    //获取要查询的航班号或者起飞城市，到达城市
    QString qfn=ui->et_fn->text();
    QString qtc=ui->et_tc->text();
    QString qlc=ui->et_lc->text();
    bool ok;//判断是否成功
    //暂时存放
    int fn;
    int tc;
    int lc;
    //Qstring转int
    fn=qfn.toInt(&ok);
    tc=qtc.toInt(&ok);
    lc=qlc.toInt(&ok);
    //遍历所有航班
    for(int i=1;i<pu->count_plane;i++){
        //根据航班号或者根据到达和起飞城市
        if(fn==pu->info[i].number_of_plane||(pu->info[i].take_off_city==tc&&pu->info[i].arrive_city==lc)){
            //如果存在则跳转到当行
            ui->tw_plane->setCurrentCell(i-1,0);
        }

    }


}
//订票按钮点击函数
void PlaneWindow::on_btn_book_clicked()
{
    bool ok;
    //打开一个输入框，用于输入用于id
    int number=QInputDialog::getInt(this,tr("Message box"),tr("UserId"),
                                 0,0,9999,1,&ok);
    //打开一个提示框用于提醒是否加载成功
      QMessageBox qb;
      //获取当前航班号
      int plane_number=pu->info[row+1].number_of_plane;
      //判断是否输入成功且订票成功
    if(ok&&pu->booking(number,plane_number)){
                qb.about(this,"Mention","success");//成功
    }else{
          qb.about(this,"Mention","Use ID doesn't exist");//失败
    }

}
//点击函数
void PlaneWindow::on_tw_plane_clicked(const QModelIndex &index)
{
    row=index.row();//返回当前点击的函数
}
