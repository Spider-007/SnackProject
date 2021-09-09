#pragma once
#include "CFood.h"
#include "CDrawBase.h"

/**蛇的动作*/
class CSnake {
public:
	CSnake();
	//長度限制，需要使用vector优化

public:
	vector<COORD> Snake;		//COORD Snake[100];

private:
	//蛇身方向
	int Dir = 右;
	//設置顯示字符
	char* str;
	//分数
	int nScoreNake;
	//步数
	int nFootNake;
	//移速
	int nSpeed;
	//自动加速
	bool isAutoSpeed = false;
	//反方向
	int m_back;
	//禁止转向
	int m_stop;

public:

	//根据蛇现在的坐标将其在屏幕上清除掉
	void ClearSnake();

	//将新的坐标在屏幕上画出来
	void DrawSnake();

	//移动蛇
	int MoveSnake(int nMap[MAP_X][MAP_Y], CFood& food);

	//设置方向
	void setDir(int dir);

	//获取蛇方向
	int getDir();

	//设置移速
	void setSpeed(int speed);

	//设置加速
	void setAutoSpeed(bool isAutoSp);

	//获取加速
	bool getAutoSpeed();

	//获取移速
	int getSpeed();

	//分数
	void AddScoreNake();

	//步数
	void AddFootNake();

	//获取蛇的分数
	int getScoreNake();

	//获取蛇的步数
	int getFootNake();

	//设置步数
	void setFootSnake(int score);

	//设置分数
	void setScoreNake(int score);

	//结束界面
	void gameOver(int x = 16, int y = 10, int color = FOREGROUND_RED);

	//设置反方向
	void SetState(int state);

	//获取状态:
	bool GetState(int state);
};