/*
������	:	XTT
����	:

ʱ��	:	2020/02/01
*/
#include "Snake.h"
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <atltrace.h>
 
static int snake_length = 3;//�ߵĳ���(����)
static int s = 0;

TCHAR s1[] = _T("̰����");
TCHAR s2[] = _T("�Ƿְ�:");

Food food;  //����ʳ��Ľṹ

char map[N][M];//��ͼ����

//����̰���ߵĵ�ͼ
void Map()
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (i == 0 || i == N - 1 || j == 0 || j == M - 1)
				map[i][j] = '*';
			else
				map[i][j] = ' ';
		}
	}
	printMap();
	//map[2][3] = '@';
	//map[2][4] = '+';
}


//���µ�ͼ
void Show_map()
{
	BeginBatchDraw();
	rectangle(0, 0, 400, 600);
	setcolor(RED);
	outtextxy(480, 50, s1);
	setcolor(WHITE);
	outtextxy(450, 90, s2);

	
	scores[0] = s / 100;
	scores[1] = (s / 10) % 10;
	scores[2] = s % 10;

	UCHAR s = scores[2] + '0';	//��λ
	outtextxy(550, 90, s);
	s = scores[1] + '0';		//ʮλ
	outtextxy(540, 90, s);
	s = scores[0] + '0';		//��λ
	outtextxy(530, 90, s);

	rectangle(0, 0, 400, 600);
	//ѭ������ÿһ������
	for (int i = 0; i < N; i++)		//y�᷽�� 480/20 �����ת����
	{
		for (int j = 0; j < M; j++)	//x�᷽�� ȡ��400 ����Ƿְ�400/20
		{
			char ch = map[i][j];
			switch (ch)
			{
			case '*'://ǽ
				rectangle(j * 20 + 1, i * 20 + 1, j * 20 + 20 - 1, i * 20 + 20 - 1);
				break;
			case '@'://��ͷ
				solidroundrect(j * 20 + 1, i * 20 + 1, j * 20 + 20 - 1, i * 20 + 20 - 1, 10, 10);
				break;
			case '+'://����
				pie(j * 20 + 1, i * 20 + 1, j * 20 + 20 - 1, i * 20 + 20 - 1, 10, 90);
				break;
			case '$'://ʳ��
				ellipse(j * 20 + 1, i * 20 + 1, j * 20 + 20 - 1, i * 20 + 20 - 1);
				break;
			case ' '://���
				clearrectangle(j * 20 + 1, i * 20 + 1, j * 20 + 20 - 1, i * 20 + 20 - 1);
				break;
			case 'X'://��β
				solidroundrect(j * 20 + 1, i * 20 + 1, j * 20 + 20 - 1, i * 20 + 20 - 1, 50, 50);
				break;
			default:
				break;
			}
		}
	}
	FlushBatchDraw();
	Sleep(100);
	EndBatchDraw();
}

//ˢ��ʳ��
void Refresh_food(char ch,list<Snake>& S)
{
	if ((food.x == S.front().x) && (food.y == S.front().y))
	{
		map[food.y][food.x] = ' ';
		s++;
		food.x = rand() % (M - 2) + 1;
		food.y = rand() % (N - 2) + 1;
		TracePrint("ˢ��ʳ��ɹ�");
		snake_length++;
		Growth_snake(ch, S);	
	}
	map[food.y][food.x] = '$';
	TracePrint(_T("ʳ�� x = %d ,y = %d\n"), food.x, food.y);
}

//������
void Create_snake(list<Snake>& S)
{
	list<Snake> _S(S);					//��ʱ��������
	srand((unsigned)time(NULL));				//�����������
	Snake* snake = new Snake[snake_length];		//������ͷ-����-��β �ܹ����ڵ�
									//��ͷ��
	//int x = rand() % (N - 2) + 1;
	//int y = rand() % (M - 5) + 1;
	for (int i = 0; i < snake_length; i++)
	{
		int _x = 10;
		int _y = 10 - i - 1;

		snake[i].x = _x;							//���긳ֵ���߽ڵ���
		snake[i].y = _y;

		_S.push_back(snake[i]);						//��������
	}
#if 0
	TracePrint(_T("��ʱ��\n"));
	printList(_S);
#endif // 0
	S = _S;										//���ظ�ԭ��������
	TracePrint(_T("�����߳ɹ�\n"));	
#if 0
	TracePrint(_T("ʵ����\n"));
	printList(S);
#endif // 0
}
//¼����
void Entry_snake(list<Snake>& S)
{

	if (S.empty())
	{
		TracePrint(_T("¼���߽ڵ�Ϊ��\n"));
		return;
	}
	else
	{
		int num = 0;
		list<Snake> _S(S);							//��ʱ��������
		map[S.front().y][S.front().x] = '@';
		for (list<Snake>::iterator it = S.begin(); it != S.end(); it++)
		{
			char _x = it->x;
			char _y = it->y;
			if (0 == num)		//��ͷ
			{
				map[_y][_x] = '@';
			}
			else if (snake_length == num)
			{
				map[_y][_x] = ' ';
			}
			else
			{
				map[_y][_x] = '+';
			}
			num++;
		}
	}
}

//�߽ڵ��
void Connect_snake(list<Snake>& S)
{
	char _x, _y, _x1, _y1;
	_x = S.front().x;
	_y = S.front().y;
	list<Snake>::iterator it = S.begin();
	//it++;
	for (; it != S.end(); it++)
	{
		_x1 = it->x;
		_y1 = it->y;
		it->x = _x;
		it->y = _y;
		_x = _x1;
		_y = _y1;
	}
	TracePrint("������\n");
	printList(S);
}


//���ߵ�������ж�λ
void Growth_snake(char ch, list<Snake>& S)
{
	Snake s1;					//��ȫ��ڵ�
	S.push_back(s1);
	for (list<Snake>::iterator it = S.begin(); it != S.end(); it++)
	{
		char _x = it->x;
		char _y = it->y;
		switch (ch)
		{
		case 'w':
			it->x = _x;
			it->y = ++_y;
			break;
		case 's':
			it->x = _x;
			it->y = --_y;
			break;
		case 'a':
			it->x = ++_x;
			it->y = _y;
			break;
		case 'd':
			it->x = --_x;
			it->y = _y;
			break;
		default:
			break;
		}
	}
}
void Control_snake(char ch, list<Snake>& S)
{
	
	char c = ch;
	list<Snake>::iterator it = S.begin();		//ʹ�õ�����
	switch (c)
	{
	case 'w':	it->y--;	break;
	case 's':	it->y++;	break;
	case 'a':	it->x--;	break;
	case 'd':	it->x++;	break;
	default:				break;
	}
//	TracePrint("�������ƶ�\n");
//	printList(S);
	Connect_snake(S);	
}

/*
����: 	- ��ӡlist����
		@const list<Snake>& L
		@param
		@param
����	:
ʾ��	:	printList(L4);
*/
void printList(const list<Snake>& L)
{
	if (L.empty())
	{
		TracePrint("��ӡ������Ϊ��");
		return;
	}
	else
	{
		for (list<Snake>::const_iterator it = L.begin(); it != L.end(); it++)
		{
			TracePrint("x = %d,y = %d\n", it->x, it->y);
		}
		//TracePrint(_T("��������%d\n"),L.size());
	}
}

void printMap()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			TracePrint("%c ", map[i][j]);
		}
		TracePrint("\n");
	}
}

//�����ӡ��������ڿ��ַ�
void TracePrint(TCHAR* format, ...)
{
	TCHAR buffer[1024];
	va_list argptr;
	va_start(argptr, format);
	wvsprintf(buffer, format, argptr);
	va_end(argptr);
	OutputDebugString(buffer);
}
//�����ӡ���������
void TracePrint(char* format, ...)
{
	char buffer[1024];
	va_list argptr;
	va_start(argptr, format);
	vsprintf_s(buffer, format, argptr);
	va_end(argptr);
	OutputDebugStringA(buffer);
}


