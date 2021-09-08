#pragma once
#include "CDrawBase.h"
#include "CSnake.h"
#include "CFood.h"

class CAre {

public:
	void initMap();				//��ʼ���؈D
	void DrawMap();				//���؈D���ϵK��
	int waitKey();				//�����Ñ�ݔ�룬�޸��ߵķ���
	void GetPlay();				//�����Ñ�����
	void StartGame();			//�_ʼ�Α�
private:
	CSnake objSnake;			//�@ȡ�ߵČ���
	CFood m_objFood;			//�@ȡʳ���
	int nMap[MAP_X][MAP_Y];		//map�؈D�惦����
	int Oper = 0;				//�@ȡ�Ñ�ݔ��
};

