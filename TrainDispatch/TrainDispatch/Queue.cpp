#include"stdafx.h"
#include"Queue.h"

Queue::~Queue()
{
	LinkNode *ptr;
	if (front != NULL)
	{
		ptr = front;
		front = front->link;
		delete ptr;
		ptr = NULL;
	}
}

bool Queue::EnQueue(int x)
{
	//将新元素插入到队尾后面,作为新队尾
	if (front == NULL)
	{
		front = rear = new LinkNode(x);
		if (front == NULL)
			return false;	//结点空间分配失败
	}
	else
	{
		rear->link = new LinkNode(x);
		if (rear->link == NULL)
			return false;	//结点空间分配失败
		rear = rear->link;
	}
	return true;
}

bool Queue::DeQueue(int& x)
{
	if (front == NULL)
		return false;	//队列为空，无法删除
	LinkNode *ptr;
	x = front->data;
	ptr = front;
	front = front->link;
	delete ptr;
	ptr = NULL;
	return true;
}

bool Queue::getFront(int& x)
{
	if (front == NULL)
		return false;	//队列为空，无元素可返回
	x = front->data;
	return true;
}

bool Queue::getRear(int& x)
{
	if (rear == NULL)
		return false;	//队列为空，无元素可返回
	x = rear->data;
	return true;
}

void Queue::printQueue()
{
	LinkNode *ptr;
	ptr = front;
	while (ptr != NULL)
	{
		cout << ptr->data << " ";
		ptr = ptr->link;
	}
	cout << endl;
}