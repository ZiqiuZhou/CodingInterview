#include<iostream>
#include<string>
using namespace std;

//题目：打印数组的全排列
void permutationProcess(string str, int index)
{
	if (index == str.size() - 1)
	{
		cout << str << endl;
		return ;
	}
	for (int j = index; j < str.size(); ++j)
	{
		std::swap(str[index], str[j]);
		permutationProcess(str, index + 1);
	}
}

void StringPermutation(string& str)
{
	if (str.size() == 0)
		return;
	int index = 0;
	permutationProcess(str, index);
}

//求数组所有子序列，包括空集
void StringSubsetProcess(string& str, string res, int index)
{
	if (index == str.size())
	{
		cout << res << endl;
		return;
	}
		
	StringSubsetProcess(str, res, index + 1);
	StringSubsetProcess(str, res + str[index], index + 1);
}

void StringSubset(string& str)
{
	if (str.size() == 0)
		return;
	string res = ""; // 结果数组，从空集开始
	StringSubsetProcess(str, res, 0);
}

int main()
{
	string str = "abc";
	StringPermutation(str);
	StringSubset(str);
	return 0;
}