#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Map.h"
#include <Windows.h>
#include "CAre.h"
#pragma comment(lib,"winmm.lib")//���������ļ���
#include <mmsystem.h>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	PlaySound(TEXT("7895.wav"),NULL, SND_ASYNC | SND_NODEFAULT | SND_FILENAME); //��������ʵ�ֹ���
	CAre objCAre;
	Map map;
	system("title ̰���߿���");
	objCAre.welcome();					//��ʾ��ӭҳ�棬��������ɫ���壬�㰴���������

	return 0;
}