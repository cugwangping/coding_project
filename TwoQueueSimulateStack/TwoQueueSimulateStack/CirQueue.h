#ifndef _CIRQUEUE_H_
#define _CIRQUEUE_H_
#include"Queue.h"
#include<assert.h>

template <class T>
class CirQueue: public Queue<T>
{
private:
	int front, rear;		//��ͷ�Ͷ�βָ��
	T *elements;		//���д������
	int maxSize;		//�����������
public:
	CirQueue(int sz );		//���캯��
	~CirQueue();		//��������
	bool EnQueue(T x);		//��Ԫ�ؽ�����
	bool DeQueue(T &x);		//�˳���ͷԪ��
	bool getFront(T &x);		//ȡ��ͷԪ��ֵ
	void makeEmpty(){ front = rear = 0; }		//�ÿգ���ͷָ��Ͷ�βָ��ָΪ0��
	bool IsEmpty()const{ return front == rear; }		//�ж϶����Ƿ�Ϊ��
	bool IsFull()const{ return (rear + 1) % maxSize == front; }			//�ж϶����Ƿ�Ϊ��
	int getSize()const{ return (rear - front + maxSize) % maxSize; }		//ȡ���е�Ԫ�ظ���
};

template <class T>
CirQueue<T>::CirQueue(int sz = 10) :front(0), rear(0), maxSize(sz)
{
	elements = new T[maxSize];
	assert(elements != NULL);		//���ԣ���̬�洢����ɹ����
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
		return false;		//�����������޷�������
	//���в�Ϊ������x���뵽���еĶ�β��
	elements[rear] = x;		//����x
	rear = (rear + 1) % maxSize;	//βָ���һ
	return true;
}

template <class T>
bool CirQueue<T>::DeQueue(T &x)
{
	if (IsEmpty())
		return false;		//����Ϊ�գ���Ԫ�ؿ��˶�
	//���в�Ϊ�գ��˳���ͷԪ��
	x = elements[front];		//ȡ����ͷ
	front = (front + 1) % maxSize;	//ͷָ���һ
	return true;
}

template <class T>
bool CirQueue<T>::getFront(T &x)
{
	if (IsEmpty())
		return false;		//�ն���
	x = elements[front];	//���ض�ͷԪ��
	return true;
}

#endif