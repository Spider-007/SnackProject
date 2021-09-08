#pragma once
#include "CFood.h"
#include "CDrawBase.h"

/**蛇的动作*/
class CSnake {

public:
	CSnake();

private:
	//長度限制，需要使用vector优化
	vector<COORD> Snake;		//COORD Snake[100];
	//蛇身方向
	int Dir = 右;
	//設置顯示字符
	char* str;
public:

	//根据蛇现在的坐标将其在屏幕上清除掉
	void ClearSnake();

	//将新的坐标在屏幕上画出来
	void DrawSnake();

	//移动蛇
	int MoveSnake(int nMap[MAP_X][MAP_Y], CFood& food);

	//设置方向
	void setDir(int dir);
	
};

