#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

//题目：字符串中第一个不重复发字符
char FirstNotReaptingChar(string& str)
{
	unordered_map<char, int> hashMap;
	for (int i = 0; i < str.size(); ++i)
		hashMap.insert(std::make_pair(str[i], 0));

	for (int i = 0; i < str.size(); ++i)
	{
		hashMap[str[i]]++;
	}

	for (int i = 0; i < str.size(); ++i)
	{
		if (hashMap[str[i]] == 1)
			return str[i];
	}
}

//在数据流中找到第一个不重复发字符
void FirstNotRepeatingCharInStream(string& str)
{
	unordered_map<char, int> hashMap;
	unordered_map<char, int>::iterator iter;
	for (int i = 0; i < str.size(); ++i)
	{
		if (hashMap.find(str[i]) == hashMap.end()) //该字符没有出现过
			hashMap[str[i]] = 1;
		else
			hashMap[str[i]]++;
		for (auto& x : hashMap)
		{
			if (x.second == 1)
			{
				cout << x.first << " ";
				break;
			}
		}
	}
}

int main()
{
	string str = "sbdhdbnvttryodhfhaasjuoiczbrwuioq";
	unordered_map<char, int> a;
	cout << FirstNotReaptingChar(str) << endl;
	FirstNotRepeatingCharInStream(str);
	return 0;
}