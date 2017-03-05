#include "planeUtil.h"
#include<iostream>
#include<fstream>
#include<Qstring>
#include<string>
#include<QDebug>
//工具类
//构造函数
planeUtil::planeUtil()
{
    info = new plane[20];//存放飞机的数组
    info_ticket = new ticket[500];//存放订单数组
    info_user = new User[50];//存放用户数组
    for (int i = 0; i < 20; i++) {//初始化航班
        info[i].number_of_plane = 0;
    }
    for (int i = 0; i < 500; i++) {//初始化订单
        info_ticket[i].id = 0;
    }
    for (int i = 0; i < 50; i++) {//初始话用户
        info_user[i].id = 0;
    }


     //文件读取模块
    //飞机信息读取模块
    FILE* fh;
    fopen_s(&fh, "plane.txt", "r");//打开飞机文件，设置模式为可读
    if (fh == NULL) {//如果不存在该文件
        fopen_s(&fh, "plane.txt", "wb+");//以写的方式创建此文件
        fprintf(fh,"%d\n", count_plane);//第一行为航班数
        fprintf(fh,"%s", "0 0 0 0 0 0 0 0\n");//第一行为初始化数据
        fclose(fh);//关闭读取
        fopen_s(&fh, "plane.txt", "r");//以只读的方式打开
    }

        fscanf_s(fh,"%d\n",&count_plane);//读取航班数
        for (int i = 0; i < count_plane; i++) {
            //读取信息，分别是航班号，起飞，到达时间（long），起飞到达城市，价格，折扣，剩余人数
            fscanf_s(fh, "%d %ld %ld %d %d %d %d %d\n",
                     &(info[i].number_of_plane),
                     &(info[i].take_off_time),
                     &(info[i].arrive_time),
                     &(info[i].take_off_city),
                     &(info[i].arrive_city),
                     &(info[i].cost),
                     &(info[i].discount),
                     &(info[i].remain_number));


        }
        fclose(fh);//关闭读取
           //读取订单信息
        FILE* fh_ticket;
        fopen_s(&fh_ticket, "ticket.txt", "r");//设置为只读
        if (fh_ticket == NULL) {//如果文件不存在
            fopen_s(&fh_ticket, "ticket.txt", "wb+");//设置为写
            fprintf(fh_ticket, "%d\n", count_ticket);//写入订单数
            fprintf(fh_ticket, "%s", "0 0 0 0\n");//写入初始化数据
            fclose(fh_ticket);//关闭写
            fopen_s(&fh_ticket, "ticket.txt", "r");//以只读方式打开
        }
        fscanf_s(fh_ticket, "%d\n", &count_ticket);//读取订单数
        for (int i = 0; i < count_ticket; i++) {
            //读取订单信息，订单id，用户id，航班id，状态
            fscanf_s(fh_ticket, "%d %d %d %d\n", &(info_ticket[i].id), &(info_ticket[i].user_id), &(info_ticket[i].plane_id),&(info_ticket[i].valid));
        }
        fclose(fh_ticket);//关闭文件

      //读取用户信息
        FILE* fh_user;
        fopen_s(&fh_user, "user.txt", "r");//设置为制度
        if (fh_user == NULL) {//如果文件不存在
            fopen_s(&fh_user, "user.txt", "wb+");//设置为写
            fprintf(fh_user, "%d\n", count_user);//写入用户数
            fprintf(fh_user, "%s", "0 0 a\n ");//写入初始化数据
            fclose(fh_user);//关闭写
            fopen_s(&fh_user, "user.txt", "r");//以只读方式打开
        }

        fscanf_s(fh_user, "%d\n", &count_user);//读取用户数

        for (int i = 0; i < count_user; i++) {
            //读取用户信息 id，订单数，姓名
            fscanf_s(fh_user, "%d %d %s", &(info_user[i].id), &(info_user[i].number_of_ticket), (info_user[i].name),10);
             //再次遍历读取订单
            for (int j = 0; j < info_user[i].number_of_ticket; j++) {
                //读取该用户的订单号
                fscanf_s(fh_user, " %d", &(info_user[i].ticket[j]));
            }
            //读取换行符
            fscanf_s(fh_user, "\n");
        }
        fclose(fh_user);//关闭读


}


//析构函数，文件写入模块
planeUtil::~planeUtil()
{
    //航班模块
    FILE *fh;
    fopen_s(&fh, "plane.txt", "wb+");//打开文件，写的模式
    fprintf(fh, "%d\n", count_plane);//写进航班数
    for (int i = 0; i < count_plane; i++) {
     //写入航班信息
    fprintf(fh, "%d %ld %ld %ld %d %d %d %d\n", (info[i].number_of_plane), (info[i].take_off_time), (info[i].arrive_time), (info[i].take_off_city), (info[i].arrive_city), (info[i].cost), (info[i].discount), (info[i].remain_number));


    }
    fclose(fh);//关闭文件写入
    delete []info;//清除航班数组

    //订单模块
    FILE *fh_ticket;
    fopen_s(&fh_ticket, "ticket.txt", "wb+");//打开文件，写的模式
    fprintf(fh_ticket, "%d\n", count_ticket); //写进订单数
    for (int i = 0; i < count_ticket; i++) {
        //写入订单数
        fprintf(fh_ticket, "%d %d %d %d\n", (info_ticket[i].id), (info_ticket[i].user_id), (info_ticket[i].plane_id),(info_ticket[i].valid));
    }
    fclose(fh_ticket);
    delete []info_ticket;//清除订单数组

    //用户模块
    FILE *fh_user;
    fopen_s(&fh_user, "user.txt", "wb+");//打开文件
    fprintf(fh_user, "%d\n", count_user);//写入用户数
    for (int i = 0; i < count_user; i++) {
        //写入用户信息
        fprintf(fh_user, "%d %d %s", (info_user[i].id), (info_user[i].number_of_ticket), (info_user[i].name));
        //循环写入订单信息
        for (int j = 0; j < info_user[i].number_of_ticket; j++) {
            fprintf(fh_user, " %d", (info_user[i].ticket[j]));
        }
        fprintf(fh_user, "\n");//写换行符
    }
    fclose(fh_user);//关闭文件写
    delete []info_user;

}

//写入航班信息
bool planeUtil::input_plane(int fnumber,long dt,long lt,int dc,int lc,int cost,int discount,int people)
{
     //数组下标
    int i = 0;
    //判断航班是否已经存在
    for (;i < count_plane; i++) {
        if (fnumber == info[i].number_of_plane) {
            //有重复的航班，返回错误
            return false;
        }
    }
    if (i == 20) {
        return false;//数组越界
    }
    //信息赋值
    info[i].number_of_plane = fnumber;
    info[i].take_off_time=dt;
    info[i].arrive_time=lt;
    info[i].take_off_city = dc;
    info[i].arrive_city = lc;
    info[i].cost = cost;
    info[i].discount = discount;
    info[i].remain_number = people;
    //航班数++
    count_plane++;

    return true;
}
//添加用户
bool planeUtil::input_uer(int userid,std::string username)
{
    //数组下标
    int i = 0;
    //判断是否有相同用户id
    for (; i < count_user; i++) {
        if (userid == info_user[i].id) {
//如果有则返回false
            return false;
        }
    }
    //越界判断
    if (i == 50) {
        return false;
    }

   //用户id赋值
    info_user[i].id = userid;
    //字符串转字符数组
    const char* temp=username.c_str();
    //字符数组赋值
    for(int j=0;j<username.size();j++){
        info_user[i].name[j]=temp[j];
    }
    //初始订单数量为0
    info_user[i].number_of_ticket = 0;
    //用户数量++
    count_user++;

    return true;
}


//订票函数
bool planeUtil::booking(int userid,int choice)
{
    //如果为值0，直接返回false
    if(choice==0||userid==0){
        return false;
    }
    //存在判断标志
    bool exist=false;
    //寻找用户id所在的内存位置
    for(int i=1;i<count_user;i++){
        //如果找到
        if(userid==info_user[i].id){
            //如果订单数超过上限，退出
            if(info_user[i].number_of_ticket==99){
                return false;
            }
            //否则表示存在
            exist=true;
            break;
        }
    }

      //如果订单总数在500内，且用户合法
    if (count_ticket< 500&&exist) {
        //用户id，航班号赋值给订单
        info_ticket[count_ticket].id = info_ticket[count_ticket - 1].id + 1;
        info_ticket[count_ticket].plane_id = choice;
        info_ticket[count_ticket].user_id = userid;
        info_ticket[count_ticket].valid = 1;
        //订单数量++
        count_ticket++;
        //寻找用户
        for (int i = 1; i < count_user; i++) {
            if (info_user[i].id == userid) {
                //用户订单数++
                int x=++info_user[i].number_of_ticket;
                //用户的订单数组最后一个赋值订单号
                info_user[i].ticket[x - 1] = info_ticket[count_ticket-1].id;
            }
        }

     } else {
        return false;
    }
//寻找航班
    for(int i=1;i<count_plane;i++){
        //存在次航班且剩余人数大于等于1
        if(info[i].number_of_plane==choice&&info[i].remain_number>=1){
            info[i].remain_number--;//航班人数--
            break;
        }


    }
    return true;


}

//退票函数
bool planeUtil::refund_booking(int ticket_id)
{
       //如果订单已完成或已经被废弃，则退票无效返回false
       if(info_ticket[ticket_id].valid==0&&info_ticket[ticket_id].valid==2){
           return false;
       }
       //获得对应的航班号
      int plane_id=info_ticket[ticket_id].plane_id;
      //寻找此航班号对应的数组位置
      for(int i=1;i<count_plane;i++){
          if(info[i].number_of_plane==plane_id){
               //剩余人数++
              info[i].remain_number++;
          }
      }


       //设置标记位废弃
      info_ticket[ticket_id].valid=2;


       return true;




}



//航班完成函数
bool planeUtil::plane_finished(int plane_id){

            //设置数组标号
            int i=1;
            //计算有多少人完成订单
            int count=0;
            //寻找相关订单订单
            for(;i<count_ticket;i++){
                //如果航班号匹配，且状态为准备中
                if(info_ticket[i].plane_id==plane_id&&info_ticket[i].valid==1){
                    //修改状态为完成
                    info_ticket[i].valid=0;
                    //人数++
                    count++;
                }
            }



               //寻找对应航班的数组位置
               for(i=1;i<count_plane;i++){
                  if(info[i].number_of_plane==plane_id){
                     //如果id为0直接返回false
                      if(plane_id==0){
                          return false;
                      }
                      //达到城市和抵达城市交换
                      int temp= info[i].arrive_city;
                      info[i].arrive_city=info[i].take_off_city;
                      info[i].take_off_city=temp;
                      //起飞时间和到达时间延后4个小时（假设飞机维修，准备为4个小时）
                      info[i].take_off_time+=10000;
                      info[i].arrive_time+=10000;
                      //恢复飞机可载人数
                      info[i].remain_number+=count;
                      break;
                  }
              }
              //数组越界，出错
              if(i==20){
                  return false;
              }



              return true;
}


