#include<iostream>
#include<vector>
using namespace std;

/*
首先选取数组中右上角的数字。 如果该数字等于要查找的数字，
则查找过程结束： 如果该数字大于要查找的数字， 则剔除这个
数字所在的列：如果该数字小于要查找的数字，则剔除这个数字
所在的行。知道找到查找数字或者查找范围为空
*/

//number为需要查找的数
int find(vector<vector<int> > matrix, int number)
{
	if (matrix.size() == 0)
		return -1;
	if (matrix.size() == 1)
	{
		if (number = matrix[0][0])
			return 1;
		else return -1;
	}

	//初始位置右上角
	int row = 0;
	int col = matrix[0].size() - 1;
	while (row <= matrix.size() - 1 && col >= 0)
	{
		if (matrix[row][col] == number)
			return 1;
		if (matrix[row][col] < number)
			row++;
		else if (matrix[row][col] > number)
			col--;
	}
	return -1;
}

int main()
{
	vector<vector<int> > matrix1 = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	cout << find(matrix1, 7) << endl;
	cout << find(matrix1, 5) << endl;
	cout << find(matrix1, 0) << endl;
	cout << find(matrix1, 16) << endl;
}