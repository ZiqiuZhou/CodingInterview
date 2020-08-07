#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

/*
����ջ��������������ÿ��λ��Ԫ����ߺ��ұߵ�һ��������/С��Ԫ�أ�
���Ҫ��ÿ��Ԫ�����ұߵ����ֵ���򵥵�ջ��ջ�׵�ջ��˳��Ϊ��С��
*/
int LargestRectangleInHistogram(vector<int>& array);

/*��Ŀ��һ����ά����Ԫ��ȡֵֻ��0��1���ھ�����������������ʹ�ø�
���ε�Ԫ��ȫ����1��
*/
int maxRecSize(vector<vector<int> >& matrix)
{
	if (matrix.empty()) return -1;

	int maxArea = 0;
	cout << "1";
	vector<int> height(matrix[0].size());
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[0].size(); ++j)
			height[j] = matrix[i][j] == 0 ? 0 : height[j] + 1;
		maxArea = std::max(maxArea, LargestRectangleInHistogram(height));
	}
	return maxArea;
}


/*��Ŀ��һ��һά�������ֱ��ͼ����������[4, 3, 5, 2]����ֱ��ͼ�ĸ߶�
�ֱ�Ϊ4, 3, 5, 2����ֱ��ͼ�������������򣬱�������˵������Ԫ����������
һֱ��չֱ���ҵ�����С�����������������������Ϊ��Ԫ�صĸߡ��ƶ���λ����.
����ջ��ջ�׵���Ϊ��С����
*/
int LargestRectangleInHistogram(vector<int>& array)
{
	if (array.size() == 0)
		return 0;

	int maxRecArea = 0;
	stack<int> stack1;//�������ĵ���ջ
	for (int i = 0; i < array.size(); ++i)
	{
		while (!stack1.empty() && array[i] < array[stack1.top()]) //������С�����˳�򣬵���ջ����ȷ��������������С����
		{
			int j = stack1.top(); //��ջ�������������Ҹ�����λ���������Ҹ�Сֵ
			stack1.pop();
			//��ߵĸ�Сֵ�Ǵ�ʱ��ջ�����ߴ�λ���Ѿ������������,
			//�ұߵĸ�Сֵ�ǵ�ǰλ��i��Ԫ��(��Ҫ��ջ)
			int k = stack1.empty() ? -1 : stack1.top();
			int recArea = (i - k - 1) * array[j];
			maxRecArea = std::max(recArea, maxRecArea);
		}
		stack1.push(i);
	}

	//������ջ�л���Ԫ��ʱ��˵��ջ������λ��Ԫ�ص��Ҳ����ޱ����С��Ԫ��
	while (!stack1.empty())
	{
		int j = stack1.top();
		stack1.pop();
		int k = stack1.empty() ? -1 : stack1.top();
		int recArea = (array.size() - k - 1) * array[j];
		maxRecArea = std::max(recArea, maxRecArea);
	}
	return maxRecArea;
}

int main()
{
	vector<vector<int> > matrix{ {1, 1, 1, 1}, {1, 1, 1, 1} };
	cout << maxRecSize(matrix);
	return 0;
}