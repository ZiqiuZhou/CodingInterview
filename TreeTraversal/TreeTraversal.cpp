#include <iostream>
#include<stack>
using namespace std;

struct TreeNode {
	int element;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int value) :left{ nullptr }, right{ nullptr }
	{
		element = value;
	}
	TreeNode() {}
};

//ǰ������ݹ�ʵ��
void preOrderTraversal(TreeNode* head)
{
	if (head == nullptr)
		return;
	if (head != nullptr)
	{
		cout << head->element << " ";
		preOrderTraversal(head->left);
		preOrderTraversal(head->right);
	}
}

//��������ݹ�ʵ��
void inOrderTraversal(TreeNode* head)
{
	if (head == nullptr)
		return;
	if (head != nullptr)
	{
		inOrderTraversal(head->left);
		cout << head->element << " ";
		inOrderTraversal(head->right);
	}
}

//��������ݹ�ʵ��
void posOrderTraversal(TreeNode* head)
{
	if (head == nullptr)
		return;
	if (head != nullptr)
	{
		posOrderTraversal(head->left);
		posOrderTraversal(head->right);
		cout << head->element << " ";
	}
}

//ǰ������ǵݹ�ʵ��
void preOrderTraversalStack(TreeNode* head)
{
	if (head == nullptr)
		return;
	stack<TreeNode*> stack1;
	stack1.push(head);
	while (!stack1.empty())
	{
		TreeNode* printedNode = stack1.top();
		cout << printedNode->element << " ";
		stack1.pop();
		if (printedNode->right != nullptr)
			stack1.push(printedNode->right);
		if (printedNode->left != nullptr)
			stack1.push(printedNode->left);
	}
}

//��������ǵݹ�ʵ��
void inOrderTraversalStack(TreeNode* head)
{
	if (head == nullptr)
		return;
	stack<TreeNode*> stack1;
	TreeNode* currentNode = head;
	while (!stack1.empty() || currentNode != nullptr)
	{
		if (currentNode != nullptr)
		{
			stack1.push(currentNode);
			currentNode = currentNode->left;
		}
		else
		{
			TreeNode* printedNode = stack1.top();
			cout << printedNode->element << " ";
			stack1.pop();
			currentNode = printedNode->right;
		}
	}
}

//��������ǵݹ�ʵ��
void posOrderTraversalStack(TreeNode* head)
{
	if (head == nullptr)
		return;
	stack<TreeNode*> stack1;
	stack<TreeNode*> stack2;
	stack1.push(head);
	while (!stack1.empty())
	{
		TreeNode* popedNode = stack1.top();
		stack1.pop();
		stack2.push(popedNode);
		if (popedNode->left != nullptr)
			stack1.push(popedNode->left);
		if (popedNode->right != nullptr)
			stack1.push(popedNode->right);
	}

	while (!stack2.empty())
	{
		cout << stack2.top()->element << " ";
		stack2.pop();
	}
}

int main()
{
	TreeNode* head = new TreeNode(5);
	head->left = new TreeNode(3);
	head->right = new TreeNode(8);
	head->left->left = new TreeNode(2);
	head->left->right = new TreeNode(4);
	head->left->left->left = new TreeNode(1);
	head->right->left = new TreeNode(7);
	head->right->left->left = new TreeNode(6);
	head->right->right = new TreeNode(10);
	head->right->right->left = new TreeNode(9);
	head->right->right->right = new TreeNode(11);

	cout << "ǰ�����" << endl;
	preOrderTraversal(head);
	cout << endl;
	preOrderTraversalStack(head);
	cout << endl;
	cout << "�������" << endl;
	inOrderTraversal(head);
	cout << endl;
	inOrderTraversalStack(head);
	cout << endl;
	cout << "�������" << endl;
	posOrderTraversal(head);
	cout << endl;
	posOrderTraversalStack(head);
	return 0;
}