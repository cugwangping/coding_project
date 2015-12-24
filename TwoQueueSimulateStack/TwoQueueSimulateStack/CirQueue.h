#ifndef _CIRQUEUE_H_
#define _CIRQUEUE_H_
#include"Queue.h"
#include<assert.h>

template <class T>
class CirQueue: public Queue<T>
{
private:
	int front, rear;		//队头和队尾指针
	T *elements;		//队列存放数组
	int maxSize;		//队列最大容量
public:
	CirQueue(int sz );		//构造函数
	~CirQueue();		//析构函数
	bool EnQueue(T x);		//新元素进队列
	bool DeQueue(T &x);		//退出队头元素
	bool getFront(T &x);		//取队头元素值
	void makeEmpty(){ front = rear = 0; }		//置空，队头指针和队尾指针指为0；
	bool IsEmpty()const{ return front == rear; }		//判断队列是否为空
	bool IsFull()const{ return (rear + 1) % maxSize == front; }			//判断队列是否为满
	int getSize()const{ return (rear - front + maxSize) % maxSize; }		//取队列的元素个数
};

template <class T>
CirQueue<T>::CirQueue(int sz = 10) :front(0), rear(0), maxSize(sz)
{
	elements = new T[maxSize];
	assert(elements != NULL);		//断言，动态存储分配成功与否
}

template <class T>
CirQueue<T>::~CirQueue()
{
	delete[]elements;
	elements = NULL;
}

template <class T>
bool CirQueue<T>::EnQueue(T x)
{
	if (IsFull())
		return false;		//队列已满，无法再入列
	//队列不为满，将x插入到队列的队尾。
	elements[rear] = x;		//存入x
	rear = (rear + 1) % maxSize;	//尾指针加一
	return true;
}

template <class T>
bool CirQueue<T>::DeQueue(T &x)
{
	if (IsEmpty())
		return false;		//队列为空，无元素可退队
	//队列不为空，退出队头元素
	x = elements[front];		//取出队头
	front = (front + 1) % maxSize;	//头指针加一
	return true;
}

template <class T>
bool CirQueue<T>::getFront(T &x)
{
	if (IsEmpty())
		return false;		//空队列
	x = elements[front];	//返回队头元素
	return true;
}

#endif