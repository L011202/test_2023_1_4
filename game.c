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
//δ�Ż�ǰ�Ĵ���
//void DisplayBorad(char borad[ROW][COL], int row, int col)
//{
//	int i;
//	for (i = 0; i < row; i++)
//	{
//		//��ӡһ�е�����
//		printf(" %c | %c | %c\n",borad[i][0],borad[i][1],borad[i][2]);
//		//��ӡ�ָ���
//		if (i < row - 1)
//		{
//			printf("---|---|---\n");
//		}
//	}
//	
//}
//�Ż���Ĵ���
void DisplayBorad(char borad[ROW][COL], int row, int col)
{
	int i;
	for (i=0;i<row;i++)
	{
		int j;
		for (j = 0; j < col; j++)
		{
			//��ӡһ�е�����
			printf(" %c ", borad[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		//��ӡ�ָ���
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
	printf("�������\n");
	while (1)
	{
		printf("���������Ҫ�µ�����\n");
		scanf("%d %d", &x, &y);
		//�ж�������������ĺϷ���
		if ((x >= 1 && x <= row) ,(y >= 1 && y <= col))
		{
			if (borad[x - 1][y - 1] == ' ')
			{
				borad[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�������Ѿ������ù�����\n");
			}
		}
		else
		{
			printf("��������겻�Ϸ������������ٴ����룡\n");
		}
	}
}
void ComputerMove(char borad[ROW][COL], int row, int col)
{
	int x;
	int y;
	printf("������\n");
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
	//�ж���
	for (i = 0; i < row; i++)
	{
		if ((borad[i][0] == borad[i][1]) && (borad[i][1] == borad[i][2]&& borad[i][1] != ' '))
		{
			return borad[i][1];
		}
	}
	//�ж���
	for (i = 0; i < col; i++)
	{
		if (borad[0][i] == borad[1][i] && borad[1][i] == borad[1][i] == borad[2][i] && borad[1][i] != ' ')
		{
			return borad[1][i];
		}
	}
	//�ж�б
	if (borad[0][0] == borad[1][1] && borad[1][1] == borad[2][2] && borad[1][1] != ' ')
	{
		return borad[1][1];
	}
	if (borad[2][0] == borad[1][1] && borad[1][1] == borad[0][2] && borad[1][1] != ' ')
	{
		return borad[1][1];
	}
	//�ж��Ƿ�ƽ��
	if (IsFull(borad, row, col) == 1)
	{
		return 'Q';
	}
		return "C";
}