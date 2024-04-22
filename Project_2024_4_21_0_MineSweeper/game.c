#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for(i = 0;i<rows;i++)
	{
		for(j =0;j<cols;j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	//��ӡ�к�
	for(i =0; i<= col; i++)
	{
		printf("%d ", i);		
	}
	printf("\n");
	
	for(i = 1; i<=row; i++)//�к�
	{
		printf("%d ", i);//��ӡ�к�
		for(j =1; j<=col; j++)//�к�
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	//'3' - '0' = 3
	//'1' - '0' = 1
	return mine[x-1][y] + 
	mine[x-1][y-1] + 
	mine[x][y-1] + 
	mine[x+1][y-1] + 
	mine[x+1][y] + 
	mine[x+1][y+1] + 
	mine[x][y+1] + 
	mine[x-1][y+1] - 8*'0'; //�ַ�0�����Գˣ��������ascii��ֵ
	
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	int x = 0;
	int y = 0;
	while(count)
	{
		x = (rand()%row) + 1;//1-9
		y = (rand()%col) + 1;
		if(board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

//void Set_space(char mine[ROWS][COLS],char show[ROWS][COLS], int x, int y)
//{
//	
//	int count1 = get_mine_count(mine, x-1, y);
//	int count2 = get_mine_count(mine, x-1, y-1);
//	int count3 = get_mine_count(mine, x-1, y+1);
//	int count4 = get_mine_count(mine, x, y-1);
//	int count5 = get_mine_count(mine, x, y+1);
//	int count6 = get_mine_count(mine, x+1, y-1);
//	int count7 = get_mine_count(mine, x+1, y);
//	int count8 = get_mine_count(mine, x+1, y+1);
//	if()
//}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	
	int win = 0;
	while(win<row*col - EASY_COUNT)
	{
		printf("�������Ų��׵�����:> ");
		scanf("%d%d", &x, &y);
		if(x>=1 && x<= row && y>=1 && y<=col)
		{
			//����Ϸ�
			//1.����
			if(mine[x][y] == '1')
			{
				printf("���ź����㱻ը���ˣ�\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else//������
			{
				int count = 0;
				//����x, y��Χ�м�����
				count = get_mine_count(mine, x, y);
//				if(count == 0)
//				{
//					Set_space(show, x, y);
//					DisplayBoard(mine , show, row, col);
//					win+=row*col;
//				}
//				else
//				{
					show[x][y] = count + '0';//ת��Ϊ�ַ�
					DisplayBoard(show, row, col);
					win++;
//				}
			
			}
		}
		else
		{
			printf("��������Ƿ������������룡\n");	
		}
	}
	if(win == row*col - EASY_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ���\n");
		DisplayBoard(mine, row, col);
	}

}