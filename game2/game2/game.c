#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

//初始化棋盘
void Initboard(char board[ROWS][COLS], int rows, int cols,char ch)
{
	int i = 0;
	int j = 0;
	for (i=0;i<rows;i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = ch;
		}
	}
}
//打印棋盘
void Displayboard(char board[ROWS][COLS], int row, int col)
{	
	int i = 0;
	int j = 0;
	//打印列号
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	//打印表格
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//行号
		for (j = 1; j <= col;j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
//埋雷
void Mine(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int x = 0;
	int y = 0;
	int count = MINE;
	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if ('0' == board[x][y])
		{
			board[x][y] = '1';
			count--;
		}
	}


}

int  minenum(char board[ROWS][COLS], int x, int y)
{
	return board[x - 1][y] + board[x - 1][y - 1] + board[x][y - 1] +
		board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1] +
		board[x][y + 1] + board[x - 1][y + 1] - 8 * '0';
}
//扫雷
void Sweepmine(char mineboard[ROWS][COLS], char showboard[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;
	while (count<row*col - MINE)
	{
		printf("请输入坐标->");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= col && y >= 1 && y <= row)
		{
			//踩雷
			if ('1' == mineboard[x][y])
			{
				printf("游戏结束\n");
				Displayboard(mineboard, ROW, COL);
				break;
			}
			else//不是雷
			{
				char mine=minenum(mineboard, x, y)+'0';	//周围雷的个数
				showboard[x][y] = mine;
				Displayboard(showboard, ROW, COL);
				count++;
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
	if (count = row*col - MINE)
	{
		printf("游戏胜利\n");
	}
}