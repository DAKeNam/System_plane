#pragma once
#include "iostream"

class  plane
{
public:
	 plane();
	~ plane();
     //航班号，起飞，到达城市，时间，价格，折扣，剩余人数
	int number_of_plane;
    long take_off_time;
    long arrive_time;
	int take_off_city;
	int arrive_city;
	int cost;
	int discount;
	int remain_number;
};

