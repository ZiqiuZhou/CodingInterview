#include<iostream>
#include<vector>
using namespace std;

// ��Ŀ���������飬����Ԫ�������и����㣬���ۼӺ�Ϊtarget��������鳤��
int SumEqualToTarget(vector<int>& arr, int target)
{
	if (arr.empty())
		return 0;

	int longestSubArray = 0;
	//������ʱ�������Ѿ���������ۼӺ�(��0��iλ��)
	int* tmp = new int[arr.size()]();

	for (int i = 0; i < arr.size(); ++i)
	{
		tmp[i] = i > 0 ? tmp[i - 1] + arr[i] : arr[i];
		if (tmp[i] == target)
			longestSubArray = longestSubArray < (i + 1)? i + 1 : longestSubArray;

		for (int j = 1; j <= i; ++j)
		{
			if (tmp[i] - tmp[j - 1] == target)
				longestSubArray = longestSubArray < i - j + 1 ? i - j + 1 : longestSubArray;
		}
	}
	delete[] tmp;
	return longestSubArray;
}

int main()
{
	vector<int> arr{4, -2, 6, 1, 3, 7, -4, -1, 8, 3, -5, 6, -1, 4, 2, 8};
	cout << SumEqualToTarget(arr, 3);
	return 0;
}