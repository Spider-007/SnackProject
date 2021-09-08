#pragma once
#include "CDrawBase.h"
#include "CSnake.h"
#include "CFood.h"

class CAre {
public:
	void welcome(int x = 2, int y = 5, int color = FOREGROUND_RED); 	    //��ӭ����
	int gameOption(int x = 26, int y = 20, int color = FOREGROUND_RED);		//��ʼ����Ϸ
	void gameOver(int x = 16, int y = 10, int color = FOREGROUND_RED);		//��������
	void initMap();								//��ʼ���؈D
	void initSmallMap(int x = 42, int y = 10, int color = FOREGROUND_RED);						//��ʼ���҂�С�؈D
	void DrawMap();								//���؈D���ϵK��
	int waitKey();								//�����Ñ�ݔ�룬�޸��ߵķ���
	void GetPlay();								//�����Ñ�����
	void StartGame(int speed, bool isDefault = true);	//�_ʼ�Α�
	void handleInput();							//�����������뷨


private:
	CSnake objSnake;							//�@ȡ�ߵČ���
	CFood m_objFood;							//�@ȡʳ���
	int nMap[MAP_X][MAP_Y];						//map�؈D�惦����
	int widgetMap[MAP_X][MAP_Y];                //�Զ����ͼ
	int Oper = 0;								//�@ȡ�Ñ�ݔ��
	int flag = 0;								//�ǲ����״μ��ص�ͼ
};
