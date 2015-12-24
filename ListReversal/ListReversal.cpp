// ListReversal.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"List.h"
#include<iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	List<int> L;
	cout << "请输入一个整型数据作为输入的结束符！" << endl;
	int EndTag;		//单链表数据输入的结束符
	cin >> EndTag;
	cout << "请输入相应的数据来创建所需的链表！" << endl;
	L.PreInput(EndTag);		//前插法建立单链表
	L.printList();		//输出建立的单链表
	L.reversal();		//将链表反转
	cout << "反转后的单链表:" << endl;
	L.printList();		//输出反转后的单链表
	return 0;
}

