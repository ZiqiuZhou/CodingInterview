#include<iostream>
#include<vector>
using namespace std;

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