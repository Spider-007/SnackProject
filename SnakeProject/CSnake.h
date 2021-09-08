#pragma once
#include "CFood.h"
#include "CDrawBase.h"

/**�ߵĶ���*/
class CSnake {
public:
	CSnake();
	//�L�����ƣ���Ҫʹ��vector�Ż�

private:
	//������
	int Dir = ��;
	//�O���@ʾ�ַ�
	char* str;
	vector<COORD> Snake;		//COORD Snake[100];
	int nScoreNake;
	int nFootNake;

public:

	//���������ڵ����꽫������Ļ�������
	void ClearSnake();

	//���µ���������Ļ�ϻ�����
	void DrawSnake();

	//�ƶ���
	int MoveSnake(int nMap[MAP_X][MAP_Y], CFood& food);

	//���÷���
	void setDir(int dir);

	//����
	void AddScoreNake();

	//����
	void AddFootNake();

	//��ȡ�ߵķ���
	int getScoreNake();

	//��ȡ�ߵĲ���
	int getFootNake();
};
