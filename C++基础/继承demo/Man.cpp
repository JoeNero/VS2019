#include "Man.h"

Man::Man()
{
	eye = RED;
}

Man::~Man()
{

}

void Man::ShowInfo()
{
	cout << "眼睛是" << eye << endl;
}

WhiteMan::WhiteMan()
{
	eye = BULE;
}

WhiteMan::~WhiteMan()
{

}

void WhiteMan::Speak()
{
	cout << "白人说话" << endl;
}

BlackeMan::BlackeMan()
{
	eye = GREEN;
}

BlackeMan::~BlackeMan()
{

}

void BlackeMan::Speak()
{
	cout << "黑人说话" << endl;
}

