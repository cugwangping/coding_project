#ifndef _STACK_H_
#define _STACK_H_
#include"LinkNode.h"
#include<assert.h>

template<class T>
class Stack
{
private:
	LinkNode<T> *top;	//ջ��ָ�룬������ͷָ��
public:
	Stack(){ top = NULL; }		//���캯�����ÿ�ջ
	~Stack();	//��������
	void Push(const T& x);		//Ԫ��x��ջ
	bool Pop(T& x);		//��ջ
	bool getTop(T& x)const;		//��ȡջ��Ԫ��
	bool IsEmpty()const{ return (top == NULL) ? true : false; }		//�ж�ջ�Ƿ�Ϊ��
	int getSize()const;		//��ջ��Ԫ�صĸ���
	bool makeEmpty();		//��ջ�ÿ�
};

template<class T>
Stack<T>::~Stack()
{
	LinkNode<T> *p;
	while (top != NULL)		//�������ͷ�
	{
		p = top;
		top = top->link;
		delete p;
		p = NULL;
	}
}

template<class T>
void Stack<T>::Push(const T& x)
{
	top = new LinkNode<T>(x, top);	//�����µĽ�㣬����Ϊx
	assert(top != NULL);		//���ԣ������½��ʧ�ܾ��˳�
}

template<class T>
bool Stack<T>::Pop(T& x)
{
	if (IsEmpty())
		return false;		//��ջΪ�գ�����
	LinkNode<T> *p = top;	//�ݴ�ջ��Ԫ��
	top = top->link;
	x = p->data;		//�����˳�Ԫ��
	delete p;		//�ͷŽ��
	p = NULL;
	return true;
}

template<class T>
bool Stack<T>::getTop(T& x)const
{
	if (IsEmpty())	//ջ��
		return false;
	//ջ���գ�����ջ��Ԫ��
	x = top->data;
	return true;
}

template<class T>
int Stack<T>::getSize()const
{
	LinkNode<T> *p = top;
	int size = 0;
	while (top != NULL)
	{
		top = top->link;
		size++;
	}
	return size;
}

template<class T>
bool Stack<T>::makeEmpty()
{
	if (IsEmpty())
		return false;		//��ջΪ�գ�����
	LinkNode<T> *p = top;	//�ݴ�ջ��Ԫ��
	top = top->link;
	T x = p->data;		//�����˳�Ԫ��
	delete p;		//�ͷŽ��
	p = NULL;
	return true;
}

#endif