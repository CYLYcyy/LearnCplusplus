#include "test2.h"

void add(int x,int y)
{
	cout << x + y << endl;
}
void multiply(int x,int y)
{
	cout << x * y << endl;
}

void (*cal(char sym))(int,int)
{
	switch (sym)
	{
	case '+':
		return add;
		break;
	case '*':
		return multiply;
		break;
	}
}


typedef void (*pfun)(int,int);
pfun mycal(char sym)
{
	switch (sym)
	{
	case '+':
		return add;
		break;
	case '*':
		return multiply;
		break;
	}
}
typedef pfun (*mysignal)(char);

typedef void (*(*MySignal)(char))(int,int);

void Param::set(int a)
{
	x = a;
}

Accessor* Int::pAccessor(void)
{
	Accessor* pA = new Accessor(this, (void (Param::*)(int))&Int::set);
	return pA;
}

Accessor::Accessor(Param* x,setter pfun)
	:mpParam(x),pf(pfun)
{
}

void Accessor::set(int a)
{
	(mpParam->*pf)(a);
	Param P;

	(P.*pf)(a);

	int x = mpParam->x;
}



void Int::set(int a)
{
	Param::set(a);
	x = a;
}

void test2()
{
	
	mysignal pcal = cal;
	auto pf = pcal('+');

	pf(1, 2);

	MySignal p = mycal;
	auto pF = p('*');

	pF(2, 2);
	

	Int myint;
	(myint.pAccessor())->set(1);
}

