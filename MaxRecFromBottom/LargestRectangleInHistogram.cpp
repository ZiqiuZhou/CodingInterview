#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

/*题目：一个一维数组代表直方图；例如数组[4, 3, 5, 2]代表直方图的高度
分别为4, 3, 5, 2。在直方图中找最大矩形区域，本质上是说对任意元素它向左右
一直延展直到找到比它小的左右两个数，矩形面积即为该元素的高×移动的位置数.
单调栈从栈底到顶为从小到大
*/
int LargestRectangleInHistogram(vector<int>& array)
{
	if (array.size() == 0)
		return 0;

	int maxRecArea = 0;
	stack<int> stack1;//存索引的单调栈
	for (int i = 0; i < array.size(); ++i)
	{
		while (!stack1.empty() && array[i] < array[stack1.top()]) //不满足小到大的顺序，弹出栈顶，确定左右两个比其小的数
		{
			int j = stack1.top(); //出栈的索引，下面找该索引位置数的左右更小值
			stack1.pop();
			//左边的更小值是此时的栈顶或者此位置已经是数组最左边,
			//右边的更小值是当前位置i的元素(正要入栈)
			int k = stack1.empty() ? -1 : stack1.top(); 
			int recArea = (i - k - 1) * array[j];
			maxRecArea = std::max(recArea, maxRecArea);
		}
		stack1.push(i);
	}

	//当单调栈中还有元素时，说明栈中索引位置元素的右侧再无比起更小的元素
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
	vector<int> arr{ 4, 3, 2, 5, 6, 3, 8 };
	cout << LargestRectangleInHistogram(arr);
	return 0;
}