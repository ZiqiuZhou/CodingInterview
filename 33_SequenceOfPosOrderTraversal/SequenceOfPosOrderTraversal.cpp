#include<iostream>
#include<vector>
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

//判断序列是否是一棵树的后序遍历序列

//后序遍历递归实现
template<typename Object>
void posOrderTraversal(TreeNode<Object>* head, vector<Object>& vec)
{
	if (head == nullptr)
	{
		return ;
	}
	if (head != nullptr)
	{
		posOrderTraversal(head->leftChild, vec);
		posOrderTraversal(head->rightChild, vec);
		vec.push_back(head->element);
	}
}

template<typename Object>
bool verifySequence(TreeNode<Object>* root, vector<Object>& sequence)
{
	vector<Object> arr;
	posOrderTraversal(root, arr);
	if (arr.size() != sequence.size())
		return false;

	typename std::vector<Object>::iterator iter1 = arr.begin();
	typename std::vector<Object>::iterator iter2 = sequence.begin();
	while (iter1 != arr.end())
	{
		if (*iter1++ != *iter2++)
			return false;
	}
	return true;
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

	vector<int> vec1 = { 4, 5, 1, 2, 7, 9, 3, 4 };
	vector<int> vec2 = { 7, 8, 3, 3, 5, 0, 1, 2 };
	cout << verifySequence(tree1, vec1) << endl;
	cout << verifySequence(tree1, vec2) << endl;
}