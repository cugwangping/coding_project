// ListMerge.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"List.h"
#include<iostream>
using namespace std;

template<class T>
void printList(LinkNode<T> *Head)		//头结点作为参数，输出以Head为头结点的链表数据
{
	LinkNode<T> *current = Head->link;
	if (current == NULL)	//判断链表是否为空
	{
		cout << "空表!" << endl;		//如果链表为空，则没有数据，输出空表
		return;
	}
	while (current != NULL)
	{
		cout << current->data << '\t';		//依次输出链表的结点数据
		current = current->link;
	}
	cout << endl;	//换行
}

template<class T>
LinkNode<T> *Merge(LinkNode<T> *h1, LinkNode<T> *h2)		//链表的合并
{
	if (h1 == NULL&&h1->link==NULL)		//如果头结点为h1的链表是空表，直接返回头结点为h2的链表
		return h2;
	if (h2 == NULL&&h2->link==NULL)		//如果头结点为h2的链表是空表，直接返回头结点为h1的链表
		return h1;
	//两个链表均不为空，直接将头结点为h2的单链表h2的下一个结点接到头结点为h1的链表的尾结点的后面，
	LinkNode<T> *last1 = h1->link;
	while (last1->link != NULL)		//遍历第一个链表一遍，找到尾结点
		last1 = last1->link;
	last1->link = h2->link;		//第二个结点的h2的下一个结点接到第一个链表的尾部
	h2->link = NULL;		//将第二个链表置空
	return h1;		//返回合并后的链表的头结点
}

template<class T>
LinkNode<T> *Sort(LinkNode<T> * Head)		//对合并后的链表进行排序，冒泡法从大到小排序
{
	if (Head == NULL&&Head->link == NULL)
		return Head;
	LinkNode<T> *current, *next;		//当前结点，当前结点的下一个结点
	T temp;
	for (current = Head->link; current != NULL; current = current->link)
	{
		for (next = current->link; next != NULL; next = next->link)
		{
			if (next->data > current->data)
			{
				temp = current->data;
				current->data = next->data;
				next->data = temp;
			}
		}
	}
	return Head;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//创建第一个单链表
	List<int> L1;
	int EndTag1;		//第一个链表数据输入的结束符
	cout << "请输入结束标识符！" << endl;
	cin >> EndTag1;
	cout << "请按从小到大的顺序依次输入链表数据！" << endl;
	L1.PreInput(EndTag1);		//前插法创建单链表
	LinkNode<int> *Head1 = L1.getHead();
	printList(Head1);		//输出第一个单链表的数据

	//创建第二个单链表
	List<int> L2;
	int EndTag2;		//第二个链表数据输入的结束符
	cout << "请输入结束标识符！" << endl;
	cin >> EndTag2;
	cout << "请按从小到大的顺序依次输入链表数据！" << endl;
	L2.PreInput(EndTag2);		//前插法创建单链表
	LinkNode<int> *Head2 = L2.getHead();
	printList(Head2);		//输出第二个单链表的数据
	LinkNode<int> *Head = Merge(Head1, Head2);		//合并两个链表
	cout << "合并后的单链表:" << endl;
	printList(Head);		//输出合并后的单链表
	cout << "合并且排序后的单链表:" << endl;
	printList(Sort(Head));	//输出合并且排序后的单链表
	return 0;
}

