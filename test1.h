/*
* �̳����̬�е�����
*/

#ifndef TEST1
#define TEST1
#include<iostream>
using namespace std;

class A
{
public:
	A(int a) :x(a) {};
	virtual void fun1();
	virtual void fun2();
	int x;
};
class B :public A
{
public:
	void fun1();
	void fun2(int);
	void fun2();
	B() :y(2), A(y) {}
	int y;
};

//��ʼ���б��˳��
void test1();

//�麯�����
void test1_2();

#endif
