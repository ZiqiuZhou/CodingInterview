#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
题目：在某数组中找出所有满足条件的子数组数量：该子数组的最大值减最小值小于等于某阈值thershold， 要求O(n)
分析：暴力查找以任意元素为起始点的子数组需要O(n²),如果建立两个双端队列用于滑动窗口，不固定窗宽，则
可以O(n)时间找到所有子数组

分析: 1.对于某一子数组，如果该子树组满足条件，它的所有子数组都满足条件;如果不满足，再扩张的都不满足
      2. 窗宽不固定， 任意长度为N的窗宽内一共有N个子数组
	  3.要计算以任意元素为起始点的子数组，窗宽的最左边就是该元素
	  4.以该元素为起始点，窗右端不断向右扩张，直到不满足条件
*/
int AllLessNumSubArray(vector<int>& array, int threshold)
{
	if (array.empty())
		return 0;
	//存放滑窗最大最小值(存索引)
	deque<int> minDeque;
	deque<int> maxDeque;
	int start = 0; //窗口起始元素位置，从头开始
	int end = 0; //窗口结束元素位置

	int numOfSubArray = 0;
	for (start; start < array.size(); ++start)
	{
		for(end; end < array.size(); ++end)
		{
			//窗口内最大值更新策略：队列最左侧始终保持最大值
			while (!maxDeque.empty() && array[maxDeque.back()] <= array[end])
				maxDeque.pop_back();
			maxDeque.push_back(end);
			//窗口内最小值更新策略：队列最左侧始终保持最小值
			while (!minDeque.empty() && array[minDeque.back()] >= array[end])
				minDeque.pop_back();
			minDeque.push_back(end);

			//直到扩张到不满足阈值时，停止扩张
			if (array[maxDeque.front()] - array[minDeque.front()] > threshold)
				break;
		}
		//计算此时以start开头， end - 1 结尾的子数组的个数
		
		numOfSubArray += end - start;

		//更新过期节点
		if (maxDeque.front() == start) maxDeque.pop_front();
		if (minDeque.front() == start) minDeque.pop_front();
	}
	return numOfSubArray;
}

int main()
{
	vector<int> arr {3, -3, 6, 2, 8, 3, 4, -6, -1, 7, 4, -7, 5, 9};
	cout << AllLessNumSubArray(arr, 3);
	return 0;
}