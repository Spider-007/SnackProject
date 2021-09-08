#include "CSnake.h"

CSnake::CSnake() {				// ��ʼ������ 
	COORD Temp = {10,3};
	for (int i = 3; i < 7;i++) {
		//vector�ӑB���M
		Temp.Y = i;
		Snake.push_back(Temp);
	}
	int length = strlen("��") + 1;
	str = new char[length + 1];
	strcpy_s(str, length, "��"); 

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
	Snake.insert(Snake.begin(),mTemp); //����ͷ�ڵ�

	Snake[0].X = nTempX;//�ߵ�ͷ����Ϊ������
	Snake[0].Y = nTempY;//֮����Y
}

void CSnake::setDir(int dir) {
	Dir = dir;
}

