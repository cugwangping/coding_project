// LinkList.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"List.h"
#include<iostream>
using namespace std;

template<class T>
LinkNode<T>* merge(LinkNode<T> *ha, LinkNode<T> *hb)		//ǰ�巨�ϲ�����������
{
	if (ha->link == NULL)
		return hb;
	if (hb->link == NULL)
		return ha;
	LinkNode<T> *nextA = ha->link;	//�ж�ѭ��ʱ�ӱ�ͷ������һ����㿪ʼ
	LinkNode<T> *nextB = hb->link;
	LinkNode<T> *ptr = NULL;
	LinkNode<T> *sur = NULL;	//ʣ����
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
		ptr->link = Head->link;		//ʣ������뵽��ǰ��
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
void printList(LinkNode<T> *Head)	//��������������е�Ԫ��
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
	//��������ha�����ݣ���������ha
	cout << "������һ��T���͵�������Ϊ����la��������Ľ�������" << endl;
	int Value_A;
	cin >> Value_A;
	cout << "�밴�Ӵ�С��˳��������������la������!" << endl;
	la.PreInput(Value_A);
	printList(ha);		//�������la
	cout << "������һ��T���͵�������Ϊ����lb��������Ľ�������" << endl;
	int Value_B;
	cin >> Value_B;
	cout << "�밴�Ӵ�С��˳��������������lb������!" << endl;
	lb.PreInput(Value_B);
	printList(hb);		//�������lb
	LinkNode<int> *mergeNode = merge(ha, hb);		//�ϲ���������
	printList(mergeNode);		//����ϲ��������
	
	/*LinkNode<int> *reNode = reversal(ha);
	printList(reNode);*/
	return 0;
}