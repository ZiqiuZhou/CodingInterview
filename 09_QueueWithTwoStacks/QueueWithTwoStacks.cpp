#include<iostream>
#include<stack>
#include<queue>
using namespace std;

//������ջģ����У�ԭ��pushStack��popStack�㵹Ԫ��ʱ����һ�����㵹�⣻
//popStack����ȫ��Ԫ�ض���ջ��pushStack�����ٰ�Ԫ���㵹����
template<typename T>
class QueueWithTwoStacks
{
private:
	stack<T> pushStack;
	stack<T> popStack;

public:
	QueueWithTwoStacks() {}
	~QueueWithTwoStacks() {}

	void pushTail(const T& node);
	T& popHead(); 
};

template<typename T> void QueueWithTwoStacks<T>::pushTail(const T& node)
{
	pushStack.push(node);
}

template<typename T> T& QueueWithTwoStacks<T>::popHead()
{
	if(popStack.empty()) //popStackΪ�գ���Ҫpop�����pushStack������
	{
		if (pushStack.empty())
			throw new exception("queue is empty.");
		while (!pushStack.empty())
		{
			T& pushedNode = pushStack.top();
			popStack.push(pushedNode);
			pushStack.pop();
		}
	}
	T& returnedNode = popStack.top();
	popStack.pop();
	return returnedNode;
}


//����������ʵ��ջ��Ԫ���Ƚ���queue1, �ٽ��������һ����ӵ�Ԫ��֮��
//����Ԫ�س��ӽ���queue2��queue��pop�����Ԫ�أ���󽻻�����Ԫ�أ�������
//����queue1
template<typename T>
class StackWithTwoQueues
{
private:
	queue<T> queue1;
	queue<T> queue2;

public:
	StackWithTwoQueues() {}
	~StackWithTwoQueues() {}

	void push(const T& node);
	T& pop();
};

template<typename T> void StackWithTwoQueues<T>::push(const T& node)
{
	queue1.push(node);
}

template<typename T> T& StackWithTwoQueues<T>::pop()
{
	if (queue1.empty())
		throw new exception("stack is empty.");

	while (queue1.size() > 1)
	{
		T& pushededNode = queue1.front();
		queue2.push(pushededNode);
		queue1.pop();
	}

	T& returnedNode = queue1.front();
	queue1.pop();
	std::swap(queue1, queue2);
	return returnedNode;
}



int main()
{
	QueueWithTwoStacks<int> myQueue;
	myQueue.pushTail(1);
	myQueue.pushTail(2);
	myQueue.pushTail(3);
	cout << myQueue.popHead() << " ";
	cout << myQueue.popHead() << " ";
	cout << myQueue.popHead() << " ";
	myQueue.pushTail(4);
	cout << myQueue.popHead() << " ";
	//cout << queue.popHead() << " ";
	cout << endl;
	cout << "-----------------------------" << endl;

	StackWithTwoQueues<int> myStack;
	for (size_t i = 0; i < 10; i++) {
		myStack.push(i);
	}
	for (size_t i = 0; i < 10; i++) {
		cout << myStack.pop() << " ";
	}
	return 0;
}


