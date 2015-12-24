// Console_BinaryTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"BinaryTree.h"
#include<string>
#include<iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string NodeData;
	cout << "请输入结点数据NodeData！" << endl;
	cin >> NodeData;
	char EndTag;
	cout << "请输入结点创建的结束符！" << endl;
	cin >> EndTag;
	CBinaryTree<char> BinTree(NodeData, EndTag);
	cout << "二叉树的结点数据为：" << endl;
	BinTree.PrintBinTree(BinTree.getRoot());
	cout << endl;

	char Key;
	cout << "请输入需要查找的数据：" << endl;
	cin >> Key;
	if (BinTree.Find(BinTree.getRoot(), Key) == false)
		cout << "未找到" << Key << endl;
	cout << endl;

	BinTree.SwapTree(BinTree.getRoot());
	cout << "交换后的结点数据为：" << endl;
	BinTree.PrintBinTree(BinTree.getRoot());
	cout << endl;
	return 0;
}

