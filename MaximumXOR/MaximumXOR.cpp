#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;


/*��������ִ�������Դ�����˼·���֣�����ʱ��λ��iΪ��β����������ִ�*/

/*
��Ŀ����һ�������������������ͣ�ĳ������������Ԫ������Ľ����
���ñ��������ķ�ʽ����������λ��i,�������λ��0��i����������������ͣ�
���Ӷ�O(n**3),��Ϊÿ��λ��i,��Ҫ�����һ����ʼλ��start(0 <= start <= i)
����λ�õ�����
���������������ʣ� ���E1 ^ E2 = E3����E1 = E2 ^ E3
E3�����0��ʼ��������iλ�ý�β������������ͣ�E1�����ĳ����ʼ��start��i�ε�
���ͣ�����ͨ���������0λ�õ�start-1�ε�����������E2�������ֻҪ��E2�����
һ�������У���ʡȥһ�����
*/
int getMaxXOR(int vec[])
{
	int length = sizeof(vec) / sizeof(vec[0]);
	int max = INT_MIN;
	int* storeXOR = new int[length](); //�������0��startλ�õ�����(E2)
	int eor = 0; //��ʼ����0��λ��i������(E1)
	for (int i = 0; i < length; ++i)
	{
		eor ^= vec[i]; // ��0��λ��i������(E1)
		max = std::max(max, eor);
		storeXOR[i] = eor;
		for (int start = 1; start <= i; ++start)
		{
			int currentEor = eor ^ storeXOR[i - 1]; // start��i������ = 0��start-1���������0��i������
			max = std::max(max, currentEor);
		}
	}
	delete[] storeXOR;
	return max;
}

int main()
{
	int arr[] = {1, 3, 7, 2, 4, 0, 3, 2, 6};
	cout << getMaxXOR(arr);
	return 0;
}