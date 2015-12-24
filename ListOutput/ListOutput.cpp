// ListOutput.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"List.h"

template<class T>
void Seq_PrintList(LinkNode<T> *node, ofstream &file_out)		//˳���������������
{
	file_out << node->data<<'\t';
	node = node->link;
	if (node != NULL)
		Seq_PrintList(node, file_out);		//�ݹ����
}

template<class T>
void Re_PrintList(LinkNode<T> * node, ofstream &file_out)		//�����������������
{
	if (node->link != NULL)
		Re_PrintList(node->link, file_out);		//�ݹ����
	file_out << node->data << '\t';
}

template<class T>
void FactList_Output(LinkNode<T> *Head, bool k)
{
	if (Head->link == NULL)
	{
		cout << "��������" << endl;
		return;
	}
	if (k)
	{
		ofstream Seq_out("SeqOutput.txt");		//SeqOutput.txt,�洢˳�����������ı��ļ�
		Seq_PrintList(Head, Seq_out);
	}
	else
	{
		ofstream Re_out("ReOutput.txt");		//ReOutput.txt,�洢�������������ı��ļ�
		Re_PrintList(Head, Re_out);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream file_in("in.txt");		//in.txt,�������������ļ�
	List<int> L;
	int EndTag;		//������������Ľ�����
	file_in >> EndTag;
	L.PreInput(EndTag, file_in);		//ǰ�巨����������
	bool k1;		//�ж���˳��������Ƿ������������
	file_in >> k1;
	FactList_Output(L.getHead(), k1);
	bool k2;
	file_in >> k2;
	FactList_Output(L.getHead(), k2);
	return 0;
}
