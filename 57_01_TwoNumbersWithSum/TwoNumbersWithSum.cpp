#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
/*
题目：在一个递增数组中挑选两个数，使得两数之和等于给定的数
*/
tuple<int, int> TwoNumbersWithSum(vector<int>& array, int target)
{
	if (array.empty())
		throw new exception("Invalid input!");
	int leftPtr = 0;
	int rightPtr = array.size() - 1;
	while (leftPtr < rightPtr)
	{
		int sum = array[leftPtr] + array[rightPtr];
		if (sum == target)
		{
			//cout << array[leftPtr] << " " << array[rightPtr];
			return std::make_tuple(array[leftPtr], array[rightPtr]);
		}
		else if (sum > target)
			rightPtr--;
		else
			leftPtr++;
	}
}

int main()
{
	vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9};
	tuple<int, int> a;
	a = TwoNumbersWithSum(arr, 6);
	cout << std::get<0>(a) << " "<< std::get<1>(a) ;
	return 0;
}

