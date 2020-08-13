#include<iostream>
#include<vector>
using namespace std;

//题目：给定数组所有元素都是正数，求其累加和为给定target的最长子数组,返回其长度
int SumOfArray(vector<int>& arr, int target)
{
	if (arr.empty() || target <= 0)
		return 0;

	int lengthOfLongestSubArray = 0;
	int currentSum = 0;
	int ptr1 = 0;
	int ptr2 = 0;
	while (ptr1 < arr.size() && ptr2 < arr.size())
	{
		if (currentSum < target)
			currentSum += arr[ptr1++]; //当前子数组和小于target，ptr1右移
		else if (currentSum > target)
			currentSum -= arr[ptr2++]; //当前子数组大于target，ptr2左移
		else // 当前子数组等于target
		{
			lengthOfLongestSubArray = ptr1 - ptr2 > lengthOfLongestSubArray? ptr1 - ptr2: lengthOfLongestSubArray; //统计子数组长度
			currentSum -= arr[ptr2++];
		}
	}
	//当ptr1越界时累加和刚好为target
	if(currentSum == target)
		lengthOfLongestSubArray = arr.size() - ptr2 > lengthOfLongestSubArray ? arr.size() - ptr2 : lengthOfLongestSubArray;
	return lengthOfLongestSubArray;
}

int main()
{
	vector<int> arr{8, 1, 4, 3, 2, 6, 5, 7, 4, 6, 2, 3, 1, 4, 6, 4, 5, 2, 1, 4 };
	cout << SumOfArray(arr, 8);
	return 0;
}
