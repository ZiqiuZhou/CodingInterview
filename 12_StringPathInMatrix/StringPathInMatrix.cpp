#include<iostream>
#include<vector>
#include<string>
using namespace std;

// 题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有
// 字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵中向左、右、
// 上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入
// 该格子。例如在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字
// 母用下划线标出）。但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个
// 字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子

bool hasPathCore(vector<vector<char> >& matrix, string& str, int& Row, int& Col,
	int row, int col, int& pathIndex, bool** visited);


bool hasPath(vector<vector<char> >& matrix, string& str)
{
	if (matrix.empty() || str.empty())
		return false;

	int Row = matrix.size();
	int Col = matrix[0].size();

	//动态初始化访问数组，标记已访问元素，起初元素初始化为0
	bool** visited = new bool* [Row];
	for (int i = 0; i < Row; ++i)
	{
		visited[i] = new bool[Col];
		memset(visited[i], 0, Col*sizeof(bool));
	}

	int pathIndex = 0; // 从str第0个位置找起
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
	//当遇到矩阵元素与str中此刻索引的元素相同并且矩阵元素未被访问过
	if (row >=0 && row < Row && col >= 0 &&  col < Col && matrix[row][col] == str[pathIndex]
		&& !visited[row][col])
	{
		pathIndex++; // 该位置元素被找到，继续下一位置
		visited[row][col] = true;
		
		//按照上左右下的顺序寻找下一个字符
		hasPath = hasPathCore(matrix, str, Row, Col, row, col - 1, pathIndex, visited)
			|| hasPathCore(matrix, str, Row, Col, row - 1, col, pathIndex, visited)
			|| hasPathCore(matrix, str, Row, Col, row, col + 1, pathIndex, visited)
			|| hasPathCore(matrix, str, Row, Col, row + 1, col, pathIndex, visited);

		if (!hasPath) //如果所有邻居遍历结束都没找到下一个符合的字符：回溯到上一轮位置
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