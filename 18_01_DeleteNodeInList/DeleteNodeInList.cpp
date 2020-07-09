#include<iostream>
using namespace std;

// ��Ŀ���������������ͷָ���һ���ڵ�ָ�룬����һ��������O(1)ʱ��ɾ����
// �ڵ�(����֪��ǰ��ڵ�)��ǰ�᣺�������Ѿ�ȷ���иýڵ㣬��ûȷ�����軨������ʱ��ȷ��
template<typename Object>
struct linkedList
{
	Object value;
	linkedList<Object>* next;
	linkedList(Object ele) :next{ nullptr } { value = ele; }
	linkedList() { next = nullptr; }
};

template<typename Object>
void deleteNode(linkedList<Object>* head, linkedList<Object>* toBeDeleted)
{
	if (head == nullptr || toBeDeleted == nullptr)
	{
		cout << "Invalid input.";
		return;
	}
	
	if (head == toBeDeleted) // ��ɾ���Ľڵ���ͷ�ڵ�
	{
		delete head;
		head == nullptr;
		toBeDeleted = nullptr;
		cout << "deleted head node.";
	}

	// ��ɾ���ڵ���β�ڵ㣬 ֻ����O(n)���Ӷȱ����ҵ�ǰ��ڵ�
	else if (toBeDeleted->next == nullptr) 
	{
		linkedList<Object>* ptr = head;
		while (ptr->next != toBeDeleted)
		{
			ptr = ptr->next;
		}
		delete ptr->next;
		ptr->next = nullptr;
		toBeDeleted = nullptr;
		cout << "deleted tail node.";
	}

	else //��ɾ���ڵ�����ͨ�ڵ�
	{
		linkedList<Object>* ptr = toBeDeleted->next;
		//�������ڵ�����ݸ��Ƶ���ɾ���ڵ�
		toBeDeleted->value = ptr->value;
		toBeDeleted->next = ptr->next;
		delete ptr;
		ptr = nullptr;
		cout << "node deleted.";
	}
}

int main()
{
	int arr[] = { 7, 9, 1, 8, 5, 2, 5 };
	linkedList<int>* head1 = new linkedList<int>(arr[0]); //�޻�
	head1->next = new linkedList<int>(arr[1]);
	head1->next->next = new linkedList<int>(arr[2]);
	head1->next->next->next = new linkedList<int>(arr[3]);
	head1->next->next->next->next = new linkedList<int>(arr[4]);
	head1->next->next->next->next->next = new linkedList<int>(arr[5]);
	head1->next->next->next->next->next->next = new linkedList<int>(arr[6]);

	deleteNode(head1, head1); // ɾ��ͷ�ڵ�
	deleteNode(head1, head1->next->next); // ɾ����ͨ�ڵ�ڵ�
	linkedList<int>* tail = head1->next->next->next->next->next->next;
	deleteNode(head1, tail); // ɾ����ͨ�ڵ�ڵ�
	return 0;
}
