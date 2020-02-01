/*
������	:	XTT
����	:

ʱ��	:	2020/02/01
*/
#pragma once
#include<atltrace.h>
#include <list>
#include <graphics.h>



//#define DEBUG 1
//
//#if DEBUG
//#define TRACE(s) OutputDebugString(s)
//#endif

using namespace std;

const short ScreenWidth = 640;
const short ScreenHeight = 480;

const int num[10] = { 0,1,2,3,4,5,6,7,8,9 };
static int scores[3] = { 4,2,3 };

#define N 24  //��ͼ�Ŀ�    Y�� ����
#define M 20  //��ͼ�ĳ�	X��	����
//(24-2)*(20-2)-3 = 393

//�ߵĽṹ
class Snake
{
public:
	Snake()
	{
		x = 10;
		y = 10;
	}
	Snake(int _x, int _y)
	{
		x = _x;
		y = _y;
	};
	int x;
	int y;
};

//ʳ��Ľṹ
struct Food
{
	char x = 2;
	char y = 4;
};


//̰���ߵĵ�ͼ
void Map();

//�������
void Show_map();

//ˢ��ʳ��
void Refresh_food(char ,list<Snake>&);

void Create_snake(list<Snake>&);

void Entry_snake(list<Snake>&);

void Connect_snake(list<Snake>&);

void Growth_snake(char ch, list<Snake>& S);

void Control_snake(char ch,list<Snake>&);

void printList(const list<Snake>&);			//��ӡ

void printMap();

void TracePrint(TCHAR*,...);

void TracePrint(char*, ...);


