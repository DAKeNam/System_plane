#include "User.h"


//用户信息类
User::User()
{
    for (int i = 0; i < 100; i++) {
		ticket[i] = 0;
    }//初始话订单数组
    for(int i=0;i<10;i++){
        name[i]='\0';
    }//初始话姓名
    id=0;//初始化用户id

}


User::~User()
{
}
