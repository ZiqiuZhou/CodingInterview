#include<iostream>
#include<vector>
using namespace std;

template<typename Object>
struct TreeNode
{
	Object element;
	TreeNode<Object>* leftChild;
	TreeNode<Object>* rightChild;

	TreeNode(Object value) :leftChild{ nullptr }, rightChild{nullptr}
	{
		element = value;
	}

	TreeNode():leftChild{ nullptr }, rightChild{ nullptr }{}
	~TreeNode() { leftChild = nullptr; rightChild = nullptr; }
};

template<typename Object>
vector<Object>& preOrderTraversal(TreeNode<Object>* pRoot, vector<Object>& result);

template<typename Object>
bool findSubTree(vector<Object>& array1, vector<Object>& array2);

// 题目：输入两棵二叉树A和B，判断B是不是A的子结构
template<typename Object>
bool hasSubTree(TreeNode<Object>* pRoot1, TreeNode<Object>* pRoot2)
{
	if (pRoot1 == nullptr && pRoot2 == nullptr)
		return true;
	if (pRoot1 == nullptr || pRoot2 == nullptr) //某一棵树为空
		return false;

	//数组用于存放两树遍历结果
	vector<Object> traversalResult1;
	vector<Object> traversalResult2;
	traversalResult1 = preOrderTraversal(pRoot1, traversalResult1);
	traversalResult2 = preOrderTraversal(pRoot2, traversalResult2);

	bool hasTree = false;
	if (findSubTree(traversalResult1, traversalResult2))
		hasTree = true;
	return hasTree;
}

//前序遍历树，将结果存入数组
template<typename Object>
vector<Object>& preOrderTraversal(TreeNode<Object>* pRoot, vector<Object>& result)
{
	if (pRoot == nullptr)
	{
		result.push_back(-1); //代表空指针，一定不能忘
		return result;
	}
	if (pRoot != nullptr)
	{
		result.push_back(pRoot->element);
		result = preOrderTraversal(pRoot->leftChild, result);
		result = preOrderTraversal(pRoot->rightChild, result);
	}
	return result;
}

template<typename Object>
bool findSubTree(vector<Object>& array1, vector<Object>& array2)
{
	if (array1.size() < array2.size())
		return false;
	typename vector<Object>::iterator iter1 = array1.begin();
	typename vector<Object>::iterator iter2 = array2.begin();
	while (iter1 != array1.end()) // 遍历第一个数组，直到找到与数组二首元素相同的位置
	{
		if (*iter1 != *iter2)
			++iter1;
		else //找到相同元素
			break;
	}
	if (iter1 == array1.end()) //遍历完数组1仍然找不到数组二的首元素
		return false;

	while (iter2 != array2.end())
	{
		if (iter1 == array1.end() || *iter1 != *iter2)
			return false;
		iter1++;
		iter2++;
	}
	return true;
}

int main()
{
	int arr[] = {2, 3, 1, 7, 3, 5, 0, 8};
	TreeNode<int>* tree1 = new TreeNode<int>(arr[0]);
	tree1->leftChild = new TreeNode<int>(arr[1]);
	tree1->rightChild = new TreeNode<int>(arr[2]);
	tree1->leftChild->leftChild = new TreeNode<int>(arr[3]);
	tree1->leftChild->rightChild = new TreeNode<int>(arr[4]);
	tree1->rightChild->leftChild = new TreeNode<int>(arr[5]);
	tree1->rightChild->rightChild = new TreeNode<int>(arr[6]);
	tree1->leftChild->rightChild->leftChild = new TreeNode<int>(arr[7]);

	int arr2[] = {7, 3, 8}; //不是子树
	TreeNode<int>* tree2 = new TreeNode<int>(arr2[0]);
	tree2->leftChild = new TreeNode<int>(arr2[1]);
	tree2->rightChild = new TreeNode<int>(arr2[2]);
	cout << hasSubTree(tree1, tree2) << endl;

	int arr3[] = { 1, 5, 0 }; // 是子树
	TreeNode<int>* tree3 = new TreeNode<int>(arr3[0]);
	tree3->leftChild = new TreeNode<int>(arr3[1]);
	tree3->rightChild = new TreeNode<int>(arr3[2]);
	cout << hasSubTree(tree1, tree3) << endl;
	return 0;
}