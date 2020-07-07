#include<iostream>
using namespace std;

template<typename Object>
struct linkedList
{
	Object value;
	linkedList<Object>* next;
	linkedList(Object ele) :next{ nullptr } { value = ele; }
	linkedList() { next = nullptr; }
	~linkedList() {}
};

/*
判断单向链表是否有环：使用一快一慢两个指针
*/
template<typename Object>
linkedList<Object>* isNoLoop(linkedList<Object>* head)
{
	// 如果链表中节点数目不足3不可能成链表
	if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
		return nullptr;

	//定义一快一慢两个指针
	linkedList<Object>* fast = new linkedList<Object>;
	fast = head->next->next;
	linkedList<Object>* slow = new linkedList<Object>;
	slow = head->next;

	while (fast != slow)
	{
		if (fast->next == nullptr || fast->next->next == nullptr)
			return nullptr;
		fast = fast->next->next;
		slow = slow->next;
	}

	fast = head; // fast指回头节点
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

