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

//����fun2,B::��û��fun2(),��������B�н��˺��������븸�����������ͬ�ĺ���(���������麯��:��д;�����Ƿ���:���ǣ�
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
	
	p->fun1(); //������д�麯��ʱ��û�м�virtual
	b.fun1();

	p->fun2();//p->fun2(1)����
	//b.fun2();
	b.fun2(1);
	B* pb;
}