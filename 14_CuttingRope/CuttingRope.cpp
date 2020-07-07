#include<iostream>
#include<algorithm>
using namespace std;

//递归
int maxCutRopeRecursionCore(int length);
int maxCutRopeRecursion(int length)
{
	// 当绳子长度小于等于3时是特殊情况
	if (length == 0)
		return 0;
	if (length == 1)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;
	else
	{
		int result = maxCutRopeRecursionCore(length);
		return result;
	}
}

int maxCutRopeRecursionCore(int length)
{
	if (length <= 3)
		return length;

	int maxResult = 0;
	for (int i = 1; i <= length / 2; ++i)
	{
		int result = maxCutRopeRecursionCore(i) * maxCutRopeRecursionCore(length - i);
		if (result > maxResult)
			maxResult = result;
	}
	return maxResult;
}

//动态规划
int cutRopeDP(int length)
{
	// 当绳子长度小于等于3时是特殊情况
	if (length == 0)
		return 0;
	if (length == 1)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	int* dpTable = new int[length + 1];
	//非依赖项
	dpTable[0] = 0;
	dpTable[1] = 1;
	dpTable[2] = 2;
	dpTable[3] = 3;
	//依赖项
	int max;
	for (int i = 4; i <= length; ++i)
	{
		max = 0;
		for (int j = 0; j <= length / 2; ++j)
		{
			int result = dpTable[j] * dpTable[i - j];
			if (result > max)
				max = result;
		}
		dpTable[i] = max;
	}
	max = dpTable[length];
	delete[] dpTable;
	return max;
}


int main()
{
	int len = 8;
	cout << maxCutRopeRecursion(len) << endl;
	cout << cutRopeDP(len);
	return 0;
}