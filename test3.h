#ifndef TEST3
#define TEST3
#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

class Observer
{
	friend class subject;
public:
	virtual void update();
	subject* psub;
};
class subject
{
	friend class Observer;
public:
	void add(Observer* ob);
	void del(Observer* ob);
	void notify();
	void modify(int x);
private:
	int len;
	vector<Observer*> oVector;
};

void test3();
#endif
