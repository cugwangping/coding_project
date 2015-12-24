#ifndef List_H
#define List_H
#include<iostream>
#include<fstream>
using namespace std;

struct LinkNode		//单链表结点类的定义
{
	int son_data;		//结点数据域
	int parent_data;
	LinkNode *link;		//结点指针域
	LinkNode(LinkNode *ptr = NULL)		//结点构造函数
	{
		link = ptr;
	}
	LinkNode(const int &x1, const int &x2, LinkNode *ptr = NULL)	//结点构造函数
	{
		son_data = x1;
		parent_data = x2;
		link = ptr;
	}
};

//存储N的阶乘的结果的单链表
class List		//单链表类的定义
{
private:
	LinkNode *head;		//头结点
	LinkNode *last;		//尾结点
public:
	List(const int& son1, const int &parent1, const int &son2, const int &parent2);		
	List(List& L);
	~List();
	void makeEmpty();
	LinkNode *getHead()const;
	void InsertFarey(int N);
	void printFraction();
};

List::List(const int& son1, const int &parent1, const int &son2, const int &parent2)	//有参构造函数
{
	head = new LinkNode(son1, parent1);		//头结点的初始化
	last = new LinkNode(son2, parent2);		//尾结点的初始化
	head->link = last;
	last->link = NULL;
}

List::List(List& L)	//复制构造函数
{
	int value1, value2;
	LinkNode *srcptr = L.getHead();		//被复制表的附加头结点地址
	LinkNode *destptr = head = new LinkNode;
	while (srcptr->link != NULL)		//逐个结点复制
	{
		value1 = srcptr->link->son_data;	//取出分子
		value2 = srcptr->link->parent_data;	//取出分母
		destptr->link = new LinkNode(value1, value2);	//将分子分母复制到新建的结点中
		destptr = destptr->link;
		srcptr = srcptr->link;
	}
	destptr->link = NULL;
}

List::~List()		//析构函数
{
	makeEmpty();	//将链表置空
	delete head;	//析释
	head = NULL;
}

void List::makeEmpty()	//将链表置为空表
{
	LinkNode *p;
	while (head->link != NULL)
	{
		p = head->link;
		head->link = p->link;
		delete p;		//逐个结点析释
		p = NULL;
	}
}

LinkNode *List::getHead()const
{
	return head;		//返回头结点
}
void List::InsertFarey(int N)		//将法雷数列依次推算并放入链表中
{
	LinkNode *current = head;		//当前结点
	while (current->link != NULL)
	{
		if ((current->parent_data + current->link->parent_data) <= N)		//判断分母是否大于N，否，推出下一个数据的分子分母放入新插入的结点中
		{
			LinkNode *newNode = new LinkNode;		//建立新结点
			newNode->parent_data = current->parent_data + current->link->parent_data;		//新结点分母等于最近左右两边分数的分母之和
			newNode->son_data = current->son_data + current->link->son_data;		//新结点分子等于最近左右两边分数的分子之和
			newNode->link = current->link;
			current->link = newNode;
		}
		else
			current = current->link;		//分母大于N，跳过，处理后面的两个数据
	}
}

void List::printFraction()		//输出法雷序列
{
	ofstream file_out("Farey.txt");		//法雷序列结果输出文件
	LinkNode* current = head->link;
	while (current != NULL)
	{
		file_out << current->son_data << '/' << current->parent_data << endl;		//循环依次输出法雷序列
		current = current->link;
	}
}

#endif