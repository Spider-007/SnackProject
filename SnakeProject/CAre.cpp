#include "CAre.h"
#include "Map.h"
#include "Clock.h"
Map map;
//欢迎界面
void CAre::welcome(int x, int y, int color) {
	WriteChar(x, y, "■■■■■　　　　　　　■■　　■　　　　　　　　■■■　　　　　　　　■　　■■　　　　　　　■■■■■", color);
	WriteChar(x, y + 1, "■■　■■　　　　　　　■■■　■　　　　　　　　■■■　　　　　　　　■　■■■　　　　　　　■　　　　", color);
	WriteChar(x, y + 2, "■■　　■　　　　　　　■■■　■　　　　　　　■■■■　　　　　　　　■■■■　　　　　　　　■　　　　", color);
	WriteChar(x, y + 3, "■■■■　　　　　　　　■■■　■　　　　　　　■■■■　　　　　　　　■■■　　　　　　　　　■■■■　", color);
	WriteChar(x, y + 4, "■■■■　　　　　　　　■■■　■　　　　　　　■■■■　　　　　　　　■■■　　　　　　　　　■■■■　", color);
	WriteChar(x, y + 5, "　■■■■　　　　　　　■　■■■　　　　　　　■■　■■　　　　　　　■■■■　　　　　　　　■　　　　", color);
	WriteChar(x, y + 6, "■　　■■　　　　　　　■　■■■　　　　　　　■■■■■　　　　　　　■　■■　　　　　　　　■　　　　", color);
	WriteChar(x, y + 7, "■■　■■　　　　　　　■　■■■　　　　　　■■　　■■　　　　　　　■　■■■　　　　　　　■　　　　", color);
	WriteChar(x, y + 8, "■■■■■　　　　　　　■　　■■　　　　　　■■　　■■■　　　　　　■　　■■　　　　　　　■■■■■", color);
	WriteChar(x, y + 9, "　　■　　　　　　　　　　　　　　　　　　　　■■　　　■■　　　　　　　　　　　　　　　　　　　　　　　", color);
	gameOption();
}

//打开游戏界面，选择游戏模式,选择难度
int CAre::gameOption(int x, int y, int color) {
	vector<string> mArr;
	ShowCursor(false, 10);
	WriteChar(x, y, "开始游戏", FOREGROUND_RED);
	WriteChar(x, y + 1, "简单模式", FOREGROUND_RED);
	WriteChar(x, y + 2, "噩梦模式", FOREGROUND_RED);
	WriteChar(x, y + 3, "炼狱模式", FOREGROUND_RED);
	WriteChar(x, y + 4, "自定义模式", FOREGROUND_RED);
	//WriteChar(x+10, y+2, "使用说明：",   FOREGROUND_GREEN);
	//WriteChar(x+12, y+3, "WS控制",		 FOREGROUND_GREEN);
	//WriteChar(x+12, y+4, "Enter确定",	 FOREGROUND_GREEN);
	mArr.push_back("");
	mArr.push_back("开始游戏");
	mArr.push_back("简单模式");
	mArr.push_back("噩梦模式");
	mArr.push_back("炼狱模式");
	mArr.push_back("自定义模式");
	int result = UpDownSelect(x, y - 1, mArr, 1);
	int speed;								//根据选择模式控制速度
	switch (result) {
	case 1:
		system("cls");
		speed = 100;
		StartGame(speed);
		break;
	case 2:
		system("cls");
		speed = 80;
		StartGame(speed);
		break;
	case 3:
		system("cls");
		speed = 60;
		StartGame(speed);
		break;
	case 4:
		system("cls");
		speed = 40;
		StartGame(speed);
		break;
	case 5:
	{
		//自定义地图，自定义地图显示属性
		system("cls");
		int result = map.MessageLoop();
		if (result == 1) {
			objSnake.gameOver();
		}
	}
	break;
	default:
		system("cls");
		objSnake.gameOver();
		break;
	}
}

/**主要是界面交互*/
void CAre::initSmallMap(int x, int y, int color) {
	CSnake nake;
	WriteChar(x, y + 1, "************操作提示************", FOREGROUND_RED);
	WriteChar(x, y + 2, "分数:", FOREGROUND_RED);
	WriteChar(x, y + 3, "步数:", FOREGROUND_RED);
	WriteChar(x, y + 5, "空格键暂停恢复", FOREGROUND_RED);
	WriteChar(x, y + 6, "WSAD 控制上下左右，不区分大小写", FOREGROUND_RED);
	WriteChar(x, y + 7, "连按方向键自动加速", FOREGROUND_RED);
	WriteChar(x, y + 8, "按键 q 添加障碍物", FOREGROUND_RED);
	WriteChar(x, y + 12, "R-> 重新开始", FOREGROUND_RED);
}

//初始化地图
void CAre::initMap() {
	for (int i = 0; i < MAP_X; i++) {										//行坐标
		for (int j = 0; j < MAP_Y; j++) {									//纵坐标
			if (i == 0 || j == 0 || i == MAP_X - 1 || j == MAP_Y - 1) {		//画出来地图上的四个点
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

//处理中文输入法
void CAre::handleInput() {
	keybd_event(VK_SHIFT, 0, 0, 0);			              //使用SHIFT切换中英文
	Sleep(100);											 //按键响应时间，100ms
	keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);			//键盘按下抬起事件
}

//获取键盘按键
int CAre::waitKey() {
	if (_kbhit()) { //判断此时用户是否按键，有返回1
		return _getch(); //接收用户按键就,并将按键返回
	}
	return 0;//没有按键，返回0
}

//添加障碍物
void CAre::AddObstacles(int cout) {
	//设置随机坐标值数据
	int i = 0;
	if (cout == 0)cout = rand() % 8;
	while (i <= cout) {
		int pX = rand() % MAP_X;
		int pY = rand() % MAP_Y;
		WriteChar(pX, pY, "ω", BACKGROUND_GREEN);
		nMap[pX][pY] = 障碍物;
		i++;
	}
}

//接收用户的操作
void CAre::GetPlay(int speed) {
	Oper = waitKey();
	//创建对象直接 set值，这样修改 安全性会更高一些
	switch (Oper) {
	case 'w':case 'W':
		if (objSnake.getDir() == 上) objSnake.setAutoSpeed(true);
		objSnake.setDir(上);
		break;
	case 's':case 'S':
		if (objSnake.getDir() == 下) objSnake.setAutoSpeed(true);
		objSnake.setDir(下);
		break;
	case 'a':case 'A':
		if (objSnake.getDir() == 左) objSnake.setAutoSpeed(true);
		objSnake.setDir(左);
		break;
	case 'd':case 'D':
		if (objSnake.getDir() == 右) objSnake.setAutoSpeed(true);
		objSnake.setDir(右);
		break;
	case 32:
		map.SaveMap();     //存档
		system("pause>nul");
		break;
	case 43://代表加速，需要减时间
		objSnake.setSpeed(speed - 5);
		break;
	case 45:case 95:
		//代表减速，需要加时间
		objSnake.setSpeed(speed + 5);
		break;
	case 'q':case 'Q':
		//按下x,生成5个障碍物
		AddObstacles(5);
		break;
	case 'r':case 'R':

		map.SaveMap();     //存档
		system("cls");	   //清屏幕
		welcome();
		break;

	default:
		break;
	}
}

//开始游戏
void CAre::StartGame(int speed, bool isDefault) {
	if (isDefault) {
		initMap();					//默认地图
		DrawMap();					//加载地图后显示界面
		initSmallMap();				//加載小地圖
	}
	ShowCursor(false);
	map.OpenMap();					//读档
	int nLive = 1;					//判断是否死掉，将其在地图中也清掉;
	while (nLive) {
		//1.获取用户输入
		GetPlay(speed);
		//2.根据当前获取的下标在屏幕上清空掉
		objSnake.ClearSnake();
		//3.根据蛇的方向去移动蛇
		nLive = objSnake.MoveSnake(nMap, m_objFood);
		//4.根据新坐标将蛇传递过去
		if (nLive != 0)objSnake.DrawSnake();
		//5.创建一个食物出来
		m_objFood.CreateFood(nMap);
		//吃到食物就++
		if (nLive != 0 && m_objFood.getFoodExist() == 1) {
			objSnake.AddFootNake();
			WriteChar(50, 12, objSnake.getScoreNake(), FOREGROUND_GREEN);//设置分数
			WriteChar(50, 13, objSnake.getFootNake(), FOREGROUND_GREEN);//设置步数
		}

		Sleep(objSnake.getAutoSpeed() == true ? 0 : speed);
		objSnake.setAutoSpeed(false);
	}
}