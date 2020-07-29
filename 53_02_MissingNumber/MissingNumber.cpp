#include<iostream>
#include<vector>
using namespace std;

//题目：排序数组长度为n-1，所有数都在0~n-1之间且只在数组中出现一次，
//数组长度即为n,说明有一个数没出现，找出这个没出现的数
int FindMissingNumber(vector<int>& array)
{
	if (array.empty()) throw new exception("Invalid Input!");

	int left = 0;
	int right = array.size() - 1;
	//二分查找
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (array[middle] == middle) // 未出现的数在该位置右边
			left++;
		else
		{
			if (middle == 0)// 来到最开始的位置
				return 0;
			else
			{
				if (array[middle - 1] == middle - 1)
					return middle;
				else
					right--;
			}
		}
	}
}

int main()
{
	vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8};
	cout << FindMissingNumber(arr);
	return 0;
}