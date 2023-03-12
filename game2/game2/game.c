#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

//��ʼ������
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
//��ӡ����
void Displayboard(char board[ROWS][COLS], int row, int col)
{	
	int i = 0;
	int j = 0;
	//��ӡ�к�
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	//��ӡ���
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//�к�
		for (j = 1; j <= col;j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
//����
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
//ɨ��
void Sweepmine(char mineboard[ROWS][COLS], char showboard[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;
	while (count<row*col - MINE)
	{
		printf("����������->");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= col && y >= 1 && y <= row)
		{
			//����
			if ('1' == mineboard[x][y])
			{
				printf("��Ϸ����\n");
				Displayboard(mineboard, ROW, COL);
				break;
			}
			else//������
			{
				char mine=minenum(mineboard, x, y)+'0';	//��Χ�׵ĸ���
				showboard[x][y] = mine;
				Displayboard(showboard, ROW, COL);
				count++;
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
		}
	}
	if (count = row*col - MINE)
	{
		printf("��Ϸʤ��\n");
	}
}