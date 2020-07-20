#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<cstdlib>
using namespace std;

//求数据流中的中位数
template<typename Object>
Object findStreamMedian(priority_queue<Object>& maxHeap, priority_queue<Object, vector<Object>, greater<Object>>& minHeap, Object number);

template<typename Object>
void streamMedian(vector<Object>& stream)
{
	//建立一个大根堆和一个小根堆
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

	if (number > maxHeap.top()) //如果当前数比大根堆的堆顶大
		minHeap.push(number);
	else
		maxHeap.push(number);

	//如果两堆元素数量大于1，则将元素多的堆顶给另一个，
	//保证两个堆中元素平衡
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

	//寻找中位数
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