#ifndef _STACK_H_
#define _STACK_H_
#include"LinkNode.h"
#include<assert.h>

template<class T>
class Stack
{
private:
	LinkNode<T> *top;	//栈顶指针，即链表头指针
public:
	Stack(){ top = NULL; }		//构造函数，置空栈
	~Stack();	//析构函数
	void Push(const T& x);		//元素x进栈
	bool Pop(T& x);		//退栈
	bool getTop(T& x)const;		//读取栈顶元素
	bool IsEmpty()const{ return (top == NULL) ? true : false; }		//判断栈是否为空
	int getSize()const;		//求栈的元素的个数
	bool makeEmpty();		//将栈置空
};

template<class T>
Stack<T>::~Stack()
{
	LinkNode<T> *p;
	while (top != NULL)		//逐个结点释放
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
	top = new LinkNode<T>(x, top);	//创建新的结点，数据为x
	assert(top != NULL);		//断言，创建新结点失败就退出
}

template<class T>
bool Stack<T>::Pop(T& x)
{
	if (IsEmpty())
		return false;		//若栈为空，返回
	LinkNode<T> *p = top;	//暂存栈顶元素
	top = top->link;
	x = p->data;		//返回退出元素
	delete p;		//释放结点
	p = NULL;
	return true;
}

template<class T>
bool Stack<T>::getTop(T& x)const
{
	if (IsEmpty())	//栈空
		return false;
	//栈不空，返回栈顶元素
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
		return false;		//若栈为空，返回
	LinkNode<T> *p = top;	//暂存栈顶元素
	top = top->link;
	T x = p->data;		//返回退出元素
	delete p;		//释放结点
	p = NULL;
	return true;
}

#endif