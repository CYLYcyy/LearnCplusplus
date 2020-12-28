#include "test1.h"

void A::fun1()
{
	cout << "A::fun1"<<endl;
}

void A::fun2()
{
	cout << "A::fun1" << endl;
}

void B::fun1()
{
	cout << "B::fun1" << endl;
}

//隐藏fun2,B::中没有fun2(),除非再在B中将此函数重载与父类参数类型相同的函数(若父类是虚函数:重写;父类是非虚:覆盖）
void B::fun2(int a = 1)
{

}

void B::fun2()
{
	cout << "B::fun2" << endl;
}


void test1()
{
	B b;
	cout << b.x << endl << b.y << endl;
}

void test1_2()
{
	B b;
	A* p = &b;
	
	p->fun1(); //子类重写虚函数时若没有加virtual
	b.fun1();

	p->fun2();//p->fun2(1)报错
	//b.fun2();
	b.fun2(1);
	B* pb;
}