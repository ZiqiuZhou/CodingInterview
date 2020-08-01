#include<iostream>
#include<string>
using namespace std;

//题目：把字符串头n个字符旋转到字符串末尾，如abcdef和n=2, 结果为cdefab
void Rotate(string& str, int beginIdx, int endIdx)
{
	while (beginIdx <= endIdx)
	{
		std::swap(str[beginIdx], str[endIdx]);
		beginIdx++;
		endIdx--;
	}
}

void LeftRotateString(string& str, int length)
{
	if (str.empty() || length > str.size())
		throw new exception("Invalid Input!");

	//翻转整个数组，以字符为单位
	int begin = 0;
	int end = str.size() - 1;
	Rotate(str, begin, end);

	//前length长度的子字符串此时在最后length长度位置,以boundIndex索引分界
	int boundIndex = str.size() - length;
	//分别对boundIndex前后两个子字符串翻转
	if (length == str.size())
	{
		Rotate(str, begin, end);
		return ;
	}
	else
	{
		Rotate(str, 0, boundIndex - 1);
		Rotate(str, boundIndex, str.size() - 1);
		return;
	}
}

int main()
{
	string str = "abcdefg";
	LeftRotateString(str, 3);
	cout << str;
	return 0;
}