#pragma once
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <string>
#include <iostream>
#include <time.h>
using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::string;

#define 上				1
#define 下				2
#define 左				3
#define 右				4
#define MAP_X			40
#define MAP_Y			30

#define 空地			0
#define 食物			1
#define 障碍物			2
#define 自己			3
#define 对象			4

//清楚颜色，默认为黑色0
void clearColor();

//输出坐标字符(带颜色)
void WriteChar(int x, int y, const char* szInfo, int color = FOREGROUND_RED);

//输出double类型坐标字符
void WriteChar(int x, int y, double szInfo, int color = FOREGROUND_RED);

//输出string字符格式
void WriteChar(int x, int y, string szInfo, int color = FOREGROUND_RED);

//显示鼠标光标
void ShowCursor(bool isShow, int size = 1);

//设置光标大小
void setSize(int size);

//设置背景颜色
void SetBackColor();

//设置文本颜色
void SetTextColor();

//设置坐标
void GotToXY(short x, short y);

//设置高亮选中
int UpDownSelect(short posX, short posY, vector<string> strs, int gap);

//输出游戏文本
int PrintSaveGameText(int x, int y, int code);

//清掉坐标
void clearXY();