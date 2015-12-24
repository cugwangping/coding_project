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
	BinTreeNode<T> *root;	//ָ�������ָ��
	T EndTag;	//����������������־
	string NodeData;	//����Ķ������������
	int k = 0;	//NodeData���±꣬����ȡ�������������
	Stack<T> S_Node;
	void CreateBinTree(BinTreeNode<T> *& subTree);		//ǰ���������������
	void DeleteBinTree(BinTreeNode<T> *subTree);	//�������ɾ��������
public:
	CBinaryTree(string NoDa, T EndT);		//���캯��,���������
	~CBinaryTree();		//��������,ɾ��������
	BinTreeNode<T> *getRoot(){ return root; }	//��ȡ�������ĸ����
	bool Find(BinTreeNode<T> *Root, T key, bool judge=false);	//����ֵΪkey�Ľ�㣬������ý����������Ƚ������
	void SwapTree(BinTreeNode<T> *Root);	//����ǰ���������ÿ��������������������
	void PrintBinTree(BinTreeNode<T> *Root);	//����������Ľ������	
};
template <class T>
CBinaryTree<T>::CBinaryTree(string NoDa, T EndT)	//���캯��
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
void CBinaryTree<T>::CreateBinTree(BinTreeNode<T> *& subTree)	//����ǰ���������������
{
	if (NodeData[k] != EndTag)
	{
		subTree = new BinTreeNode<T>(NodeData[k]);	//���������
		k++;
		CreateBinTree(subTree->LeftChild);	//�ݹ齨��������
		CreateBinTree(subTree->RightChild);	//�ݹ齨��������
	}
	else
	{
		subTree = NULL;
		k++;
	}
}

template <class T>
void CBinaryTree<T>::DeleteBinTree(BinTreeNode<T> *subTree)	//�������ɾ��������
{
	if (subTree->LeftChild)
		DeleteBinTree(subTree->LeftChild);
	if (subTree->RightChild)
		DeleteBinTree(subTree->RightChild);
	delete subTree;
}

template <class T>
bool CBinaryTree<T>::Find(BinTreeNode<T> *Root, T key, bool judge=false)	//����ֵΪkey�Ľ�㣬������ý����������Ƚ������
{
	if (judge)
	{
		return judge;
	}
	if (Root)
	{
		if (Root->data == key)
		{
			cout << "�ҵ���" << Root->data << ", ���������Ƚ������Ϊ��" << endl;
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
void CBinaryTree<T>::SwapTree(BinTreeNode<T> *Root)		//����ǰ���������ÿ��������������������
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
void CBinaryTree<T>::PrintBinTree(BinTreeNode<T> *Root)		//����������Ľ������
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