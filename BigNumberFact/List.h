#ifndef List_H
#define List_H
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#define Over_Max 1000

struct LinkNode		//单链表结点类的定义
{
	int data;		//结点数据域
	LinkNode *link;		//结点指针域
	LinkNode(LinkNode *ptr = NULL)
	{
		link = ptr;
	}
	LinkNode(const int &x, LinkNode *ptr = NULL)
	{
		data = x;
		link = ptr;
	}
};

class List		//单链表类的定义		
{
private:
	LinkNode *head;		//头结点
	LinkNode *last;		//尾结点
	int Remainder;	//余数
	int CarryBit;	//进位
public:
	List();
	List(const int& x);
	List(List& L);
	~List();
	void makeEmpty();
	LinkNode *getHead()const;	//取链表的头结点
	void reversal();	//链表反转
	int getLastData();		//取链表的尾结点的数据
	bool Insert(int m);		//若尾结点数据大于999，则将进位存入新结点中
	void Fact(int n);		//递归计算阶乘
	void printFact();		//输出阶乘的结果
};

List::List()		//无形参构造函数
{
	head = new LinkNode;
	last = head;
}

List::List(const int& x)	//有参构造函数
{
	head = new LinkNode(x);
	last = head;
}

List::List(List& L)	//复制构造函数
{
	int value;
	LinkNode *srcptr = L.getHead();		//被复制表的附加头结点地址
	LinkNode *destptr = head = new LinkNode;
	while (srcptr->link != NULL)		//逐个结点复制
	{
		value = srcptr->link->data;
		destptr->link = new LinkNode(value);
		destptr = destptr->link;
		srcptr = srcptr->link;
	}
	destptr->link = NULL;
}

List::~List()		//析构函数
{
	makeEmpty();
	delete head;
	head = NULL;
}

void List::makeEmpty()	//将链表置为空表
{
	LinkNode *p;
	while (head->link != NULL)
	{
		p = head->link;
		head->link = p->link;
		delete p;
		p = NULL;
	}
}

LinkNode* List::getHead()const		//返回附加头结点地址
{
	return head;
}

void List::reversal()
{
	if (head == NULL || head->link == NULL)
		return;
	LinkNode *current = head->link;
	LinkNode *ptr = NULL;
	while (current != NULL)
	{
		head->link = ptr;
		ptr = head;
		head = current;
		current = current->link;
	}
	head->link = ptr;
}


int List::getLastData()
{
	if (head == NULL&&head->link == NULL)
		return 0;
	LinkNode *current = head;
	int x;
	while (current->link != NULL)
	{
		current = current->link;
	}
	x = current->data;
	return x;
}

bool List::Insert(int m)		//当尾结点数据大于999时，需要进位，增加新结点，将进位存入新结点中。
{
	Remainder = m%Over_Max;		//余数
	CarryBit = m / Over_Max;	//进位数
	last->data = Remainder;		//将余数作为尾结点的数据
	LinkNode *newNode = new LinkNode;	//增加新结点
	last->link = newNode;
	newNode->data = CarryBit;	//将进位数作为新结点的数据
	last = newNode;		//用last表示新结点作为尾结点的标志
	return true;
}

void List::Fact(int i)
{
	if (i < 0)
	{
		cout << "错误的阶乘基数i!" << endl;		//阶乘基数为非负
		return;
	}
	if (i == 0)
	{
		head->data = 1;		//最开始将1存入链表中，然后与后面自增的i累积
		return;
	}
	//i为正整数时将链表的数据与i分别累积，进位的结点，余数存入，进位数存入新结点
	CarryBit = 0;
	LinkNode *current = head;		//记录当前结点
	while (current->link != NULL)		//遍历链表,每个结点的数据都要乘以i
	{
		Remainder = current->data*i + CarryBit;		//阶乘的当前结果等于当前结点数据与阶乘基数i的积再加进位数
		CarryBit = Remainder / Over_Max;			//然后重复累积
		current->data = Remainder%Over_Max;
		current = current->link;		//当前结点指向下一个结点，循环
	}
	last->data = current->data*i + CarryBit;		//阶乘的最后一个结点的结果等于最后一个结点数据与阶乘基数i的积再加进位数
}

void List::printFact()
{
	ofstream file_out("BigNumber.txt");		//存储输出结果的文本文件
	LinkNode *current = head;		//当前结点
	file_out << current->data << ',';	//输出头结点数据
	current = current->link;		
	while (current->link != NULL)		//判断是否循环的条件：当前结点的下一个结点不为空
	{
		file_out << setfill('0') << setw(3) << current->data << ',';	//格式化输出，如果数据不足100，则前面补0，输出必须为3位数字，确保中间不掉0，结果正确
		current = current->link;
	}
	file_out << setfill('0') << setw(3) << current->data << endl;	//输出尾结点数据，最后三位
}

#endif