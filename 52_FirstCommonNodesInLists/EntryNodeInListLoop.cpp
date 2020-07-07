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
�жϵ��������Ƿ��л���ʹ��һ��һ������ָ��
*/
template<typename Object>
linkedList<Object>* isNoLoop(linkedList<Object>* head)
{
	// ��������нڵ���Ŀ����3�����ܳ�����
	if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
		return nullptr;

	//����һ��һ������ָ��
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

	fast = head; // fastָ��ͷ�ڵ�
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

