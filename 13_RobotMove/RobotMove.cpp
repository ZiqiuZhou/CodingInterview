#include<iostream>
#include<vector>
using namespace std;

// ��Ŀ��������һ��m��n�еķ���һ�������˴�����(0, 0)�ĸ��ӿ�ʼ�ƶ�����
// ÿһ�ο��������ҡ��ϡ����ƶ�һ�񣬵����ܽ�������������������λ֮��
// ����k�ĸ��ӡ����磬��kΪ18ʱ���������ܹ����뷽��(35, 37)����Ϊ3+5+3+7=18��
// �������ܽ��뷽��(35, 38)����Ϊ3+5+3+8=19�����ʸû������ܹ�������ٸ����ӣ�

int countCore(vector<vector<int> >& matrix, int threshold, int row, int col, int Row, int Col, bool** visited);
bool checker(int threshold, int row, int col, int Row, int Col, bool** visited);
int getDigitSum(int num);

int moveCount(vector<vector<int> >& matrix, int threshold)
{
	if (matrix.empty() || threshold < 0)
		return 0;
	int Row = matrix.size();
	int Col = matrix[0].size();

	//��ʼ�����ʾ��󣬱���Ѿ������ʹ���Ԫ��
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

//�ж�ĳ������λ֮���Ƿ���������
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