#include<iostream>
#include<vector>
using namespace std;

/*
��Ŀ���һ�Ӳ�ҡ�����һ�������һ��Ŀ����target�������������
������ѡ������Ԫ���ۼ��ܵõ�target���������ÿ��Ԫ�ؿ�ѡ��������
*/

// �����ݹ飺ĳ��λ��i����ѡ0�ο�ʼ��һֱ����ѡn��ʹ�� n*arr[i] > target
// ��λ��i����ѡ��k��ʱ������Ԫ��ͬ�������˹��̣�Ŀ����target - k*arr[i]��
// i+1λ����ѡ0�ε�m�Σ�ֱ�� m*arr[i+1] > target - k*arr[i]��
int process1(vector<int>& arr, int index, int target);

int ChangeCoinsRecursively(vector<int>& arr, int target)
{
	if (arr.empty() || arr.size() == 0 || target < 0)
		return 0;
	int result = process1(arr, 0, target);
	return result;
}

int process1(vector<int>& arr, int index, int target)
{
	int result = 0;
	if (index == arr.size()) // ���һ��λ��Ԫ�ص���һ��λ�ã���ʱ��targetӦ��Ϊ0
	{
		result = target == 0 ? 1 : 0;
		return result;
	}
	
	int selectNum = 0; // ��ǰλ�õ�Ԫ�ر�ѡ��Ĵ���
	for (selectNum; selectNum * arr[index] <= target; ++selectNum)
		result += process1(arr, index + 1, target - selectNum * arr[index]);
	return result;
}

/*
��̬�滮���޺�Ч�����⣺�ɱ����Ϊ��index��0��arr.size(), target��0������Ŀ��target
*/
int ChangeCoinsDP(vector<int>& arr, int target)
{
	if (arr.empty() || arr.size() == 0 || target < 0)
		return 0;

	int indexLength = arr.size() + 1;
	int targetLength = target + 1;
	//������ά��̬�滮��
	int** dp = new int* [indexLength];
	for (int i = 0; i < indexLength; ++i)
	{
		dp[i] = new int[targetLength](); //��ʼ��Ϊ0
		memset(dp[i], 0, targetLength * sizeof(int));
	}

	//�������base case
	dp[arr.size()][0] = 1;

	//���������һ�����·�λ�ú������·����ÿ��arr[index]ѡ��һ����������ۼ�
	for (int i = arr.size() - 1; i >= 0; --i)
	{
		for (int j = 0; j < targetLength; ++j)
		{
			dp[i][j] = dp[i + 1][j];
			dp[i][j] += j - arr[i] >= 0 ? dp[i][j - arr[i]] : 0; //û��ȡ����(�벻����������)
		}
	}

	int result = dp[0][target]; // ����λ��

	//������̬�滮��
	for (int i = 0; i < indexLength; ++i)
	{
		delete[] dp[i];
		dp[i] = nullptr;
	}
	delete[] dp;
	dp = nullptr;
	return result;
}

int main()
{
	vector<int> arr{10, 20, 50, 100, 200};
	//cout << ChangeCoinsRecursively(arr, 10000) << endl; ��target���10000ʱ�����ݹ�û�������
	cout << ChangeCoinsDP(arr, 10000);
	return 0;
}