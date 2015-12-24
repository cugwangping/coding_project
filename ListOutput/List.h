#ifndef List_H
#define List_H
#include<fstream>
#include<iostream>
using namespace std;

template<class T>
struct LinkNode		//单链表结点类的定义
{
	T data;		//结点数据域
	LinkNode<T> *link;		//结点指针域
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
class List		//单链表类的定义		
{
private:
	LinkNode<T> *head;		//头结点
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
List<T>::List()		//无形参构造函数
{
	head = new LinkNode<T>;
}

template<class T>
List<T>::List(const T& x)	//有参构造函数
{
	head = new LinkNode<T>(x);
}

template<class T>
List<T>::List(List<T>& L)	//复制构造函数
{
	T value;
	LinkNode<T> *srcptr = L.getHead();		//被复制表的附加头结点地址
	LinkNode<T> *destptr = head = new LinkNode<T>;
	while (srcptr->link != NULL)		//逐个结点复制
	{
		value = srcptr->link->data;
		destptr->link = new LinkNode<T>(value);
		destptr = destptr->link;
		srcptr = srcptr->link;
	}
	destptr->link = NULL;
}

template<class T>
List<T>::~List()		//析构函数
{
	makeEmpty();
	delete head;
}

template<class T>
void List<T>::makeEmpty()	//将链表置为空表
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
LinkNode<T>* List<T>::getHead()const		//返回附加头结点地址
{
	return head;
}

template<class T>
void List<T>::PreInput(T EndTag, ifstream &file_in)		//前插建立单链表
{
	LinkNode<T> *newNode;
	T NodeData;
	makeEmpty();
	//输入链表数据
	file_in >> NodeData;
	while (NodeData != EndTag)		//EndTag为输入数据结束的标志
	{
		newNode = new LinkNode<T>(NodeData);		//创建新结点
		if (newNode == NULL)
		{
			cout << "数据无效!" << endl;
			return;
		}
		newNode->link = head->link;
		head->link = newNode;	//插入到表前端
		file_in >> NodeData;
	}
}

#endif