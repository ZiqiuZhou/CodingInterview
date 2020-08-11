#include<iostream>
#include<vector>
using namespace std;

/*
题目：兑换硬币。给定一个数组和一个目标数target，求出在数组中
任意挑选任意多个元素累加能得到target的组合数。每个元素可选择任意多次
*/

// 暴力递归：某个位置i从挑选0次开始，一直到挑选n次使得 n*arr[i] > target
// 当位置i处挑选了k次时，后面元素同样持续此过程（目标变成target - k*arr[i]，
// i+1位置挑选0次到m次，直到 m*arr[i+1] > target - k*arr[i]）
int process1(vector<int>& arr, int index, int target);

int ChangeCoinsRecursively(vector<int>& arr, int target)
{
	if (arr.empty() || arr.size() == 0 || target < 0)
		return 0;
	int result = process1(arr, 0, target);
	return result;
}

int process1(vector<int>& arr, int index, int target)
{
	int result = 0;
	if (index == arr.size()) // 最后一个位置元素的下一个位置，此时的target应当为0
	{
		result = target == 0 ? 1 : 0;
		return result;
	}
	
	int selectNum = 0; // 当前位置的元素被选择的次数
	for (selectNum; selectNum * arr[index] <= target; ++selectNum)
		result += process1(arr, index + 1, target - selectNum * arr[index]);
	return result;
}

/*
动态规划，无后效性问题：可变参数为：index从0到arr.size(), target从0到最终目标target
*/
int ChangeCoinsDP(vector<int>& arr, int target)
{
	if (arr.empty() || arr.size() == 0 || target < 0)
		return 0;

	int indexLength = arr.size() + 1;
	int targetLength = target + 1;
	//建立二维动态规划表
	int** dp = new int* [indexLength];
	for (int i = 0; i < indexLength; ++i)
	{
		dp[i] = new int[targetLength](); //初始化为0
		memset(dp[i], 0, targetLength * sizeof(int));
	}

	//非依赖项：base case
	dp[arr.size()][0] = 1;

	//依赖项：由下一行正下方位置和其正下方左边每隔arr[index]选择一个，结果的累加
	for (int i = arr.size() - 1; i >= 0; --i)
	{
		for (int j = 0; j < targetLength; ++j)
		{
			dp[i][j] = dp[i + 1][j];
			dp[i][j] += j - arr[i] >= 0 ? dp[i][j - arr[i]] : 0; //没采取遍历(想不起来看左神)
		}
	}

	int result = dp[0][target]; // 最终位置

	//析构动态规划表
	for (int i = 0; i < indexLength; ++i)
	{
		delete[] dp[i];
		dp[i] = nullptr;
	}
	delete[] dp;
	dp = nullptr;
	return result;
}

int main()
{
	vector<int> arr{10, 20, 50, 100, 200};
	//cout << ChangeCoinsRecursively(arr, 10000) << endl; 当target变成10000时暴力递归没等来结果
	cout << ChangeCoinsDP(arr, 10000);
	return 0;
}