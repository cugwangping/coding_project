#ifndef _STACK_H_
#define _STACK_H_
#include"CirQueue.h"

template <class T>
class Stack
{
private:
	CirQueue<T> CQ1, CQ2;		//����CQ1��ջ����ѹ����˳�Ԫ�صĲ���������CQ2��Ϊ��������,�������еĴ�С���
public:
	Stack(int sz):CQ1(sz),CQ2(sz){}		//���캯��
	~Stack(){}		//��������
	bool Push(T &x);		//��xѹ��ջ
	bool Pop(T &x);		//��ջ
	bool getTop(T &x)const;	//ȡջ��
	bool IsEmpty()const;		//�ж�ջ�Ƿ�Ϊ��
	bool IsFull()const;		//�ж�ջ�Ƿ�Ϊ��
	int getSize()const;		//ȡջ�ĵ�ǰԪ�ظ���
};

template <class T>
bool Stack<T>::Push(T &x)
{
	if (IsFull())
		return false;		//ջ�����޷��ٽ���ѹջ����
	//ջδ������xѹ��ջ
	if ((CQ1.IsEmpty() && CQ2.IsEmpty()) || (CQ1.IsEmpty() == false && CQ2.IsEmpty()))
		CQ1.EnQueue(x);
	else
		CQ2.EnQueue(x);
	return true;
}

template <class T>
bool Stack<T>::Pop(T &x)
{
	if (IsEmpty())
		return false;		//ջ�գ�û��Ԫ�ؿ���ջ
	//ջ��Ϊ�գ���ջ��Ԫ����ջ
	T Element=0;
	int size = getSize();
	//ջ��Ԫ�ظ�������1��
	//ջ��Ԫ��λ��CQ1�Ķ�β������βǰ���Ԫ��ȫ��ѹ��CQ2���л��档
	if (CQ1.IsEmpty())
	{
		while (size > 1)
		{
			CQ2.DeQueue(Element);
			CQ1.EnQueue(Element);
			size--;
		}
		//ջ��Ԫ��ֻ��1����ֱ����ջ
		CQ2.DeQueue(Element);
		x = Element;
	}
	else
	{
		while (size > 1)
		{
			CQ1.DeQueue(Element);
			CQ2.EnQueue(Element);
			size--;
		}
		//ջ��Ԫ��ֻ��1����ֱ����ջ
		CQ1.DeQueue(Element);
		x = Element;
	}
	return true;
}
template <class T>
bool Stack<T>::getTop(T &x)const
{
	if (IsEmpty())
		return false;	//���ջ�գ�ȡջ��ʧ��
	//ջ��Ϊ�գ�ȡջ��Ԫ��
	T Element;
	int size = getSize();
	//ջ��Ԫ�ظ�������1��
	//ջ��Ԫ��λ��CQ1�Ķ�β������βǰ���Ԫ��ȫ��ѹ��CQ2���л��档
	if (CQ1.IsEmpty())
	{
		while (size > 1)
		{
			CQ2.DeQueue(Element);
			CQ1.EnQueue(Element);
			size--;
		}
		//ջ��Ԫ��ֻ��1����Ϊջ��Ԫ��,���䷵��
		CQ2.DeQueue(Element);
		x = Element;
		CQ1.EnQueue(Element);
	}
	else
	{
		while (size > 1)
		{
			CQ1.DeQueue(Element);
			CQ2.EnQueue(Element);
			size--;
		}
		//ջ��Ԫ��ֻ��1����Ϊջ��Ԫ��,���䷵��
		CQ1.DeQueue(Element);
		x = Element;
		CQ2.EnQueue(Element);
	}
	return true;
}

template <class T>
bool Stack<T>::IsEmpty()const
{
	if (CQ1.IsEmpty() && CQ2.IsEmpty())
		return true;
	return false;
}

template <class T>
bool Stack<T>::IsFull()const
{
	if ((CQ1.IsEmpty() && CQ2.IsFull()) || (CQ2.IsEmpty() && CQ1.IsFull()))
		return true;
	return false;
}

template <class T>
int Stack<T>::getSize()const
{
	if (CQ1.IsEmpty())
		return CQ2.getSize();
	else
		return CQ1.getSize();
}
#endif