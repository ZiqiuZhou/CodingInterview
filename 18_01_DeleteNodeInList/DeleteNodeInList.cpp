#include<iostream>
using namespace std;

// 题目：给定单向链表的头指针和一个节点指针，定义一个函数在O(1)时间删除该
// 节点(无须知道前项节点)。前提：链表中已经确认有该节点，如没确认则还需花费线性时间确认
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
	
	if (head == toBeDeleted) // 待删除的节点是头节点
	{
		delete head;
		head == nullptr;
		toBeDeleted = nullptr;
		cout << "deleted head node.";
	}

	// 待删除节点是尾节点， 只能以O(n)复杂度遍历找到前项节点
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

	else //待删除节点是普通节点
	{
		linkedList<Object>* ptr = toBeDeleted->next;
		//将后续节点的内容复制到待删除节点
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
	linkedList<int>* head1 = new linkedList<int>(arr[0]); //无环
	head1->next = new linkedList<int>(arr[1]);
	head1->next->next = new linkedList<int>(arr[2]);
	head1->next->next->next = new linkedList<int>(arr[3]);
	head1->next->next->next->next = new linkedList<int>(arr[4]);
	head1->next->next->next->next->next = new linkedList<int>(arr[5]);
	head1->next->next->next->next->next->next = new linkedList<int>(arr[6]);

	deleteNode(head1, head1); // 删除头节点
	deleteNode(head1, head1->next->next); // 删除普通节点节点
	linkedList<int>* tail = head1->next->next->next->next->next->next;
	deleteNode(head1, tail); // 删除普通节点节点
	return 0;
}
