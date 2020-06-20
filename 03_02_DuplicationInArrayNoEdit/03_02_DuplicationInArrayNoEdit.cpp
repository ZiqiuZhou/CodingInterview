#include<iostream>
#include<vector>
using namespace std;

/*
长度为n+1的数组元素大小在 1~n之间；要求不修改原数组
我们把从l～n的数字从中间的数字m分为两部分，前面一半为l～m,
后面一半为 m+I ～n; 如果l～m的数字的数目超过m， 那么这一半
的区间一定包含重复数字；我们可以继续把包含重复数字的区间一分为二，
直到找到 个重复的数字。
时间复杂度O(nlogn), 空间复杂度O(1)
*/

int countRange(vector<int>& arr, int left, int right);

int getDuplication(vector<int>& arr, int left, int right)
{
	//无效输入:空数组
	if (arr.size() == 0)
		return -1;
	//无效输入:元素范围越界
	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] < 1 || arr[i] > arr.size() - 1)
			return -1;
	}
	//二分查找
	while (left <= right)
	{
		int middle = (left + right) / 2;
		int count = countRange(arr, left, middle);
		if (left == right) // 精确定位到某个数
		{
			if (count > 1)
				return left; //或者return middle, right
			else break; //找不到重复元素
		}

		if (count > (middle - left + 1)) //重复元素在此区间
			right = middle;
		else
			left = middle + 1;
	}
	return -1;
}

//计算数组在某数字区间[left, right]中的元素数量
int countRange(vector<int>& arr, int left, int right)
{
	int count = 0;
	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] >= left && arr[i] <= right)
			count++;
	}
	return count;
}

int main()
{
	vector<int> arr1{ 2, 3, 5, 4, 3, 2, 6, 7 };
	cout << getDuplication(arr1, 1, arr1.size() - 1) << endl;
	vector<int> arr2{ 1, 7, 3, 4, 5, 6, 8, 2, 8 };
	cout << getDuplication(arr2, 1, arr2.size() - 1) << endl;
	vector<int> arr3{ 1, 1 };
	cout << getDuplication(arr3, 1, arr3.size() - 1) << endl;
	vector<int> arr4{ 3, 2, 1, 3, 4, 5, 6, 7 };
	cout << getDuplication(arr4, 1, arr4.size() - 1) << endl;
	vector<int> arr5{ 1, 2, 6, 4, 5, 3 };
	cout << getDuplication(arr5, 1, arr5.size() - 1) << endl;
	return 0;
}
