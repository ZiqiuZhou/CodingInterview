#include<iostream>
#include<string>
using namespace std;

//��Ŀ�����ַ���ͷn���ַ���ת���ַ���ĩβ����abcdef��n=2, ���Ϊcdefab
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

	//��ת�������飬���ַ�Ϊ��λ
	int begin = 0;
	int end = str.size() - 1;
	Rotate(str, begin, end);

	//ǰlength���ȵ����ַ�����ʱ�����length����λ��,��boundIndex�����ֽ�
	int boundIndex = str.size() - length;
	//�ֱ��boundIndexǰ���������ַ�����ת
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