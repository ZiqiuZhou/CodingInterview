#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
/*
��Ŀ����һ��������������ѡ��������ʹ������֮�͵��ڸ�������
*/
void TwoNumbersWithSum(vector<int>& array, int target)
{
	if (array.empty())
		throw new exception("Invalid input!");
	int leftPtr = 0;
	int rightPtr = array.size() - 1;
	while (leftPtr < rightPtr)
	{
		int sum = array[leftPtr] + array[rightPtr];
		if (sum > target)
			rightPtr--;
		else if (sum < target)
			leftPtr--;
		else
		{
			cout << array[leftPtr] << " " << array[rightPtr];
			break;
		}
	}
}

int main()
{
	vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9};
	TwoNumbersWithSum(arr, 6);
	return 0;
}

