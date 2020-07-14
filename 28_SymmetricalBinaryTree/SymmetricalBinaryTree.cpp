#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//判断二叉树是否对称：只需判断此树与其镜像树是否完全相同
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

//镜像树
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

//前序遍历树，将结果存入数组
template<typename Object>
vector<Object>& preOrderTraversal(TreeNode<Object>* pRoot, vector<Object>& result)
{
	if (pRoot == nullptr)
	{
		result.push_back(INT_MIN); //代表空指针，一定不能忘
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

//判断两数组序列是否相同
template<typename Object>
bool isEqualArray(vector<Object>& result1, vector<Object>& result2)
{
	typename std::vector<Object>::iterator iter1 = result1.begin();
	typename std::vector<Object>::iterator iter2 = result2.begin();
	for (iter1; iter1 != result1.end(); ++iter1, ++iter2)
	{
		if (*iter1 != *iter2)
			return false;
	}
	return true;
}

//判断是否对称树
template<typename Object>
bool isSymmetricTree(TreeNode<Object>* pRoot)
{
	if (pRoot == nullptr)
		return true;
	if (pRoot->leftChild == nullptr || pRoot->rightChild == nullptr)
		return true;

	vector<Object> beforeMirrorArr;
	vector<Object> afterMirrorArr;
	beforeMirrorArr = preOrderTraversal(pRoot, beforeMirrorArr);
	MirrorRecursively(pRoot);
	afterMirrorArr = preOrderTraversal(pRoot, afterMirrorArr);
	return isEqualArray(beforeMirrorArr, afterMirrorArr);
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

	cout << isSymmetricTree(tree1) << " " << endl;//不是对称树

	int arr2[] = { 8, 6, 6, 5, 7, 7, 5 };
	TreeNode<int>* tree2 = new TreeNode<int>(arr2[0]);
	tree2->leftChild = new TreeNode<int>(arr2[1]);
	tree2->rightChild = new TreeNode<int>(arr2[2]);
	tree2->leftChild->leftChild = new TreeNode<int>(arr2[3]);
	tree2->leftChild->rightChild = new TreeNode<int>(arr2[4]);
	tree2->rightChild->leftChild = new TreeNode<int>(arr2[5]);
	tree2->rightChild->rightChild = new TreeNode<int>(arr2[6]);

	cout << isSymmetricTree(tree2) << " " << endl;//是对称树

	delete tree1;
	delete tree2;
	tree1 = nullptr;
	tree2 = nullptr;
}