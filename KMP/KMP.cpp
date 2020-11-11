#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> getNextArray(string& str);
// KMP解决str2是否是str1的子串的问题，如果是，返回str2在str1中的下标
// 不是返回-1， STL中string类有类似的函数
int KMP(string& str1, string& str2) {
	if (str1.empty() || str2.empty() || str2.size() > str1.size())
		return -1;

	int i = 0;
	int j = 0;
	// next数组的作用：求出str2中每个位置元素最长的前缀与最长的后缀匹配长度
	// 如aaaaab,对于b,最长前缀和最长后缀匹配长度是4(aaaa),前缀不能包含该元素
	// 之前的最后一个元素， 后缀不能来到字符串的第一个元素
	vector<int> next = getNextArray(str2);
	while (i < str1.size() && j < str2.size()) {
		if (str1[i] == str2[j]) {
			++i;
			++j;
		}
		else { // 该位置没匹配上
			if (next[j] == -1) // j来到开头位置，说明i位置和str2中第一个位置都不匹配
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
	int cn = 0; // cn是向前跳转到的位置(最长前缀的下一个位置)
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