#pragma once
#include<string>
#include<stdio.h>
class User
{
public:
	User();
	~User();
    char name[10];//名字
    int id;
    //订单数
	int number_of_ticket;
    //订单数组
    int ticket[100];

};

