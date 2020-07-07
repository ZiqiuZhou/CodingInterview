#include<iostream>
#include"EntryNodeInListLoop.cpp"
using namespace std;

// 题目：输入两个链表，找出它们的第一个公共结点。
template<typename Object>
linkedList<Object>* getIntersection(linkedList<Object>* head1, linkedList<Object>* head2)
{
	if (head1 == nullptr || head2 == nullptr)
		return nullptr;
	if (isNoLoop(head1) || isNoLoop(head2)) //两链表存在有环链表
		return nullptr;

	linkedList<Object>* ptrList1 = new linkedList<Object>();
	ptrList1 = head1;
	linkedList<Object>* ptrList2 = new linkedList<Object>();
	ptrList2 = head2;
	//计算两链表的长度
	int lengthList1 = 1; int lengthList2 = 1;
	while (ptrList1->next != nullptr)
	{
		ptrList1 = ptrList1->next;
		lengthList1++;
	}
	while (ptrList2->next != nullptr)
	{
		ptrList2 = ptrList2->next;
		lengthList2++;
	}

	ptrList1 = head1;
	ptrList2 = head2;
	if (lengthList1 >= lengthList2)
	{
		for (int i = 0; i < lengthList1 - lengthList2; ++i)
			ptrList1 = ptrList1->next;
		while (ptrList1 != ptrList2)
		{
			ptrList1 = ptrList1->next;
			ptrList2 = ptrList2->next;
		}
	}
	else if (lengthList1 < lengthList2)
	{
		for (int i = 0; i < lengthList2 - lengthList1; ++i)
			ptrList2 = ptrList2->next;
		while (ptrList1 != ptrList2)
		{
			ptrList1 = ptrList1->next;
			ptrList2 = ptrList2->next;
		}
	}
	return ptrList1;
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

	linkedList<int>* head2 = new linkedList<int>(arr[0]); // 有环
	head2->next = new linkedList<int>(arr[1]);
	head2->next->next = new linkedList<int>(arr[2]);
	head2->next->next->next = new linkedList<int>(arr[3]);
	head2->next->next->next->next = head1->next->next;
	cout << getIntersection(head1, head2)->value << endl;


	return 0;
}