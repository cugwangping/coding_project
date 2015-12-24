#ifndef List_H
#define List_H
#include<fstream>
#include<iostream>
using namespace std;

template<class T>
struct LinkNode		//����������Ķ���
{
	T data;		//���������
	LinkNode<T> *link;		//���ָ����
	LinkNode(LinkNode<T> *ptr = NULL)
	{
		link = ptr;
	}
	LinkNode(const T &x, LinkNode<T> *ptr = NULL)
	{
		data = x;
		link = ptr;
	}
};

template<class T>
class List		//��������Ķ���		
{
private:
	LinkNode<T> *head;		//ͷ���
public:
	List();
	List(const T& x);
	List(List<T>& L);
	~List();
	void makeEmpty();
	LinkNode<T> *getHead()const;
	void PreInput(T EndTag, ifstream &file_in);
};

template<class T>
List<T>::List()		//���βι��캯��
{
	head = new LinkNode<T>;
}

template<class T>
List<T>::List(const T& x)	//�вι��캯��
{
	head = new LinkNode<T>(x);
}

template<class T>
List<T>::List(List<T>& L)	//���ƹ��캯��
{
	T value;
	LinkNode<T> *srcptr = L.getHead();		//�����Ʊ�ĸ���ͷ����ַ
	LinkNode<T> *destptr = head = new LinkNode<T>;
	while (srcptr->link != NULL)		//�����㸴��
	{
		value = srcptr->link->data;
		destptr->link = new LinkNode<T>(value);
		destptr = destptr->link;
		srcptr = srcptr->link;
	}
	destptr->link = NULL;
}

template<class T>
List<T>::~List()		//��������
{
	makeEmpty();
	delete head;
}

template<class T>
void List<T>::makeEmpty()	//��������Ϊ�ձ�
{
	LinkNode<T> *p;
	while (head->link != NULL)
	{
		p = head->link;
		head->link = p->link;
		delete p;
		p = NULL;
	}
}

template<class T>
LinkNode<T>* List<T>::getHead()const		//���ظ���ͷ����ַ
{
	return head;
}

template<class T>
void List<T>::PreInput(T EndTag, ifstream &file_in)		//ǰ�彨��������
{
	LinkNode<T> *newNode;
	T NodeData;
	makeEmpty();
	//������������
	file_in >> NodeData;
	while (NodeData != EndTag)		//EndTagΪ�������ݽ����ı�־
	{
		newNode = new LinkNode<T>(NodeData);		//�����½��
		if (newNode == NULL)
		{
			cout << "������Ч!" << endl;
			return;
		}
		newNode->link = head->link;
		head->link = newNode;	//���뵽��ǰ��
		file_in >> NodeData;
	}
}

#endif