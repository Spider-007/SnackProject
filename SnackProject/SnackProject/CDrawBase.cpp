#include "CDrawBase.h"
#include <stdio.h>

void WriteChar(int x, int y, const char* szInfo, int color) { //实现一个能够在屏幕任何位置输出字符串的函数
	COORD pos = { x * 2 ,y }; //获取x,y的坐标的值，保存两个坐标 
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); //获得了输出句柄(控制台的屏幕！)
	SetConsoleCursorPosition(hOut, pos); //设置光标的下标位置
	printf("%s", szInfo); //输出字符串
}
