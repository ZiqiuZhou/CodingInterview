#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;


/*子数组或字串问题可以从以下思路着手：遍历时以位置i为结尾的子数组或字串*/

/*
题目：求一个数组的最大异或子数组和（某个子数组所有元素异或后的结果）
采用暴力遍历的方式，对于任意位置i,都计算从位置0到i的所有子数组的异或和，
复杂度O(n**3),因为每个位置i,都要计算从一个起始位置start(0 <= start <= i)
到该位置的异或和
利用异或运算的性质： 如果E1 ^ E2 = E3，则E1 = E2 ^ E3
E3代表从0开始，以数组i位置结尾的子数组的异或和，E1代表从某个起始点start到i段的
异或和，可以通过计算计算0位置到start-1段的子数组异或和E2来算出，只要将E2存放在
一个数组中，可省去一层遍历
*/
int getMaxXOR(int vec[])
{
	int length = sizeof(vec) / sizeof(vec[0]);
	int max = INT_MIN;
	int* storeXOR = new int[length](); //用来存放0到start位置的异或和(E2)
	int eor = 0; //初始化从0到位置i的异或和(E1)
	for (int i = 0; i < length; ++i)
	{
		eor ^= vec[i]; // 从0到位置i的异或和(E1)
		max = std::max(max, eor);
		storeXOR[i] = eor;
		for (int start = 1; start <= i; ++start)
		{
			int currentEor = eor ^ storeXOR[i - 1]; // start到i的异或和 = 0到start-1的异或和异或0到i的异或和
			max = std::max(max, currentEor);
		}
	}
	delete[] storeXOR;
	return max;
}

int main()
{
	int arr[] = {1, 3, 7, 2, 4, 0, 3, 2, 6};
	cout << getMaxXOR(arr);
	return 0;
}