#pragma once
#include "CDrawBase.h"
#include "CSnake.h"
#include "CFood.h"

class CAre {
public:
	void welcome(int x = 2, int y = 5, int color = FOREGROUND_RED); 	    //欢迎界面
	int gameOption(int x = 26, int y = 20, int color = FOREGROUND_RED);		//初始化游戏
	void gameOver(int x = 16, int y = 10, int color = FOREGROUND_RED);		//结束界面
	void initMap();								//初始化地圖
	void initSmallMap(int x = 42, int y = 10, int color = FOREGROUND_RED);						//初始化右側小地圖
	void DrawMap();								//畫地圖，障礙物
	int waitKey();								//接受用戶輸入，修改蛇的方向
	void GetPlay();								//接受用戶操作
	void StartGame(int speed, bool isDefault = true);	//開始游戲
	void handleInput();							//处理中文输入法


private:
	CSnake objSnake;							//獲取蛇的對象
	CFood m_objFood;							//獲取食物對象
	int nMap[MAP_X][MAP_Y];						//map地圖存儲數據
	int widgetMap[MAP_X][MAP_Y];                //自定义地图
	int Oper = 0;								//獲取用戶輸入
	int flag = 0;								//是不是首次加载地图
};
