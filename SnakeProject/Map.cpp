#include "Map.h"
#include <stdio.h>
#include "CDrawBase.h"
#include "CSnake.h"
#include "CAre.h"
#define KEY_DOWN(key) GetAsyncKeyState(key) ==(SHORT)0x8001?1:0;

//�����¼�����
void Map::KeyEventProc(KEY_EVENT_RECORD ker) {
	if (ker.bKeyDown) {	//���̰���
	}
	else {
		//����̧�������enter����ʼ��Ϸ
		if (_getch() == 13) {
			CAre care;
			care.StartGame(100, false);
		}
	}
}

//����¼�������
void Map::MouseEventProc(MOUSE_EVENT_RECORD mer) {
	switch (mer.dwEventFlags) {
	case 0://��굥�� ,ֹͣ�༭��ͼ
		break;
	case DOUBLE_CLICK:
		WriteChar(0, 0, "˫���༭��ͼ", BACKGROUND_BLUE);
		//��ͣ��Ϸ����ʼ�༭ģʽ
		if (_getch() == 32) {
			//ʹ�ÿո��ʼ�༭,todo �༭֮�󱣴浽�ļ�����
			mer.dwEventFlags = MOUSE_MOVED;
		}
		break;
	case MOUSE_MOVED:
		auto point = mer.dwMousePosition;
		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {		//����������
			// ������ʲô����¼����������������
			tempWall.X = point.Y;
			tempWall.Y = point.X / 2;
			Snake.push_back(tempWall);
			WriteChar(point.X / 2, point.Y, "��", BACKGROUND_GREEN);
		}
		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED) {
			int nMouseX = mer.dwMousePosition.X / 2;
			int nMouseY = mer.dwMousePosition.Y;
			WriteChar(point.X / 2, point.Y, "  ", BACKGROUND_GREEN);
		}
		break;
	}
}

int Map::MessageLoop() {
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);			//�����¼�  ��һ���ض��ı�׼�豸��ȡ��һ�������ʾ��ͬ���豸����ֵ
	INPUT_RECORD stcRecord = { 0 };
	DWORD dwRead;
	SetConsoleMode(hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	while (1) {
		ReadConsoleInput(hStdin, &stcRecord, 1, &dwRead);	// ָ�����ָ�룬���ջ�ȡ�������¼��ָ��
		if (stcRecord.EventType == KEY_EVENT) {
			KeyEventProc(stcRecord.Event.KeyEvent);
		}
		else if (stcRecord.EventType == MOUSE_EVENT) {
			MouseEventProc(stcRecord.Event.MouseEvent);
		}
	}
}