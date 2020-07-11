#include<iostream>
using namespace std;

template<typename Object>
struct linkedList
{
	Object element;
	linkedList<Object>* next;
	linkedList(Object value) : next{ nullptr } { element = value; }
	linkedList() :next{ nullptr } {}
	~linkedList() { delete next;  next = nullptr; }
};

//题目：对两个递增排序链表进行合并，生成第三个链表
template<typename Object>
void printMergedList(linkedList<Object>* list);


template<typename Object>
linkedList<Object>* mergeSortedLink(linkedList<Object>* list1, linkedList<Object>* list2)
{
	if (list1 == nullptr || list2 == nullptr) //如果存在输入链表为空
	{
		return list1 == nullptr ? list2 : list1;
	}

	linkedList<Object>* ptrList1 = new linkedList<Object>();
	linkedList<Object>* ptrList2 = new linkedList<Object>();
	ptrList1 = list1;
	ptrList2 = list2;
	linkedList<Object>* mergedList = new linkedList<Object>();
	//先确定合并链表的头节点
	mergedList = ptrList1->element <= ptrList2->element ? ptrList1 : ptrList2;
	ptrList1 = ptrList1->next;
	ptrList2 = ptrList2->next;
	
	linkedList<Object>* currentPos = new linkedList<Object>();
	currentPos = mergedList;
	while (ptrList1 != nullptr &&  ptrList2 != nullptr)
	{
		if (ptrList1->element <= ptrList2->element) //链表1节点小于链表2节点
		{
			currentPos->next = ptrList1;
			currentPos = currentPos->next;
			ptrList1 = ptrList1->next;
		}
		else
		{
			currentPos->next = ptrList2;
			currentPos = currentPos->next;
			ptrList2 = ptrList2->next;
		}
	}

	while (ptrList1 != nullptr) //如果链表1还有剩余
	{
		currentPos->next = ptrList1;
		currentPos = currentPos->next;
		ptrList1 = ptrList1->next;
	}

	while (ptrList2 != nullptr) //如果链表1还有剩余
	{
		currentPos->next = ptrList2;
		currentPos = currentPos->next;
		ptrList2 = ptrList2->next;
	}
	currentPos->next = nullptr;
	return mergedList;
}

template<typename Object>
void printMergedList(linkedList<Object>* list)
{
	while (list != nullptr)
	{
		cout << list->element << " ";
		list = list->next;
	}
	cout << endl;
}

int main()
{
	int arr[] = { 1, 2, 5, 5, 7, 8, 9 };
	linkedList<int>* head1 = new linkedList<int>(arr[0]);
	head1->next = new linkedList<int>(arr[1]);
	head1->next->next = new linkedList<int>(arr[2]);
	head1->next->next->next = new linkedList<int>(arr[3]);
	head1->next->next->next->next = new linkedList<int>(arr[4]);
	head1->next->next->next->next->next = new linkedList<int>(arr[5]);
	head1->next->next->next->next->next->next = new linkedList<int>(arr[6]);
	
	int arr2[] = { 1, 3, 4, 7, 9, 12 };
	linkedList<int>* head2 = new linkedList<int>(arr2[0]);
	head2->next = new linkedList<int>(arr2[1]);
	head2->next->next = new linkedList<int>(arr2[2]);
	head2->next->next->next = new linkedList<int>(arr2[3]);
	head2->next->next->next->next = new linkedList<int>(arr2[4]);
	head2->next->next->next->next->next = new linkedList<int>(arr2[5]);

	linkedList<int>* head3 = nullptr;
	linkedList<int>* result2 = mergeSortedLink<int>(head1, head3);
	printMergedList(result2);

	linkedList<int>* result = mergeSortedLink<int>(head1, head2);
	printMergedList(result);
	return 0;
}