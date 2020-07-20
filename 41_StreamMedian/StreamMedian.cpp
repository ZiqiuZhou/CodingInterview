#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<cstdlib>
using namespace std;

//���������е���λ��
template<typename Object>
Object findStreamMedian(priority_queue<Object>& maxHeap, priority_queue<Object, vector<Object>, greater<Object>>& minHeap, Object number);

template<typename Object>
void streamMedian(vector<Object>& stream)
{
	//����һ������Ѻ�һ��С����
	priority_queue<Object> maxHeap;
	priority_queue<Object, vector<Object>, greater<Object> > minHeap;
	for (int i = 0; i < stream.size(); ++i)
		cout << findStreamMedian<Object>(maxHeap, minHeap, stream[i]) << endl;
}

template<typename Object>
Object findStreamMedian(priority_queue<Object>& maxHeap, priority_queue<Object, vector<Object>, greater<Object>>& minHeap, Object number)
{
	if (maxHeap.empty() && minHeap.empty())
	{
		maxHeap.push(number);
		return maxHeap.top();
	}

	if (number > maxHeap.top()) //�����ǰ���ȴ���ѵĶѶ���
		minHeap.push(number);
	else
		maxHeap.push(number);

	//�������Ԫ����������1����Ԫ�ض�ĶѶ�����һ����
	//��֤��������Ԫ��ƽ��
	if (std::abs(double(maxHeap.size() - minHeap.size())) > 1) 
	{
		if (maxHeap.size() > minHeap.size())
		{
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		}
		else
		{
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
	}

	//Ѱ����λ��
	if (maxHeap.size() == minHeap.size())
		return (maxHeap.top() + minHeap.top()) / 2;
	else
	{
		if (maxHeap.size() > minHeap.size())
			return maxHeap.top();
		else
			return minHeap.top();
	}
}

int main()
{
	vector<double> stream = {3.4, 2.1, 8.6, 5.1, 2.0, 7.4, 0.5};
	streamMedian(stream);
	return 0;
}