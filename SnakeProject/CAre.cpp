#include "CAre.h"
#include "Map.h"
#include "Clock.h"
Map map;
//��ӭ����
void CAre::welcome(int x, int y, int color) {
	WriteChar(x, y, "����������������������������������������������������������������������������������������������������������", color);
	WriteChar(x, y + 1, "����������������������������������������������������������������������������������������������������������", color);
	WriteChar(x, y + 2, "����������������������������������������������������������������������������������������������������������", color);
	WriteChar(x, y + 3, "����������������������������������������������������������������������������������������������������������", color);
	WriteChar(x, y + 4, "����������������������������������������������������������������������������������������������������������", color);
	WriteChar(x, y + 5, "����������������������������������������������������������������������������������������������������������", color);
	WriteChar(x, y + 6, "����������������������������������������������������������������������������������������������������������", color);
	WriteChar(x, y + 7, "����������������������������������������������������������������������������������������������������������", color);
	WriteChar(x, y + 8, "����������������������������������������������������������������������������������������������������������", color);
	WriteChar(x, y + 9, "����������������������������������������������������������������������������������������������������������", color);
	gameOption();
}

//����Ϸ���棬ѡ����Ϸģʽ,ѡ���Ѷ�
int CAre::gameOption(int x, int y, int color) {
	vector<string> mArr;
	ShowCursor(false, 10);
	WriteChar(x, y, "��ʼ��Ϸ", FOREGROUND_RED);
	WriteChar(x, y + 1, "��ģʽ", FOREGROUND_RED);
	WriteChar(x, y + 2, "ج��ģʽ", FOREGROUND_RED);
	WriteChar(x, y + 3, "����ģʽ", FOREGROUND_RED);
	WriteChar(x, y + 4, "�Զ���ģʽ", FOREGROUND_RED);
	//WriteChar(x+10, y+2, "ʹ��˵����",   FOREGROUND_GREEN);
	//WriteChar(x+12, y+3, "WS����",		 FOREGROUND_GREEN);
	//WriteChar(x+12, y+4, "Enterȷ��",	 FOREGROUND_GREEN);
	mArr.push_back("");
	mArr.push_back("��ʼ��Ϸ");
	mArr.push_back("��ģʽ");
	mArr.push_back("ج��ģʽ");
	mArr.push_back("����ģʽ");
	mArr.push_back("�Զ���ģʽ");
	int result = UpDownSelect(x, y - 1, mArr, 1);
	int speed;								//����ѡ��ģʽ�����ٶ�
	switch (result) {
	case 1:
		system("cls");
		speed = 100;
		StartGame(speed);
		break;
	case 2:
		system("cls");
		speed = 80;
		StartGame(speed);
		break;
	case 3:
		system("cls");
		speed = 60;
		StartGame(speed);
		break;
	case 4:
		system("cls");
		speed = 40;
		StartGame(speed);
		break;
	case 5:
	{
		//�Զ����ͼ���Զ����ͼ��ʾ����
		system("cls");
		int result = map.MessageLoop();
		if (result == 1) {
			objSnake.gameOver();
		}
	}
	break;
	default:
		system("cls");
		objSnake.gameOver();
		break;
	}
}

/**��Ҫ�ǽ��潻��*/
void CAre::initSmallMap(int x, int y, int color) {
	CSnake nake;
	WriteChar(x, y + 1, "************������ʾ************", FOREGROUND_RED);
	WriteChar(x, y + 2, "����:", FOREGROUND_RED);
	WriteChar(x, y + 3, "����:", FOREGROUND_RED);
	WriteChar(x, y + 5, "�ո����ͣ�ָ�", FOREGROUND_RED);
	WriteChar(x, y + 6, "WSAD �����������ң������ִ�Сд", FOREGROUND_RED);
	WriteChar(x, y + 7, "����������Զ�����", FOREGROUND_RED);
	WriteChar(x, y + 8, "���� q ����ϰ���", FOREGROUND_RED);
	WriteChar(x, y + 12, "R-> ���¿�ʼ", FOREGROUND_RED);
}

//��ʼ����ͼ
void CAre::initMap() {
	for (int i = 0; i < MAP_X; i++) {										//������
		for (int j = 0; j < MAP_Y; j++) {									//������
			if (i == 0 || j == 0 || i == MAP_X - 1 || j == MAP_Y - 1) {		//��������ͼ�ϵ��ĸ���
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

//�����������뷨
void CAre::handleInput() {
	keybd_event(VK_SHIFT, 0, 0, 0);			              //ʹ��SHIFT�л���Ӣ��
	Sleep(100);											 //������Ӧʱ�䣬100ms
	keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);			//���̰���̧���¼�
}

//��ȡ���̰���
int CAre::waitKey() {
	if (_kbhit()) { //�жϴ�ʱ�û��Ƿ񰴼����з���1
		return _getch(); //�����û�������,������������
	}
	return 0;//û�а���������0
}

//����ϰ���
void CAre::AddObstacles(int cout) {
	//�����������ֵ����
	int i = 0;
	if (cout == 0)cout = rand() % 8;
	while (i <= cout) {
		int pX = rand() % MAP_X;
		int pY = rand() % MAP_Y;
		WriteChar(pX, pY, "��", BACKGROUND_GREEN);
		nMap[pX][pY] = �ϰ���;
		i++;
	}
}

//�����û��Ĳ���
void CAre::GetPlay(int speed) {
	Oper = waitKey();
	//��������ֱ�� setֵ�������޸� ��ȫ�Ի����һЩ
	switch (Oper) {
	case 'w':case 'W':
		if (objSnake.getDir() == ��) objSnake.setAutoSpeed(true);
		objSnake.setDir(��);
		break;
	case 's':case 'S':
		if (objSnake.getDir() == ��) objSnake.setAutoSpeed(true);
		objSnake.setDir(��);
		break;
	case 'a':case 'A':
		if (objSnake.getDir() == ��) objSnake.setAutoSpeed(true);
		objSnake.setDir(��);
		break;
	case 'd':case 'D':
		if (objSnake.getDir() == ��) objSnake.setAutoSpeed(true);
		objSnake.setDir(��);
		break;
	case 32:
		map.SaveMap();     //�浵
		system("pause>nul");
		break;
	case 43://������٣���Ҫ��ʱ��
		objSnake.setSpeed(speed - 5);
		break;
	case 45:case 95:
		//������٣���Ҫ��ʱ��
		objSnake.setSpeed(speed + 5);
		break;
	case 'q':case 'Q':
		//����x,����5���ϰ���
		AddObstacles(5);
		break;
	case 'r':case 'R':

		map.SaveMap();     //�浵
		system("cls");	   //����Ļ
		welcome();
		break;

	default:
		break;
	}
}

//��ʼ��Ϸ
void CAre::StartGame(int speed, bool isDefault) {
	if (isDefault) {
		initMap();					//Ĭ�ϵ�ͼ
		DrawMap();					//���ص�ͼ����ʾ����
		initSmallMap();				//���dС�؈D
	}
	ShowCursor(false);
	map.OpenMap();					//����
	int nLive = 1;					//�ж��Ƿ������������ڵ�ͼ��Ҳ���;
	while (nLive) {
		//1.��ȡ�û�����
		GetPlay(speed);
		//2.���ݵ�ǰ��ȡ���±�����Ļ����յ�
		objSnake.ClearSnake();
		//3.�����ߵķ���ȥ�ƶ���
		nLive = objSnake.MoveSnake(nMap, m_objFood);
		//4.���������꽫�ߴ��ݹ�ȥ
		if (nLive != 0)objSnake.DrawSnake();
		//5.����һ��ʳ�����
		m_objFood.CreateFood(nMap);
		//�Ե�ʳ���++
		if (nLive != 0 && m_objFood.getFoodExist() == 1) {
			objSnake.AddFootNake();
			WriteChar(50, 12, objSnake.getScoreNake(), FOREGROUND_GREEN);//���÷���
			WriteChar(50, 13, objSnake.getFootNake(), FOREGROUND_GREEN);//���ò���
		}

		Sleep(objSnake.getAutoSpeed() == true ? 0 : speed);
		objSnake.setAutoSpeed(false);
	}
}