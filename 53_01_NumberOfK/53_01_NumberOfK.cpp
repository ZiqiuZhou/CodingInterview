#include<iostream>
#include<vector>
using namespace std;

//有序数组中查找某个数的在排序数组中的个数
int findRightBoundary(vector<int>& arr, int target, int indexOfTarget, int right);
int findLeftBoundary(vector<int>& arr, int target, int left, int indexOfTarget);

int NumberInSortedArray(vector<int>& arr, int target)
{
	if (arr.empty())
		return -1;

	//利用二分查找先定位到该目标数的位置
	int indexOfTarget = -1;
	int left = 0;
	int right = arr.size() - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (target == arr[middle])
		{
			indexOfTarget = middle;
			break;
		}
		else if (target > arr[middle])
			left = middle + 1;
		else
			right = middle - 1;
	}
	if (indexOfTarget == -1) // 数组中没找到目标数
		return -1;
	else // 数组中找到目标数, 定义此若干个相等的该目标数为“序列”
	{
		if (indexOfTarget - 1 < 0 || arr[indexOfTarget - 1] < target) //定位到的数位于此序列最左端
		{
			int rightBoundary = findRightBoundary(arr, target, indexOfTarget, arr.size() - 1);
			return rightBoundary - indexOfTarget + 1;
		}
		else if (indexOfTarget + 1 >= arr.size() || arr[indexOfTarget + 1] > target) //定位到的数位于此序列最右端
		{
			int leftBoundary = findLeftBoundary(arr, target, 0, indexOfTarget);
			return indexOfTarget - leftBoundary + 1;
		}
		else // 定位到的数位于此序列中间某个位置，左右元素都和该数相同
		{
			int rightBoundary = findRightBoundary(arr, target, indexOfTarget, arr.size() - 1);
			int leftBoundary = findLeftBoundary(arr, target, 0, indexOfTarget);
			return rightBoundary - leftBoundary + 1;
		}
	}
}

int findRightBoundary(vector<int>& arr, int target, int indexOfTarget, int right)
{
	if (arr[indexOfTarget] == target && indexOfTarget == arr.size() - 1)
		return arr.size() - 1;

	int middle = (indexOfTarget + right) / 2;
	if (arr[middle] == target)
	{
		if (arr[middle + 1] > target)
			return middle;
		else
			return findRightBoundary(arr, target, middle + 1, right);
	}
	else if(arr[middle] > target)
		return findRightBoundary(arr, target, indexOfTarget, middle - 1);
}

int findLeftBoundary(vector<int>& arr, int target, int left, int indexOfTarget)
{
	if (arr[indexOfTarget] == target && indexOfTarget == 0)
		return 0;

	int middle = (indexOfTarget + left) / 2;
	if (arr[middle] == target)
	{
		if (middle == 0)
			return 0;
		else if (arr[middle - 1] < target)
			return middle;
		else
			return findLeftBoundary(arr, target, left, middle - 1);
	}
	else if (arr[middle] < target)
		return findLeftBoundary(arr, target, middle + 1, indexOfTarget);
}

int main()
{
	vector<int> arr1{1, 3, 5, 5, 7, 9, 11, 20};
	vector<int> arr2{1, 2, 3, 3, 3, 3, 4, 5};
	vector<int> arr3{0,0,0,0,0,0,0,0,0,0};
	cout << NumberInSortedArray(arr3, 0);
}