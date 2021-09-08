#include "CDrawBase.h"
#include <stdio.h>

//���char����
void WriteChar(int x, int y, const char* szInfo, int color) {	//ʵ��һ���ܹ�����Ļ�κ�λ������ַ����ĺ���
	COORD pos = { x * 2 ,y };									//��ȡx,y�������ֵ��������������
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);				//�����������(����̨����Ļ��)
	SetConsoleCursorPosition(hOut, pos);						//���ù����±�λ��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	cout << szInfo;									//����ַ���
}

//double���char����
void WriteChar(int x, int y, double szInfo, int color) {	//ʵ��һ���ܹ�����Ļ�κ�λ������ַ����ĺ���
	COORD pos = { x * 2 ,y };									//��ȡx,y�������ֵ��������������
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);				//�����������(����̨����Ļ��)
	SetConsoleCursorPosition(hOut, pos);						//���ù����±�λ��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	cout << szInfo;										//����ַ���
}

//�ַ����char����
void WriteChar(int x, int y, string szInfo, int color) {	//ʵ��һ���ܹ�����Ļ�κ�λ������ַ����ĺ���
	COORD pos = { x * 2 ,y };									//��ȡx,y�������ֵ��������������
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);				//�����������(����̨����Ļ��)
	SetConsoleCursorPosition(hOut, pos);						//���ù����±�λ��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	cout << szInfo;										//����ַ���
}

//�����ɫ
void clearColor() {
	void WriteChar(int x, int y, const char* szInfo, int color = 0);
}

//���������С
void setSize(int size) {
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = size;
}

/**@param size �����С*/
void ShowCursor(bool isShow, int size) {
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);			//��װһ�������ڿ���̨����ַ��ĺ���
	CONSOLE_CURSOR_INFO cci;									//����̨�����Ϣ�ṹ����
	cci.dwSize = size;											//����С
	cci.bVisible = isShow;										//�Ƿ���ʾ���
	SetConsoleCursorInfo(hOutStd, &cci);						//���ÿ���̨����С�Ϳɼ���
}

void gotoxy(short x, short y) {                             	// ָ������̨���
	COORD pos;
	pos.X = x;
	pos.Y = y;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
	// ���ع��
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	SetConsoleCursorInfo(hOutput, &cursor);
}

//���ñ�����ɫ
void SetBackColor() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
}

//�����ı���ɫ
void SetTextColor() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
}

//���ƹ��λ��
void GotToXY(short x, short y) {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//��þ��
	COORD pos = { x * 2 , y };   //����
	SetConsoleCursorPosition(hOut, pos);    //���ù��λ��
}

/**
	@param->��ʼ����λ�ã��ַ�������
	@msg->����ѡ�����
	@return:ѡ�е��ַ����±�
	@gap �Ŵ���
*/
int UpDownSelect(short posX, short posY, vector<string> strs, int gap) {
	int ch;
	int key = 0;
	int size = strs.size() - 1;

	GotToXY(posX, posY);
	SetBackColor();
	cout << strs[0];

	while (ch = _getch()) {
		switch (ch) {
		case 'w':case 'W':
			if (key == 0)
				break;

			GotToXY(posX, posY + (key - 1) * gap);
			SetBackColor();
			cout << strs[key - 1];//�����ǰ�±�

			GotToXY(posX, posY + key * gap);
			SetTextColor();
			cout << strs[key];
			--key;
			break;
		case 's':case 'S':
			if (key == size)
				break;
			//ȡ��֮ǰ��ѡ��
			GotToXY(posX, posY + key * gap);
			SetTextColor();
			cout << strs[key];
			//ѡ��
			GotToXY(posX, posY + (key + 1) * gap);
			SetBackColor();
			cout << strs[key + 1];
			++key;
			break;
		case 13://�س�
			return key;
			break;
		}
	}
}

//������Ϸ����
int PrintSaveGameText(int x, int y, int code)
{
	WriteChar(x, y, "�Ƿ񱣴���ȣ�", 0xa);
	WriteChar(x, y + 2, "    ���ǡ�    ", 0xa);
	WriteChar(x, y + 4, "    ����    ", 2);

	int nkey;

	while (1)
	{
		nkey = _getch();

		switch (nkey)
		{
		case 'w':case 'W':case 72:
			if (code > 2) code--;
			break;
		case 's':case 'S':case 80:
			if (code < 3) code++;
			break;
		case 13:case 32:
			return code;
		default:
			break;
		}

		switch (code)
		{
		case 2:
			WriteChar(x, y, "�Ƿ񱣴���ȣ�", 0xa);
			WriteChar(x, y + 2, "    ���ǡ�    ", 0xa);
			WriteChar(x, y + 4, "    ����    ", 2);
			break;
		case 3:
			WriteChar(x, y, "�Ƿ񱣴���ȣ�", 0xa);
			WriteChar(x, y + 2, "    ���ǡ�    ", 2);
			WriteChar(x, y + 4, "    ����    ", 0xa);
			break;
		default:
			break;
		}
	}

}