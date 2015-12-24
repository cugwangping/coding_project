#ifndef _QUEUE_H_
#define _QUEUE_H_

template <class T>
struct Node		//队列结点类
{
	T data;
	Node *link;		//结点指针，指向下一个结点
	Node(Node *ptr = NULL)
	{
		link = ptr;
	}
	Node(T element, Node *ptr = NULL)
	{
		data = element;
		link = ptr;
	}
};

template <class T>
class Queue
{
private:
	Node<T> *front, *rear;		//对头指针和队尾指针
public:
	Queue()		//构造函数，构造一个空队列
	{
		front = NULL;
		rear = NULL;
	}
	~Queue();		//析构函数
	bool IsEmpty(){ return (front == NULL) ? true : false; }
	bool EnQueue(const T x);		//将数据x插入队尾
	bool DeQueue(T &x);		//将队首元素返回
};

template <class T>
Queue<T>::~Queue()
{
	if (front != NULL)
	{
		Node<T> *ptr = NULL;
		while (front != NULL)
		{
			ptr = front;
			front = front->link;
			delete ptr;
		}
	}
}

template <class T>
bool Queue<T>::EnQueue(const T x)	//将数据x插入队尾
{
	if (front == NULL)
	{
		front = rear = new Node<T>(x);
		if (front == NULL)
			return false;
	}
	else
	{
		rear->link = new Node<T>(x);
		if (rear->link == NULL)
			return false;
		rear = rear->link;
	}
	return true;
}


template <class T>
bool Queue<T>::DeQueue(T& x)		//将队首元素返回
{
	if (front == NULL)
		return false;		//队列为空，没有元素可从队列中弹出
	x = front->data;
	Node<T> *ptr = front;
	front = front->link;
	delete ptr;
	return true;
}

#endif