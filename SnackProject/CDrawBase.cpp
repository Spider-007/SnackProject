#include "CDrawBase.h"
#include <stdio.h>

void WriteChar(int x, int y, const char* szInfo, int color) { //ʵ��һ���ܹ�����Ļ�κ�λ������ַ����ĺ���
	COORD pos = { x * 2 ,y }; //��ȡx,y�������ֵ�������������� 
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); //�����������(����̨����Ļ��)
	SetConsoleCursorPosition(hOut, pos); //���ù����±�λ��
	printf("%s", szInfo); //����ַ���
}
