// LinkList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"List.h"
#include<iostream>
using namespace std;

template<class T>
LinkNode<T>* merge(LinkNode<T> *ha, LinkNode<T> *hb)		//前插法合并两个单链表
{
	if (ha->link == NULL)
		return hb;
	if (hb->link == NULL)
		return ha;
	LinkNode<T> *nextA = ha->link;	//判断循环时从表头结点的下一个结点开始
	LinkNode<T> *nextB = hb->link;
	LinkNode<T> *ptr = NULL;
	LinkNode<T> *sur = NULL;	//剩余结点
	LinkNode<T> *Head = NULL;
	if (nextA->data <= nextB->data)
		Head = hb;
	else
		Head = ha;
	while (nextA != NULL&&nextB != NULL)
	{
		if (nextA->data <= nextB->data)
		{
			ptr = nextA;		
			nextA = ptr->link;
		}
		else
		{
			ptr = nextB;
			nextB = ptr->link;
		}
		ptr->link = Head->link;		
		Head->link = ptr;
	}
	if (nextA == NULL)
		sur = nextB;
	else
		sur = nextA;
	while (sur != NULL)
	{
		ptr = sur;
		sur = sur->link;
		ptr->link = Head->link;		//剩余结点插入到表前端
		Head->link = ptr;
	}
	return Head;
}

template<class T>
LinkNode<T>* reversal(LinkNode<T> *Head)
{
	if (Head == NULL || Head->link == NULL)
		return Head;
	LinkNode<T> *ptr = Head->link;
	LinkNode<T> *q = NULL;
	while (ptr != NULL)
	{
		Head->link=q;
		q = Head;
		Head = ptr;
		ptr = ptr->link;
	}
	Head ->link= q;
	return Head;
}

template<class T>
void printList(LinkNode<T> *Head)	//输出链表数据域中的元素
{
	LinkNode<T> *current = Head->link;
	while (current != NULL)
	{
		cout << current->data << '\t';
		current = current->link;
	}
	cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	List<int> la, lb;
	LinkNode<int> *ha = la.getHead();
	LinkNode<int> *hb = lb.getHead();
	//输入链表ha的数据，构造链表ha
	cout << "请输入一个T类型的数据作为链表la数据输入的结束符！" << endl;
	int Value_A;
	cin >> Value_A;
	cout << "请按从大到小的顺序依次输入链表la的数据!" << endl;
	la.PreInput(Value_A);
	printList(ha);		//输出链表la
	cout << "请输入一个T类型的数据作为链表lb数据输入的结束符！" << endl;
	int Value_B;
	cin >> Value_B;
	cout << "请按从大到小的顺序依次输入链表lb的数据!" << endl;
	lb.PreInput(Value_B);
	printList(hb);		//输出链表lb
	LinkNode<int> *mergeNode = merge(ha, hb);		//合并两个链表
	printList(mergeNode);		//输出合并后的链表
	
	/*LinkNode<int> *reNode = reversal(ha);
	printList(reNode);*/
	return 0;
}