#include<iostream>
using namespace std;

// 镜像二叉树：前序遍历树，先对根节点的
//两个子节点交换位置，再递归每个节点，直到遇到
//叶子节点

template<typename Object>
struct TreeNode
{
	Object element;
	TreeNode<Object>* leftChild;
	TreeNode<Object>* rightChild;

	TreeNode(Object value) :leftChild{ nullptr }, rightChild{ nullptr }
	{
		element = value;
	}

	TreeNode() :leftChild{ nullptr }, rightChild{ nullptr }{}
	~TreeNode() { leftChild = nullptr; rightChild = nullptr; }
};

template<typename Object>
void MirrorRecursively(TreeNode<Object>* pRoot)
{
	if (pRoot == nullptr)
		return;
	if (pRoot->leftChild == nullptr && pRoot->rightChild == nullptr) // 叶子节点
		return;

	// 交换左右子节点
	std::swap(pRoot->leftChild, pRoot->rightChild);
	MirrorRecursively(pRoot->leftChild);
	MirrorRecursively(pRoot->rightChild);
}

//前序遍历树，用于验证
template<typename Object>
void preOrderTraversal(TreeNode<Object>* pRoot)
{
	if (pRoot == nullptr)
	{
		return ;
	}
	cout << pRoot->element << " ";
	preOrderTraversal(pRoot->leftChild);
	preOrderTraversal(pRoot->rightChild);
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

	preOrderTraversal(tree1); // 2 3 7 3 8 1 5 0
	cout << endl;
	MirrorRecursively(tree1);
	preOrderTraversal(tree1); // 2 1 0 5 3 3 8 7
	delete tree1;
	return 0;
}