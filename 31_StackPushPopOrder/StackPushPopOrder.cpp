#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/*
 ���������������У� ��һ�����б�ʾջ��ѹ�����У��жϵڶ���ջ
�Ƿ���Գ�Ϊ���ܵĳ�ջ���У���һ��ȫ��ѹջ��ų�ջ��
˼·������һ������ջ����ѹ�����У��ӳ�ջ�����������жϣ���ǰԪ���ǲ���
ջ�д˿̵�ջ�����ǵĻ�Ԫ�س�ջ��ָ��������ջ������һ��λ�ã����ǵĻ�����
ѹջ�����л�δ��ջԪ�������ѹջ��ֱ��ѹ���Ԫ���Ǹó�ջ�����е�ǰԪ�أ�
���ѹջ����ȫ����ջ��Ȼû�ҵ��� ���ջ���в���ȷ��
*/
bool findElement(vector<int>& pushOrder, vector<int>& popOrder);

bool isPopOrder(vector<int>& pushOrder, vector<int>& popOrder)
{
	if (pushOrder.size() != popOrder.size())
		return false;
	if (!findElement(pushOrder, popOrder)) //����Ч����
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
			if (iter1 == pushOrder.end() && *iter2 != help.top()) //���������pushOrder��Ȼû�ҵ�
				return false;
		}
		help.pop();
		++iter2;
	}
	return true;
}

//�ж�ѹջ�ͳ�ջ������Ԫ��ʱ���ж�Ӧ�����ж����������Ƿ���Ч
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