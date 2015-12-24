#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_
#include"Stack.h"
#include<iostream>
using namespace std;

template <class T>
struct BinTreeNode
{
	T data;
	BinTreeNode<T> *LeftChild, *RightChild;
	BinTreeNode(BinTreeNode<T> *left = NULL, BinTreeNode<T> *right = NULL)
	{
		LeftChild = left;
		RightChild = right;
	}
	BinTreeNode(T item, BinTreeNode<T> *left = NULL, BinTreeNode<T> *right = NULL)
	{
		data = item;
		LeftChild = left;
		RightChild = right;
	}
};

template <class T>
class CBinaryTree
{
private:
	BinTreeNode<T> *root;	//指向根结点的指针
	T EndTag;	//结点数据输入结束标志
	string NodeData;	//传入的二叉树结点数据
	int k = 0;	//NodeData的下标，用于取出单个结点数据
	Stack<T> S_Node;
	void CreateBinTree(BinTreeNode<T> *& subTree);		//前序遍历创建二叉树
	void DeleteBinTree(BinTreeNode<T> *subTree);	//后序遍历删除二叉树
public:
	CBinaryTree(string NoDa, T EndT);		//构造函数,构造二叉树
	~CBinaryTree();		//析构函数,删除二叉树
	BinTreeNode<T> *getRoot(){ return root; }	//获取二叉树的根结点
	bool Find(BinTreeNode<T> *Root, T key, bool judge=false);	//查找值为key的结点，并输出该结点的所有祖先结点数据
	void SwapTree(BinTreeNode<T> *Root);	//利用前序遍历交换每个结点的左子树和右子树
	void PrintBinTree(BinTreeNode<T> *Root);	//输出二叉树的结点数据	
};
template <class T>
CBinaryTree<T>::CBinaryTree(string NoDa, T EndT)	//构造函数
{
	NodeData = NoDa;
	EndTag = EndT;
	CreateBinTree(root);
}

template <class T>
CBinaryTree<T>::~CBinaryTree()
{
	DeleteBinTree(root);
}

template <class T>
void CBinaryTree<T>::CreateBinTree(BinTreeNode<T> *& subTree)	//利用前序遍历创建二叉树
{
	if (NodeData[k] != EndTag)
	{
		subTree = new BinTreeNode<T>(NodeData[k]);	//建立根结点
		k++;
		CreateBinTree(subTree->LeftChild);	//递归建立左子树
		CreateBinTree(subTree->RightChild);	//递归建立右子树
	}
	else
	{
		subTree = NULL;
		k++;
	}
}

template <class T>
void CBinaryTree<T>::DeleteBinTree(BinTreeNode<T> *subTree)	//后序遍历删除二叉树
{
	if (subTree->LeftChild)
		DeleteBinTree(subTree->LeftChild);
	if (subTree->RightChild)
		DeleteBinTree(subTree->RightChild);
	delete subTree;
}

template <class T>
bool CBinaryTree<T>::Find(BinTreeNode<T> *Root, T key, bool judge=false)	//查找值为key的结点，并输出该结点的所有祖先结点数据
{
	if (judge)
	{
		return judge;
	}
	if (Root)
	{
		if (Root->data == key)
		{
			cout << "找到了" << Root->data << ", 其所有祖先结点数据为：" << endl;
			S_Node.printStack();
			judge = true;
			return judge;
		}
		else
		{
			S_Node.Push(Root->data);
			judge=Find(Root->LeftChild, key, judge);
			judge=Find(Root->RightChild, key, judge);
			T x;
			S_Node.Pop(x);
		}
	}
	return judge;
}

template <class T>
void CBinaryTree<T>::SwapTree(BinTreeNode<T> *Root)		//利用前序遍历交换每个结点的左子树和右子树
{
	BinTreeNode<T> *temp = NULL;
	if (Root->LeftChild != NULL || Root->RightChild != NULL)
	{
		temp = Root->LeftChild;
		Root->LeftChild = Root->RightChild;
		Root->RightChild = temp;
	}
	if (Root->LeftChild)
		SwapTree(Root->LeftChild);
	if (Root->RightChild)
		SwapTree(Root->RightChild);
}

template <class T>
void CBinaryTree<T>::PrintBinTree(BinTreeNode<T> *Root)		//输出二叉树的结点数据
{
	if (Root != NULL)
	{
		cout << Root->data;
		if (Root->LeftChild != NULL || Root->RightChild != NULL)
		{
			cout << "(";
			PrintBinTree(Root->LeftChild);
			if (Root->LeftChild != NULL&&Root->RightChild != NULL)
			{
				cout << ",";
			}
			PrintBinTree(Root->RightChild);
			cout << ")";
		}
	}
}

#endif