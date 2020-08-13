#include<iostream>
#include<vector>
using namespace std;

//��Ŀ��������������Ԫ�ض��������������ۼӺ�Ϊ����target���������,�����䳤��
int SumOfArray(vector<int>& arr, int target)
{
	if (arr.empty() || target <= 0)
		return 0;

	int lengthOfLongestSubArray = 0;
	int currentSum = 0;
	int ptr1 = 0;
	int ptr2 = 0;
	while (ptr1 < arr.size() && ptr2 < arr.size())
	{
		if (currentSum < target)
			currentSum += arr[ptr1++]; //��ǰ�������С��target��ptr1����
		else if (currentSum > target)
			currentSum -= arr[ptr2++]; //��ǰ���������target��ptr2����
		else // ��ǰ���������target
		{
			lengthOfLongestSubArray = ptr1 - ptr2 > lengthOfLongestSubArray? ptr1 - ptr2: lengthOfLongestSubArray; //ͳ�������鳤��
			currentSum -= arr[ptr2++];
		}
	}
	//��ptr1Խ��ʱ�ۼӺ͸պ�Ϊtarget
	if(currentSum == target)
		lengthOfLongestSubArray = arr.size() - ptr2 > lengthOfLongestSubArray ? arr.size() - ptr2 : lengthOfLongestSubArray;
	return lengthOfLongestSubArray;
}

int main()
{
	vector<int> arr{8, 1, 4, 3, 2, 6, 5, 7, 4, 6, 2, 3, 1, 4, 6, 4, 5, 2, 1, 4 };
	cout << SumOfArray(arr, 8);
	return 0;
}
