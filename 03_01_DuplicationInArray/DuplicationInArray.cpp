#include<iostream>
#include<vector>
using namespace std;
/*
�������������Ź������顣 ��ͷ��β����ɨ����������е�ÿ�����֡�
��ɨ�赽�±�Ϊi������ʱ�����ȱȽ�������֣���m��ʾ���ǲ��ǵ���i��
����ǣ� �����ɨ����һ�����֣� ������ǣ� ���������͵�m�����ֽ��бȽϡ�
������͵�m��������ȣ� ���ҵ���һ���ظ������֣����������±�Ϊi��m��λ�ö������ˣ���
������͵�m�����ֲ���ȣ� �Ͱѵ�i���� �ֺ͵�m�����ֽ����� ��m�ŵ���������λ�á� 
���������ظ�����Ƚϡ� �����Ĺ��̣� ֱ�����Ƿ���һ���ظ������֡�

ʱ�临�Ӷ� O(n), �ռ临�Ӷ�O(1)
*/
//*********************************************************

// ����arr���㳤��Ϊn��Ԫ�ط�Χ����[0, n-1]
bool duplicate(vector<int>& arr)
{
	//��Ч����:k������
	if (arr.size() == 0)
	{
		cout << "��Ч����" << endl;
		return false;
	}
	//��Ч����:Ԫ�ط�Χ�в���[0, n-1]
	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] < 0 || arr[i] >= arr.size())
		{
			cout << "��Ч����" << endl;
			return false;
		}
	}

	for (int i = 0; i < arr.size(); ++i)
	{
		while (arr[i] != i)
		{
			int& m = arr[i];
			if (arr[i] == arr[m])
			{
				cout << arr[i] << endl;
				return true;
			}
			else
			{
				std::swap(arr[i], arr[m]);
			}	
		}
	}
	return false;
}

int main()
{
	vector<int> arr1{ 2, 1, 3, 1, 4 }; // �ظ�����������������С������
	cout << duplicate(arr1) << endl;
	vector<int> arr2{ 2, 4, 3, 1, 4 }; // �ظ�����������������������
	cout << duplicate(arr2) << endl;
	vector<int> arr3{ 2, 4, 2, 1, 4 }; // �����д��ڶ���ظ�������
	cout << duplicate(arr3) << endl;
	vector<int> arr4{ 2, 1, 3, 0, 4 }; // û���ظ�������
	cout << duplicate(arr4) << endl;
	vector<int> arr5{ 2, 1, 3, 0, 7 }; // ��Ч����
	cout << duplicate(arr5) << endl;
	return 0;
}