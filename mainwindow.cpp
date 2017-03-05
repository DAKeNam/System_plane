#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>
#include"res.h"
#include<time.h>
#include<QDebug>
#include<QDateTime>
#include<QTimer>
#include<cmath>
#define Random(x) (rand() % x)//随机数生成

//主界面的构造函数
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);//绑定界面

    //订单信息显示
    QStringList strList;//绑定表头信息
    strList.append("ID of ticket");
    strList.append("User ID");
    strList.append("plane ID");
    strList.append("Status");
 //设置列数
     ui->tw_show->setColumnCount(4);
//设置行数
     ui->tw_show->setRowCount(pu->count_ticket-1);
     //设置表头
    ui->tw_show->setHorizontalHeaderLabels(strList);
    //遍历订单
    for(int i=1;i<pu->count_ticket;i++){
     //绑定信息到tablewiget的灭一个item

    ui->tw_show->setItem(i-1,0,new QTableWidgetItem(QString::number(pu->info_ticket[i].id)));
    ui->tw_show->setItem(i-1,1,new QTableWidgetItem(QString::number(pu->info_ticket[i].user_id)));

    ui->tw_show->setItem(i-1,2,new QTableWidgetItem(QString::number(pu->info_ticket[i].plane_id)));

    if(pu->info_ticket[i].valid==0){
    ui->tw_show->setItem(i-1,3,new QTableWidgetItem("Finished"));
    }
    else if(pu->info_ticket[i].valid==1){
    ui->tw_show->setItem(i-1,3,new QTableWidgetItem("Preparing"));
      }else{
         ui->tw_show->setItem(i-1,3,new QTableWidgetItem("abandoned"));
    }

    //设置属性
    ui->tw_show->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
    ui->tw_show->setSelectionBehavior(QAbstractItemView::SelectRows);//行选择
    ui->tw_show->setSelectionMode(QAbstractItemView::SingleSelection);//只可单选
    ui->tw_show->resizeColumnsToContents();//设置内容自动适配大小
    ui->tw_show->show();

}
//绑定城市界面
 city=new int*[7];
 for(int i=0;i<7;i++){
     city[i]=new int[2];//city[][0]是x坐标，city[][1]使y坐标
 }
  city[1][0]=ui->l_1->x();
  city[1][1]=ui->l_1->y();
  city[2][0]=ui->l_2->x();
  city[2][1]=ui->l_2->y();
  city[3][0]=ui->l_3->x();
  city[3][1]=ui->l_3->y();
  city[4][0]=ui->l_4->x();
  city[4][1]=ui->l_4->y();
  city[5][0]=ui->l_5->x();
  city[5][1]=ui->l_5->y();
  city[6][0]=ui->l_6->x();
  city[6][1]=ui->l_6->y();

  //设置初始的城市坐标
  end_x=city[1][0];
  end_y=city[1][1];
  //隐藏飞机图标
  ui->l_plane->hide();
  //设置计时器
  QTimer *timer = new QTimer(this);
  //绑定计时器信号绑定槽函数
  connect(timer, SIGNAL(timeout()),
          this, SLOT(updateTime()));
  //每10毫秒更新一次
  timer->start(10);


}


//析构函数
MainWindow::~MainWindow()
{

    delete ui;//删除界面
    //删除城市数组
    for(int i=0;i<7;i++){
        delete[] city[i];
    }
    delete[] city;

   //调用工具类的析构函数
    pu->~planeUtil();

}

//订单刷新函数
void MainWindow::rebuild(){
    //设置函数
       ui->tw_show->setRowCount(pu->count_ticket-1);
       //遍历订单
    for(int i=1;i<pu->count_ticket;i++){
     //绑定订单信息到tablewiget的每一个item

    ui->tw_show->setItem(i-1,0,new QTableWidgetItem(QString::number(pu->info_ticket[i].id)));
    ui->tw_show->setItem(i-1,1,new QTableWidgetItem(QString::number(pu->info_ticket[i].user_id)));

    ui->tw_show->setItem(i-1,2,new QTableWidgetItem(QString::number(pu->info_ticket[i].plane_id)));

    if(pu->info_ticket[i].valid==0){
    ui->tw_show->setItem(i-1,3,new QTableWidgetItem("Finished"));
    }
    else if(pu->info_ticket[i].valid==1){
    ui->tw_show->setItem(i-1,3,new QTableWidgetItem("Prepaing"));
      }else{
         ui->tw_show->setItem(i-1,3,new QTableWidgetItem("abandoned"));
    }


}
        ui->tw_show->show();
        ui->tw_show->setCurrentCell(pu->count_ticket-2,0);//将窗口移动到最新的一行
}
//显示飞机窗口
void MainWindow::on_pushButton_clicked()
{
    pw=new PlaneWindow();//申明飞机窗口类
    pw->show();
}
//显示用户窗口
void MainWindow::on_btn_user_clicked()
{
    du=new Dialog_user();//申明用户窗口类
    du->show();
}
//显示订单窗口
void MainWindow::on_btn_ticket_clicked()
{
    dt=new Dialog_ticket();//申明订单窗口
    dt->show();
}
//双击订单信息
void MainWindow::on_tw_show_doubleClicked(const QModelIndex &index)
{
    int row=index.row();//获得双击的行
    ticket_id=row+1;//订单id是行数+1
    plane_id=pu->info_ticket[row+1].plane_id;//获得航班号
    user_id=pu->info_ticket[row+1].user_id;//获得用户id
    di=new Dialog_information();//显示信息窗口
    di->show();

}


//模拟航班
void MainWindow::on_btn_m_clicked()
{
     //读取图片
     QImage* img=new QImage;
     //加载图片
     img->load( "C:/Users/zjz/Desktop/plane.jpg");
     //随机订2次票
     for(int m=0;m<2;m++)
{            //随机选择一个航班
         int x=  pu->info[Random(pu->count_plane)+1].number_of_plane;
         //随机选择一个用户
         int y= pu->info_user[ (Random(pu->count_user)+1)].id;
          //调用工具类的订票函数
         pu->booking(y,x);
     }

      //随机一个航班
     int temp=Random(pu->count_plane)+1;
     //如果航班号越界则-1
     if(temp==pu->count_plane){
         temp--;
     }
     //获得航班号
     int z=  pu->info[temp].number_of_plane;
     //获得起飞城市的坐标
     begin_x= city[pu->info[temp].take_off_city][0];
     begin_y= city[pu->info[temp].take_off_city][1];
     //获得到达城市的坐标
     end_x=city[pu->info[temp].arrive_city][0];
     end_y=city[pu->info[temp].arrive_city][1];
     //显示图片
     ui->l_plane->setPixmap(QPixmap::fromImage(*img));
     //设置图片平移的变化比例
     percent=1;
     //显示变化的航班号
     ui->l_pn->setText(QString::number(z));
     //调用工具类的完成函数
     pu->plane_finished(z);
     //刷新订单
     rebuild();


}
//时间更新的槽函数，绘制函数
void MainWindow::updateTime()
{

    //将距离分成100份
    float dx=((float)(end_x-begin_x))/100;
    float dy=((float)(end_y-begin_y))/100;
   //如果没有到达
    if(percent!=101){

         ui->l_plane->show();//显示飞机图片
          ui->l_plane->move(begin_x+dx*percent,begin_y+dy*percent);//每次移动百分之一
          percent++;
   }else{
        ui->l_plane->hide();//如果到达则隐藏
    }

}

