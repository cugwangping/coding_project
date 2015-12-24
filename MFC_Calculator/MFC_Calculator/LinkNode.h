#ifndef _LINKNODE_H_
#define _LINKNODE_H_

template<class T>
struct LinkNode
{
	T data;		//结点数据
	LinkNode<T> *link;		//结点指针
	LinkNode(LinkNode<T> *ptr = NULL){ link = ptr; }	//仅初始化结点指针的构造函数
	LinkNode(const T& item, LinkNode<T> *ptr = NULL)		//初始化数据和指针的构造函数
	{
		data = item;
		link = ptr;
	}
};

#endif