#ifndef _GRAPH_H_
#define _GRAPH_H_
#include<iostream>
using namespace std;

template <class T, class E>
struct Edge			//边结点的定义
{
	int Dest;		//边的另一顶点位置
	E Weight;		//边上的权值
	Edge<T, E> *link;		//下一条边链指针
	Edge(){}		//构造函数
	Edge(int num, E weight)		//构造函数
	{
		Dest = num;
		Weight = weight;
		link = NULL;
	}
	bool operator !=(Edge<T, E>& R)const		//判断边是否不等
	{
		return (Dest != R.Dest) ? true : false;
	}
};

template <class T, class E>	
struct Vertex		//顶点的定义
{
	T data;		//顶点的名字
	Edge<T, E> *adj;		//边链表的头指针
};

//图的类定义
const int DefaultVertices = 30;

template <class T, class E>
class Graph
{
private:
	Vertex<T, E> *NodeTable;		//顶点表（各边链表的头结点）
	int MaxVertices;		//图中最大顶点数
	int CurrentNumEdges;		//当前边数
	int CurrentNumVertices;		//当前顶点数
public:
	//const E MaxWeight = ......;		//最大权值，代表无穷大
	Graph(const int Size = DefaultVertices);		//构造函数
	~Graph();		//析构函数
	int GetVertexPos(const T Vertex);		//给出顶点Vertex在图中的位置
	bool GraphEmpty()const		//判断图空否
	{
		return (CurrentNumEdges == 0) ? true : false;
	}
	bool GraphFull()const	//判断图满否
	{
		//图的顶点满了或者边满了
		return(CurrentNumVertices == MaxNumVertices || CurrentNumEdges == MaxVertices*(MaxVertices - 1) / 2) ? true : false;
	}		

	int GetCurNumVertices(){ return CurrentNumVertices; }		//返回当前顶点数
	int GetCurNumEdges(){ return CurrentNumEdges; }		//返回当前边数
	T GetValue(int i)		//取顶点i的值，i不合理返回0
	{
		return (i >= 0 && i < CurrentNumVertices) ? NodeTable[i].data : 0;
	}
	//E GetWeight(int v1, int v2);		//取边（v1，v2）上的权值
	int GetFirstNeighbor(int v);		//取顶点v的第一个邻接顶点
	int GetNextNeighbor(int v, int w);		//取邻接顶点w的下一个邻接顶点
	bool InsertVertex(const T& Vertex);		//插入一个顶点Vertex
	bool InsertEdge(int v1, int v2, E weight);		//插入边（v1，v2），权为weight
	//bool RemoveVertex(int v);		//删除顶点v和所有与之相关联边
	//bool RemoveEdge(int v1, int v2);		//在图中删除边（v1，v2）
};

//私有成员函数
template <class T, class E>
int Graph<T, E>::GetVertexPos(const T Vertex)		//给出顶点Vertex在图中的位置
{
	for (int i = 0; i < CurrentNumVertices; i++)
	{
		if (NodeTable[i].data == Vertex)
			return i;
	}
	return -1;
}

//公有成员函数
template <class T, class E>
Graph<T, E>::Graph(const int Size)		//构造函数,创建一个空的邻接表
{
	MaxVertices = Size;
	CurrentNumVertices = 0;
	CurrentNumEdges = 0;
	NodeTable = new Vertex<T, E>[MaxVertices];		//动态创建顶点表数组
	for (int i = 0; i < MaxVertices; i++)
		NodeTable[i].adj = NULL;
}

template <class T, class E>
Graph<T, E>::~Graph()		//析构函数
{
	for (int i = 0; i < CurrentNumVertices; i++)		//删除各边链表中的结点
	{
		Edge<T, E> *ptr = NodeTable[i].adj;		//找到其对应边链表的首结点
		while (ptr != NULL)		//循环删除第一个结点
		{
			NodeTable[i].adj = ptr->link; 
			delete ptr;
			ptr = NodeTable[i].adj;
		}
	}
	delete[]NodeTable;		//删除顶点表数组
}

template <class T, class E>
int Graph<T, E>::GetFirstNeighbor(int v)
{
	//给出顶点位置为v的第一个邻接顶点的位置，如果找不到，返回-1
	if (v != -1)	//顶点v存在
	{
		Edge<T, E> *ptr = NodeTable[v].adj;		//对应边链表第一个边结点
		if (ptr != NULL)
			return ptr->Dest;		//存在，返回第一个邻接顶点位置
	}
	return - 1;		//第一个邻接顶点不存在
}

template <class T, class E>
int Graph<T, E>::GetNextNeighbor(int v, int w)
{
	//给出顶点v的邻接顶点w的下一个邻接顶点的位置，若没有下一个邻接顶点，返回-1
	if (v != -1)
	{
		Edge<T, E> *ptr = NodeTable[v].adj;		//对应边链表第一个边结点
		while (ptr != NULL&&ptr->link != NULL)		//寻找邻接顶点w
		{
			if (ptr->Dest == w)
				break;
			else
				ptr = ptr->link;
		}
		if (ptr != NULL&&ptr->link != NULL)
			return ptr->link->Dest;		//返回下一个邻接顶点
	}
	return -1;		//下一个邻接顶点不存在
}

/*
template <class T, class E>
E Graph<T, E>::GetWeight(int v1, int v2)
{
	//函数返回边（v1，v2）上的权值，若该边不在图中，则函数返回权值0
	if (v1 != -1 && v2 != -1)
	{
		Edge<T, E> *ptr = NodeTable[v1].adj;	//v1的第一条关联的边
		while (ptr != NULL&&ptr->Dest != v2)	//寻找邻接顶点v2
			ptr = ptr->link;
		if (ptr != NULL)
			return ptr->Weight;		//找到此边，返回权值
	}
	else
		return 0;		//没有找到此边，返回0
}
*/

template <class T, class E>
bool Graph<T, E>::InsertVertex(const T& Vertex)
{
	//在图的顶点表中插入一个新顶点Vertex。若插入成功，函数返回true，否则返回false
	if (CurrentNumVertices == MaxVertices)
		return false;		//顶点表已满，插入失败
	NodeTable[CurrentNumVertices].data = Vertex;		//将新顶点插入表的末端
	CurrentNumVertices++;		//表的当前顶点数加一
	return true;
}

template <class T, class E>
bool Graph<T, E>::InsertEdge(int v1, int v2, E weight)		//插入边（v1，v2），权为weight
{
	if (CurrentNumEdges == CurrentNumVertices*(CurrentNumVertices - 1) / 2)		//图中的边满了
		return false;
	//在带权无向图中插入一条边（v1，v2），权值为weight。若此边已存在或者参数不正确，函数返回false，否则返回true
	if (v1 >= 0 && v1 < CurrentNumVertices&&v2 >= 0 && v2 < CurrentNumVertices)
	{
		Edge<T, E> *q;
		Edge<T, E> *ptr = NodeTable[v1].adj;	//v1对应的边链表头指针
		//查找是否存在边（v1，v2），若存在，直接返回false，否则插入
		while (ptr != NULL&&ptr->Dest != v2)
			ptr = ptr->link;
		if (ptr != NULL)		//存在边（v1，v2）
			return false;
		//不存在边（v1，v2），插入（v1，v2）
		ptr = new Edge<T, E>(v2, weight);		//创建新边
		q = new Edge<T, E>(v1, weight);
		//ptr->Dest = v2;
		//ptr->Weight = weight;
		ptr->link = NodeTable[v1].adj;		//连接到v1边链表
		NodeTable[v1].adj = ptr;
		//q->Dest = v1;
		//q->Weight = weight;
		q->link = NodeTable[v2].adj;		//连接到v2边链表
		NodeTable[v2].adj = q;
		return true;
	}
	else
		return false;
}

/*
template <class T, class E>
bool Graph<T, E>::RemoveVertex(int v)		//删除顶点v和所有与之相关联边
{
	//在图中删除一个指定顶点v，v是顶点号。
	if (CurrentNumVertices == 1 || v < 0 || v >= CurrentNumVertices)
		return false;		//表空或顶点号超出范围
	Edge<T, E> *ptr, *s, *t;
	int i, k;
	while (NodeTable[v].adj != NULL)	//删除第v个边链表中的所有边结点
	{
		ptr = NodeTable[v].adj;		
		k = ptr->Dest;		//取邻接顶点k
		s = NodeTable[k].adj;		//找对称存放的边结点
		t = NULL;
		while (s != NULL&&s->Dest != v)
		{
			t = s;
			s = s->link;
		}
		if (s != NULL)		//删除对称存放的边结点
		{
			if (t == NULL)
				NodeTable[k].adj = s->link;		//边链表的第一个结点就是该边
			else
				t->link = s->link;
			delete s;
		}
		NodeTable[v].adj = ptr->link;
		delete ptr;
		CurrentNumEdges--;
	}
	CurrentNumVertices--;		//图的顶点个数减一
	//用顶点数组最后一个顶点填补刚刚被删除的顶点，然后更新刚刚填补后的顶点和与之关联的边的数据
	NodeTable[v].data = NodeTable[CurrentNumVertices].data;		
	ptr = NodeTable[v].adj = NodeTable[CurrentNumVertices].adj;		
	//更新与最后一个顶点相关联的顶点的边链表的dest
	while (ptr != NULL)
	{
		s = NodeTable[ptr->Dest].adj;
		while (s != NULL)
		{
			if (s->Dest == CurrentNumVertices)
			{
				s->Dest = v;	//原来s->Dest==CurrentNumVertices
				break;
			}
			else
				s = s->link;
		}
		ptr = ptr->link;		//从第一个邻接顶点开始逐个向后更新
	}
	return true;
}

template <class T,class E>
bool Graph<T, E>::RemoveEdge(int v1, int v2)
{
	//在图中删除一条边(v1, v2)
	if (v1 >= 0 && v1 < CurrentNumVertices && v2 >= 0 && v2 < CurrentNumVertices)		//边的两个顶点都存在
	{
		Edge<T, E> *ptr = NodeTable[v1].adj, *q = NULL;
		Edge<T, E> *s = ptr;	//用s指针记录边链表首结点

		while (ptr != NULL&&ptr->Dest != v2)		//v1对应边链表中找被删边
		{
			q = ptr;
			ptr = ptr->link;
		}
		if (ptr != NULL)		//找到了被删边结点
		{
			if (ptr == s)
				NodeTable[v1].adj = ptr->link;		//该结点是边链表首结点
			else
				q->link = ptr->link;
			delete ptr;
		}
		else
			return false;		//没有找到被删边结点

		ptr = NodeTable[v2].adj;		//v2对应边链表中删除
		q = NULL;
		s = ptr;		//用s指针记录边链表首结点	
		while (ptr->Dest != v1)		//寻找被删边结点
		{
			q = ptr;
			ptr = ptr->link;
		}
		if (ptr == s)
			NodeTable[v2].adj = ptr->link;		//该结点是边链表首结点
		else
			q->link = ptr->link;	
		delete ptr;
		return true;		
	}
	else
		return false;		//没有找到结点
}
*/

#endif