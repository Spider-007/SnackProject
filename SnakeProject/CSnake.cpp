#include "CSnake.h"

CSnake::CSnake() {				// 初始化坐標
	COORD Temp = { 10,3 };
	for (int i = 3; i < 7; i++) {
		//vector動態數組
		Temp.Y = i;
		Snake.push_back(Temp);
	}
	int length = strlen("⊙") + 1;
	str = new char[length + 1];
	strcpy_s(str, length, "⊙");
}

void CSnake::AddFootNake() {
	nFootNake += 1;
}

void CSnake::AddScoreNake() {
	nScoreNake += 10;
}

int CSnake::getScoreNake() {
	return nScoreNake;
}

void CSnake::setScoreNake(int score) {
	nScoreNake = score;
}

void CSnake::setFootSnake(int score) {
	nFootNake = score;
}

int CSnake::getFootNake() {
	return nFootNake;
}

//根據蛇現在 坐標-> 把蛇隱藏（清除）掉
void CSnake::ClearSnake() {
	for (int i = 0; i < Snake.size(); i++) {
		WriteChar(Snake[i].X, Snake[i].Y, "  ");
	}
}

//將新的坐標 -> 畫到屏幕上
void CSnake::DrawSnake() {
	for (int j = 0; j < Snake.size(); j++) {
		WriteChar(45, 20, "X:", FOREGROUND_RED);
		WriteChar(46, 20, Snake[j].X, FOREGROUND_RED);
		WriteChar(48, 20, "Y:", FOREGROUND_RED);
		WriteChar(49, 20, Snake[j].Y, FOREGROUND_RED);
		WriteChar(Snake[j].X, Snake[j].Y, str);//str在全局变量中，蛇身的字符显示
	}
}

//移動蛇 -> 方向
int CSnake::MoveSnake(int nMap[MAP_X][MAP_Y], CFood& food) {
	int nTempX = Snake[0].X;
	int nTempY = Snake[0].Y;
	COORD mTemp = { nTempX,nTempY };		//最后一个删掉
	switch (Dir) {
	case 上:
		nTempY--;
		break;
	case 下:
		nTempY++;
		break;
	case 左:
		nTempX--;
		break;
	case 右:
		nTempX++;
		break;
	default:
		break;
	}
	if (nMap[nTempX][nTempY] == 空地) {
		//空地
	}
	else if (nMap[nTempX][nTempY] == 食物) {
		PlaySound(TEXT("7896.wav"), NULL, SND_ASYNC | SND_NODEFAULT | SND_FILENAME); //播放音乐实现功能
		AddScoreNake();
		Snake.insert(Snake.begin(), mTemp);
		nMap[nTempX][nTempY] = 空地;
		food.setFoodExist(0);
		return 1;
	}
	else if (nMap[nTempX][nTempY] == 障碍物) {
		gameOver();
		return 0;
	}
	else if (nMap[nTempX][nTempY] == 自己) {
		//判斷撞到自己
		gameOver();
		return 0;
	}

	Snake.erase(Snake.end() - 1);		//删除最后一个节点
	Snake.insert(Snake.begin(), mTemp); //插入头节点

	Snake[0].X = nTempX;//蛇的头部改为新坐标
	Snake[0].Y = nTempY;//之后是Y
}

void CSnake::setDir(int dir) {
	Dir = dir;
}

int CSnake::getDir() {
	return Dir;
}

void CSnake::setSpeed(int speed) {
	nSpeed = speed;
}

int CSnake::getSpeed() {
	return nSpeed;
}

//设置加速
void CSnake::setAutoSpeed(bool isAutoSp) {
	isAutoSpeed = isAutoSp;
}

//获取加速状态
bool CSnake::getAutoSpeed() {
	return isAutoSpeed;
}

//结束游戏
void CSnake::gameOver(int x, int y, int color) {
	system("cls");
	WriteChar(x, y, "/ ___| __ _ _ __ ___   ___ / _ \__   _____ _ __ ", color);
	WriteChar(x, y + 1, "| |  _ / _` | '_ ` _ \ / _ \ | | \ \ / / _ \ '__|", color);
	WriteChar(x, y + 2, "| |_| | (_| | | | | | |  __/ |_| |\ V /  __/ |   ", color);
	WriteChar(x, y + 3, " \____|\__,_|_| |_| |_|\___|\___/  \_/ \___|_|   ", color);

	WriteChar(x + 8, y + 12, "请输入任意字符结束！", color);
	if (_getch)
		return;
}

//设置反方向
void CSnake::SetState(int state)//1:反方向 2：禁止转向
{
	switch (state)
	{
	case 1:
		m_back = time(NULL);
		break;
	case 2:
		m_stop = time(NULL);
		break;
	default:
		break;
	}
}

//获取状态:
bool CSnake::GetState(int state)//1:反方向 2：禁止转向
{
	switch (state)
	{
	case 1:
		if (time(NULL) - m_back >= 5)return false;
		return true;
		break;
	case 2:
		if (time(NULL) - m_stop >= 5)return false;
		return true;
		break;
	default:
		break;
	}
	return false;
}