#ifndef _LINKNODE_H_
#define _LINKNODE_H_
#include<iostream>
using namespace std;

//HafMan���Ľ����
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
	unsigned char ch;	//��ĳ�����ݶ�ȡ���ļ��ж�ȡ�����ַ�
	int count = 0;	//�ڴ˴ζ�ȡ��������ch���ļ��г��ֵĴ���, Ƶ��
	string HafDistribute;	//��Haf���еķֲ�λ��Ϊ01�ַ���
	int L = 0;		//·���ĳ���
	unsigned int Value = 0;		//01�ַ���ת��Ϊ��ʮ���Ƶ�ֵ
};

#endif