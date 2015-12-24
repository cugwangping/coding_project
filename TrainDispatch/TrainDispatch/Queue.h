#ifndef _QUEUE_H_
#define _QUEUE_H_
#include<iostream>
using namespace std;

struct LinkNode
{
	int data;
	LinkNode *link;
	LinkNode(LinkNode *ptr = NULL){ link = ptr; }
	LinkNode(const int &element, LinkNode *ptr=NULL)
	{
		data = element;
		link = ptr;
	}
};

class Queue
{
private:
	LinkNode *front, *rear;		//��ͷָ�룬��βָ��
public:
	Queue() :front(NULL), rear(NULL){}		//���캯��
	~Queue();		//��������
	bool IsEmpty(){ return front == NULL; }
	bool EnQueue(int x);
	bool DeQueue(int& x);
	bool getFront(int& x);
	bool getRear(int& x);
	void printQueue();		//�������Ԫ��
};
#endif

