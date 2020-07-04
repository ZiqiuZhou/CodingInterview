#include<iostream>
#include<vector>
using namespace std;

/*
递增排序旋转数组的最小值，采用二分查找
原排序数组：{1，2，3，4，5}
旋转数组：{3，4，5，1，2}
*/

template<typename Object>
Object MinInOrder(vector<Object>& array, int indexLeft, int indexRight)
{
	Object min = array[indexLeft];
	while (indexLeft <= indexRight)
	{
		if (array[indexLeft] <= min)
			min = array[indexLeft++];
	}
	return min;
}

template<typename Object>
Object findMin(vector<Object>& array)
{
	if (array.size() == 0)
		throw new exception("invalid input");
	int indexLeft = 0;
	int indexRight = array.size() - 1;
	if (array[indexLeft] <= array[indexRight]) //数组没有元素被旋转
		return array[indexLeft];
	while (indexRight - indexLeft > 1)
	{
		int indexMid = (indexLeft + indexRight) / 2;
		//如果leftPtr, indexMid和rightPtr指向数字相同，则不能二分，只能遍历
		if (array[indexLeft] == array[indexMid] && array[indexMid] == array[indexRight])
			return MinInOrder(array, indexLeft, indexRight); 

		if (array[indexMid] >= array[indexLeft])
			indexLeft = indexMid;
		else if (array[indexMid] <= array[indexLeft])
			indexRight = indexMid;
	}
	return array[indexRight];
}


int main()
{
	vector<int> arr1{3, 4, 5, 1, 2};
	cout << findMin(arr1) << endl;
	vector<int> arr2{ 1, 2, 3, 4, 5 };
	cout << findMin(arr2) << endl;
	return 0;
}