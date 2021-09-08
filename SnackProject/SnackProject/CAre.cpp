#include "CAre.h"

//��ʼ����ͼ
void CAre::initMap() {
	for (int i = 0; i < MAP_X; i++) {
		for (int j = 0; j < MAP_Y; j++) {
			if (i == 0 || j == 0 || i == MAP_X - 1 || j == MAP_Y - 1) {	//����ڵ�ͼ���ĸ��㣬�͸����������Ϳ�����
				nMap[i][j] = �ϰ���;
			}
			else {
				nMap[i][j] = �յ�;
			}
		}
	}
}

//�����ϰ���
void CAre::DrawMap() {
	for (int i = 0; i < MAP_X; i++) {
		for (int j = 0; j < MAP_Y; j++) {
			if (nMap[i][j] == �ϰ���) {
				WriteChar(i, j, "��");
			}
		}
	}
}

//��ȡ���̰���
int CAre::waitKey() {
	if (_kbhit()) { //�жϴ�ʱ�û��Ƿ񰴼����з���1
		return _getch(); //�����û�������,������������
	}
	return 0;//û�а���������0
}

//�����û��Ĳ���
void CAre::GetPlay() {
	Oper = waitKey();
	switch (Oper) { //��������ֱ�� setֵ�������޸� ��ȫ�Ի����һЩ		
		case 'w':
			objSnake.setDir(��);
			break;
		case 's':
			objSnake.setDir(��);
			break;
		case 'a':
			objSnake.setDir(��);
			break;
		case 'd':
			objSnake.setDir(��);
			break;
		default:
			break;
	}
}
//��ʼ��Ϸ
void CAre::StartGame() {
	//��ʼ��Ϸ���ȼ��ص�ͼ
	initMap();
	//���ص�ͼ����ʾ����
	DrawMap();
	int nLive = 1;//�ж��Ƿ������������ڵ�ͼ��Ҳ���;
	while (nLive) {
		//1.��ȡ�û�����
		GetPlay();
		//2.���ݵ�ǰ��ȡ���±�����Ļ����յ�
		objSnake.ClearSnake();
		//3.�����ߵķ���ȥ�ƶ���
		nLive = objSnake.MoveSnake(nMap, m_objFood);
		//4.���������꽫�ߴ��ݹ�ȥ
		objSnake.DrawSnake();
		//5.����һ��ʳ�����
		m_objFood.CreateFood(nMap);
		Sleep(100);
	}
}