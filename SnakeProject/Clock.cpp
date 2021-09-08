#include "Clock.h"
#include "CDrawBase.h"

void Clock::set(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
}
void Clock::show()
{
	string str = hour + ":";
	str = str.append(minute + "").append(second + "");
	WriteChar(45, 10, str);
}

void Clock::clrscr() //��������
{
	COORD coordScreen = { 0, 0 };
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
	SetConsoleCursorPosition(hConsole, coordScreen);
}

void Clock::startClock() {
	while (1)
	{
		set(24, 60, 60);
		show();
		Sleep(1000); //�ӳٺ���������������Լ��趨����λΪ���룬����1000��Ϊ1000���뼴1�롣
		clrscr();
		second--;
		if (second == -1)
		{
			second = 59;
			minute--;
			if (minute == -1)
			{
				minute = 59;
				hour--;
				if (hour == -1) //��ʱ����
				{
					WriteChar(45, 10, "��ʱ����!");
					break;
				}
			}
		}
	}
}