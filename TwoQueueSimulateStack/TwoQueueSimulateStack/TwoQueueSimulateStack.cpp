// TwoQueueSimulateStack.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"CirQueue.h"
#include"Stack.h"
#include<iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int size_n;
	cout << "������ѹ��ջ��Ԫ�ظ�����" << endl;
	cin >> size_n;
	int Stack_Size;	//ջ�Ĵ�С
	cout << "������ջ�Ĵ�С: " << endl;
	cin >> Stack_Size;
	if (Stack_Size<size_n)
	{
		cout << "ջ�Ŀռ�̫С����Ų�����ô��Ԫ�أ��˳���" << endl;
		return 0;
	}
	Stack<int> S(Stack_Size);		//����ջ�Ķ��󣬸�ջ�����С
	int element;
	cout << "���������ջ��Ԫ��:" << endl;
	while (size_n > 0)
	{
		cin >> element;
		S.Push(element);
		size_n--;
	}
	cout << endl;
	cout << "��ջ��ѹ����Ԫ��Ϊ��" << endl;
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

