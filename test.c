#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
void menu()//菜单栏
{
	printf("**************************\n");
	printf("****  1.PLAY  0.EXIT  ****\n");
	printf("**************************\n");
}
void game()
{
	char receive=0;
	//数组存放走出的棋盘信息
	char borad[ROW][COL] = {0};//全部空格
	//初始化棋盘
	InitBorad(borad, ROW, COL);
	//打印棋盘
	DisplayBorad(borad,ROW,COL);
	while (1)
	{
		//玩家下棋
		PlayerMove(borad, ROW, COL);
		DisplayBorad(borad, ROW, COL);
		//判断玩家输赢
		receive = IsWin(borad,ROW,COL);
		if (receive != 'C')
		{
			break;
		}
		//电脑下棋
		printf("1");
		ComputerMove(borad, ROW, COL);
		DisplayBorad(borad, ROW, COL);
		//判断电脑输赢
		receive=IsWin(borad,ROW,COL);
		if (receive != 'C')
		{
			break;
		}
	}
	if (receive == '*')
	{
		printf("玩家获胜！\n");
	}
	else if (receive == '#')
	{
		printf("电脑获胜！\n");
	}
	else
	{
		printf("比赛结果为平局\n");
	}
}
void test()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入你的选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("\t三子棋游戏\n\n\n");
			game();
			break;
		case 0:
			printf("退出游戏！");
			break;
		default:
			printf("选择错误，请重新选择！");
			break;
		}
	} while (input);
}
//测试三子棋游戏
int main()
{
	test();
	return 0;
}