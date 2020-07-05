#include<iostream>
#include<vector>
using namespace std;

// 题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
// 每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
// 大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
// 但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

int countCore(vector<vector<int> >& matrix, int threshold, int row, int col, int Row, int Col, bool** visited);
bool checker(int threshold, int row, int col, int Row, int Col, bool** visited);
int getDigitSum(int num);

int moveCount(vector<vector<int> >& matrix, int threshold)
{
	if (matrix.empty() || threshold < 0)
		return 0;
	int Row = matrix.size();
	int Col = matrix[0].size();

	//初始化访问矩阵，标记已经被访问过的元素
	bool** visited = new bool* [Row];
	for (int i = 0; i < Row; ++i)
	{
		visited[i] = new bool[Col];
		memset(visited[i], 0, Col * sizeof(bool));
	}
	int count = countCore(matrix, threshold, 0, 0, Row, Col, visited);
	delete[] visited;
	return count;
}

int countCore(vector<vector<int> >& matrix, int threshold, int row, int col, int Row, int Col, bool** visited)
{
	int count = 0;
	if (checker(threshold, row, col, Row, Col, visited))
	{
		visited[row][col] = true;
		count = 1 + countCore(matrix, threshold, row, col - 1, Row, Col, visited)
			+ countCore(matrix, threshold, row - 1, col, Row, Col, visited)
			+ countCore(matrix, threshold, row, col + 1, Row, Col, visited)
			+ countCore(matrix, threshold, row + 1, col, Row, Col, visited);
	}
	return count;
}

//判断某索引数位之和是否满足条件
bool checker(int threshold, int row, int col, int Row, int Col, bool** visited)
{
	if (row >= 0 && row < Row && col >= 0 && col < Col
		&& getDigitSum(row) + getDigitSum(col) <= threshold
		&& !visited[row][col])
		return true;
	else
		return false;
}

int getDigitSum(int num)
{
	int sum = 0;
	while (num > 0)
	{
		sum += num % 10;
		num = num / 10;
	}
	return sum;
}

int main()
{
	vector<vector<int> > matrix = { {1, 2, 3, 4}, {5, 6, 7, 8} };
	cout << moveCount(matrix, 5);
	return 0;
}