#pragma once
#include <Windows.h>
#include <conio.h>
#include <vector>
using std::vector;

#define 上				1
#define 下				2
#define 左				3
#define 右				4
#define MAP_X			30
#define MAP_Y			30

#define 空地			0
#define 食物			1
#define 障碍物			2
#define 自己			3

void WriteChar(int x, int y, const char* szInfo, int color = 0);

