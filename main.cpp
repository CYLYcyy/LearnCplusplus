#include "test1.h"
#include "test2.h"
#include "test3.h"
#include "blackBox.h"
#include "exercise.h"
#include <vector>
using namespace std;
int& topOf(vector<int>& vec)
{
	return *(vec.end() - 1);
}
class maxStack {
public:
	void push(int val) {
		stack.push_back(val);
		if (max.empty())
		{
			max.push_back(val);
		}
		else if (val >= topOf(max))
		{
			max.push_back(val);
		}
	}

	void pop() {
		if (stack.empty())
		{
			return;
		}
		if (max.empty())
		{
			return;
		}

		if (topOf(max) == topOf(stack))
		{
			max.pop_back();
		}
		stack.pop_back();
	}

	int top()
	{
		return topOf(stack);
	}

	int getMax()
	{
		return topOf(max);
	}
private:
	std::vector<int> stack;
	std::vector<int> max;
};
/*
 * �����Ա����stack��maxӦ����std::stack����
 * ���ջ��˼·���ǳ�����������ջ���ٹ���һ�����ֵ��ջ��ÿ����ջ���뵱ǰ���ֵ�Ƚϣ�������ڵ��ڣ���ͬʱѹ�����ջ
 * ��ջʱͬ�����ǡ�õ������ֵ��ջ��ջ�����ͽ���һ�𵯳�
 * ��ջʱ�����ڵ�ǰ���ֵʱ��Ȼ��ջ�Ĳ����ͱ�֤�˶����ͬ�����ֵʱpop����Ҳ�������
 */

int main()
{
	t962();
}