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
	LinkNode *front, *rear;		//队头指针，队尾指针
public:
	Queue() :front(NULL), rear(NULL){}		//构造函数
	~Queue();		//析构函数
	bool IsEmpty(){ return front == NULL; }
	bool EnQueue(int x);
	bool DeQueue(int& x);
	bool getFront(int& x);
	bool getRear(int& x);
	void printQueue();		//输出队列元素
};
#endif

