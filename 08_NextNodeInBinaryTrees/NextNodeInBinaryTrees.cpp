#include<iostream>
using namespace std;

struct TreeNode
{
	int element;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent; //ÿ���ڵ�����һ�����ڵ�

	TreeNode(int x) :left{ nullptr }, right{ nullptr }, parent{nullptr}
	{
		element = x;
	}
	TreeNode() {}
};

/*
�������Ѱ�Һ�̽ڵ㣺1.�����ǰ�ڵ�����������������������ĵ�һ���ڵ㣨����ڵ�);
����ý�û�����������鿴�ýڵ��Ƿ����丸�ڵ�����ӣ�������Ϊ���ڵ㣻���ǣ�
��ǰ�ڵ�ת�������ڵ㣬�����Ҹ��ڵ㣬ֱ����ǰ�ڵ����丸�ڵ�����ӣ�ԭʼ�ڵ�ĺ��
��Ϊ��ǰ�ڵ�ĸ��ڵ�
ͷ�ڵ�ĸ��׽ڵ���nullptr
*/
TreeNode* getSuccessorNode(TreeNode* current)
{
	if (current == nullptr)
		return nullptr;

	if (current->right != nullptr)
	{
		current = current->right;
		while (current->left != nullptr)
			current = current->left;
		return current;
	}

	else if (current->right == nullptr)
	{
		TreeNode* parent = current->parent;
		while (parent != nullptr && parent->left != current)
		{
			current = current->parent;
			parent = current->parent;
		}
		return parent;
	}
}

int main()
{
	TreeNode* head = new TreeNode(6);
	head->parent = nullptr;
	head->left = new TreeNode(3);
	head->left->parent = head;
	head->left->left = new TreeNode(1);
	head->left->left->parent = head->left;
	head->left->left->right = new TreeNode(2);
	head->left->left->right->parent = head->left->left;
	head->left->right = new TreeNode(4);
	head->left->right->parent = head->left;
	head->left->right->right = new TreeNode(5);
	head->left->right->right->parent = head->left->right;
	head->right = new TreeNode(9);
	head->right->parent = head;
	head->right->left = new TreeNode(8);
	head->right->left->parent = head->right;
	head->right->left->left = new TreeNode(7);
	head->right->left->left->parent = head->right->left;
	head->right->right = new TreeNode(10);
	head->right->right->parent = head->right;

	TreeNode* test1 = head->left->left;
	cout << getSuccessorNode(test1)->element << " ";
	cout << endl;
	TreeNode* test2 = head->right;
	cout << getSuccessorNode(test2)->element << " ";
	cout << endl;
	return 0;
}