#pragma once
#include "CFood.h"
#include "CDrawBase.h"

/**�ߵĶ���*/
class CSnake {

public:
	CSnake();

private:
	//�L�����ƣ���Ҫʹ��vector�Ż�
	vector<COORD> Snake;		//COORD Snake[100];
	//������
	int Dir = ��;
	//�O���@ʾ�ַ�
	char* str;
public:

	//���������ڵ����꽫������Ļ�������
	void ClearSnake();

	//���µ���������Ļ�ϻ�����
	void DrawSnake();

	//�ƶ���
	int MoveSnake(int nMap[MAP_X][MAP_Y], CFood& food);

	//���÷���
	void setDir(int dir);
	
};

