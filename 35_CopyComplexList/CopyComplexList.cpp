#include<iostream>
#include<unordered_map>
using namespace std;

template<typename Object>
struct linkedList
{
	Object element;
	linkedList<Object>* nextNode;
	linkedList<Object>* siblingNode;
	linkedList(Object ele) :nextNode{ nullptr }, siblingNode{ nullptr }{element = ele; }
	linkedList() :nextNode{ nullptr }, siblingNode{ nullptr }{}
	~linkedList()
	{
		delete nextNode;
		delete siblingNode;
		nextNode = nullptr;
		siblingNode = nullptr;
	}
};

//��Ŀ�����Ƹ����������Ȳ���siblingNode�������������������nextNodeָ������;
//����һ����siblingNode
template<typename Object>
linkedList<Object>* CopyComplexList(linkedList<Object>* pRoot)
{
	if (pRoot == nullptr) 
		return nullptr;

	//�Ƚ�ͷ�ڵ㸴�ƣ� ����֮��������ƺ����Ҳ���ͷ�ڵ�
	linkedList<Object>* pRootCopy = new linkedList<Object> ();
	pRootCopy->element = pRoot->element;
	pRootCopy->nextNode = pRoot->nextNode;
	pRootCopy->siblingNode = nullptr;

	//��ͨ���������ֻ��nextNodeָ������
	linkedList<Object>* ptr = pRoot->nextNode;
	while (ptr != nullptr)
	{
		linkedList<Object>* nodeCopy = new linkedList<Object> (ptr->element);
		nodeCopy->nextNode = ptr->nextNode;
		nodeCopy->siblingNode = nullptr;
		ptr = ptr->nextNode;
	}

	// ����siblingNode
	ptr = pRoot;
	linkedList<Object>* ptr2 = pRootCopy;
	while (ptr != nullptr)
	{
		ptr2->siblingNode = ptr->siblingNode;
		ptr = ptr->nextNode;
	}
	return pRootCopy;
}

//ʹ�ù�ϣ��洢ԭ�ڵ�͸��ƽڵ㣬Ȼ���ҵ�siblingNodeֻ��ҪO(1)
template<typename Object>
linkedList<Object>* CopyComplexList_2(linkedList<Object>* pRoot)
{
	if (pRoot == nullptr)
		return nullptr;

	unordered_map<linkedList<Object>*, linkedList<Object>*> hashTable;
	//�Ƚ�ͷ�ڵ㸴�ƣ� ����֮��������ƺ����Ҳ���ͷ�ڵ�
	linkedList<Object>* pRootCopy = new linkedList<Object>(pRoot->element);
	hashTable[pRoot] = pRootCopy;

	linkedList<Object>* ptr = pRoot->nextNode;
	while (ptr != nullptr)
	{
		linkedList<Object>* nodeCopy = new linkedList<Object>(ptr->element);
		hashTable[ptr] = nodeCopy; // ��ÿ���½ڵ�����ϣ��
		ptr = ptr->nextNode;
	}
	ptr = pRoot;
	while (ptr != nullptr)
	{
		hashTable[ptr]->nextNode = hashTable[ptr->nextNode];
		hashTable[ptr]->siblingNode = hashTable[ptr->siblingNode];
		ptr = ptr->nextNode;
	}
	return pRootCopy;
}

int main()
{
	int arr[] = { 1, 2, 3, 4 };
	linkedList<int>* head1 = new linkedList<int>(arr[0]); //�޻�
	head1->siblingNode = nullptr;
	head1->nextNode = new linkedList<int>(arr[1]);
	head1->nextNode->siblingNode = head1;
	head1->nextNode->nextNode = new linkedList<int>(arr[2]);
	head1->nextNode->nextNode->siblingNode = nullptr;
	head1->nextNode->nextNode->nextNode = new linkedList<int>(arr[3]);
	head1->nextNode->nextNode->nextNode->siblingNode = head1->nextNode->nextNode;

	linkedList<int>* head2 = CopyComplexList(head1);
	cout << head2->nextNode->element << endl;
	cout << head2->nextNode->siblingNode->element;
}
