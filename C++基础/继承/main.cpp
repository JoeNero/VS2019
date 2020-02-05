/*
文件名 	:   main.cpp
创建者	:	XTT
功能	:


时间	:	2020/02/05
*/
#define CRTDBG_MAP_ALLOC  
#include <iostream>
#include <crtdbg.h> 
#include "Man.h"

using namespace std;

int main()
{
	WhiteMan w1;
	BlackeMan b1;
	w1.Speak();
	w1.ShowInfo();

	b1.Speak();
	b1.ShowInfo();

	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}


