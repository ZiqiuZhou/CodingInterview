#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//��Ŀ������ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ����СԪ�ص�min
// �������ڸ�ջ�У�����min��push��pop��ʱ�临�Ӷȶ���O(1)��

template<typename Object>
class MinStack
{
private:
	stack<Object> normalStack; //װ������ջֵ
	stack<Object> minStack; //װ��Сֵ

public:
	MinStack() {}

	void pop()
	{
		if (normalStack.empty())
			throw new exception("Invalid operation.");
		normalStack.pop();
		minStack.pop();
	}

	void push(Object num)
	{
		if (normalStack.empty())
		{
			normalStack.push(num);
			minStack.push(num);
		}
		else
		{
			if (num < minStack.top())
			{
				normalStack.push(num);
				minStack.push(num);
			}
			else
				normalStack.push(num);
		}
	}

	Object min()
	{
		if (normalStack.empty())
			throw new exception("Invalid operation.");
		else
		{
			Object popedNum = minStack.top();
			return popedNum;
		}
	}
};

int main()
{
	vector<int> arr = {3, 0, 4, 2, 6, 1, 7, 2, 5, 4, 1};
	MinStack<int> minStack1;
	for (int i = 0; i < arr.size(); ++i)
	{
		minStack1.push(arr[i]);
		cout << minStack1.min() << " ";
		minStack1.pop();
	}
	
	return 0;
}