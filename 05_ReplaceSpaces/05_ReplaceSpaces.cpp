#include<iostream>
#include<string>
using namespace std;

/*
���ַ����еĿո��滻�ɡ�%20��:ÿ������һ���ո�
�ַ����ܳ��Ⱦͼ�2

����׼������ָ��: P1��P2��P1ָ��ԭʼ�ַ�����ĩβ�� 
��P2 ָ���滻֮����ַ�����ĩβ����ǰ�ƶ�ָ��P1��
�������ָ����ַ����Ƶ�P2ָ ���λ�ã� 
ֱ��������һ���ո�Ϊֹ��
������һ���ո�֮��,��P1 ��ǰ�ƶ�l��,��P2 ֮ǰ
�����ַ���"%20"������"%20"�ĳ���Ϊ3, ͬʱҲҪ��P2
��ǰ�ƶ�3��
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