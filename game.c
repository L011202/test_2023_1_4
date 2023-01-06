#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include "game.h"
void InitBorad(char borad[ROW][COL], int row, int col)
{
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			borad[i][j]=' ';
		}
	}
}
//未优化前的代码
//void DisplayBorad(char borad[ROW][COL], int row, int col)
//{
//	int i;
//	for (i = 0; i < row; i++)
//	{
//		//打印一行的数据
//		printf(" %c | %c | %c\n",borad[i][0],borad[i][1],borad[i][2]);
//		//打印分割行
//		if (i < row - 1)
//		{
//			printf("---|---|---\n");
//		}
//	}
//	
//}
//优化后的代码
void DisplayBorad(char borad[ROW][COL], int row, int col)
{
	int i;
	for (i=0;i<row;i++)
	{
		int j;
		for (j = 0; j < col; j++)
		{
			//打印一行的数据
			printf(" %c ", borad[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		//打印分割行
		if (i<row-1)
			{
			for (j=0;j<col;j++)
				{
				printf("---");
				if (j<col-1)
					{
					printf("|");
					}
				}
			printf("\n");
			}
		}
	}
void PlayerMove(char borad[ROW][COL], int row, int col)
{
	int x;
	int y;
	printf("玩家请走\n");
	while (1)
	{
		printf("请玩家输入要下的坐标\n");
		scanf("%d %d", &x, &y);
		//判断玩家输入的坐标的合法性
		if ((x >= 1 && x <= row) ,(y >= 1 && y <= col))
		{
			if (borad[x - 1][y - 1] == ' ')
			{
				borad[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标已经被放置过棋子\n");
			}
		}
		else
		{
			printf("输入的坐标不合法，请您重新再次输入！\n");
		}
	}
}
void ComputerMove(char borad[ROW][COL], int row, int col)
{
	int x;
	int y;
	printf("电脑走\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (borad[x][y] == ' ')
		{
			borad[x][y] = '#';
			break;
		}
	}
}
int IsFull(char borad[ROW][COL],int row,int col)
{
	int i;
	int j;
	for (i=0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (borad[i][j] == ' ')
			{
				return 0; 
			}
		}
	}
	return 1;
}
char IsWin(char borad[ROW][COL], int row, int col)
{
	int i;
	//判断行
	for (i = 0; i < row; i++)
	{
		if ((borad[i][0] == borad[i][1]) && (borad[i][1] == borad[i][2]&& borad[i][1] != ' '))
		{
			return borad[i][1];
		}
	}
	//判断列
	for (i = 0; i < col; i++)
	{
		if (borad[0][i] == borad[1][i] && borad[1][i] == borad[1][i] == borad[2][i] && borad[1][i] != ' ')
		{
			return borad[1][i];
		}
	}
	//判断斜
	if (borad[0][0] == borad[1][1] && borad[1][1] == borad[2][2] && borad[1][1] != ' ')
	{
		return borad[1][1];
	}
	if (borad[2][0] == borad[1][1] && borad[1][1] == borad[0][2] && borad[1][1] != ' ')
	{
		return borad[1][1];
	}
	//判断是否平局
	if (IsFull(borad, row, col) == 1)
	{
		return 'Q';
	}
		return "C";
}