#ifndef _STACK_H_
#define _STACK_H_
#include"CirQueue.h"

template <class T>
class Stack
{
private:
	CirQueue<T> CQ1, CQ2;		//队列CQ1对栈进行压入和退出元素的操作，队列CQ2作为缓冲区域,两个队列的大小相等
public:
	Stack(int sz):CQ1(sz),CQ2(sz){}		//构造函数
	~Stack(){}		//析构函数
	bool Push(T &x);		//将x压入栈
	bool Pop(T &x);		//退栈
	bool getTop(T &x)const;	//取栈顶
	bool IsEmpty()const;		//判断栈是否为空
	bool IsFull()const;		//判断栈是否为空
	int getSize()const;		//取栈的当前元素个数
};

template <class T>
bool Stack<T>::Push(T &x)
{
	if (IsFull())
		return false;		//栈满，无法再进行压栈操作
	//栈未满，将x压入栈
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
		return false;		//栈空，没有元素可退栈
	//栈不为空，将栈顶元素退栈
	T Element=0;
	int size = getSize();
	//栈里元素个数大于1，
	//栈顶元素位于CQ1的队尾，将队尾前面的元素全部压入CQ2进行缓存。
	if (CQ1.IsEmpty())
	{
		while (size > 1)
		{
			CQ2.DeQueue(Element);
			CQ1.EnQueue(Element);
			size--;
		}
		//栈里元素只有1个，直接退栈
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
		//栈里元素只有1个，直接退栈
		CQ1.DeQueue(Element);
		x = Element;
	}
	return true;
}
template <class T>
bool Stack<T>::getTop(T &x)const
{
	if (IsEmpty())
		return false;	//如果栈空，取栈顶失败
	//栈不为空，取栈顶元素
	T Element;
	int size = getSize();
	//栈里元素个数大于1，
	//栈顶元素位于CQ1的队尾，将队尾前面的元素全部压入CQ2进行缓存。
	if (CQ1.IsEmpty())
	{
		while (size > 1)
		{
			CQ2.DeQueue(Element);
			CQ1.EnQueue(Element);
			size--;
		}
		//栈里元素只有1个，为栈顶元素,将其返回
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
		//栈里元素只有1个，为栈顶元素,将其返回
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