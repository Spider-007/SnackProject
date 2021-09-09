#include "CSnake.h"

CSnake::CSnake() {				// ��ʼ������
	COORD Temp = { 10,3 };
	for (int i = 3; i < 7; i++) {
		//vector�ӑB���M
		Temp.Y = i;
		Snake.push_back(Temp);
	}
	int length = strlen("��") + 1;
	str = new char[length + 1];
	strcpy_s(str, length, "��");
}

void CSnake::AddFootNake() {
	nFootNake += 1;
}

void CSnake::AddScoreNake() {
	nScoreNake += 10;
}

int CSnake::getScoreNake() {
	return nScoreNake;
}

void CSnake::setScoreNake(int score) {
	nScoreNake = score;
}

void CSnake::setFootSnake(int score) {
	nFootNake = score;
}

int CSnake::getFootNake() {
	return nFootNake;
}

//�����߬F�� ����-> �����[�أ��������
void CSnake::ClearSnake() {
	for (int i = 0; i < Snake.size(); i++) {
		WriteChar(Snake[i].X, Snake[i].Y, "  ");
	}
}

//���µ����� -> ������Ļ��
void CSnake::DrawSnake() {
	for (int j = 0; j < Snake.size(); j++) {
		WriteChar(45, 20, "X:", FOREGROUND_RED);
		WriteChar(46, 20, Snake[j].X, FOREGROUND_RED);
		WriteChar(48, 20, "Y:", FOREGROUND_RED);
		WriteChar(49, 20, Snake[j].Y, FOREGROUND_RED);
		WriteChar(Snake[j].X, Snake[j].Y, str);//str��ȫ�ֱ����У�������ַ���ʾ
	}
}

//�Ƅ��� -> ����
int CSnake::MoveSnake(int nMap[MAP_X][MAP_Y], CFood& food) {
	int nTempX = Snake[0].X;
	int nTempY = Snake[0].Y;
	COORD mTemp = { nTempX,nTempY };		//���һ��ɾ��
	switch (Dir) {
	case ��:
		nTempY--;
		break;
	case ��:
		nTempY++;
		break;
	case ��:
		nTempX--;
		break;
	case ��:
		nTempX++;
		break;
	default:
		break;
	}
	if (nMap[nTempX][nTempY] == �յ�) {
		//�յ�
	}
	else if (nMap[nTempX][nTempY] == ʳ��) {
		PlaySound(TEXT("7896.wav"), NULL, SND_ASYNC | SND_NODEFAULT | SND_FILENAME); //��������ʵ�ֹ���
		AddScoreNake();
		Snake.insert(Snake.begin(), mTemp);
		nMap[nTempX][nTempY] = �յ�;
		food.setFoodExist(0);
		return 1;
	}
	else if (nMap[nTempX][nTempY] == �ϰ���) {
		gameOver();
		return 0;
	}
	else if (nMap[nTempX][nTempY] == �Լ�) {
		//�Д�ײ���Լ�
		gameOver();
		return 0;
	}

	Snake.erase(Snake.end() - 1);		//ɾ�����һ���ڵ�
	Snake.insert(Snake.begin(), mTemp); //����ͷ�ڵ�

	Snake[0].X = nTempX;//�ߵ�ͷ����Ϊ������
	Snake[0].Y = nTempY;//֮����Y
}

void CSnake::setDir(int dir) {
	Dir = dir;
}

int CSnake::getDir() {
	return Dir;
}

void CSnake::setSpeed(int speed) {
	nSpeed = speed;
}

int CSnake::getSpeed() {
	return nSpeed;
}

//���ü���
void CSnake::setAutoSpeed(bool isAutoSp) {
	isAutoSpeed = isAutoSp;
}

//��ȡ����״̬
bool CSnake::getAutoSpeed() {
	return isAutoSpeed;
}

//������Ϸ
void CSnake::gameOver(int x, int y, int color) {
	system("cls");
	WriteChar(x, y, "/ ___| __ _ _ __ ___   ___ / _ \__   _____ _ __ ", color);
	WriteChar(x, y + 1, "| |  _ / _` | '_ ` _ \ / _ \ | | \ \ / / _ \ '__|", color);
	WriteChar(x, y + 2, "| |_| | (_| | | | | | |  __/ |_| |\ V /  __/ |   ", color);
	WriteChar(x, y + 3, " \____|\__,_|_| |_| |_|\___|\___/  \_/ \___|_|   ", color);

	WriteChar(x + 8, y + 12, "�����������ַ�������", color);
	if (_getch)
		return;
}

//���÷�����
void CSnake::SetState(int state)//1:������ 2����ֹת��
{
	switch (state)
	{
	case 1:
		m_back = time(NULL);
		break;
	case 2:
		m_stop = time(NULL);
		break;
	default:
		break;
	}
}

//��ȡ״̬:
bool CSnake::GetState(int state)//1:������ 2����ֹת��
{
	switch (state)
	{
	case 1:
		if (time(NULL) - m_back >= 5)return false;
		return true;
		break;
	case 2:
		if (time(NULL) - m_stop >= 5)return false;
		return true;
		break;
	default:
		break;
	}
	return false;
}