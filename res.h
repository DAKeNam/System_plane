#ifndef RES_H
#define RES_H
#include"planeUtil.h"
#include "planewindow.h"
#include<string>
#include<iostream>
extern planeUtil* pu;//用于操作信息的指针
extern int edit_row;//需要处理的tablewiget的行的id
extern PlaneWindow *pw;//主窗口界面
//当前操作的id
extern int ticket_id;
extern int plane_id;
extern int user_id;
#endif // RES_H
