// ListOutput.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"List.h"

template<class T>
void Seq_PrintList(LinkNode<T> *node, ofstream &file_out)		//顺序输出链表的数据
{
	file_out << node->data<<'\t';
	node = node->link;
	if (node != NULL)
		Seq_PrintList(node, file_out);		//递归输出
}

template<class T>
void Re_PrintList(LinkNode<T> * node, ofstream &file_out)		//反序输出链表的数据
{
	if (node->link != NULL)
		Re_PrintList(node->link, file_out);		//递归输出
	file_out << node->data << '\t';
}

template<class T>
void FactList_Output(LinkNode<T> *Head, bool k)
{
	if (Head->link == NULL)
	{
		cout << "空链表！" << endl;
		return;
	}
	if (k)
	{
		ofstream Seq_out("SeqOutput.txt");		//SeqOutput.txt,存储顺序输出结果的文本文件
		Seq_PrintList(Head, Seq_out);
	}
	else
	{
		ofstream Re_out("ReOutput.txt");		//ReOutput.txt,存储反序输出结果的文本文件
		Re_PrintList(Head, Re_out);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream file_in("in.txt");		//in.txt,链表数据输入文件
	List<int> L;
	int EndTag;		//链表数据输入的结束符
	file_in >> EndTag;
	L.PreInput(EndTag, file_in);		//前插法建立单链表
	bool k1;		//判断是顺序输出还是反序输出单链表
	file_in >> k1;
	FactList_Output(L.getHead(), k1);
	bool k2;
	file_in >> k2;
	FactList_Output(L.getHead(), k2);
	return 0;
}

