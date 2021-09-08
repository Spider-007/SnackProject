#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Map.h"
#include <Windows.h>
#include "CAre.h"
#pragma comment(lib,"winmm.lib")//导入音乐文件库
#include <mmsystem.h>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	PlaySound(TEXT("7895.wav"),NULL, SND_ASYNC | SND_NODEFAULT | SND_FILENAME); //播放音乐实现功能
	CAre objCAre;
	Map map;
	system("title 贪吃蛇快跑");
	objCAre.welcome();					//显示欢迎页面，输出红黑颜色蛇体，点按任意键继续

	return 0;
}