#ifndef _QUEUE_H_
#define _QUEUE_H_

template<class T>
class Queue
{
public:
	Queue(){}		//构造函数
	~Queue(){}		//析构函数
	virtual bool EnQueue(T x) = 0;		//进队列
	virtual bool DeQueue(T &x) = 0;		//出队列
	virtual bool getFront(T &x) = 0;		//取队头,元素由x返回
	virtual bool IsEmpty()const = 0;		//判断队空否。若为空，返回true
	virtual bool IsFull()const = 0;		//判断队满否。若为满，返回true
	virtual int getSize()const = 0;		//取队列当前元素的个数
};
#endif