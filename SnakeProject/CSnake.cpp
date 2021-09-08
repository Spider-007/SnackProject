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
		return 0;
	}

	else if (nMap[nTempX][nTempY] == �Լ�) {
		//�Д�ײ���Լ�
		return 0;
	}

	Snake.erase(Snake.end() - 1);	   //ɾ�����һ���ڵ�
	Snake.insert(Snake.begin(), mTemp); //����ͷ�ڵ�

	Snake[0].X = nTempX;//�ߵ�ͷ����Ϊ������
	Snake[0].Y = nTempY;//֮����Y
}

/**
//ײǽ
int gameover()//��Ϸ������ײǽ����ײ�Լ�
{
	//ײǽ
	if (Snake.xy[0].x < 0 || snake.xy[0].y < 0 || snake.xy[0].x>650 || snake.xy[0].y>480)
	{
		outtextxy(280, 210, "GameOver!");
		MessageBox(hwnd, "���ܚ_���ǽ����", "��Ϸ����", 0);
		return 1;
	}
	//ײ�Լ�
	for (int i = 1; i < snake.num; i++)
	{
		if (snake.xy[0].x == snake.xy[i].x && snake.xy[0].y == snake.xy[i].y)
		{
			outtextxy(280, 210, "GameOver��");
			MessageBox(hwnd, "����Ū����ײ���Լ���", "��Ϸ����", 0);
			return 1;
		}
	}

	return 0;
}
*/

void CSnake::setDir(int dir) {
	Dir = dir;
}