
#include "game.h"

void menu()
{
	printf("******************************\n");
	printf("****   1.paly   0.exit   *****\n");
	printf("******************************\n");
}


void game()
{
	int set=0;
	char board[ROW][COL]={0};
	//初始化棋盘
	Initboard(board,ROW,COL);
	//创建棋盘
	Displayboard(board,ROW,COL);
	
	while(1)
	{
		//玩家输入
		Playermove(board,ROW,COL);
		set=Iswin(board,ROW,COL);
		Displayboard(board,ROW,COL);
		if(set!='C')
		{
			break;
		}
		//电脑输入
		Computermove(board,ROW,COL);
		set=Iswin(board,ROW,COL);
		Displayboard(board,ROW,COL);
		if(set!='C')
		{
			break;
		}
	}
	if(set=='*')
	{
		printf("玩家赢\n");
	}
	else if(set=='#')
	{
		printf("电脑赢\n");
	}
	else if(set=='D')
	{
		printf("平局了\n");
	}
	
	

}

int main()
{
	int input=0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				printf("开始游戏\n");
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("输入错误\n");
				break;
		
		}
	}while(input);

	return 0;
}