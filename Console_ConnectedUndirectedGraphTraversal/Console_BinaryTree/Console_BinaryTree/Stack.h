#ifndef _STACK_H_
#define _STACK_H_
#include<assert.h>

template <class T>
class Stack
{
private:
	T *elements;	//���ջ��Ԫ�ص�����
	int top;	//ջ��ָ��
	int maxSize;	//ջ���������
public:
	Stack(int size=100);	//���캯��������һ����ջ
	~Stack();	//��������
	bool IsEmpty()const { return (top == -1) ? true : false; }	//�ж�ջ�շ�
	bool IsFull()const { return (top == maxSize - 1) ? true : false; }	//�ж�ջ����
	bool Push(const T& x);	//ѹջ����x����ջ��
	bool Pop(T& x);		//��ջ����ջ��Ԫ�ص�������x����
	void printStack();	//���ջ�е�Ԫ��
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
	elements[++top] = x;	//ջ����ָ���һ���ٽ�xѹջ��
	return true;
}

template <class T>
bool Stack<T>::Pop(T& x)
{
	if (IsEmpty())
		return false;
	x = elements[top--];	//�ֽ�ջ��Ԫ����ջ���ٽ�ջ��ָ���һ��
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