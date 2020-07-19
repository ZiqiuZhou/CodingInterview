#include<iostream>
#include<vector>
using namespace std;

template<typename Object>
struct TreeNode
{
	Object element;
	TreeNode<Object>* leftChild;
	TreeNode<Object>* rightChild;
	TreeNode<Object>* parent;
	TreeNode() { element = 0; leftChild = nullptr; rightChild = nullptr; parent = nullptr; }
	TreeNode(Object value) :leftChild{ nullptr }, rightChild{ nullptr }, parent{nullptr}{element = value; }
	~TreeNode()
	{
		delete leftChild;
		delete rightChild;
		delete parent;
		leftChild = nullptr;
		rightChild = nullptr;
		parent = nullptr;
	}
};

//题目：输入一棵二叉树和一个整数，打印出二叉树中节点之和为输入整数的所有路径
template<typename Object>
bool isSum(TreeNode<Object>* pRoot, Object target, vector<TreeNode<Object>*>& storedLeaf)
{
	if (pRoot == nullptr)
	{
		if (target == 0)
			return true;
		else
			return false;
	}
	Object currentSum = pRoot->element;
	return isSumCore(pRoot, target, currentSum, storedLeaf);
}

template<typename Object>
bool isSumCore(TreeNode<Object>* pRoot, Object target, Object currentSum, vector<TreeNode<Object>*>& storedLeaf)
{
	//数组storedLeaf用来储存满足条件的叶子节点最终用来重构路径
	if (pRoot->leftChild == nullptr && pRoot->rightChild == nullptr) // 叶子节点
	{
		if (currentSum == target)
		{
			storedLeaf.push_back(pRoot);
			return true;
		}
		return false;
	}
	else if(pRoot->leftChild == nullptr && pRoot->rightChild != nullptr)
		return isSumCore(pRoot->rightChild, target, currentSum + pRoot->rightChild->element, storedLeaf);
	else if (pRoot->leftChild != nullptr && pRoot->rightChild == nullptr)
		return isSumCore(pRoot->leftChild, target, currentSum + pRoot->leftChild->element, storedLeaf);
	else
	{
		return isSumCore(pRoot->leftChild, target, currentSum + pRoot->leftChild->element, storedLeaf) ||
			isSumCore(pRoot->rightChild, target, currentSum + pRoot->rightChild->element, storedLeaf);
	}
}

template<typename Object>
void reconstructPath(TreeNode<Object>* pRoot, Object target)
{
	vector<TreeNode<Object>*> storedLeaf;
	if (isSum(pRoot, target, storedLeaf))
	{
		for (int i = 0; i < storedLeaf.size(); ++i)
		{
			TreeNode<Object>* nodePtr = new TreeNode<Object>();
			nodePtr = storedLeaf[i];
			while (nodePtr != nullptr)
			{
				cout << nodePtr->element << " ";
				nodePtr = nodePtr->parent;
			}
			cout << endl;
		}
	}
}

int main()
{
	int arr[] = { 2, 3, 1, 7, 3, 13, 0, 8 };
	TreeNode<int>* tree1 = new TreeNode<int>(arr[0]);
	tree1->leftChild = new TreeNode<int>(arr[1]);
	tree1->leftChild->parent = tree1;
	tree1->rightChild = new TreeNode<int>(arr[2]);
	tree1->rightChild->parent = tree1;
	tree1->leftChild->leftChild = new TreeNode<int>(arr[3]);
	tree1->leftChild->leftChild->parent = tree1->leftChild;
	tree1->leftChild->rightChild = new TreeNode<int>(arr[4]);
	tree1->leftChild->rightChild->parent = tree1->leftChild;
	tree1->rightChild->leftChild = new TreeNode<int>(arr[5]);
	tree1->rightChild->leftChild->parent = tree1->rightChild;
	tree1->rightChild->rightChild = new TreeNode<int>(arr[6]);
	tree1->rightChild->rightChild->parent = tree1->rightChild;
	tree1->leftChild->rightChild->leftChild = new TreeNode<int>(arr[7]);
	tree1->leftChild->rightChild->leftChild->parent = tree1->leftChild->rightChild;
	reconstructPath(tree1, 16);
	return 0;
}