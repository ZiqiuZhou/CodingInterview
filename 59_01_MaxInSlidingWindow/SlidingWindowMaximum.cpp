#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//滑动窗口从左到右滑过数组，固定窗宽，求每一时刻窗口中的最大值
//方法：双端队列最左侧一定存放实时最大值的索引，队列中只存放索引，
//按对应数组元素值降序放置。
//加入新元素：和队尾比较，队尾存放的索引对应元素小，就pop堆尾，直到队中
//的索引对应元素值更大或者队列已空
//删除队列中过期元素：当队头（一定是当前最大值的索引）索引值超出窗宽，弹出
vector<int> SlidingWindowMaxvector(vector<int>& array, int winLength)
{
	if (array.empty() || winLength > array.size())
		throw new exception("Invalid Input!");

	vector<int> maxInTime;
	deque<int> winDeque; // 双端队列
	for (int i = 0; i < array.size(); ++i)
	{
		//比新入队元素小的数依次pop,直到队列为空
		while (!winDeque.empty() && array[winDeque.back()] < array[i])
			winDeque.pop_back();
		winDeque.push_back(i); // 索引入队

		//删除过期节点:索引比窗左端还小
		if (winDeque.front() == i - winLength)
			winDeque.pop_front();
		maxInTime.push_back(array[winDeque.front()]);
	}
	return maxInTime;
}

int main()
{
	vector<int> arr{1, 4, 6, 2, 8, 5, 11, 3, 6, 15, 9, 2, 6, 12, 8, 5};
	vector<int> result = SlidingWindowMaxvector(arr, 5);
	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << " ";
}