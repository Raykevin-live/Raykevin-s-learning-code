#define _CRT_SECURE_NO_WARNINGS 1


#include "game.h"

void menu()
{
	printf("*************************\n");
	printf("****     1. play     ****\n");
	printf("****     0. exit     ****\n");
	printf("*************************\n");
}

void game()
{
	//雷的信息存储
	
	//1.布置好的雷的信息
	char mine[ROWS][COLS] = {0};//11*11
	//2.排查出的雷的信息
	char show[ROWS][COLS] = {0};
	//初始化
	InitBoard(mine , ROWS, COLS, '0');//初始化设置成不同字符，加入一个参数
	InitBoard(show , ROWS, COLS, '*');

	//打印棋盘
	DisplayBoard(show, ROW, COL);
	
	
	//布置雷
	SetMine(mine, ROW, COL);
	printf("\n");
	DisplayBoard(mine, ROW, COL);

	//扫雷
	// 
//	DisplayBoard(mine, ROW, COL);
	FindMine(mine, show, ROW, COL);
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			printf("      扫雷\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新选择!\n");
			break;
		}
	}
	while(input);
}


int main()
{
	test();
	return 0;
}
