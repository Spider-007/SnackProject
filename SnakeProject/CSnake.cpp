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
		return 0;
	}

	else if (nMap[nTempX][nTempY] == 自己) {
		//判斷撞到自己
		return 0;
	}

	Snake.erase(Snake.end() - 1);	   //删除最后一个节点
	Snake.insert(Snake.begin(), mTemp); //插入头节点

	Snake[0].X = nTempX;//蛇的头部改为新坐标
	Snake[0].Y = nTempY;//之后是Y
}

/**
//撞墙
int gameover()//游戏结束，撞墙或者撞自己
{
	//撞墙
	if (Snake.xy[0].x < 0 || snake.xy[0].y < 0 || snake.xy[0].x>650 || snake.xy[0].y>480)
	{
		outtextxy(280, 210, "GameOver!");
		MessageBox(hwnd, "你能歘，怼墙上了", "游戏结束", 0);
		return 1;
	}
	//撞自己
	for (int i = 1; i < snake.num; i++)
	{
		if (snake.xy[0].x == snake.xy[i].x && snake.xy[0].y == snake.xy[i].y)
		{
			outtextxy(280, 210, "GameOver！");
			MessageBox(hwnd, "你能弄撒？撞死自己了", "游戏结束", 0);
			return 1;
		}
	}

	return 0;
}
*/

void CSnake::setDir(int dir) {
	Dir = dir;
}