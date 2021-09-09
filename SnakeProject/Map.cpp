#include "Map.h"
#include <stdio.h>
#include "CDrawBase.h"
#include "CSnake.h"
#include "CAre.h"
#define KEY_DOWN(key) GetAsyncKeyState(key) ==(SHORT)0x8001?1:0;
int flag = 0;
CAre cAre;
//键盘事件处理
void Map::KeyEventProc(KEY_EVENT_RECORD ker) {
	if (ker.bKeyDown && flag == 1) {
		cAre.StartGame(100, false);
		flag = 0;
	}
}

//鼠标事件处理
void Map::MouseEventProcs(MOUSE_EVENT_RECORD mer) {
	switch (mer.dwEventFlags) {
	case 0://鼠标单击 ,停止编辑地图
		break;
	case DOUBLE_CLICK:
		flag = 0;
		return;
		break;
	case MOUSE_MOVED:
		auto point = mer.dwMousePosition;
		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
			//鼠标左键按下
			tempWall.X = point.Y;
			tempWall.Y = point.X / 2;
			Snake.push_back(tempWall);
			cAre.nMap[point.X / 2][point.Y] = 障碍物;
			WriteChar(point.X / 2, point.Y, "ω", BACKGROUND_RED);
			flag = 1;
		}
		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED) {
			cAre.nMap[point.X / 2][point.Y] == 空地;
			WriteChar(point.X / 2, point.Y, "  ", 0);
			flag = 1;
		}
		break;
	}
}

int Map::MessageLoop() {
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);	//输入事件  从一个特定的标准设备中取得一个句柄表示不同的设备的数值
	INPUT_RECORD stcRecord = { 0 };
	DWORD dwRead;
	SetConsoleMode(hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	while (1) {
		ReadConsoleInput(hStdin, &stcRecord, 1, &dwRead);	// 指向变量指针，接收获取的输入记录的指针
		if (stcRecord.EventType == KEY_EVENT) {
			KeyEventProc(stcRecord.Event.KeyEvent);
		}
		else if (stcRecord.EventType == MOUSE_EVENT) {
			MouseEventProcs(stcRecord.Event.MouseEvent);
		}
	}
}

//读取地图
void Map::OpenMap()
{
	FILE* pfile;
	const char* szFileName = "Map1.dat";

	CSnake csNake;
	int nsize = 0;
	//读取Snake数据 //读取分数
	int error = fopen_s(&pfile, szFileName, "rb");
	if (error == 0) {
		fread(&nsize, 1, sizeof(int), pfile);

		int score = 0; //分数
		fread(&score, 1, sizeof(int), pfile);
		csNake.setScoreNake(score);

		int footNum = 0; //步数
		fread(&footNum, 1, sizeof(int), pfile);
		csNake.setFootSnake(footNum);

		fclose(pfile);
	}
}

//保存地图
bool Map::SaveMap() {
	FILE* pfile;
	CSnake csNake;
	const char* szFileName = "Map1.dat";
	int nsize = 0;

	int error = fopen_s(&pfile, szFileName, "wb");
	if (error == 0) {
		//储存Snake数据 //储存分数
		nsize = csNake.Snake.size();
		fwrite(&nsize, 1, sizeof(int), pfile);

		int score = 100; //分数
		score = csNake.getScoreNake();
		fwrite(&score, 1, sizeof(int), pfile);

		int footNum = 200; //步数
		footNum = csNake.getFootNake();

		fwrite(&footNum, 1, sizeof(int), pfile);

		fclose(pfile);
	}

	return true;
}