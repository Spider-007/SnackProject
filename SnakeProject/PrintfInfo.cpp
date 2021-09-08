#include "PrintfInfo.h"

//关于各种打印的函数
void PrintPoint(WORD x, WORD y, char* data, int color)
{
	using std::cout;

	HANDLE HND;
	HND = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = false;
	cci.dwSize = 1;
	SetConsoleCursorInfo(HND, &cci);

	COORD pos = { x * 2,y };
	SetConsoleCursorPosition(HND, pos);

	SetConsoleTextAttribute(HND, color);
	//SetConsoleTextAttribute(HND, rand()%16);

	cout << data;
}

void PrintPoint(WORD x, WORD y, int data, int color)
{
	using std::cout;

	HANDLE HND;
	HND = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = false;
	cci.dwSize = 1;
	SetConsoleCursorInfo(HND, &cci);

	COORD pos = { x * 2,y };
	SetConsoleCursorPosition(HND, pos);

	SetConsoleTextAttribute(HND, color);
	//SetConsoleTextAttribute(HND, rand()%16);

	cout << data;
}

void PrintInfo(WORD x, WORD y, char* data, int num, int color)
{
	using std::cout;

	HANDLE HND;
	HND = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = false;
	cci.dwSize = 1;
	SetConsoleCursorInfo(HND, &cci);

	SetConsoleTextAttribute(HND, color);

	COORD pos = { x * 2 ,y };
	SetConsoleCursorPosition(HND, pos);
	cout << data << num;
}