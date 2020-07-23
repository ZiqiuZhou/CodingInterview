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

//��Ŀ������������ת�����������е�˫������
//�������������ʣ����������ȸýڵ�С�����������ȸýڵ��
//������������С�������˳��

template<typename Object>
void ConvertBinarySearchTreeCore(TreeNode<Object>* pRoot, TreeNode<Object>*& preNode);

template<typename Object>
TreeNode<Object>* ConvertBinarySearchTree(TreeNode<Object>*& pRoot)
{
	if (pRoot == nullptr) return nullptr;
	if (pRoot->leftChild == nullptr && pRoot->rightChild == nullptr) return pRoot;

	TreeNode<Object>* preNode = new TreeNode<Object>; //����ͷ�ڵ��ǰ��ڵ�,����ת�������е�ǰ�ڵ��ǰ��ڵ�
	preNode = nullptr;
	ConvertBinarySearchTreeCore<Object>(pRoot, preNode);
	while (preNode->leftChild != nullptr)
		preNode = preNode->leftChild;
	return preNode;
}

//�������
// ��������޸�ָ���ָ�򣬾�Ҫ��ָ���ָ�룬����ָ������ã��˴�preNode
template<typename Object>
void ConvertBinarySearchTreeCore(TreeNode<Object>* pRoot, TreeNode<Object>*& preNode)
{
	if (pRoot == nullptr) return ;

	ConvertBinarySearchTreeCore<Object>(pRoot->leftChild, preNode);
	pRoot->leftChild = preNode; //��ڵ�����ǰ��ڵ�
	if (preNode != nullptr)
		preNode->rightChild = pRoot;
	preNode = pRoot; //ǰ��ڵ��������ǰ�ڵ�
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