#pragma once
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <string>
#include <iostream>
#include <time.h>
using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::string;

#define ��				1
#define ��				2
#define ��				3
#define ��				4
#define MAP_X			40
#define MAP_Y			30

#define �յ�			0
#define ʳ��			1
#define �ϰ���			2
#define �Լ�			3
#define ����			4

//�����ɫ��Ĭ��Ϊ��ɫ0
void clearColor();

//��������ַ�(����ɫ)
void WriteChar(int x, int y, const char* szInfo, int color = FOREGROUND_RED);

//���double���������ַ�
void WriteChar(int x, int y, double szInfo, int color = FOREGROUND_RED);

//���string�ַ���ʽ
void WriteChar(int x, int y, string szInfo, int color = FOREGROUND_RED);

//��ʾ�����
void ShowCursor(bool isShow, int size = 1);

//���ù���С
void setSize(int size);

//���ñ�����ɫ
void SetBackColor();

//�����ı���ɫ
void SetTextColor();

//��������
void GotToXY(short x, short y);

//���ø���ѡ��
int UpDownSelect(short posX, short posY, vector<string> strs, int gap);

//�����Ϸ�ı�
int PrintSaveGameText(int x, int y, int code);

//�������
void clearXY();