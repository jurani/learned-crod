#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void meun()
{
	printf("*****************************\n");
	printf("****   1.play   0.exit   ****\n");
	printf("*****************************\n");
}

void game()
{	//�׵���Ϣ����
	char mineboard[ROWS][COLS] = { 0 };
	//�Ų����Ϣ����
	char showboard[ROWS][COLS] = { 0 };
	//��ʼ������
	Initboard(mineboard,ROWS,COLS,'0');
	Initboard(showboard, ROWS, COLS, '*');
	//��ӡ����
	Displayboard(showboard, ROW, COL);
	//����
	Mine(mineboard, ROW, COL);
	Displayboard(mineboard, ROW, COL);
	//ɨ��
	Sweepmine(mineboard, showboard, ROW, COL);

}
void test()
{
	int input = 0;
	do
	{
		meun();
		scanf("%d", &input);
		switch (input)//��Ϸѡ��
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������������ѡ��\n");
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

