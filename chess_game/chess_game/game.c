#define _CRT_SECURE_NO_WARNINGS
#include "game.h"


//初始化棋盘
void Initboard(char board[ROW][COL],int row,int col)
{
	int i=0;
	int j=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			board[i][j]=' ';
		}
	}
}

//创建棋盘
void Displayboard(char board[ROW][COL],int row,int col)
{
	int i=0;
	int j=0;
	//1.打印内容行
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf(" %c ",board[i][j]);
			if(j<col-1)
				printf("|");
		}
		printf("\n");
	//2.打印分割行
		if(i<row-1)
		{
			for(j=0;j<col;j++)
			{
				printf("---");
			    if(j<col-1)
				    printf("|");
			}
			printf("\n");
		
		}
	}
}


//玩家输入
void Playermove(char board[ROW][COL],int row,int col)
{
	int x=0;
	int y=0;
	while(1)
	{
		printf("请输入坐标->");
		scanf("%d %d",&x,&y);
		if(x>=1&&x<=row && y>=1&&y<=col)
		{
			if(board[x-1][y-1]==' ')
			{
				board[x-1][y-1]='*';
				break;
			}
			else
			{
				printf("坐标已被占用\n");
			}
				
		}
		else
			printf("坐标非法，请重新输入\n");
	}	
	
}
	

//电脑输入
void Computermove(char board[ROW][COL],int row,int col)
{
	int x=0;
	int y=0;
	printf("电脑输入->\n");
	while(1)
	{
		x=rand()%row;
		y=rand()%col;
		if(board[x][y]==' ')
		{
			board[x][y]='#';
			break;
		}
	}
}
//判断输赢
char Iswin(char board[ROW][COL],int row,int col)
{
	int i=0;
	//横三行
	for(i=0;i<row;i++)
	{
		if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][2]!=' ')
		{
			return board[i][0];
		}
	}
	//竖三行
	for(i=0;i<col;i++)
	{
		if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[2][i]!=' ')
		{
			return board[0][i];
		}
	}
	//两行对角线
	if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0]!=' ')
	{
		return board[0][0];
	}
	if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[2][0]!=' ')
	{
		return board[2][0];
	}
	//棋盘是否满
	if(Isfull(board,ROW,COL)==1)
	{
		return 'D';
	}
	else
		return 'C';
}

int Isfull(char board[ROW][COL],int row,int col)
{
//1.返回1表示满了
//2.返回0表示没满
	int i=0;
	int j=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(board[i][j]==' ')
			{
				return 0;
			}
		}
	}
	return 1;
}