#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// 找出数组中出现次数超过一半的数
void MoreThanHalfNumber(vector<int>& arr)
{
	//遍历数组，建立关于每个元素和其出现次数的hash表：O(n)
	unordered_map<int, int> hashMap;
	for (int i = 0; i < arr.size(); ++i)
	{
		if (hashMap.find(arr[i]) == hashMap.end())
			hashMap[arr[i]] = 1;
		else
			hashMap[arr[i]]++;
	}

	//O(n)遍历哈希表，找到value > length / 2 的<key, value> pair
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