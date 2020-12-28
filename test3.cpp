#include "test3.h"

void Observer::update()
{

	cout << "Now "<<typeid(*psub).name() <<": lenth's len is "<<psub->len;
}

void subject::add(Observer* ob)
{
	typeid(2);
	oVector.push_back(ob);
	ob->psub = this;
}

void subject::del(Observer* ob)
{
	oVector.erase(remove(oVector.begin(), oVector.end(), ob), oVector.end());
}

void subject::notify()
{
	for (auto p = oVector.begin(); p != oVector.end(); p++)
	{
		(*p)->update();
	}
}

void subject::modify(int x)
{
	len = x;
}

void test3()
{
	Observer ob;
	subject lenth;
	lenth.add(&ob);
	lenth.modify(3);
	lenth.notify();
	lenth.del(&ob);
}
