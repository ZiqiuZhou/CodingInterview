#include<iostream>
#include<queue>
#include<stack>
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

//题目：从上到下打印一棵树（本质上是宽度优先遍历）
template<typename Object>
void printTreeFromTopToBottom(TreeNode<Object>* root)
{
	if (root == nullptr)
		throw new exception("Invalid Input!");
	queue<TreeNode<Object>* > queueTreeNode;
	queueTreeNode.push(root);
	while (!queueTreeNode.empty())
	{
		TreeNode<Object>* poped = new TreeNode<Object>;
		poped = queueTreeNode.front();
		cout << poped->element << " ";
		queueTreeNode.pop();
		if (poped->leftChild != nullptr)
			queueTreeNode.push(poped->leftChild);
		if (poped->rightChild != nullptr)
			queueTreeNode.push(poped->rightChild);
	}
}

//从上到下打印树，但是每层要分行
template<typename Object>
void printTreeFromTopToBottomPerLine(TreeNode<Object>* root)
{
	if (root == nullptr)
		throw new exception("Invalid Input!");
	queue<TreeNode<Object>* > queueTreeNode;
	queueTreeNode.push(root);
	int nextLevel = 0; // 下一层需要打印的节点数量
	int toBePrinted = 1; //本层还有未打印的节点数量
	while (!queueTreeNode.empty())
	{
		TreeNode<Object>* poped = new TreeNode<Object>;
		poped = queueTreeNode.front();
		cout << poped->element << " ";
		toBePrinted--;
		queueTreeNode.pop();
		if (poped->leftChild != nullptr)
		{
			queueTreeNode.push(poped->leftChild);
			nextLevel++;
		}
		if (poped->rightChild != nullptr)
		{
			queueTreeNode.push(poped->rightChild);
			nextLevel++;
		}

		if (toBePrinted == 0)
		{
			cout << endl;
			toBePrinted = nextLevel;
			nextLevel = 0;
		}
	}
}

//之字型打印树：第一层从左往右，第二层从右往左，以此类推
template<typename Object>
void ZigZagPrintTreeFromTopToBottomPerLine(TreeNode<Object>* root)
{
	if (root == nullptr)
		throw new exception("Invalid Input!");
	queue<TreeNode<Object>* > queueTreeNode;
	stack<TreeNode<Object>* > tempSTack;
	queueTreeNode.push(root);
	int nextLevel = 0; // 下一层需要打印的节点数量
	int toBePrinted = 1; //本层还有未打印的节点数量
	int level = 0; //level为奇数层的节点入栈
	while (!queueTreeNode.empty())
	{
		TreeNode<Object>* poped = new TreeNode<Object>;
		poped = queueTreeNode.front();
		if (level % 2 != 0)
			tempSTack.push(poped);
		else
			cout << poped->element << " ";
		toBePrinted--;
		queueTreeNode.pop();
		if (poped->leftChild != nullptr)
		{
			queueTreeNode.push(poped->leftChild);
			nextLevel++;
		}
		if (poped->rightChild != nullptr)
		{
			queueTreeNode.push(poped->rightChild);
			nextLevel++;
		}

		if (toBePrinted == 0)
		{
			if(level % 2 == 0)
				cout << endl;
			if (level % 2 != 0)
			{
				while (!tempSTack.empty())
				{
					cout << tempSTack.top()->element << " ";
					tempSTack.pop();
				}
				cout << endl;
			}
			toBePrinted = nextLevel;
			nextLevel = 0;
			level++;
		}
	}
}

int main()
{
	int arr[] = { 2, 3, 1, 7, 3, 5, 0, 8, 9 };
	TreeNode<int>* tree1 = new TreeNode<int>(arr[0]);
	tree1->leftChild = new TreeNode<int>(arr[1]);
	tree1->rightChild = new TreeNode<int>(arr[2]);
	tree1->leftChild->leftChild = new TreeNode<int>(arr[3]);
	tree1->leftChild->rightChild = new TreeNode<int>(arr[4]);
	tree1->rightChild->leftChild = new TreeNode<int>(arr[5]);
	tree1->rightChild->rightChild = new TreeNode<int>(arr[6]);
	tree1->leftChild->rightChild->leftChild = new TreeNode<int>(arr[7]);
	tree1->leftChild->rightChild->rightChild = new TreeNode<int>(arr[8]);
	printTreeFromTopToBottom(tree1);
	cout << endl << endl;
	printTreeFromTopToBottomPerLine(tree1);
	cout << endl;
	ZigZagPrintTreeFromTopToBottomPerLine(tree1);
}