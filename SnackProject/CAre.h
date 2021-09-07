#pragma once
#include "CDrawBase.h"
#include "CSnake.h"
#include "CFood.h"

class CAre {

public:
	void initMap();				//初始化地圖
	void DrawMap();				//畫地圖，障礙物
	int waitKey();				//接受用戶輸入，修改蛇的方向
	void GetPlay();				//接受用戶操作
	void StartGame();			//開始游戲
private:
	CSnake objSnake;			//獲取蛇的對象
	CFood m_objFood;			//獲取食物對象
	int nMap[MAP_X][MAP_Y];		//map地圖存儲數據
	int Oper = 0;				//獲取用戶輸入
};

