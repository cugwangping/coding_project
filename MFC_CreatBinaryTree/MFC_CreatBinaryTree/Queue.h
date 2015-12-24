#ifndef _QUEUE_H_
#define _QUEUE_H_
#include<iostream>
using namespace std;

template <class T, class E, class K>
struct LinkNode
{
	T data1;
	E data2; 
	K data3;
	LinkNode<T, E, K> *link;
	LinkNode(LinkNode<T, E, K> *ptr = NULL){ link = ptr; }
	LinkNode(const T &element1, const E &element2, const K &element3, LinkNode<T, E, K> *ptr = NULL)
	{
		data1 = element1;
		data2 = element2;
		data3 = element3;
		link = ptr;
	}
};

template <class T, class E, class K>
class Queue
{
private:
	LinkNode<T, E, K> *front, *rear;		//队头指针，队尾指针
public:
	Queue() :front(NULL), rear(NULL){}		//构造函数
	~Queue();		//析构函数
	bool IsEmpty(){ return front == NULL; }
	bool EnQueue(T x1, E x2, K x3);
	bool DeQueue(T& x1, E& x2, K& x3);
};

template <class T, class E, class K>
Queue<T, E, K>::~Queue()
{
	LinkNode<T, E, K> *ptr;
	if (front != NULL)
	{
		ptr = front;
		front = front->link;
		delete ptr;
		ptr = NULL;
	}
}

template <class T, class E, class K>
bool Queue<T, E, K>::EnQueue(T x1, E x2, K x3)
{
	//将新元素插入到队尾后面,作为新队尾
	if (front == NULL)
	{
		front = rear = new LinkNode<T, E, K>(x1, x2, x3);
		if (front == NULL)
			return false;	//结点空间分配失败
	}
	else
	{
		rear->link = new LinkNode<T, E, K>(x1, x2, x3);
		if (rear->link == NULL)
			return false;	//结点空间分配失败
		rear = rear->link;
	}
	return true;
}

template <class T, class E, class K>
bool Queue<T, E, K>::DeQueue(T& x1, E& x2, K& x3)
{
	if (front == NULL)
		return false;	//队列为空，无法删除
	LinkNode<T, E, K> *ptr;
	x1 = front->data1;
	x2 = front->data2;
	x3 = front->data3;
	ptr = front;
	front = front->link;
	delete ptr;
	ptr = NULL;
	return true;
}


#endif
