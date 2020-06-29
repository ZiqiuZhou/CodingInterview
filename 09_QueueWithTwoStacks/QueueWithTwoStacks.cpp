#include<iostream>
#include<stack>
#include<queue>
using namespace std;

//用两个栈模拟队列，原则：pushStack向popStack倾倒元素时必须一次性倾倒光；
//popStack必须全部元素都出栈后pushStack才能再把元素倾倒进来
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
	if(popStack.empty()) //popStack为空，再要pop必须从pushStack拿数据
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


//用两个队列实现栈，元素先进入queue1, 再将除了最后一个入队的元素之外
//所有元素出队进入queue2，queue再pop仅存的元素；最后交换两队元素（将数据
//返回queue1
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


