#include "Map.h"
#include <stdio.h>
#include "CDrawBase.h"
#include "CSnake.h"
#include "CAre.h"
#define KEY_DOWN(key) GetAsyncKeyState(key) ==(SHORT)0x8001?1:0;
int flag = 0;
CAre cAre;
//�����¼�����
void Map::KeyEventProc(KEY_EVENT_RECORD ker) {
	if (ker.bKeyDown && flag == 1) {
		cAre.StartGame(100, false);
		flag = 0;
	}
}

//����¼�����
void Map::MouseEventProcs(MOUSE_EVENT_RECORD mer) {
	switch (mer.dwEventFlags) {
	case 0://��굥�� ,ֹͣ�༭��ͼ
		break;
	case DOUBLE_CLICK:
		flag = 0;
		return;
		break;
	case MOUSE_MOVED:
		auto point = mer.dwMousePosition;
		if (mer.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
			//����������
			tempWall.X = point.Y;
			tempWall.Y = point.X / 2;
			Snake.push_back(tempWall);
			cAre.nMap[point.X / 2][point.Y] = �ϰ���;
			WriteChar(point.X / 2, point.Y, "��", BACKGROUND_RED);
			flag = 1;
		}
		else if (mer.dwButtonState == RIGHTMOST_BUTTON_PRESSED) {
			cAre.nMap[point.X / 2][point.Y] == �յ�;
			WriteChar(point.X / 2, point.Y, "  ", 0);
			flag = 1;
		}
		break;
	}
}

int Map::MessageLoop() {
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);	//�����¼�  ��һ���ض��ı�׼�豸��ȡ��һ�������ʾ��ͬ���豸����ֵ
	INPUT_RECORD stcRecord = { 0 };
	DWORD dwRead;
	SetConsoleMode(hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	while (1) {
		ReadConsoleInput(hStdin, &stcRecord, 1, &dwRead);	// ָ�����ָ�룬���ջ�ȡ�������¼��ָ��
		if (stcRecord.EventType == KEY_EVENT) {
			KeyEventProc(stcRecord.Event.KeyEvent);
		}
		else if (stcRecord.EventType == MOUSE_EVENT) {
			MouseEventProcs(stcRecord.Event.MouseEvent);
		}
	}
}

//��ȡ��ͼ
void Map::OpenMap()
{
	FILE* pfile;
	const char* szFileName = "Map1.dat";

	CSnake csNake;
	int nsize = 0;
	//��ȡSnake���� //��ȡ����
	int error = fopen_s(&pfile, szFileName, "rb");
	if (error == 0) {
		fread(&nsize, 1, sizeof(int), pfile);

		int score = 0; //����
		fread(&score, 1, sizeof(int), pfile);
		csNake.setScoreNake(score);

		int footNum = 0; //����
		fread(&footNum, 1, sizeof(int), pfile);
		csNake.setFootSnake(footNum);

		fclose(pfile);
	}
}

//�����ͼ
bool Map::SaveMap() {
	FILE* pfile;
	CSnake csNake;
	const char* szFileName = "Map1.dat";
	int nsize = 0;

	int error = fopen_s(&pfile, szFileName, "wb");
	if (error == 0) {
		//����Snake���� //�������
		nsize = csNake.Snake.size();
		fwrite(&nsize, 1, sizeof(int), pfile);

		int score = 100; //����
		score = csNake.getScoreNake();
		fwrite(&score, 1, sizeof(int), pfile);

		int footNum = 200; //����
		footNum = csNake.getFootNake();

		fwrite(&footNum, 1, sizeof(int), pfile);

		fclose(pfile);
	}

	return true;
}