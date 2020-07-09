#include<iostream>
#include<vector>
using namespace std;

//��Ŀ������һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֡�
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

//�ݹ�ʵ��
template<typename Object>
void printMatrixInCircle(vector<vector<Object> >& matrix, int rowIdx, int colIdx, int Row, int Col)
{
	//rowIdx, colIdx: ��ǰ�ִ���ʼ�С��������� �ھ������Ͻ�
	//Row : ��ǰ����Ŀ�
	//Col : ��ǰ����ĸ�
	for (int i = 0; i < Col; ++i) //��������
	{
		cout << matrix[rowIdx][colIdx++] << " ";
	}
	colIdx--;

	for (int i = 0; i < Row - 1; ++i) //��������
	{
		cout << matrix[++rowIdx][colIdx] << " ";
	}

	for (int i = 0; i < Col - 1; ++i) //��������
	{
		cout << matrix[rowIdx][--colIdx] << " ";
	}

	for (int i = 0; i < Row - 2; ++i) //��������
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