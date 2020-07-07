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

int main()
{
	int arr[] = {7, 9, 1, 8, 5, 2, 5};
	linkedList<int>* head1 = new linkedList<int>(arr[0]); //�޻�
	head1->next = new linkedList<int>(arr[1]);
	head1->next->next = new linkedList<int>(arr[2]);
	head1->next->next->next = new linkedList<int>(arr[3]);
	head1->next->next->next->next = new linkedList<int>(arr[4]);
	head1->next->next->next->next->next = new linkedList<int>(arr[5]);
	head1->next->next->next->next->next->next = new linkedList<int>(arr[6]);
	cout << isNoLoop(head1) << endl;

	linkedList<int>* head2 = new linkedList<int>(arr[0]); // �л�
	head2->next = new linkedList<int>(arr[1]);
	head2->next->next = new linkedList<int>(arr[2]);
	head2->next->next->next = new linkedList<int>(arr[3]);
	head2->next->next->next->next = new linkedList<int>(arr[4]);
	head2->next->next->next->next->next = new linkedList<int>(arr[5]);
	head2->next->next->next->next->next->next = head2->next->next;
	cout << isNoLoop(head2)->value << endl;

	
	return 0;
}