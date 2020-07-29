#include<iostream>
#include<vector>
using namespace std;

//��Ŀ���������鳤��Ϊn-1������������0~n-1֮����ֻ�������г���һ�Σ�
//���鳤�ȼ�Ϊn,˵����һ����û���֣��ҳ����û���ֵ���
int FindMissingNumber(vector<int>& array)
{
	if (array.empty()) throw new exception("Invalid Input!");

	int left = 0;
	int right = array.size() - 1;
	//���ֲ���
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (array[middle] == middle) // δ���ֵ����ڸ�λ���ұ�
			left++;
		else
		{
			if (middle == 0)// �����ʼ��λ��
				return 0;
			else
			{
				if (array[middle - 1] == middle - 1)
					return middle;
				else
					right--;
			}
		}
	}
}

int main()
{
	vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8};
	cout << FindMissingNumber(arr);
	return 0;
}