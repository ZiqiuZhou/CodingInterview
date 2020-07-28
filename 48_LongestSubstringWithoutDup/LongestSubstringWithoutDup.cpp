#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*题目：求数组中最长不含重复字符的子字符串（包括到本元素）
递归： 任意位置的最长不含重的子字符串长度都由前一个位置决定，
如果该元素出现在前一个元素的最长非重子序列中，那么该元素的
结果为它到上一次出现相同元素的长度；如果上一次出现相同元素的
位置大于前一个元素的最长非重子序列的长度，子序列长度加一，不影响；
如果该元素从未在之前出现过，子序列长度加一.
*/

int LongestSubStringWithoutDup(string& str, int* lastPosition, int len)
{
	string subString = str.substr(0, len);
	if (subString.size() == 1) //来到字符串第一个位置
	{
		lastPosition[subString.back() - 'a'] = 0; 
		return 1;
	}

	int subStringLength = LongestSubStringWithoutDup(str, lastPosition, len - 1);
	int currentPos = len - 1;
	if (lastPosition[str[currentPos] - 'a'] == -1) //如果当前元素没出现过
	{
		lastPosition[str[currentPos] - 'a'] = currentPos; // 更新该字母在字符串中之前出现的位置
		return subStringLength + 1;
	}
	else //如果当前元之前已经出现过，需要考察之前出现的位置（记录在lastPosition中）
	{
		int distance = currentPos - lastPosition[str[currentPos] - 'a'];
		if (distance > subStringLength)
			return subStringLength + 1;
		else
			return distance;
	}
}

int main()
{
	string str = "agshdfah";
	//判断某位置元素之前是否出现过以及出现的位置
	//不一定要遍历，可以用一个数组保存位置信息
	int* lastPosition = new int[26]; //动态数组不加（）就不进行初始化，加（）各位置初始化为0
	for (int i = 0; i < 26; ++i)
		lastPosition[i] = -1;
	cout << LongestSubStringWithoutDup(str, lastPosition, str.size());
	delete[] lastPosition;
	return 0;
}