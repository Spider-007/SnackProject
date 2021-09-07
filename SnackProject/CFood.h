#pragma once
#include "CDrawBase.h"

class CFood {

private:

	int g_FoodExist;	//判斷是否吃到食物
	char *str;			//設置顯示字符

public:

	//設置無參數構造，用來初始化元素
	CFood();

	//創建食物
	void CreateFood(int nMap[MAP_X][MAP_Y]); 

	/**
		@param foodExist 1吃到食物，0沒有吃到
		msg:設置是否吃到食物
	*/
	void setFoodExist(int foodExist);
};


