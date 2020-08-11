#include<iostream>
#include<vector>
using namespace std;

//��Ŀ�������г�ȡ�����Ԫ�أ�ÿ��Ԫ�س�ȡһ�Σ����ۼӺ͵���target�ĳ�ȡ�������

/*�ݹ�汾��ÿ��λ�ö�����ѡ���߲�ѡ*/
int isSumCore(vector<int>& vec, int index, int currentResult, int target);

int isSumIteratively(vector<int>& vec, int target)
{
	if (vec.empty()) return 0;
	return isSumCore(vec, 0, 0, target);
}

int isSumCore(vector<int>& vec, int index, int currentResult, int target)
{
	if (index == vec.size())
		return currentResult == target ? 1 : 0;

	int number = isSumCore(vec, index + 1, currentResult + vec[index], target) +
		isSumCore(vec, index + 1, currentResult, target);
	return number;
}

int sumOfElement(vector<int>& vec) //��������Ԫ�غ�
{
	int sum = 0;
	for (int i = 0; i < vec.size(); ++i)
		sum += vec[i];
	return sum;
}

/*��̬�滮:�ɱ����Ϊindex��0��vec.size()��currentResult��0������Ԫ�غ�*/
int isSumDP(vector<int>& vec, int target)
{
	int largestTarget = sumOfElement(vec);
	if (vec.empty() || target > largestTarget)
		return 0;

	//������άdp��
	int** dp = new int* [vec.size() + 1];
	for (int i = 0; i < vec.size() + 1; ++i)
	{
		dp[i] = new int[largestTarget + 1]();
		memset(dp[i], 0, (largestTarget + 1) * sizeof(int));
	}
	
	//��������
	dp[vec.size()][target] = 1;

	//������
	for (int i = vec.size() - 1; i >= 0; --i)
	{
		for (int j = 0; j <= largestTarget; ++j)
		{
			dp[i][j] = dp[i + 1][j];
			dp[i][j] += j + vec[i] <= largestTarget ? dp[i + 1][j + vec[i]] : 0;
		}
	}

	int result = dp[0][0];
	//������άdp��
	for (int i = 0; i < vec.size() + 1; ++i)
	{
		delete[] dp[i];
		dp[i] = nullptr;
	}
	delete[] dp;
	return result;
}

int main()
{
	vector<int> arr{1, 8, 3, 5, 2, 7, 4, 6, 3};
	cout << isSumIteratively(arr, 6) << endl;
	cout << isSumDP(arr, 6);
	return 0;
}