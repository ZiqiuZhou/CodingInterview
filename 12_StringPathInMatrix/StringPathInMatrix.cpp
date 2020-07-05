#include<iostream>
#include<vector>
#include<string>
using namespace std;

// ��Ŀ�������һ�������������ж���һ���������Ƿ����һ������ĳ�ַ�������
// �ַ���·����·�����ԴӾ���������һ��ʼ��ÿһ�������ھ����������ҡ�
// �ϡ����ƶ�һ�����һ��·�������˾����ĳһ����ô��·�������ٴν���
// �ø��ӡ������������3��4�ľ����а���һ���ַ�����bfce����·����·���е���
// ĸ���»��߱�������������в������ַ�����abfb����·������Ϊ�ַ����ĵ�һ��
// �ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν����������

bool hasPathCore(vector<vector<char> >& matrix, string& str, int& Row, int& Col,
	int row, int col, int& pathIndex, bool** visited);


bool hasPath(vector<vector<char> >& matrix, string& str)
{
	if (matrix.empty() || str.empty())
		return false;

	int Row = matrix.size();
	int Col = matrix[0].size();

	//��̬��ʼ���������飬����ѷ���Ԫ�أ����Ԫ�س�ʼ��Ϊ0
	bool** visited = new bool* [Row];
	for (int i = 0; i < Row; ++i)
	{
		visited[i] = new bool[Col];
		memset(visited[i], 0, Col*sizeof(bool));
	}

	int pathIndex = 0; // ��str��0��λ������
	for (int i = 0; i < Row; ++i)
	{
		for (int j = 0; j < Col; ++j)
		{
			if (hasPathCore(matrix, str, Row, Col, i, j, pathIndex, visited))
			{
				delete[] visited;
				return true;
			}
		}
	}
	delete[] visited;
	return false;
}

bool hasPathCore(vector<vector<char> >& matrix, string& str, int& Row, int& Col,
			int row, int col, int& pathIndex, bool** visited)
{
	if (pathIndex == str.size()) // base case
		return true;

	bool hasPath = false;
	//����������Ԫ����str�д˿�������Ԫ����ͬ���Ҿ���Ԫ��δ�����ʹ�
	if (row >=0 && row < Row && col >= 0 &&  col < Col && matrix[row][col] == str[pathIndex]
		&& !visited[row][col])
	{
		pathIndex++; // ��λ��Ԫ�ر��ҵ���������һλ��
		visited[row][col] = true;
		
		//�����������µ�˳��Ѱ����һ���ַ�
		hasPath = hasPathCore(matrix, str, Row, Col, row, col - 1, pathIndex, visited)
			|| hasPathCore(matrix, str, Row, Col, row - 1, col, pathIndex, visited)
			|| hasPathCore(matrix, str, Row, Col, row, col + 1, pathIndex, visited)
			|| hasPathCore(matrix, str, Row, Col, row + 1, col, pathIndex, visited);

		if (!hasPath) //��������ھӱ���������û�ҵ���һ�����ϵ��ַ������ݵ���һ��λ��
		{
			pathIndex--;
			visited[row][col] = false;
		}
	}
	return hasPath;
}


int main()
{
	vector<vector<char> > matrix1 = { {'A','B', 'T', 'G'}, {'C', 'F', 'C', 'S'}, {'J', 'D', 'E', 'H'} };
	string str1 = "BFCE";
	cout << hasPath(matrix1, str1);

}