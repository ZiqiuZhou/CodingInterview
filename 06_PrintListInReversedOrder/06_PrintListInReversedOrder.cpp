#include<iostream>
#include<stack>
using namespace std;

struct linkedNode {
	int value;
	linkedNode* next;
	linkedNode(int data) :next{nullptr} { value = data; }
};
//输入一个链表的头结点，从尾到头反过来打印出每个结点的值
//不能改变指针结构，所以采用栈
void printListReversedwithStack(linkedNode* head)
{
	stack<linkedNode*> nodesStack;
	linkedNode* pNode = head;
	while (pNode != nullptr) //链表元素压栈
	{
		nodesStack.push(pNode);
		pNode = pNode->next;
	}

	while (!nodesStack.empty())
	{
		linkedNode* printedNode = nodesStack.top();
		cout << printedNode->value << " ";
		nodesStack.pop();
	}
}

void printListReversedRecursive(linkedNode* head)
{
	if (head == nullptr)
		return;
	if(head->next != nullptr)
	{
		printListReversedRecursive(head->next);
	}
	cout << head->value << " ";
}

int main()
{
	int arr[] = {7, 9, 3, 1, 8};
	linkedNode* head = new linkedNode(arr[0]);
	head->next = new linkedNode(arr[1]);
	head->next->next = new linkedNode(arr[2]);
	head->next->next->next = new linkedNode(arr[3]);
	head->next->next->next->next = new linkedNode(arr[4]);
	printListReversedwithStack(head);
	cout << endl;
	printListReversedRecursive(head);
	linkedNode* ptr = nullptr;
	printListReversedRecursive(ptr);
}