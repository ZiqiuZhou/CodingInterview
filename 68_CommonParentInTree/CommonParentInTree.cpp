#include<iostream>
#include<vector>
#include<stack>
using namespace std;

template<typename Object>
struct TreeNode
{
	Object element;
	TreeNode<Object>* leftChild;
	TreeNode<Object>* rightChild;
	TreeNode<Object>* parent;
	TreeNode(Object ele) :leftChild{ nullptr }, rightChild{ nullptr }, parent{ nullptr }{element = ele; }
	TreeNode() :leftChild{ nullptr }, rightChild{ nullptr }, parent{ nullptr }{}
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

//�ҳ�����ĳ�����ڵ����͹�������

/*
����1�������Ƕ���������������������ṹ�����ԴӸ��ڵ㿪ʼ�ң� �����ǰ�ڵ�������ڵ㶼С��
 ��תȥ���������������ǰ�ڵ�������ڵ㶼��תȥ��������ֱ����ǰ�ڵ��һ�����һ��С;
 ����ڵ�node1��node2С
*/
template<typename Object>
TreeNode<Object>* CommonParentTree1(TreeNode<Object>* pRoot, TreeNode<Object>* node1, TreeNode<Object>* node2)
{
	while (!(pRoot->element > node1->element&& pRoot->element < node2->element))
	{
		if (pRoot->element > node1->element&& pRoot->element > node2->element) //�����ڵ㶼��
			pRoot = pRoot->leftChild;
		else if(pRoot->element < node1->element&& pRoot->element < node2->element) //�����ڵ㶼С
			pRoot = pRoot->rightChild;
	}
	return pRoot;
}

/*
������Ƕ������������������Ƕ�����������Ҫ����ָ�룬ת�������������Ĺ����ڵ�
*/
template<typename Object>
TreeNode<Object>* CommonParentTree2(TreeNode<Object>* pRoot, TreeNode<Object>* node1, TreeNode<Object>* node2)
{
	int length1 = 0;
	int length2 = 0;
	TreeNode<Object>* ptr1 = new TreeNode<Object>();
	TreeNode<Object>* ptr2 = new TreeNode<Object>();
	ptr1 = node1;
	ptr2 = node2;
	while (ptr1 != nullptr)
	{
		length1++;
		ptr1 = ptr1->parent;
	}
	while (ptr2 != nullptr)
	{
		length2++;
		ptr2 = ptr2->parent;
	}

	ptr1 = node1;
	ptr2 = node2;
	if (length1 >= length2)
	{
		for (int i = 0; i < length1 - length2; ++i)
			ptr1 = ptr1->parent;
		while (ptr1 != ptr2)
		{
			ptr1 = ptr1->parent;
			ptr2 = ptr2->parent;
		}
		return ptr1;
	}
	else if (length1 < length2)
	{
		for (int i = 0; i < length2 - length1; ++i)
			ptr2 = ptr2->parent;
		while (ptr1 != ptr2)
		{
			ptr1 = ptr1->parent;
			ptr2 = ptr2->parent;
		}
		return ptr1;
	}

	delete ptr1;
	delete ptr2;
}

/*
������Ƕ������������������Ƕ�������Ҳû��parentָ�룬��ǰ���������
���������������ڵ�����·�����ٽ�·���ó���һһ�Ƚ�
*/
template<typename Object>
bool CommonParentTree3(TreeNode<Object>* pRoot, TreeNode<Object>* node1, stack<TreeNode<Object>*>& stack1)
{
	if (pRoot == nullptr)
		return false;
	if (pRoot == node1)
	{
		stack1.push(node1);
		return true;
	}

	bool result = CommonParentTree3<Object>(pRoot->leftChild, node1, stack1) || CommonParentTree3<Object>(pRoot->rightChild, node1, stack1);
	if(result)
		stack1.push(pRoot);
	return result;
}

template<typename Object>
void CommonParentTree3(TreeNode<Object>* pRoot, TreeNode<Object>* node1, TreeNode<Object>* node2)
{
	bool flag;
	stack<TreeNode<Object>*> stack1;
	stack<TreeNode<Object>*> stack2;
	//��node1��node2��·���������
	CommonParentTree3Core(pRoot, node1, stack1);
	CommonParentTree3Core(pRoot, node2, stack2);
	while (stack1.top() == stack2.top())
	{
		stack1.pop();
		stack2.pop();
	}
}

template<typename Object>
TreeNode<Object>* CommonParentTree(TreeNode<Object>* pRoot, TreeNode<Object>* node1, TreeNode<Object>* node2)
{
	if (pRoot == nullptr || node1 == nullptr || node2 == nullptr)
		throw new exception("Invalid Input!");

	if (pRoot->element == node1->element) // node1ǡ���Ǹ��ڵ�
		return node1;
	if (pRoot->element == node2->element) // node2ǡ���Ǹ��ڵ�
		return node2;

	TreeNode<Object>* result1 = CommonParentTree1<Object>(pRoot, node1, node2);
	TreeNode<Object>* result2 = CommonParentTree2<Object>(pRoot, node1, node2);
	//TreeNode<Object>* result3 = CommonParentTree3<Object>(pRoot, node1, node2);
	return result2;
}

int main()
{
	int arr[] = { 6, 3, 8, 2, 5, 7, 9, 4 };
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

	TreeNode<int>* result = new TreeNode<int>();
	result = CommonParentTree<int>(tree1, tree1->leftChild->leftChild, tree1->leftChild->rightChild->leftChild);
	cout << result->element;
}
