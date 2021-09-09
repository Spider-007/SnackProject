#pragma once
#include <Windows.h>
#include "CSnake.h"

class Map
{
private:
	COORD tempWall;
	vector<COORD> Snake;

public:
	void KeyEventProc(KEY_EVENT_RECORD ker);						//�����¼�����
	void MouseEventProcs(MOUSE_EVENT_RECORD mer);					//����¼�������
	int  MessageLoop();                                             //��Ϣ������
	bool SaveMap();
	void OpenMap();
};