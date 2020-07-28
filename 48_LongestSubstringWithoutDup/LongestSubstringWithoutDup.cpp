#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*��Ŀ����������������ظ��ַ������ַ�������������Ԫ�أ�
�ݹ飺 ����λ�õ�������ص����ַ������ȶ���ǰһ��λ�þ�����
�����Ԫ�س�����ǰһ��Ԫ�ص�������������У���ô��Ԫ�ص�
���Ϊ������һ�γ�����ͬԪ�صĳ��ȣ������һ�γ�����ͬԪ�ص�
λ�ô���ǰһ��Ԫ�ص�����������еĳ��ȣ������г��ȼ�һ����Ӱ�죻
�����Ԫ�ش�δ��֮ǰ���ֹ��������г��ȼ�һ.
*/

int LongestSubStringWithoutDup(string& str, int* lastPosition, int len)
{
	string subString = str.substr(0, len);
	if (subString.size() == 1) //�����ַ�����һ��λ��
	{
		lastPosition[subString.back() - 'a'] = 0; 
		return 1;
	}

	int subStringLength = LongestSubStringWithoutDup(str, lastPosition, len - 1);
	int currentPos = len - 1;
	if (lastPosition[str[currentPos] - 'a'] == -1) //�����ǰԪ��û���ֹ�
	{
		lastPosition[str[currentPos] - 'a'] = currentPos; // ���¸���ĸ���ַ�����֮ǰ���ֵ�λ��
		return subStringLength + 1;
	}
	else //�����ǰԪ֮ǰ�Ѿ����ֹ�����Ҫ����֮ǰ���ֵ�λ�ã���¼��lastPosition�У�
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
	//�ж�ĳλ��Ԫ��֮ǰ�Ƿ���ֹ��Լ����ֵ�λ��
	//��һ��Ҫ������������һ�����鱣��λ����Ϣ
	int* lastPosition = new int[26]; //��̬���鲻�ӣ����Ͳ����г�ʼ�����ӣ�����λ�ó�ʼ��Ϊ0
	for (int i = 0; i < 26; ++i)
		lastPosition[i] = -1;
	cout << LongestSubStringWithoutDup(str, lastPosition, str.size());
	delete[] lastPosition;
	return 0;
}