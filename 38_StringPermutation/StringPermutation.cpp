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

int main()
{
	string str = "abcdef";
	StringPermutation(str);
	return 0;
}