// Console_BinaryTree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"BinaryTree.h"
#include<string>
#include<iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string NodeData;
	cout << "������������NodeData��" << endl;
	cin >> NodeData;
	char EndTag;
	cout << "�������㴴���Ľ�������" << endl;
	cin >> EndTag;
	CBinaryTree<char> BinTree(NodeData, EndTag);
	cout << "�������Ľ������Ϊ��" << endl;
	BinTree.PrintBinTree(BinTree.getRoot());
	cout << endl;

	char Key;
	cout << "��������Ҫ���ҵ����ݣ�" << endl;
	cin >> Key;
	if (BinTree.Find(BinTree.getRoot(), Key) == false)
		cout << "δ�ҵ�" << Key << endl;
	cout << endl;

	BinTree.SwapTree(BinTree.getRoot());
	cout << "������Ľ������Ϊ��" << endl;
	BinTree.PrintBinTree(BinTree.getRoot());
	cout << endl;
	return 0;
}

