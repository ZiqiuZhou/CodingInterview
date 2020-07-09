#include<iostream>
#include<vector>
using namespace std;

//题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
template<typename Object>
void printMatrixInCircle(vector<vector<Object> >& matrix, int rowIdx, int colIdx, int Row, int Col);

template<typename Object>
void printMatrix(vector<vector<Object> >& matrix)
{
	if (matrix.empty())
	{
		cout << "empty matrix.";
		return;
	}

	int Row = matrix.size();
	int Col = matrix[0].size();
	printMatrixInCircle(matrix, 0, 0, Row, Col);
}

//递归实现
template<typename Object>
void printMatrixInCircle(vector<vector<Object> >& matrix, int rowIdx, int colIdx, int Row, int Col)
{
	//rowIdx, colIdx: 当前轮次起始行、列索引， 在矩阵左上角
	//Row : 当前矩阵的宽
	//Col : 当前矩阵的高
	for (int i = 0; i < Col; ++i) //从左往右
	{
		cout << matrix[rowIdx][colIdx++] << " ";
	}
	colIdx--;

	for (int i = 0; i < Row - 1; ++i) //从上往下
	{
		cout << matrix[++rowIdx][colIdx] << " ";
	}

	for (int i = 0; i < Col - 1; ++i) //从右往左
	{
		cout << matrix[rowIdx][--colIdx] << " ";
	}

	for (int i = 0; i < Row - 2; ++i) //从下往上
	{
		cout << matrix[--rowIdx][colIdx] << " ";
	}

	if (Row - 2 >= 1 && Col - 2 >= 1)
	{
		printMatrixInCircle(matrix, rowIdx, colIdx++, Row - 2, Col - 2);
	}
}

int main()
{	
	vector<vector<int> > matrix = { {1, 2, 3, 4}, {5, 6, 7, 8} };
	printMatrix(matrix);
	return 0;
}