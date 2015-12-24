// ListMerge.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"List.h"
#include<iostream>
using namespace std;

template<class T>
void printList(LinkNode<T> *Head)		//ͷ�����Ϊ�����������HeadΪͷ������������
{
	LinkNode<T> *current = Head->link;
	if (current == NULL)	//�ж������Ƿ�Ϊ��
	{
		cout << "�ձ�!" << endl;		//�������Ϊ�գ���û�����ݣ�����ձ�
		return;
	}
	while (current != NULL)
	{
		cout << current->data << '\t';		//�����������Ľ������
		current = current->link;
	}
	cout << endl;	//����
}

template<class T>
LinkNode<T> *Merge(LinkNode<T> *h1, LinkNode<T> *h2)		//����ĺϲ�
{
	if (h1 == NULL&&h1->link==NULL)		//���ͷ���Ϊh1�������ǿձ�ֱ�ӷ���ͷ���Ϊh2������
		return h2;
	if (h2 == NULL&&h2->link==NULL)		//���ͷ���Ϊh2�������ǿձ�ֱ�ӷ���ͷ���Ϊh1������
		return h1;
	//�����������Ϊ�գ�ֱ�ӽ�ͷ���Ϊh2�ĵ�����h2����һ�����ӵ�ͷ���Ϊh1�������β���ĺ��棬
	LinkNode<T> *last1 = h1->link;
	while (last1->link != NULL)		//������һ������һ�飬�ҵ�β���
		last1 = last1->link;
	last1->link = h2->link;		//�ڶ�������h2����һ�����ӵ���һ�������β��
	h2->link = NULL;		//���ڶ��������ÿ�
	return h1;		//���غϲ���������ͷ���
}

template<class T>
LinkNode<T> *Sort(LinkNode<T> * Head)		//�Ժϲ���������������ð�ݷ��Ӵ�С����
{
	if (Head == NULL&&Head->link == NULL)
		return Head;
	LinkNode<T> *current, *next;		//��ǰ��㣬��ǰ������һ�����
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
	//������һ��������
	List<int> L1;
	int EndTag1;		//��һ��������������Ľ�����
	cout << "�����������ʶ����" << endl;
	cin >> EndTag1;
	cout << "�밴��С�����˳�����������������ݣ�" << endl;
	L1.PreInput(EndTag1);		//ǰ�巨����������
	LinkNode<int> *Head1 = L1.getHead();
	printList(Head1);		//�����һ�������������

	//�����ڶ���������
	List<int> L2;
	int EndTag2;		//�ڶ���������������Ľ�����
	cout << "�����������ʶ����" << endl;
	cin >> EndTag2;
	cout << "�밴��С�����˳�����������������ݣ�" << endl;
	L2.PreInput(EndTag2);		//ǰ�巨����������
	LinkNode<int> *Head2 = L2.getHead();
	printList(Head2);		//����ڶ��������������
	LinkNode<int> *Head = Merge(Head1, Head2);		//�ϲ���������
	cout << "�ϲ���ĵ�����:" << endl;
	printList(Head);		//����ϲ���ĵ�����
	cout << "�ϲ��������ĵ�����:" << endl;
	printList(Sort(Head));	//����ϲ��������ĵ�����
	return 0;
}

