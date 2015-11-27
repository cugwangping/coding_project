#ifndef _LINKNODE_H_
#define _LINKNODE_H_
#include<iostream>
using namespace std;

//HafMan树的结点类
struct LinkNode
{
	int count_data;
	unsigned char ch_data;
	LinkNode *LeftChild, *RightChild, *Parent;
	LinkNode(LinkNode *Left = NULL, LinkNode *Right = NULL, LinkNode *parent = NULL)
	{
		LeftChild = Left;
		RightChild = Right;
		Parent = parent;
	}
	LinkNode(const int count_element, const char ch_element, LinkNode *Left = NULL, LinkNode *Right = NULL, LinkNode *parent = NULL)
	{
		count_data = count_element;
		ch_data = ch_element;
		LeftChild = Left;
		RightChild = Right;
		Parent = parent;
	}
	bool operator<=(LinkNode &Node)
	{
		return count_data <= Node.count_data;
	}
	bool operator>(LinkNode &Node)
	{
		return count_data > Node.count_data;
	}
};


struct FileInformation
{
	unsigned char ch;	//在某次数据读取从文件中读取到的字符
	int count = 0;	//在此次读取的数据中ch在文件中出现的次数, 频数
	string HafDistribute;	//在Haf树中的分布位置为01字符串
	int L = 0;		//路径的长度
	unsigned int Value = 0;		//01字符串转化为的十进制的值
};

#endif