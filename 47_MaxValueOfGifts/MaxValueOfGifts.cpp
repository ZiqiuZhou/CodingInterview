#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*矩阵最大路径和*/
/*方法一：暴力递归*/
int sumOfMaxPath_Iterate(vector<vector<int> >& matrix, int row, int col)
{
	if (row == matrix.size() - 1 && col == matrix[0].size() - 1)
		return matrix[row][col];
	if (row == matrix.size() - 1) //来到最后一行
		return matrix[row][col] + sumOfMaxPath_Iterate(matrix, row, col + 1);
	if(col == matrix[0].size() - 1) //来到最后一列
		return matrix[row][col] + sumOfMaxPath_Iterate(matrix, row + 1, col);

	int rightSum = sumOfMaxPath_Iterate(matrix, row, col + 1);
	int downSum = sumOfMaxPath_Iterate(matrix, row + 1, col);
	return max(rightSum, downSum) + matrix[row][col];
}

/*方法二：动态规划*/
int sumOfMaxPath_dp(vector<vector<int> >& matrix, int row, int col)
{
	int Row = matrix.size();
	int Col = matrix[0].size();
	//建立二维动态规划数组
	int** dp = new int* [Row];
	for (int i = 0; i < Row; ++i)
	{
		dp[i] = new int[Col];
		memset(dp[i], 0, Col * sizeof(int));
	}
	
	dp[Row - 1][Col - 1] = matrix[Row - 1][Col - 1];
	for (int i = Col - 2; i >= 0; --i)
		dp[Row - 1][i] = matrix[Row - 1][i] + dp[Row - 1][i + 1];
	for (int i = Row - 2; i >= 0; --i)
		dp[i][Col - 1] = matrix[i][Col - 1] + dp[i + 1][Col - 1];
	
	for (int i = Row - 2; i >= 0; --i)
	{
		for (int j = Col - 2; j >= 0; --j)
			dp[i][j] = matrix[i][j] + max(dp[i + 1][j], dp[i][j + 1]);
	}
	
	int result = dp[row][col];
	//析构动态数组
	for (int i = 0; i < Row; ++i)
		delete[] dp[i];
	delete[] dp;
	return result;
}

int sumOfMaxPath(vector<vector<int> >& matrix, int row, int col)
{
	if (matrix.empty()) return 0;
	if (row >= matrix.size() || col >= matrix[0].size()) throw new exception("Invalid!");

	int result1 = sumOfMaxPath_Iterate(matrix, row, col);
	int result2 = sumOfMaxPath_dp(matrix, row, col);
	return result2;
}
int main()
{
	vector<vector<int> > matrix = { {1, 2, 3, 4}, {5, 6, 7, 8}, {7, 2, 5, 4}, {5, 2, 9, 4}, {8, 5, 2, 6} };
	int result = sumOfMaxPath(matrix, 0, 0);
	cout << result << " ";// << result2;
	return 0;
}