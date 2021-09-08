#include "CDrawBase.h"
#include <stdio.h>

//输出char界面
void WriteChar(int x, int y, const char* szInfo, int color) {	//实现一个能够在屏幕任何位置输出字符串的函数
	COORD pos = { x * 2 ,y };									//获取x,y的坐标的值，保存两个坐标
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);				//获得了输出句柄(控制台的屏幕！)
	SetConsoleCursorPosition(hOut, pos);						//设置光标的下标位置
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	cout << szInfo;									//输出字符串
}

//double输出char界面
void WriteChar(int x, int y, double szInfo, int color) {	//实现一个能够在屏幕任何位置输出字符串的函数
	COORD pos = { x * 2 ,y };									//获取x,y的坐标的值，保存两个坐标
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);				//获得了输出句柄(控制台的屏幕！)
	SetConsoleCursorPosition(hOut, pos);						//设置光标的下标位置
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	cout << szInfo;										//输出字符串
}

//字符输出char界面
void WriteChar(int x, int y, string szInfo, int color) {	//实现一个能够在屏幕任何位置输出字符串的函数
	COORD pos = { x * 2 ,y };									//获取x,y的坐标的值，保存两个坐标
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);				//获得了输出句柄(控制台的屏幕！)
	SetConsoleCursorPosition(hOut, pos);						//设置光标的下标位置
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	cout << szInfo;										//输出字符串
}

//清空颜色
void clearColor() {
	void WriteChar(int x, int y, const char* szInfo, int color = 0);
}

//设置字体大小
void setSize(int size) {
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = size;
}

/**@param size 字体大小*/
void ShowCursor(bool isShow, int size) {
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);			//封装一个可以在控制台输出字符的函数
	CONSOLE_CURSOR_INFO cci;									//控制台光标信息结构类型
	cci.dwSize = size;											//光标大小
	cci.bVisible = isShow;										//是否显示光标
	SetConsoleCursorInfo(hOutStd, &cci);						//设置控制台光标大小和可见性
}

void gotoxy(short x, short y) {                             	// 指定控制台光标
	COORD pos;
	pos.X = x;
	pos.Y = y;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
	// 隐藏光标
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	SetConsoleCursorInfo(hOutput, &cursor);
}

//设置背景颜色
void SetBackColor() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
}

//设置文本颜色
void SetTextColor() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
}

//控制光标位置
void GotToXY(short x, short y) {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//获得句柄
	COORD pos = { x * 2 , y };   //坐标
	SetConsoleCursorPosition(hOut, pos);    //设置光标位置
}

/**
	@param->起始文字位置，字符串数组
	@msg->上下选择高亮
	@return:选中的字符串下标
	@gap 放大差距
*/
int UpDownSelect(short posX, short posY, vector<string> strs, int gap) {
	int ch;
	int key = 0;
	int size = strs.size() - 1;

	GotToXY(posX, posY);
	SetBackColor();
	cout << strs[0];

	while (ch = _getch()) {
		switch (ch) {
		case 'w':case 'W':
			if (key == 0)
				break;

			GotToXY(posX, posY + (key - 1) * gap);
			SetBackColor();
			cout << strs[key - 1];//输出当前下标

			GotToXY(posX, posY + key * gap);
			SetTextColor();
			cout << strs[key];
			--key;
			break;
		case 's':case 'S':
			if (key == size)
				break;
			//取消之前的选中
			GotToXY(posX, posY + key * gap);
			SetTextColor();
			cout << strs[key];
			//选中
			GotToXY(posX, posY + (key + 1) * gap);
			SetBackColor();
			cout << strs[key + 1];
			++key;
			break;
		case 13://回车
			return key;
			break;
		}
	}
}

//保存游戏进度
int PrintSaveGameText(int x, int y, int code)
{
	WriteChar(x, y, "是否保存进度？", 0xa);
	WriteChar(x, y + 2, "    【是】    ", 0xa);
	WriteChar(x, y + 4, "    【否】    ", 2);

	int nkey;

	while (1)
	{
		nkey = _getch();

		switch (nkey)
		{
		case 'w':case 'W':case 72:
			if (code > 2) code--;
			break;
		case 's':case 'S':case 80:
			if (code < 3) code++;
			break;
		case 13:case 32:
			return code;
		default:
			break;
		}

		switch (code)
		{
		case 2:
			WriteChar(x, y, "是否保存进度？", 0xa);
			WriteChar(x, y + 2, "    【是】    ", 0xa);
			WriteChar(x, y + 4, "    【否】    ", 2);
			break;
		case 3:
			WriteChar(x, y, "是否保存进度？", 0xa);
			WriteChar(x, y + 2, "    【是】    ", 2);
			WriteChar(x, y + 4, "    【否】    ", 0xa);
			break;
		default:
			break;
		}
	}

}