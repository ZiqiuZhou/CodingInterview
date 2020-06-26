#include<iostream>
#include<stack>
using namespace std;

struct linkedNode {
	int value;
	linkedNode* next;
	linkedNode(int data) :next{nullptr} { value = data; }
};
//����һ�������ͷ��㣬��β��ͷ��������ӡ��ÿ������ֵ
//���ܸı�ָ��ṹ�����Բ���ջ
void printListReversedwithStack(linkedNode* head)
{
	stack<linkedNode*> nodesStack;
	linkedNode* pNode = head;
	while (pNode != nullptr) //����Ԫ��ѹջ
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