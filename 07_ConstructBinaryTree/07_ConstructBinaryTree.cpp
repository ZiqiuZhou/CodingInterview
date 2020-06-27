#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
	int element;
	TreeNode* leftChild;
	TreeNode* rightChild;
	TreeNode(int elem):leftChild{ nullptr }, rightChild{nullptr}
	{
		element = elem;
	}
	~TreeNode() { delete leftChild; delete rightChild; }
};

TreeNode* constructCore(vector<int>& preOrderArr, vector<int>& inOrderArr,
			int preOrderLeft, int preOrderRight, int inOrderLeft, int inOrderRight);

//根据两个数组（前序遍历结果和中序遍历结果），重建二叉树并返回头节点
//树中没有重复数字
TreeNode* constructTree(vector<int>& arr1, vector<int>& arr2)
{
	//特殊输入
	if (arr1.size() == 0 || arr2.size() == 0)
		return nullptr;

	if (arr1.size() != arr2.size())
		return nullptr;

	int preOrderRight = arr1.size() - 1;
	int inOrderRight = arr2.size() - 1;
	TreeNode* root = constructCore(arr1, arr2, 0, preOrderRight, 0, inOrderRight);
	return root;
}

TreeNode* constructCore(vector<int>& preOrderArr, vector<int>& inOrderArr,
	int preOrderLeft, int preOrderRight, int inOrderLeft, int inOrderRight)
{
	//建立根节点：前序遍历序列首元素为根节点
	TreeNode* head = new TreeNode(preOrderArr[preOrderLeft]);

	//两序列中只有一个元素(树长度为1)：递归退出条件
	if (preOrderLeft == preOrderRight && inOrderLeft == inOrderRight)
	{
		if (preOrderArr[preOrderLeft] == inOrderArr[inOrderLeft])
		{
			return head;
		}
		else
			return nullptr; //错误输入
	}

	//在中序遍历序列中找到根节点位置
	int i = inOrderLeft;
	for (i; i <= inOrderRight; ++i)
	{
		if (inOrderArr[i] == preOrderArr[preOrderLeft])
			break;
	}
	if (i > inOrderRight) return nullptr; //遍历后没找到对应元素：错误输入
	
	
	int lengthOfLeftTree = i - inOrderLeft; //左子树长度
	if (lengthOfLeftTree > 0) //如果存在左子树， 构建左子树
	{
		head->leftChild = constructCore(preOrderArr, inOrderArr,
			preOrderLeft + 1, preOrderLeft + lengthOfLeftTree, //前序遍历序列左子树索引范围
			inOrderLeft, i - 1);//中序遍历序列左子树索引范围
	}
 
	int lengthOfRightTree = inOrderRight - i; //右子树长度
	if (lengthOfRightTree > 0)
	{
		head->rightChild = constructCore(preOrderArr, inOrderArr,
			preOrderLeft + lengthOfLeftTree + 1, preOrderRight, //前序遍历序列右子树索引范围
			i + 1, inOrderRight);//中序遍历序列右子树索引范围
	}
	return head;
}

int main()
{
	vector<int> arr1 = {5, 3, 2, 1, 4, 8, 7, 6, 10, 9, 11}; //前序遍历序列
	vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; //中序遍历序列
	TreeNode* root = constructTree(arr1, arr2);
	cout << root->element << endl;

	vector<int> arr3;
	vector<int> arr4;
	root = constructTree(arr3, arr4);
	cout << "NULL"<< endl;
	//两序列元素不匹配
	vector<int> arr5 = { 5, 12, 2, 1, 4, 8, 7, 6, 10, 9, 11 };
	vector<int> arr6 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	root = constructTree(arr3, arr4);
	cout << "Invalid Input." << endl;
}