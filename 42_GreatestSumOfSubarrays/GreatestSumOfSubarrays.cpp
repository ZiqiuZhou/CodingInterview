#include<iostream>
#include<utility>
#include<vector>
using namespace std;

//��Ŀ���������������е�����, �����е�Ԫ�������и�
int GreatestSumOfSubarray(vector<int>& array)
{
	if (array.empty())
		return 0;

	int currentSum = 0;
	int maxSum = INT_MIN;
	for (int i = 0; i < array.size(); ++i)
	{
		currentSum += array[i];
		if (currentSum > maxSum)
			maxSum = currentSum;
		if (currentSum < 0)
			currentSum = array[i];
	}
	return maxSum;
}

int main()
{
	vector<int> array{2, 7, -4, 6, 3, -9, -3, 1, -6, 8};
	cout << GreatestSumOfSubarray(array);
	return 0;
}