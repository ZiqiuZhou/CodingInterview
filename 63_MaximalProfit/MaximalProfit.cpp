#include<iostream>
#include<vector>
using namespace std;

/*题目：求数组中最大数对差值， 要求数对中前一个元素必须小于后一个元素
题意是找出数组中所有顺序数对并求最大差值，双层循环可以做到，但是复杂度高，
可以只一遍遍历，先将最小元素表示为首元素，最小数对差表示为前两个数之差，
在遍历过程中，不断看array[i - 1]是否是已知最小数，如果是，则将最小数替换
成array[i - 1]，这样才能保证数对差更大，求出此时差值，比较是否比已知
最大数对差要大。

本质上此题还可以找出最大逆序数对的最大差值，只要不断将array[i - 1]和之前找到
的最大元素比较，再求已知最大值和当前值之差的最大值

求顺序对和逆序对的最小值此方法不适用，但可以通过归并排序以O(nlogn)复杂度找到
所有顺序对或逆序对从而找出最小值
*/

//最大顺序数对差
int MaxmalSequencePair(vector<int>& array)
{
	if (array.empty() || array.size() < 2)
		throw new exception("Invalid Input.");

	//初始化最小值和最大数对差
	int min = array[0];
	int maxDiff = array[1] - array[0];
	for (int i = 1; i < array.size(); ++i)
	{
		if (array[i - 1] < min) // 更新最小值
			min = array[i - 1];
		int currentDiff = array[i] - min;
		if (currentDiff > maxDiff)
			maxDiff = currentDiff;
	}
	return maxDiff;
}

//最大逆序数对差
int MaximalReversePair(vector<int>& array)
{
	if (array.empty() || array.size() < 2)
		throw new exception("Invalid Input.");

	//初始化最大值和最大数对差
	int max = array[0];
	int maxDiff = array[0] - array[1];
	for (int i = 1; i < array.size(); ++i)
	{
		if (array[i - 1] > max) // 更新最小值
			max = array[i - 1];
		int currentDiff = max - array[i];
		if (currentDiff > maxDiff)
			maxDiff = currentDiff;
	}
	return maxDiff;
}

int main()
{
	vector<int> arr{2, 5, 1, 7 ,5, 9, 3, 7, 0, 8};
	cout << MaxmalSequencePair(arr) << " " << MaximalReversePair(arr);
	return 0;
}