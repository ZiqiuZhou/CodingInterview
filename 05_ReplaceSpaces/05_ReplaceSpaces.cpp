#include<iostream>
#include<string>
using namespace std;

/*
将字符串中的空格替换成“%20”:每当遇到一个空格，
字符串总长度就加2

肯先准备两个指钊: P1和P2。P1指向原始字符串的末尾， 
而P2 指向替换之后的字符串的末尾，向前移动指针P1，
逐个把它指向的字符复制到P2指 向的位置， 
直到碰到第一个空格为止。
碰到第一个空格之后,把P1 向前移动l格,在P2 之前
插入字符串"%20"。由于"%20"的长度为3, 同时也要把P2
向前移动3格
*/
string replaceBlank(string& str)
{
	int originalLength = str.size();
	if (originalLength == 0)
		return "/0";

	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == ' ')
		{
			str.push_back('0');
			str.push_back('0');
		}
	}

	int newLength = str.size();
	int indexOfOrigin = originalLength - 1;
	int indexOfNew = newLength - 1;
	for (indexOfOrigin; indexOfOrigin >= 0; --indexOfOrigin)
	{
		if (str[indexOfOrigin] == ' ')
		{
			str[indexOfNew--] = '0';
			str[indexOfNew--] = '2';
			str[indexOfNew--] = '%';
		}
		else
		{
			str[indexOfNew--] = str[indexOfOrigin];
		}
	}
	return str;
}

int main()
{
	string str = "ss 00 32 33";
	cout << str << endl;
	string str1 = replaceBlank(str);
	cout << str1 << endl;
	return 0;
}