#ifndef _QUEUE_H_
#define _QUEUE_H_

template <class T>
struct Node		//���н����
{
	T data;
	Node *link;		//���ָ�룬ָ����һ�����
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
	Node<T> *front, *rear;		//��ͷָ��Ͷ�βָ��
public:
	Queue()		//���캯��������һ���ն���
	{
		front = NULL;
		rear = NULL;
	}
	~Queue();		//��������
	bool IsEmpty(){ return (front == NULL) ? true : false; }
	bool EnQueue(const T x);		//������x�����β
	bool DeQueue(T &x);		//������Ԫ�ط���
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
bool Queue<T>::EnQueue(const T x)	//������x�����β
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
bool Queue<T>::DeQueue(T& x)		//������Ԫ�ط���
{
	if (front == NULL)
		return false;		//����Ϊ�գ�û��Ԫ�ؿɴӶ����е���
	x = front->data;
	Node<T> *ptr = front;
	front = front->link;
	delete ptr;
	return true;
}

#endif