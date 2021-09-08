#pragma once

class Clock //定义时钟类
{
public:
	void set(int h, int m, int s);
	void show();
	void startClock();
	void clrscr();
private:
	int hour, minute, second;
};
