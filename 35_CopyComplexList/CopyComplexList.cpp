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

//题目，复制该链表：可以先不管siblingNode，先深拷贝基本单链表，用nextNode指针相连;
//再逐一复制siblingNode
template<typename Object>
linkedList<Object>* CopyComplexList(linkedList<Object>* pRoot)
{
	if (pRoot == nullptr) 
		return nullptr;

	//先将头节点复制， 否则之后遍历复制后不用找不到头节点
	linkedList<Object>* pRootCopy = new linkedList<Object> ();
	pRootCopy->element = pRoot->element;
	pRootCopy->nextNode = pRoot->nextNode;
	pRootCopy->siblingNode = nullptr;

	//普通链表深拷贝，只用nextNode指针连接
	linkedList<Object>* ptr = pRoot->nextNode;
	while (ptr != nullptr)
	{
		linkedList<Object>* nodeCopy = new linkedList<Object> (ptr->element);
		nodeCopy->nextNode = ptr->nextNode;
		nodeCopy->siblingNode = nullptr;
		ptr = ptr->nextNode;
	}

	// 复制siblingNode
	ptr = pRoot;
	linkedList<Object>* ptr2 = pRootCopy;
	while (ptr != nullptr)
	{
		ptr2->siblingNode = ptr->siblingNode;
		ptr = ptr->nextNode;
	}
	return pRootCopy;
}

//使用哈希表存储原节点和复制节点，然后找到siblingNode只需要O(1)
template<typename Object>
linkedList<Object>* CopyComplexList_2(linkedList<Object>* pRoot)
{
	if (pRoot == nullptr)
		return nullptr;

	unordered_map<linkedList<Object>*, linkedList<Object>*> hashTable;
	//先将头节点复制， 否则之后遍历复制后不用找不到头节点
	linkedList<Object>* pRootCopy = new linkedList<Object>(pRoot->element);
	hashTable[pRoot] = pRootCopy;

	linkedList<Object>* ptr = pRoot->nextNode;
	while (ptr != nullptr)
	{
		linkedList<Object>* nodeCopy = new linkedList<Object>(ptr->element);
		hashTable[ptr] = nodeCopy; // 将每个新节点存入哈希表
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
	linkedList<int>* head1 = new linkedList<int>(arr[0]); //无环
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
