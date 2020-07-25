#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//题目: 找出数组中第k小的数

//方法1：不借助堆结构，先将头k个数存入数组并排序，再遍历后面的数去判断
//时间复杂度：O(nk)
int KLeastNumbers1(vector<int>& array, int k)
{
	if (array.size() == 0 || k == 0 || k > array.size()) 
		throw new exception("Invalid Input!");

	vector<int> containKNumbers{ array.begin(), array.begin() + k };

	std::sort(containKNumbers.begin(), containKNumbers.end()); // 默认递增
	if (k == array.size())
		return containKNumbers[k - 1];

	for (int i = k; i < array.size(); ++i)
	{
		if (k == 1) //只找最小的数
		{
			if (containKNumbers[0] > array[i])
				containKNumbers[0] = array[i];
		}
		else if(containKNumbers[k - 1] > array[i])
		{
			if(containKNumbers[k - 2] <= array[i])
				containKNumbers[k - 1] = array[i];
			else
			{
				int j = k - 2;
				while (j >= 0 && containKNumbers[j] > array[i])
				{
					containKNumbers[j + 1] = containKNumbers[j];
					--j;
				}
				containKNumbers[j + 1] = array[i];
			}
		}
	}
	return containKNumbers[k - 1];
}

//方法2：借助堆结构，先将所有元素插入最小堆， 再删除k - 1次
//时间复杂度：O(n)
int KLeastNumbersWithHeap1(vector<int>& array, int k)
{
	if (array.size() == 0 || k == 0 || k > array.size())
		throw new exception("Invalid Input!");
	priority_queue<int, vector<int>, greater<int> > minHeap; // 最小堆
	for (int i = 0; i < array.size(); ++i)
		minHeap.push(array[i]);
	while (k > 1)
	{
		minHeap.pop();
		--k;
	}
	return minHeap.top();
}


//方法2：借助堆结构，先将前k个元素插入最大堆， 遍历剩余元素去比较
//时间复杂度：O(n)
int KLeastNumbersWithHeap2(vector<int>& array, int k)
{
	if (array.size() == 0 || k == 0 || k > array.size())
		throw new exception("Invalid Input!");
	priority_queue<int> maxHeap; // 最大堆

	for (int i = 0; i < k; ++i)
		maxHeap.push(array[i]);

	if (maxHeap.size() == array.size()) // 如果k是数组长度
		return maxHeap.top();

	for (int i = k; i < array.size(); ++i)
	{
		if (array[i] < maxHeap.top())
		{
			maxHeap.pop();
			maxHeap.push(array[i]);
		}
	}
	return maxHeap.top();
}

int main()
{
	vector<int> vec{4, 5, 1, 6, 2, 7, 3};
	int result = KLeastNumbers1(vec, 4);
	cout << result << endl;
	int result2 = KLeastNumbersWithHeap1(vec, 4);
	cout << result2 << endl;
	cout << KLeastNumbersWithHeap2(vec, 4);
	return 0;
}