#pragma once
#include "CFood.h"
#include "CDrawBase.h"

/**�ߵĶ���*/
class CSnake {
public:
	CSnake();
	//�L�����ƣ���Ҫʹ��vector�Ż�

public:
	vector<COORD> Snake;		//COORD Snake[100];

private:
	//������
	int Dir = ��;
	//�O���@ʾ�ַ�
	char* str;
	//����
	int nScoreNake;
	//����
	int nFootNake;
	//����
	int nSpeed;
	//�Զ�����
	bool isAutoSpeed = false;
	//������
	int m_back;
	//��ֹת��
	int m_stop;

public:

	//���������ڵ����꽫������Ļ�������
	void ClearSnake();

	//���µ���������Ļ�ϻ�����
	void DrawSnake();

	//�ƶ���
	int MoveSnake(int nMap[MAP_X][MAP_Y], CFood& food);

	//���÷���
	void setDir(int dir);

	//��ȡ�߷���
	int getDir();

	//��������
	void setSpeed(int speed);

	//���ü���
	void setAutoSpeed(bool isAutoSp);

	//��ȡ����
	bool getAutoSpeed();

	//��ȡ����
	int getSpeed();

	//����
	void AddScoreNake();

	//����
	void AddFootNake();

	//��ȡ�ߵķ���
	int getScoreNake();

	//��ȡ�ߵĲ���
	int getFootNake();

	//���ò���
	void setFootSnake(int score);

	//���÷���
	void setScoreNake(int score);

	//��������
	void gameOver(int x = 16, int y = 10, int color = FOREGROUND_RED);

	//���÷�����
	void SetState(int state);

	//��ȡ״̬:
	bool GetState(int state);
};