#pragma once
#include <Windows.h>
#include "CSnake.h"

class Map
{
private:
	COORD tempWall;
	vector<COORD> Snake;

public:
	void OutPutPos(int nX, int nY);									//�����������
	void KeyEventProc(KEY_EVENT_RECORD ker);						//�����¼�����
	void MouseEventProc(MOUSE_EVENT_RECORD mer);					//����¼�������
	int  MessageLoop();                                             //��Ϣ������
};