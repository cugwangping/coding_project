#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

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
	T *VLR, *LVR;	//VLRΪǰ������Ķ��������У�LVRΪ��������Ķ��������С�
	int N;		//NΪ��ȷ���Ķ������Ľ�����
	BinTreeNode<T> *root;	//ָ�������ָ��
	BinTreeNode<T> *CreatBinaryTree(T *VLR, T *LVR, int n);	//�ݹ鴴������������ǰ�����������Ķ���������ȷ��һ����������
	void DeleteBinTree(BinTreeNode<T> *Root);	//���ú�������ݹ�ɾ��������
public:
	CBinaryTree(T *Pre, T *Mid, int n);	//���캯��
	int Depth(BinTreeNode<T> *Root);	//������������
	~CBinaryTree();		//��������
	BinTreeNode<T> *GetRoot(){ return root; }	//���ظ����
};

template <class T>
BinTreeNode<T> *CBinaryTree<T>::CreatBinaryTree(T *VLR, T *LVR, int n)	//VLRΪǰ������Ķ��������У�LVRΪ��������Ķ��������У�nΪ�������Ľ�����
{
	if (n == 0)
		return NULL;
	int k = 0;
	while (VLR[0] != LVR[k])	//ǰ�����еĵ�һ����Ϊ���������
		k++;	//������������Ѱ�Ҹ����
	//���������У�λ��k���������Ϊ���������ӽ�㼰�������㣬λ��k���ұ�����Ϊ�������Һ��ӽ�㼰��������
	//���������ҵ������󴴽������.
	BinTreeNode<T> *Root = new BinTreeNode<T>(VLR[0]);	//���������
	//��ǰ��VLR+1��ʼ�������0~k-1���������е�k��Ԫ�صݹ齨��������
	Root->LeftChild = CreatBinaryTree(VLR + 1, LVR, k);
	//��ǰ��VLR+k+1��ʼ�������k+1~n-1�������е�n-k-1��Ԫ�ؽ���������
	Root->RightChild = CreatBinaryTree(VLR + k + 1, LVR + k + 1, n - k - 1);
	return Root;
}

template <class T>
void CBinaryTree<T>::DeleteBinTree(BinTreeNode<T> *Root)	//���ú�������ݹ�ɾ��������
{
	if (Root)
	{
		if (Root->LeftChild)
			DeleteBinTree(Root->LeftChild);		//�ݹ�ɾ��������
		if (Root->RightChild)
			DeleteBinTree(Root->RightChild);	//�ݹ�ɾ��������
		delete Root;
	}
}

template <class T>
CBinaryTree<T>::CBinaryTree(T *Pre, T *Mid, int n)
{
	VLR = Pre;
	LVR = Mid;
	N = n;
	root = CreatBinaryTree(VLR, LVR, N);
}

template <class T>
CBinaryTree<T>::~CBinaryTree()
{
	DeleteBinTree(root);
}

template <class T>
int CBinaryTree<T>::Depth(BinTreeNode<T> *Root)	//������������
{
	if (Root == NULL)
		return 0;
	int left_depth = 1 + Depth(Root->LeftChild);
	int right_depth = 1 + Depth(Root->RightChild);
	return (left_depth < right_depth) ? right_depth : left_depth;
}

#endif