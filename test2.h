#ifndef TEST2
#define TEST2
#include <iostream>
using namespace std;

//���Ӻ������������Ա����ָ��

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
