#include<iostream>
using namespace std;


template<typename Object>
struct linkedList
{
	int element;
	linkedList<Object>* next;
	linkedList(Object value) :next(nullptr) { element = value; }
	linkedList() { element = 0; next = nullptr; }
	//~linkedList() { delete next; }
};

template<typename Object>
int computeLength(linkedList<Object>* head);

template<typename Object>
linkedList<Object>* findKthNodeFromEnd(linkedList<Object>* head, int k)
{
	if (head == nullptr || k < 1) //输入空指针或无效输入k
	{
		cout << "invalid input." << endl;
		return nullptr;
	}

	if (computeLength(head) < k) // 当链表长度不足k时
		return nullptr;

	linkedList<Object>* fastPtr = new linkedList<Object>();
	linkedList<Object>* slowPtr = new linkedList<Object>();
	fastPtr = head;
	slowPtr = head;
	for (int i = 1; i < k; ++i) // 前进k-1步
		fastPtr = fastPtr->next;
	while (fastPtr->next != nullptr)
	{
		fastPtr = fastPtr->next;
		slowPtr = slowPtr->next;
	}
	linkedList<Object>* result = new linkedList<Object>();
	result->element = slowPtr->element;
	result->next = slowPtr->next;
	delete fastPtr;
	delete slowPtr;
	fastPtr = nullptr;
	slowPtr = nullptr;
	return result;
}

template<typename Object>
int computeLength(linkedList<Object>* head)
{
	int length = 0; //记录链表长度
	linkedList<Object>* ptr = new linkedList<Object>();
	ptr = head;
	while (ptr != nullptr)
	{
		length++;
		ptr = ptr->next;
	}
	delete ptr;
	ptr = nullptr;
	return length;
}

int main()
{
	int arr[] = { 7, 9, 1, 8, 5, 2, 5 };
	linkedList<int>* head1 = new linkedList<int>(arr[0]); //无环
	head1->next = new linkedList<int>(arr[1]);
	head1->next->next = new linkedList<int>(arr[2]);
	head1->next->next->next = new linkedList<int>(arr[3]);
	head1->next->next->next->next = new linkedList<int>(arr[4]);
	head1->next->next->next->next->next = new linkedList<int>(arr[5]);
	head1->next->next->next->next->next->next = new linkedList<int>(arr[6]);
	cout << findKthNodeFromEnd(head1, 0) << endl; //无效输入
	cout << findKthNodeFromEnd(head1, 3)->element << endl; 
	return 0;
}