#include<iostream>
#include<vector>
using namespace std;

bool isEven(int num);
void print(vector<int>& arr);

//题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
// 奇数位于数组的前半部分，所有偶数位于数组的后半部分。
//可扩展为负数在前半部分非负数在后半部分
void arrayReorder(vector<int>& arr)
{
	if (arr.empty()) return;
	
	int leftPtr = 0;
	int rightPtr = arr.size() - 1;
	while (leftPtr < rightPtr)
	{
		if (isEven(arr[leftPtr])) //如果左指针指向偶数
		{
			std::swap(arr[leftPtr], arr[rightPtr--]);
		}
		else
		{
			leftPtr++;
		}
	}
	print(arr);
}

bool isEven(int num) //判断是否为偶数
{
	return num % 2 == 0;
}

bool isLagerThanZero(int num) // 判断是否大于零（也可扩展成任意条件）
{
	return num > 0;
}

void print(vector<int>& arr)
{
	for (auto& ele : arr)
		cout << ele << " ";
}

int main()
{
	vector<int> array{1, 3, 4, 8, 2, 6, 5, 9, 0, 1, 3};
	arrayReorder(array);
	return 0;
}