#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// �ҳ������г��ִ�������һ�����
void MoreThanHalfNumber(vector<int>& arr)
{
	//�������飬��������ÿ��Ԫ�غ�����ִ�����hash��O(n)
	unordered_map<int, int> hashMap;
	for (int i = 0; i < arr.size(); ++i)
	{
		if (hashMap.find(arr[i]) == hashMap.end())
			hashMap[arr[i]] = 1;
		else
			hashMap[arr[i]]++;
	}

	//O(n)������ϣ���ҵ�value > length / 2 ��<key, value> pair
	int halfLength = arr.size() / 2;
	for (auto& pair : hashMap)
	{
		if (pair.second >= halfLength)
			cout << pair.first << endl;
	}
}

int main()
{
	vector<int> arr{1, 2, 1, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1};
	MoreThanHalfNumber(arr);
}