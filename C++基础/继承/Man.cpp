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
	cout << "�۾���" << eye << endl;
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
	cout << "����˵��" << endl;
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
	cout << "����˵��" << endl;
}

