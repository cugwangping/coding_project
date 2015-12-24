#ifndef List_H
#define List_H

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
	int length()const;		
	LinkNode<T> *getHead()const;	
	LinkNode<T> *Locate(int i);
	bool Insert(int i, T& x);	
	void PreInput(T EndTag);
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
int List<T>::length()const	//计算链表的长度
{
	LinkNode<T> *p = head->link;
	int len = 0;
	while (p != NULL)
	{
		p = p->link;
		len++;
	}
	return len;
}

template<class T>
LinkNode<T>* List<T>::getHead()const		//返回附加头结点地址
{
	return head;
}
template<class T>
LinkNode<T>* List<T>::Locate(int i)		//搜索第i个元素的地址
{
	if (i < 0)		//i太小
		return NULL;
	LinkNode<T> *current = head;
	int k = 0;
	while (current != NULL && k < i)
	{
		current = current->link;
		k++;
	}
	return current;
}
template<class T>
bool List<T>::Insert(int i, T& x)		//在第i个元素后插入x
{
	LinkNode<T> *current = Locate(i);
	if (current == NULL)
		return false;
	LinkNode<T> *newNode = new LinkNode<T>(x);
	if (newNode == NULL)
	{
		cout << "存储分配失败，无法插入！" << endl;
		return false;
	}
	newNode->link = current->link;
	current->link = newNode;
	return true;
}

template<class T>
void List<T>::PreInput(T EndTag)		//前插建立单链表
{		
	LinkNode<T> *newNode;
	T NodeData;
	makeEmpty();
	//输入链表数据
	cin >> NodeData;
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
		cin >> NodeData;
	}
}

#endif