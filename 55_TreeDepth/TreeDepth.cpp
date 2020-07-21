#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

template<typename Object>
struct TreeNode
{
	Object element;
	TreeNode<Object>* leftChild;
	TreeNode<Object>* rightChild;
	TreeNode() { element = 0; leftChild = nullptr; rightChild = nullptr; }
	TreeNode(Object value) :leftChild{ nullptr }, rightChild{ nullptr }{element = value; }
	~TreeNode()
	{
		delete leftChild;
		delete rightChild;
		leftChild = nullptr;
		rightChild = nullptr;
	}
};

//计算树的深度
template<typename Object>
Object TreeDepth(TreeNode<Object>* pRoot)
{
	if (pRoot == nullptr)
		return 0;
	return std::max(TreeDepth<Object>(pRoot->leftChild), TreeDepth<Object>(pRoot->rightChild)) + 1;
}

//判断是否是平衡二叉树：左右子树的深度之差不能超过1
template<typename Object>
bool isBanlanced(TreeNode<Object>* pRoot)
{
	if (pRoot == nullptr)
		return true;
	if (std::abs(TreeDepth<Object>(pRoot->leftChild) - TreeDepth<Object>(pRoot->rightChild)) > 1)
		return false;
	return isBanlanced(pRoot->leftChild) && isBanlanced(pRoot->rightChild);
}


int main()
{
	int arr[] = { 2, 3, 1, 7, 3, 5, 0, 8 };
	TreeNode<int>* tree1 = new TreeNode<int>(arr[0]);
	tree1->leftChild = new TreeNode<int>(arr[1]);
	tree1->rightChild = new TreeNode<int>(arr[2]);
	tree1->leftChild->leftChild = new TreeNode<int>(arr[3]);
	tree1->leftChild->rightChild = new TreeNode<int>(arr[4]);
	tree1->rightChild->leftChild = new TreeNode<int>(arr[5]);
	tree1->rightChild->rightChild = new TreeNode<int>(arr[6]);
	tree1->leftChild->rightChild->leftChild = new TreeNode<int>(arr[7]);

	cout << TreeDepth(tree1) << endl;
	cout << isBanlanced(tree1) << endl;
	return 0;
}