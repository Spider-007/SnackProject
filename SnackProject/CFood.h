#pragma once
#include "CDrawBase.h"

class CFood {

private:

	int g_FoodExist;	//�Д��Ƿ�Ե�ʳ��
	char *str;			//�O���@ʾ�ַ�

public:

	//�O�ßo�������죬�Á��ʼ��Ԫ��
	CFood();

	//����ʳ��
	void CreateFood(int nMap[MAP_X][MAP_Y]); 

	/**
		@param foodExist 1�Ե�ʳ�0�]�гԵ�
		msg:�O���Ƿ�Ե�ʳ��
	*/
	void setFoodExist(int foodExist);
};


