#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> getNextArray(string& str);
// KMP���str2�Ƿ���str1���Ӵ������⣬����ǣ�����str2��str1�е��±�
// ���Ƿ���-1�� STL��string�������Ƶĺ���
int KMP(string& str1, string& str2) {
	if (str1.empty() || str2.empty() || str2.size() > str1.size())
		return -1;

	int i = 0;
	int j = 0;
	// next��������ã����str2��ÿ��λ��Ԫ�����ǰ׺����ĺ�׺ƥ�䳤��
	// ��aaaaab,����b,�ǰ׺�����׺ƥ�䳤����4(aaaa),ǰ׺���ܰ�����Ԫ��
	// ֮ǰ�����һ��Ԫ�أ� ��׺���������ַ����ĵ�һ��Ԫ��
	vector<int> next = getNextArray(str2);
	while (i < str1.size() && j < str2.size()) {
		if (str1[i] == str2[j]) {
			++i;
			++j;
		}
		else { // ��λ��ûƥ����
			if (next[j] == -1) // j������ͷλ�ã�˵��iλ�ú�str2�е�һ��λ�ö���ƥ��
				++i;
			else
				j = next[j];
		}
	}
	return j == str2.size() ? i - j : -1;
}

vector<int> getNextArray(string& str) {
	if (str.size() == 1)
		return { -1 };

	vector<int> next(str.size());
	next[0] = -1;
	next[1] = 0;
	int i = 2;
	int cn = 0; // cn����ǰ��ת����λ��(�ǰ׺����һ��λ��)
	while (i < next.size()) {
		if (str[i - 1] == str[cn])
			next[i++] = ++cn;
		else if (cn > 0)
			cn = next[cn];
		else // cn == 0
			next[i++] = 0;
	}
	return next;
}

int main() {
	string str1{"abcvfdvbkjdsbcsbcaalcso;dev"};
	string str2{"cdcdscwe"};
	cout << KMP(str1, str2);
	return 0;
}