#include "Map.h"
#include <stdio.h>
#include "CDrawBase.h"
#include "CSnake.h"
#include "CAre.h"
#define KEY_DOWN(key) GetAsyncKeyState(key) ==(SHORT)0x8001?1:0;

//键盘事件处理
void Map::KeyEventProc(KEY_EVENT_RECORD ker) {
	if (ker.bKeyDown) {	//键盘按下
	}
	else {
		//键盘抬起，如果是enter键开始游戏
		if (_getch() == 13) {
			CAre care;
			care.StartGame(100, false);
		}
	}
}

//鼠标事件处理函数
void Map::MouseEventProc(MOUSE_EVENT_RECORD mer) {
	switch (mer.dwEventFlags) {
	case 0://鼠标单击 ,停止编辑地图
		break;
	case DOUBLE_CLICK:
		WriteChar(0, 0, "双击编辑地图", BACKGROUND_BLUE);
		//暂停游戏，开始编辑模式
		if (_getch() == 32) {
			//使用空格后开始编辑,todo 编辑之后保存到文件里面
			mer.dwEventFlags = MOUSE_MOVED;
		}
		break;
	case MOUSE_MOVED:
		auto point = mer.dwMousePosition;
		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {		//鼠标左键按下
			// 无论是什么鼠标事件，都输出鼠标的坐标
			tempWall.X = point.Y;
			tempWall.Y = point.X / 2;
			Snake.push_back(tempWall);
			WriteChar(point.X / 2, point.Y, "■", BACKGROUND_GREEN);
		}
		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED) {
			int nMouseX = mer.dwMousePosition.X / 2;
			int nMouseY = mer.dwMousePosition.Y;
			WriteChar(point.X / 2, point.Y, "  ", BACKGROUND_GREEN);
		}
		break;
	}
}

int Map::MessageLoop() {
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);			//输入事件  从一个特定的标准设备中取得一个句柄表示不同的设备的数值
	INPUT_RECORD stcRecord = { 0 };
	DWORD dwRead;
	SetConsoleMode(hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	while (1) {
		ReadConsoleInput(hStdin, &stcRecord, 1, &dwRead);	// 指向变量指针，接收获取的输入记录的指针
		if (stcRecord.EventType == KEY_EVENT) {
			KeyEventProc(stcRecord.Event.KeyEvent);
		}
		else if (stcRecord.EventType == MOUSE_EVENT) {
			MouseEventProc(stcRecord.Event.MouseEvent);
		}
	}
}