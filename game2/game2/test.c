#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void meun()
{
	printf("*****************************\n");
	printf("****   1.play   0.exit   ****\n");
	printf("*****************************\n");
}

void game()
{	//雷的信息储存
	char mineboard[ROWS][COLS] = { 0 };
	//排查的信息储存
	char showboard[ROWS][COLS] = { 0 };
	//初始化棋盘
	Initboard(mineboard,ROWS,COLS,'0');
	Initboard(showboard, ROWS, COLS, '*');
	//打印棋盘
	Displayboard(showboard, ROW, COL);
	//埋雷
	Mine(mineboard, ROW, COL);
	Displayboard(mineboard, ROW, COL);
	//扫雷
	Sweepmine(mineboard, showboard, ROW, COL);

}
void test()
{
	int input = 0;
	do
	{
		meun();
		scanf("%d", &input);
		switch (input)//游戏选择
		{
		case 1:
			printf("开始游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新选择\n");
			break;

		}
	} while (input);

}



int main()
{
	srand((unsigned int)time(NULL));
	test();
	return 0;

}

