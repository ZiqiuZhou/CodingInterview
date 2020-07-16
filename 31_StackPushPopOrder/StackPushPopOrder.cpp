#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/*
 输入两个整数序列， 第一个序列表示栈的压入序列，判断第二个栈
是否可以成为可能的出栈序列（不一定全部压栈后才出栈）
思路：建立一个辅助栈用来压入序列；从出栈序列中依次判断，当前元素是不是
栈中此刻的栈顶，是的话元素出栈，指针来到出栈序列下一个位置；不是的话，从
压栈序列中还未入栈元素里持续压栈，直到压入的元素是该出栈序列中当前元素；
如果压栈序列全部入栈仍然没找到， 则出栈序列不正确。
*/
bool findElement(vector<int>& pushOrder, vector<int>& popOrder);

bool isPopOrder(vector<int>& pushOrder, vector<int>& popOrder)
{
	if (pushOrder.size() != popOrder.size())
		return false;
	if (!findElement(pushOrder, popOrder)) //有无效输入
		return false;

	stack<int> help;
	std::vector<int>::iterator iter1 = pushOrder.begin();
	std::vector<int>::iterator iter2 = popOrder.begin();
	while(iter2 != popOrder.end())
	{
		if (help.empty())
			help.push(*iter1++);
		if (*iter2 != help.top())
		{
			while (iter1 != pushOrder.end() && *iter2 != help.top())
				help.push(*iter1++);
			if (iter1 == pushOrder.end() && *iter2 != help.top()) //如果遍历完pushOrder仍然没找到
				return false;
		}
		help.pop();
		++iter2;
	}
	return true;
}

//判断压栈和出栈序列中元素时候互有对应，来判断输入序列是否无效
bool findElement(vector<int>& pushOrder, vector<int>& popOrder)
{
	bool mark = true;
	vector<int>::iterator iter;
	for (int i = 0; i < popOrder.size(); ++i)
	{
		iter = std::find(pushOrder.begin(), pushOrder.end(), popOrder[i]);
		if (iter == pushOrder.end())
		{
			mark = false;
			return mark;
		}
	}
	return mark;
}

int main()
{
	vector<int> array1 = { 1, 2, 3, 4, 5 };
	vector<int> array2 = { 4, 5, 3, 2, 1 };
	vector<int> array3 = { 4, 3, 5, 1, 2 };
	cout << isPopOrder(array1, array2) << endl;
	cout << isPopOrder(array1, array3) << endl;
	return 0;
}