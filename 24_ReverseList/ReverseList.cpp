#include<iostream>
using namespace std;

// ��Ŀ������һ������������һ�������ͷ��㣬��ת�����������ת�������
// ͷ���
template<typename Object>
struct linkedList
{
	Object element;
	linkedList<Object>* next;
	linkedList(Object value) :next{ nullptr } { element = value; }
	linkedList() : next{nullptr} {};
	~linkedList() { delete next; next = nullptr; }
};

template<typename Object>
linkedList<Object>* reverseList(linkedList<Object>* head)
{
	if (head == nullptr)
		return nullptr;
	if (head->next == nullptr) //����ֻ��һ���ڵ�
		return head;

	//��������ָ��
	linkedList<Object>* preNode = new linkedList<Object>();
	linkedList<Object>* currentNode = new linkedList<Object>();
	currentNode = head;
	
	while (currentNode->next != nullptr)
	{
		linkedList<Object>* nextNode = new linkedList<Object>();
		nextNode = currentNode->next; //�ݴ��̽ڵ�
		currentNode->next = preNode; //nextָ��ָ��ǰ��ڵ�
		preNode = currentNode;
		currentNode = nextNode;
	}
	return currentNode;
}

int main()
{
	int arr[] = { 7, 9, 1, 8, 5, 2, 5 };
	linkedList<int>* head1 = new linkedList<int>(arr[0]);
	head1->next = new linkedList<int>(arr[1]);
	head1->next->next = new linkedList<int>(arr[2]);
	head1->next->next->next = new linkedList<int>(arr[3]);
	head1->next->next->next->next = new linkedList<int>(arr[4]);
	head1->next->next->next->next->next = new linkedList<int>(arr[5]);
	head1->next->next->next->next->next->next = new linkedList<int>(arr[6]);

	cout << reverseList(head1)->element << endl;

	linkedList<int>* head2 = new linkedList<int>(arr[0]); //����ֻ��һ���ڵ�
	cout << reverseList(head2)->element << endl;
	return 0;
}