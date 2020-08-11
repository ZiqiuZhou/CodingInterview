#include<iostream>
#include<vector>
using namespace std;

//题目：数组中抽取任意个元素（每个元素抽取一次），累加和等于target的抽取组合数量

/*递归版本：每个位置都可以选或者不选*/
int isSumCore(vector<int>& vec, int index, int currentResult, int target);

int isSumIteratively(vector<int>& vec, int target)
{
	if (vec.empty()) return 0;
	return isSumCore(vec, 0, 0, target);
}

int isSumCore(vector<int>& vec, int index, int currentResult, int target)
{
	if (index == vec.size())
		return currentResult == target ? 1 : 0;

	int number = isSumCore(vec, index + 1, currentResult + vec[index], target) +
		isSumCore(vec, index + 1, currentResult, target);
	return number;
}

int sumOfElement(vector<int>& vec) //计算所有元素和
{
	int sum = 0;
	for (int i = 0; i < vec.size(); ++i)
		sum += vec[i];
	return sum;
}

/*动态规划:可变参数为index由0到vec.size()和currentResult由0到所有元素和*/
int isSumDP(vector<int>& vec, int target)
{
	int largestTarget = sumOfElement(vec);
	if (vec.empty() || target > largestTarget)
		return 0;

	//建立二维dp表
	int** dp = new int* [vec.size() + 1];
	for (int i = 0; i < vec.size() + 1; ++i)
	{
		dp[i] = new int[largestTarget + 1]();
		memset(dp[i], 0, (largestTarget + 1) * sizeof(int));
	}
	
	//非依赖项
	dp[vec.size()][target] = 1;

	//依赖项
	for (int i = vec.size() - 1; i >= 0; --i)
	{
		for (int j = 0; j <= largestTarget; ++j)
		{
			dp[i][j] = dp[i + 1][j];
			dp[i][j] += j + vec[i] <= largestTarget ? dp[i + 1][j + vec[i]] : 0;
		}
	}

	int result = dp[0][0];
	//析构二维dp表
	for (int i = 0; i < vec.size() + 1; ++i)
	{
		delete[] dp[i];
		dp[i] = nullptr;
	}
	delete[] dp;
	return result;
}

int main()
{
	vector<int> arr{1, 8, 3, 5, 2, 7, 4, 6, 3};
	cout << isSumIteratively(arr, 6) << endl;
	cout << isSumDP(arr, 6);
	return 0;
}