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
	T *VLR, *LVR;	//VLR为前序遍历的二叉树序列，LVR为中序遍历的二叉树序列。
	int N;		//N为所确定的二叉树的结点个数
	BinTreeNode<T> *root;	//指向根结点的指针
	BinTreeNode<T> *CreatBinaryTree(T *VLR, T *LVR, int n);	//递归创建二叉树，由前序和中序遍历的二叉树序列确定一个二叉树。
	void DeleteBinTree(BinTreeNode<T> *Root);	//利用后序遍历递归删除二叉树
public:
	CBinaryTree(T *Pre, T *Mid, int n);	//构造函数
	int Depth(BinTreeNode<T> *Root);	//求二叉树的深度
	~CBinaryTree();		//析构函数
	BinTreeNode<T> *GetRoot(){ return root; }	//返回根结点
};

template <class T>
BinTreeNode<T> *CBinaryTree<T>::CreatBinaryTree(T *VLR, T *LVR, int n)	//VLR为前序遍历的二叉树序列，LVR为中序遍历的二叉树序列，n为二叉树的结点个数
{
	if (n == 0)
		return NULL;
	int k = 0;
	while (VLR[0] != LVR[k])	//前序序列的第一个数为根结点数据
		k++;	//在中序序列中寻找根结点
	//中序序列中，位置k的左边数据为根结点的左孩子结点及其子孙结点，位置k的右边数据为根结点的右孩子结点及其子孙结点
	//在中序中找到根结点后创建根结点.
	BinTreeNode<T> *Root = new BinTreeNode<T>(VLR[0]);	//创建根结点
	//从前序VLR+1开始对中序的0~k-1左子树序列的k个元素递归建立左子树
	Root->LeftChild = CreatBinaryTree(VLR + 1, LVR, k);
	//从前序VLR+k+1开始对中序的k+1~n-1右子序列的n-k-1个元素建立右子树
	Root->RightChild = CreatBinaryTree(VLR + k + 1, LVR + k + 1, n - k - 1);
	return Root;
}

template <class T>
void CBinaryTree<T>::DeleteBinTree(BinTreeNode<T> *Root)	//利用后序遍历递归删除二叉树
{
	if (Root)
	{
		if (Root->LeftChild)
			DeleteBinTree(Root->LeftChild);		//递归删除左子树
		if (Root->RightChild)
			DeleteBinTree(Root->RightChild);	//递归删除右子树
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
int CBinaryTree<T>::Depth(BinTreeNode<T> *Root)	//求二叉树的深度
{
	if (Root == NULL)
		return 0;
	int left_depth = 1 + Depth(Root->LeftChild);
	int right_depth = 1 + Depth(Root->RightChild);
	return (left_depth < right_depth) ? right_depth : left_depth;
}

#endif