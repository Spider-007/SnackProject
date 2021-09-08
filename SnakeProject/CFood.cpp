#include "CFood.h"
#include <string.h>

CFood::CFood() :g_FoodExist(0) {//食物CFood，构造函数 定义出对象的时候自动调用的函数
	int length = strlen("⊙") + 1;
	str = new char[length + 1];
	strcpy_s(str, length, "⊙");
}

//创建食物，地图应该是30个元素，我们应该随机获取28个元素并且对他取余数
void CFood::CreateFood(int nMap[MAP_X][MAP_Y]) {
	if (g_FoodExist == 0) {
		//需要判断一下map地图上的这一个点是不是空地，如果是食物就画出来，然后吃这个食物
		while (1) {
			int FoodX = rand() % MAP_X - strlen(str) + 1;  //动态获取字符长度
			int FoodY = rand() % MAP_Y - strlen(str) + 1;

			if (nMap[FoodX][FoodY] == 空地) {
				nMap[FoodX][FoodY] = 食物;
				WriteChar(FoodX, FoodY, "☆");
				g_FoodExist = 1;
				break;
			}
		}
	}
}

void CFood::setFoodExist(int foodExist) {
	g_FoodExist = foodExist;
}

int CFood::getFoodExist() {
	return g_FoodExist;
}