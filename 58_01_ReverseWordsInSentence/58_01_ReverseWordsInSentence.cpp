#include<iostream>
#include<string>
using namespace std;

//反转字符串：先将字符串整体以字符为单位翻转，再将每个字符段按照字符为单位翻转
void Reverse(string& str, int beginIdx, int endIdx)
{
	while (beginIdx <= endIdx)
	{
		char tmp = move(str[beginIdx]);
		str[beginIdx] = move(str[endIdx]);
		str[endIdx] = move(tmp);
		beginIdx++;
		endIdx--;
	}
}

void ReverseWordsInSequence(string& str)
{
	if (str.empty())
	{
		cout << "Invalid Input.";
		return;
	}

	int beginIdx = 0;
	int endIdx = str.size() - 1;
	// 翻转整个句子
	Reverse(str, beginIdx, endIdx);

	//翻转每个单词
	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == ' ')
		{
			Reverse(str, beginIdx, i - 1);
			beginIdx = i + 1;
		}
		if (i == str.size() - 1)
			Reverse(str, beginIdx, i);
	}
}

int main()
{
	string str = "I am a student.";
	ReverseWordsInSequence(str);
	cout << str;
	return 0;
}