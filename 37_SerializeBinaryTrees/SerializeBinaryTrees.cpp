#include<iostream>
#include<queue>
#include<string>
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

//�����������л��ͷ����л�

//���л���ǰ�����
template<typename Object>
string serializeByPreOrder(TreeNode<Object>* pRoot, string& sequence)
{
	if (pRoot == nullptr)
	{
		sequence.append("$");
		return sequence;
	}

	sequence.append(std::to_string(pRoot->element));
	sequence = serializeByPreOrder(pRoot->leftChild, sequence);
	sequence = serializeByPreOrder(pRoot->rightChild, sequence);
	return sequence;
}

//������װ�����
queue<char>& pushSequenceIntoQueue(queue<char>& que, string& sequence)
{
	for (int i = 0; i < sequence.size(); ++i)
		que.push(sequence[i]);
	return que;
}

//�����л�
template<typename Object>
TreeNode<Object>* reconstructTree(queue<char>& que);

template<typename Object>
void preOrderTraversal(TreeNode<Object>* head);

template<typename Object>
void reconstructTree(string& sequence)
{
	if (sequence[0] == '$')
	{
		cout << "No Tree.";
		return ;
	}
	queue<char> que;
	que = pushSequenceIntoQueue(que, sequence);

	TreeNode<Object>* root = new TreeNode<Object>();
	root = reconstructTree<Object>(que);
	preOrderTraversal<Object>(root);
}

//�����л����ĺ���
template<typename Object>
TreeNode<Object>* reconstructTree(queue<char>& que)
{
	char value = que.front();
	que.pop();
	if (value == '$')
		return nullptr;

	Object element = value - '0';
	TreeNode<Object>* node = new TreeNode<Object>();
	node->element = element;
	node->leftChild = reconstructTree<Object>(que);
	node->rightChild = reconstructTree<Object>(que);
	return node;
}

//��ӡ���ڵ�
template<typename Object>
void preOrderTraversal(TreeNode<Object>* head)
{
	if (head == nullptr)
		return;
	if (head != nullptr)
	{
		cout << head->element << " ";
		preOrderTraversal(head->leftChild);
		preOrderTraversal(head->rightChild);
	}
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

	string seq;
	seq = serializeByPreOrder(tree1, seq);
	reconstructTree<int>(seq);
	return 0;
}