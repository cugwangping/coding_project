#ifndef _STACK_H_
#define _STACK_H_
#include<assert.h>

template <class T>
class Stack
{
private:
	T *elements;	//存放栈中元素的数组
	int top;	//栈顶指针
	int maxSize;	//栈的最大容量
public:
	Stack(int size=100);	//构造函数，建立一个空栈
	~Stack();	//析构函数
	bool IsEmpty()const { return (top == -1) ? true : false; }	//判断栈空否
	bool IsFull()const { return (top == maxSize - 1) ? true : false; }	//判断栈满否
	bool Push(const T& x);	//压栈，将x放入栈顶
	bool Pop(T& x);		//弹栈，将栈顶元素弹出，由x返回
	void printStack();	//输出栈中的元素
};

template <class T>
Stack<T>::Stack(int size)
{
	top = -1;
	maxSize = size;
	elements = new T[maxSize];
	assert(elements != NULL);
}

template <class T>
Stack<T>::~Stack()
{
	delete[]elements;
}

template <class T>
bool Stack<T>::Push(const T& x)
{
	if (IsFull())
		return false;
	elements[++top] = x;	//栈顶先指针加一，再将x压栈；
	return true;
}

template <class T>
bool Stack<T>::Pop(T& x)
{
	if (IsEmpty())
		return false;
	x = elements[top--];	//现将栈顶元素退栈，再将栈顶指针减一；
	return true;
}

template <class T>
void Stack<T>::printStack()
{
	for (int i = 0; i <= top; i++)
		cout << elements[i] << " ";
	cout << endl;
}

#endif