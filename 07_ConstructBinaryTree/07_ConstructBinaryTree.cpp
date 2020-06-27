#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
	int element;
	TreeNode* leftChild;
	TreeNode* rightChild;
	TreeNode(int elem):leftChild{ nullptr }, rightChild{nullptr}
	{
		element = elem;
	}
	~TreeNode() { delete leftChild; delete rightChild; }
};

TreeNode* constructCore(vector<int>& preOrderArr, vector<int>& inOrderArr,
			int preOrderLeft, int preOrderRight, int inOrderLeft, int inOrderRight);

//�����������飨ǰ�������������������������ؽ�������������ͷ�ڵ�
//����û���ظ�����
TreeNode* constructTree(vector<int>& arr1, vector<int>& arr2)
{
	//��������
	if (arr1.size() == 0 || arr2.size() == 0)
		return nullptr;

	if (arr1.size() != arr2.size())
		return nullptr;

	int preOrderRight = arr1.size() - 1;
	int inOrderRight = arr2.size() - 1;
	TreeNode* root = constructCore(arr1, arr2, 0, preOrderRight, 0, inOrderRight);
	return root;
}

TreeNode* constructCore(vector<int>& preOrderArr, vector<int>& inOrderArr,
	int preOrderLeft, int preOrderRight, int inOrderLeft, int inOrderRight)
{
	//�������ڵ㣺ǰ�����������Ԫ��Ϊ���ڵ�
	TreeNode* head = new TreeNode(preOrderArr[preOrderLeft]);

	//��������ֻ��һ��Ԫ��(������Ϊ1)���ݹ��˳�����
	if (preOrderLeft == preOrderRight && inOrderLeft == inOrderRight)
	{
		if (preOrderArr[preOrderLeft] == inOrderArr[inOrderLeft])
		{
			return head;
		}
		else
			return nullptr; //��������
	}

	//����������������ҵ����ڵ�λ��
	int i = inOrderLeft;
	for (i; i <= inOrderRight; ++i)
	{
		if (inOrderArr[i] == preOrderArr[preOrderLeft])
			break;
	}
	if (i > inOrderRight) return nullptr; //������û�ҵ���ӦԪ�أ���������
	
	
	int lengthOfLeftTree = i - inOrderLeft; //����������
	if (lengthOfLeftTree > 0) //��������������� ����������
	{
		head->leftChild = constructCore(preOrderArr, inOrderArr,
			preOrderLeft + 1, preOrderLeft + lengthOfLeftTree, //ǰ���������������������Χ
			inOrderLeft, i - 1);//�����������������������Χ
	}
 
	int lengthOfRightTree = inOrderRight - i; //����������
	if (lengthOfRightTree > 0)
	{
		head->rightChild = constructCore(preOrderArr, inOrderArr,
			preOrderLeft + lengthOfLeftTree + 1, preOrderRight, //ǰ���������������������Χ
			i + 1, inOrderRight);//�����������������������Χ
	}
	return head;
}

int main()
{
	vector<int> arr1 = {5, 3, 2, 1, 4, 8, 7, 6, 10, 9, 11}; //ǰ���������
	vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; //�����������
	TreeNode* root = constructTree(arr1, arr2);
	cout << root->element << endl;

	vector<int> arr3;
	vector<int> arr4;
	root = constructTree(arr3, arr4);
	cout << "NULL"<< endl;
	//������Ԫ�ز�ƥ��
	vector<int> arr5 = { 5, 12, 2, 1, 4, 8, 7, 6, 10, 9, 11 };
	vector<int> arr6 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	root = constructTree(arr3, arr4);
	cout << "Invalid Input." << endl;
}