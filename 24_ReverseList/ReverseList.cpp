#include<iostream>
using namespace std;

// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的
// 头结点
template<typename Object>
struct linkedList
{
	Object element;
	linkedList<Object>* next;
	linkedList(Object value) :next{ nullptr } { element = value; }
	linkedList() : next{nullptr} {};
	~linkedList() { delete next; next = nullptr; }
};

template<typename Object>
linkedList<Object>* reverseList(linkedList<Object>* head)
{
	if (head == nullptr)
		return nullptr;
	if (head->next == nullptr) //链表只有一个节点
		return head;

	//定义三个指针
	linkedList<Object>* preNode = new linkedList<Object>();
	linkedList<Object>* currentNode = new linkedList<Object>();
	currentNode = head;
	
	while (currentNode->next != nullptr)
	{
		linkedList<Object>* nextNode = new linkedList<Object>();
		nextNode = currentNode->next; //暂存后继节点
		currentNode->next = preNode; //next指针指向前项节点
		preNode = currentNode;
		currentNode = nextNode;
	}
	return currentNode;
}

int main()
{
	int arr[] = { 7, 9, 1, 8, 5, 2, 5 };
	linkedList<int>* head1 = new linkedList<int>(arr[0]);
	head1->next = new linkedList<int>(arr[1]);
	head1->next->next = new linkedList<int>(arr[2]);
	head1->next->next->next = new linkedList<int>(arr[3]);
	head1->next->next->next->next = new linkedList<int>(arr[4]);
	head1->next->next->next->next->next = new linkedList<int>(arr[5]);
	head1->next->next->next->next->next->next = new linkedList<int>(arr[6]);

	cout << reverseList(head1)->element << endl;

	linkedList<int>* head2 = new linkedList<int>(arr[0]); //链表只有一个节点
	cout << reverseList(head2)->element << endl;
	return 0;
}