#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
void menu()//�˵���
{
	printf("**************************\n");
	printf("****  1.PLAY  0.EXIT  ****\n");
	printf("**************************\n");
}
void game()
{
	char receive=0;
	//�������߳���������Ϣ
	char borad[ROW][COL] = {0};//ȫ���ո�
	//��ʼ������
	InitBorad(borad, ROW, COL);
	//��ӡ����
	DisplayBorad(borad,ROW,COL);
	while (1)
	{
		//�������
		PlayerMove(borad, ROW, COL);
		DisplayBorad(borad, ROW, COL);
		//�ж������Ӯ
		receive = IsWin(borad,ROW,COL);
		if (receive != 'C')
		{
			break;
		}
		//��������
		printf("1");
		ComputerMove(borad, ROW, COL);
		DisplayBorad(borad, ROW, COL);
		//�жϵ�����Ӯ
		receive=IsWin(borad,ROW,COL);
		if (receive != 'C')
		{
			break;
		}
	}
	if (receive == '*')
	{
		printf("��һ�ʤ��\n");
	}
	else if (receive == '#')
	{
		printf("���Ի�ʤ��\n");
	}
	else
	{
		printf("�������Ϊƽ��\n");
	}
}
void test()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("���������ѡ��:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("\t��������Ϸ\n\n\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ��");
			break;
		default:
			printf("ѡ�����������ѡ��");
			break;
		}
	} while (input);
}
//������������Ϸ
int main()
{
	test();
	return 0;
}