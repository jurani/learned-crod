
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
	//��ʼ������
	Initboard(board,ROW,COL);
	//��������
	Displayboard(board,ROW,COL);
	
	while(1)
	{
		//�������
		Playermove(board,ROW,COL);
		set=Iswin(board,ROW,COL);
		Displayboard(board,ROW,COL);
		if(set!='C')
		{
			break;
		}
		//��������
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
		printf("���Ӯ\n");
	}
	else if(set=='#')
	{
		printf("����Ӯ\n");
	}
	else if(set=='D')
	{
		printf("ƽ����\n");
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
				printf("��ʼ��Ϸ\n");
				game();
				break;
			case 0:
				printf("�˳���Ϸ\n");
				break;
			default:
				printf("�������\n");
				break;
		
		}
	}while(input);

	return 0;
}