#include<iostream>
#include<vector>
using namespace std;

/*
����Ϊn+1������Ԫ�ش�С�� 1~n֮�䣻Ҫ���޸�ԭ����
���ǰѴ�l��n�����ִ��м������m��Ϊ�����֣�ǰ��һ��Ϊl��m,
����һ��Ϊ m+I ��n; ���l��m�����ֵ���Ŀ����m�� ��ô��һ��
������һ�������ظ����֣����ǿ��Լ����Ѱ����ظ����ֵ�����һ��Ϊ����
ֱ���ҵ� ���ظ������֡�
ʱ�临�Ӷ�O(nlogn), �ռ临�Ӷ�O(1)
*/

int countRange(vector<int>& arr, int left, int right);

int getDuplication(vector<int>& arr, int left, int right)
{
	//��Ч����:������
	if (arr.size() == 0)
		return -1;
	//��Ч����:Ԫ�ط�ΧԽ��
	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] < 1 || arr[i] > arr.size() - 1)
			return -1;
	}
	//���ֲ���
	while (left <= right)
	{
		int middle = (left + right) / 2;
		int count = countRange(arr, left, middle);
		if (left == right) // ��ȷ��λ��ĳ����
		{
			if (count > 1)
				return left; //����return middle, right
			else break; //�Ҳ����ظ�Ԫ��
		}

		if (count > (middle - left + 1)) //�ظ�Ԫ���ڴ�����
			right = middle;
		else
			left = middle + 1;
	}
	return -1;
}

//����������ĳ��������[left, right]�е�Ԫ������
int countRange(vector<int>& arr, int left, int right)
{
	int count = 0;
	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] >= left && arr[i] <= right)
			count++;
	}
	return count;
}

int main()
{
	vector<int> arr1{ 2, 3, 5, 4, 3, 2, 6, 7 };
	cout << getDuplication(arr1, 1, arr1.size() - 1) << endl;
	vector<int> arr2{ 1, 7, 3, 4, 5, 6, 8, 2, 8 };
	cout << getDuplication(arr2, 1, arr2.size() - 1) << endl;
	vector<int> arr3{ 1, 1 };
	cout << getDuplication(arr3, 1, arr3.size() - 1) << endl;
	vector<int> arr4{ 3, 2, 1, 3, 4, 5, 6, 7 };
	cout << getDuplication(arr4, 1, arr4.size() - 1) << endl;
	vector<int> arr5{ 1, 2, 6, 4, 5, 3 };
	cout << getDuplication(arr5, 1, arr5.size() - 1) << endl;
	return 0;
}
