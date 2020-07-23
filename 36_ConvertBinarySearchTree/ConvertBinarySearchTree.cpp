#include<iostream>
using namespace std;

template<typename Object>
struct TreeNode
{
	Object element;
	TreeNode<Object>* leftChild;
	TreeNode<Object>* rightChild;
	TreeNode(Object value) :leftChild{ nullptr }, rightChild{ nullptr }{element = value; }
	TreeNode() :leftChild{ nullptr }, rightChild{ nullptr }{}
	~TreeNode()
	{
		delete leftChild;
		delete rightChild;
		leftChild = nullptr; 
		rightChild = nullptr;
	}
};

//题目：二叉搜索树转换成升序排列的双向链表
//二叉搜索树性质：左子树都比该节点小，右子树都比该节点大
//中序遍历满足从小到大遍历顺序

template<typename Object>
void ConvertBinarySearchTreeCore(TreeNode<Object>* pRoot, TreeNode<Object>*& preNode);

template<typename Object>
TreeNode<Object>* ConvertBinarySearchTree(TreeNode<Object>*& pRoot)
{
	if (pRoot == nullptr) return nullptr;
	if (pRoot->leftChild == nullptr && pRoot->rightChild == nullptr) return pRoot;

	TreeNode<Object>* preNode = new TreeNode<Object>; //链表头节点的前序节点,代表转换过程中当前节点的前项节点
	preNode = nullptr;
	ConvertBinarySearchTreeCore<Object>(pRoot, preNode);
	while (preNode->leftChild != nullptr)
		preNode = preNode->leftChild;
	return preNode;
}

//中序遍历
// 如果想用修改指针的指向，就要用指针的指针，或者指针的引用：此处preNode
template<typename Object>
void ConvertBinarySearchTreeCore(TreeNode<Object>* pRoot, TreeNode<Object>*& preNode)
{
	if (pRoot == nullptr) return ;

	ConvertBinarySearchTreeCore<Object>(pRoot->leftChild, preNode);
	pRoot->leftChild = preNode; //左节点连接前序节点
	if (preNode != nullptr)
		preNode->rightChild = pRoot;
	preNode = pRoot; //前序节点后移至当前节点
	ConvertBinarySearchTreeCore<Object>(pRoot->rightChild, preNode);
}

template<typename Object>
void printTreeNode(TreeNode<Object>*& ptrNode)
{
	if (ptrNode == nullptr) return;
	while (ptrNode != nullptr)
	{
		cout << ptrNode->element << " ";
		ptrNode = ptrNode->rightChild;
	}
}

int main()
{
	int arr[] = { 6, 3, 8, 2, 5, 7, 9, 4 };
	TreeNode<int>* tree1 = new TreeNode<int>(arr[0]);
	tree1->leftChild = new TreeNode<int>(arr[1]);
	tree1->rightChild = new TreeNode<int>(arr[2]);
	tree1->leftChild->leftChild = new TreeNode<int>(arr[3]);
	tree1->leftChild->rightChild = new TreeNode<int>(arr[4]);
	tree1->rightChild->leftChild = new TreeNode<int>(arr[5]);
	tree1->rightChild->rightChild = new TreeNode<int>(arr[6]);
	tree1->leftChild->rightChild->leftChild = new TreeNode<int>(arr[7]);

	TreeNode<int>* treeNode = new TreeNode<int>;
	treeNode = ConvertBinarySearchTree(tree1);
	printTreeNode(treeNode); // 2 3 4 5 6 7 8 9
	delete treeNode;
	treeNode = nullptr;
	return 0;
}