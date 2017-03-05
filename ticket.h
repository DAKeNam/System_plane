#pragma once
class ticket
{
public:
	ticket();
	~ticket();
    int id;//订单id
    //其它如字面意思
	int user_id;
	int plane_id;
    //为0已完成，1待完成，2取消
	int valid=0;
};

