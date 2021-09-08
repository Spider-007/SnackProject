#include "CAre.h"

//初始化地图
void CAre::initMap() {
	for (int i = 0; i < MAP_X; i++) {
		for (int j = 0; j < MAP_Y; j++) {
			if (i == 0 || j == 0 || i == MAP_X - 1 || j == MAP_Y - 1) {	//如果在地图上四个点，就给他画出来就可以了
				nMap[i][j] = 障碍物;
			}
			else {
				nMap[i][j] = 空地;
			}
		}
	}
}

//设置障碍物
void CAre::DrawMap() {
	for (int i = 0; i < MAP_X; i++) {
		for (int j = 0; j < MAP_Y; j++) {
			if (nMap[i][j] == 障碍物) {
				WriteChar(i, j, "ω");
			}
		}
	}
}

//获取键盘按键
int CAre::waitKey() {
	if (_kbhit()) { //判断此时用户是否按键，有返回1
		return _getch(); //接收用户按键就,并将按键返回
	}
	return 0;//没有按键，返回0
}

//接收用户的操作
void CAre::GetPlay() {
	Oper = waitKey();
	switch (Oper) { //创建对象直接 set值，这样修改 安全性会更高一些		
		case 'w':
			objSnake.setDir(上);
			break;
		case 's':
			objSnake.setDir(下);
			break;
		case 'a':
			objSnake.setDir(左);
			break;
		case 'd':
			objSnake.setDir(右);
			break;
		default:
			break;
	}
}
//开始游戏
void CAre::StartGame() {
	//开始游戏首先加载地图
	initMap();
	//加载地图后显示界面
	DrawMap();
	int nLive = 1;//判断是否死掉，将其在地图中也清掉;
	while (nLive) {
		//1.获取用户输入
		GetPlay();
		//2.根据当前获取的下标在屏幕上清空掉
		objSnake.ClearSnake();
		//3.根据蛇的方向去移动蛇
		nLive = objSnake.MoveSnake(nMap, m_objFood);
		//4.根据新坐标将蛇传递过去
		objSnake.DrawSnake();
		//5.创建一个食物出来
		m_objFood.CreateFood(nMap);
		Sleep(100);
	}
}