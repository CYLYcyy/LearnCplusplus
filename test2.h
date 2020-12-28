#ifndef TEST2
#define TEST2
#include <iostream>
using namespace std;

//复杂函数声明与类成员函数指针

class Param
{
public:
	virtual void set(int a);

	int x;
	
};

class Accessor
{
public:
	typedef void(__thiscall Param::* setter)(int);
public:
	Accessor(Param* x,setter pf);

	void set(int a);

	Param* mpParam;
	void (Param::* pf)(int);
};

class Int :public Param
{
public:
	virtual void set(int a);

	Accessor* pAccessor(void);
	
	int x;
};  


void test2();
#endif
