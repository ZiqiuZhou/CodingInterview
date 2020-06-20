#include<iostream>
#include<vector>
using namespace std;
/*
现在让我们重排过个数组。 从头到尾依次扫描这个数组中的每个数字。
当扫描到下标为i的数字时，首先比较这个数字（用m表示）是不是等于i。
如果是， 则接着扫描下一个数字： 如果不是， 则再拿它和第m个数字进行比较。
如果它和第m个数字相等， 就找到了一个重复的数字（该数字在下标为i和m的位置都出现了）；
如果它和第m个数字不相等， 就把第i个数 字和第m个数字交换， 把m放到属于它的位置。 
接下来再重复这个比较、 交换的过程， 直到我们发现一个重复的数字。

时间复杂度 O(n), 空间复杂度O(1)
*/
//*********************************************************

// 数组arr满足长度为n且元素范围都在[0, n-1]
bool duplicate(vector<int>& arr)
{
	//无效输入:k空数组
	if (arr.size() == 0)
	{
		cout << "无效输入" << endl;
		return false;
	}
	//无效输入:元素范围有不在[0, n-1]
	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] < 0 || arr[i] >= arr.size())
		{
			cout << "无效输入" << endl;
			return false;
		}
	}

	for (int i = 0; i < arr.size(); ++i)
	{
		while (arr[i] != i)
		{
			int& m = arr[i];
			if (arr[i] == arr[m])
			{
				cout << arr[i] << endl;
				return true;
			}
			else
			{
				std::swap(arr[i], arr[m]);
			}	
		}
	}
	return false;
}

int main()
{
	vector<int> arr1{ 2, 1, 3, 1, 4 }; // 重复的数字是数组中最小的数字
	cout << duplicate(arr1) << endl;
	vector<int> arr2{ 2, 4, 3, 1, 4 }; // 重复的数字是数组中最大的数字
	cout << duplicate(arr2) << endl;
	vector<int> arr3{ 2, 4, 2, 1, 4 }; // 数组中存在多个重复的数字
	cout << duplicate(arr3) << endl;
	vector<int> arr4{ 2, 1, 3, 0, 4 }; // 没有重复的数字
	cout << duplicate(arr4) << endl;
	vector<int> arr5{ 2, 1, 3, 0, 7 }; // 无效输入
	cout << duplicate(arr5) << endl;
	return 0;
}