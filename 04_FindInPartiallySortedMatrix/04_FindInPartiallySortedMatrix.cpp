#include<iostream>
#include<vector>
using namespace std;

/*
����ѡȡ���������Ͻǵ����֡� ��������ֵ���Ҫ���ҵ����֣�
����ҹ��̽����� ��������ִ���Ҫ���ҵ����֣� ���޳����
�������ڵ��У����������С��Ҫ���ҵ����֣����޳��������
���ڵ��С�֪���ҵ��������ֻ��߲��ҷ�ΧΪ��
*/

//numberΪ��Ҫ���ҵ���
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

	//��ʼλ�����Ͻ�
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