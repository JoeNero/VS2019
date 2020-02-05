#pragma once
#include <string>
#include <iostream>

using namespace std;
enum  Color
{
	RED = 1,
	GREEN,
	BULE
};
class Man
{
public:
	Man();
	~Man();
	virtual void Speak() = 0;		//´¿Ðéº¯Êý
	void ShowInfo();
protected:
	int eye;
private:

};

class WhiteMan:public Man
{
public:
	WhiteMan();
	~WhiteMan();
	void Speak();
private:

};

class BlackeMan :public Man
{
public:
	BlackeMan();
	~BlackeMan();
	void Speak();
private:

};


