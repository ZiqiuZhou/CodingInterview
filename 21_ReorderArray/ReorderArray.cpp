#include<iostream>
#include<vector>
using namespace std;

bool isEven(int num);
void print(vector<int>& arr);

//��Ŀ������һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ������
// ����λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�
//����չΪ������ǰ�벿�ַǸ����ں�벿��
void arrayReorder(vector<int>& arr)
{
	if (arr.empty()) return;
	
	int leftPtr = 0;
	int rightPtr = arr.size() - 1;
	while (leftPtr < rightPtr)
	{
		if (isEven(arr[leftPtr])) //�����ָ��ָ��ż��
		{
			std::swap(arr[leftPtr], arr[rightPtr--]);
		}
		else
		{
			leftPtr++;
		}
	}
	print(arr);
}

bool isEven(int num) //�ж��Ƿ�Ϊż��
{
	return num % 2 == 0;
}

bool isLagerThanZero(int num) // �ж��Ƿ�����㣨Ҳ����չ������������
{
	return num > 0;
}

void print(vector<int>& arr)
{
	for (auto& ele : arr)
		cout << ele << " ";
}

int main()
{
	vector<int> array{1, 3, 4, 8, 2, 6, 5, 9, 0, 1, 3};
	arrayReorder(array);
	return 0;
}