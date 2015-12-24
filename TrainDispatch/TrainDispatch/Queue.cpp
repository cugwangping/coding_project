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
	//����Ԫ�ز��뵽��β����,��Ϊ�¶�β
	if (front == NULL)
	{
		front = rear = new LinkNode(x);
		if (front == NULL)
			return false;	//���ռ����ʧ��
	}
	else
	{
		rear->link = new LinkNode(x);
		if (rear->link == NULL)
			return false;	//���ռ����ʧ��
		rear = rear->link;
	}
	return true;
}

bool Queue::DeQueue(int& x)
{
	if (front == NULL)
		return false;	//����Ϊ�գ��޷�ɾ��
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
		return false;	//����Ϊ�գ���Ԫ�ؿɷ���
	x = front->data;
	return true;
}

bool Queue::getRear(int& x)
{
	if (rear == NULL)
		return false;	//����Ϊ�գ���Ԫ�ؿɷ���
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