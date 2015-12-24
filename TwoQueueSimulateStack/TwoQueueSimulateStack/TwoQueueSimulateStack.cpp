// TwoQueueSimulateStack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"CirQueue.h"
#include"Stack.h"
#include<iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int size_n;
	cout << "请输入压入栈的元素个数：" << endl;
	cin >> size_n;
	int Stack_Size;	//栈的大小
	cout << "请输入栈的大小: " << endl;
	cin >> Stack_Size;
	if (Stack_Size<size_n)
	{
		cout << "栈的空间太小，存放不了这么多元素，退出！" << endl;
		return 0;
	}
	Stack<int> S(Stack_Size);		//建立栈的对象，给栈分配大小
	int element;
	cout << "依次输入进栈的元素:" << endl;
	while (size_n > 0)
	{
		cin >> element;
		S.Push(element);
		size_n--;
	}
	cout << endl;
	cout << "从栈中压出的元素为：" << endl;
	int Size = S.getSize();
	while (Size > 0)
	{
		int x;
		S.Pop(x);
		cout << x << endl;
		Size--;
	}
	return 0;
}

