#pragma once

class Clock //����ʱ����
{
public:
	void set(int h, int m, int s);
	void show();
	void startClock();
	void clrscr();
private:
	int hour, minute, second;
};
