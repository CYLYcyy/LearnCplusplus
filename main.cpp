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
 * 这里成员变量stack和max应该用std::stack更好
 * 最大栈的思路就是除了自身管理的栈，再管理一个最大值的栈。每次入栈都与当前最大值比较，如果大于等于，就同时压入最大栈
 * 出栈时同理，如果恰好等于最大值的栈的栈顶，就将它一起弹出
 * 入栈时，等于当前最大值时仍然入栈的操作就保证了多个相同的最大值时pop操作也不会出错
 */

int main()
{
	t962();
}