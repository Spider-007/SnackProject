#pragma once
#include <Windows.h>
#include "CSnake.h"

class Map
{
private:
	COORD tempWall;
	vector<COORD> Snake;

public:
	void OutPutPos(int nX, int nY);									//输出调试坐标
	void KeyEventProc(KEY_EVENT_RECORD ker);						//键盘事件处理
	void MouseEventProc(MOUSE_EVENT_RECORD mer);					//鼠标事件处理函数
	int  MessageLoop();                                             //消息处理函数
};