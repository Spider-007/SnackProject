#include "CFood.h"
#include <string.h>

CFood::CFood():g_FoodExist(0){//ʳ��CFood�����캯�� ����������ʱ���Զ����õĺ���	
	int length  = strlen("��")+1;
    str = new char[length+1];
	strcpy_s(str,length,"��");
}

//����ʳ���ͼӦ����30��Ԫ�أ�����Ӧ�������ȡ28��Ԫ�ز��Ҷ���ȡ����
void CFood::CreateFood(int nMap[MAP_X][MAP_Y]) {

	if (g_FoodExist == 0) {

		int FoodX = rand() % MAP_X - strlen(str) + 1;  //��̬��ȡ�ַ�����
		int FoodY = rand() % MAP_Y - strlen(str) + 1;

		//��Ҫ�ж�һ��map��ͼ�ϵ���һ�����ǲ��ǿյأ������ʳ��ͻ�������Ȼ������ʳ��
		if (nMap[FoodX][FoodY] == �յ�) {	
			nMap[FoodX][FoodY] = ʳ��;
			WriteChar(FoodX, FoodY, "��");
			g_FoodExist = 1;
			return;
		}
	}
}

void CFood::setFoodExist(int foodExist) {
	g_FoodExist = foodExist;
}
