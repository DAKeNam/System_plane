#pragma once
#include "Plane.h"
#include "ticket.h"
#include "User.h"
#pragma once
#include<stdio.h>
#include<iostream>

//工具类
//信息操作
class plane;
class planeUtil
{
public:
	planeUtil();
	~planeUtil();
    //添加航班信息
    bool input_plane(int fnumber,long dt,long lt,int dc,int lc,int cost,int discount,int people);
    //添加用户信息
    bool input_uer(int userid,std::string username);
    //订票
    bool booking(int userid,int choice);
    //退票
	bool refund_booking(int userid);
    //完成航班
    bool plane_finished(int plane_id);
    //航班信息数组
	plane* info;
    //订单信息数组
	ticket* info_ticket;
    //用户信息数组
	User* info_user;
    //初始化航班，用户，订单信息
    int count_plane=1;
	int count_ticket = 1;
	int count_user = 1;

};

