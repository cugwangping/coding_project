#include"stdafx.h"
#include"Graph.h"

//私有成员函数
int Graph::GetVertexPos(const CPoint Vertex)		//给出顶点Vertex在图中的位置
{
	for (int i = 0; i < CurrentNumVertices; i++)
	{
		if (NodeTable[i].Point == Vertex)
			return i;
	}
	return -1;
}

//公有成员函数
Graph::Graph(const int Size)		//构造函数,创建一个空的邻接表
{
	MaxVertices = Size;
	CurrentNumVertices = 0;
	CurrentNumEdges = 0;
	NodeTable = new Vertex[MaxVertices];		//动态创建顶点表数组
	int i;
	for (i = 0; i < MaxVertices; i++)
		NodeTable[i].adj = NULL;
}

Graph::~Graph()		//析构函数
{
	for (int i = 0; i < CurrentNumVertices; i++)		//删除各边链表中的结点
	{
		Edge *ptr = NodeTable[i].adj;		//找到其对应边链表的首结点
		while (ptr != NULL)		//循环删除第一个结点
		{
			NodeTable[i].adj = ptr->link;
			delete ptr;
			ptr = NodeTable[i].adj;
		}
	}
	delete[]NodeTable;		//删除顶点表数组
}

int Graph::GetFirstNeighbor(int v)
{
	//给出顶点位置为v的第一个邻接顶点的位置，如果找不到，返回-1
	if (v != -1)	//顶点v存在
	{
		Edge *ptr = NodeTable[v].adj;		//对应边链表第一个边结点
		if (ptr != NULL)
			return ptr->Dest;		//存在，返回第一个邻接顶点位置
	}
	return -1;		//第一个邻接顶点不存在
}

int Graph::GetNextNeighbor(int v, int w)
{
	//给出顶点v的邻接顶点w的下一个邻接顶点的位置，若没有下一个邻接顶点，返回-1
	if (v != -1)
	{
		Edge *ptr = NodeTable[v].adj;		//对应边链表第一个边结点
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

double Graph::GetWeight(int v1, int v2)
{
	//函数返回边（v1，v2）上的权值，若该边不在图中，则函数返回权值0
	if (v1 != -1 && v2 != -1)
	{
		Edge *ptr = NodeTable[v1].adj;	//v1的第一条关联的边
		while (ptr != NULL&&ptr->Dest != v2)	//寻找邻接顶点v2
			ptr = ptr->link;
		if (ptr != NULL)
			return ptr->Weight;		//找到此边，返回权值
	}
	return 0;		//没有找到此边，返回0
}

bool Graph::InsertVertex(const CPoint& Vertex)
{
	//在图的顶点表中插入一个新顶点Vertex。若插入成功，函数返回true，否则返回false
	if (CurrentNumVertices == MaxVertices)
		return false;		//顶点表已满，插入失败
	NodeTable[CurrentNumVertices].Point = Vertex;		//将新顶点插入表的末端
	CurrentNumVertices++;		//表的当前顶点数加一
	return true;
}

bool Graph::InsertEdge(int v1, int v2, double weight)		//插入边（v1，v2），权为weight
{
	if (CurrentNumEdges == CurrentNumVertices*(CurrentNumVertices - 1) / 2)		//图中的边满了
		return false;
	//在带权无向图中插入一条边（v1，v2），权值为weight。若此边已存在或者参数不正确，函数返回false，否则返回true
	if (v1 >= 0 && v1 < CurrentNumVertices&&v2 >= 0 && v2 < CurrentNumVertices)
	{
		Edge *q;
		Edge *ptr = NodeTable[v1].adj;	//v1对应的边链表头指针
		//查找是否存在边（v1，v2），若存在，直接返回false，否则插入
		while (ptr != NULL&&ptr->Dest != v2)
			ptr = ptr->link;
		if (ptr != NULL)		//存在边（v1，v2）
			return false;
		//不存在边（v1，v2），插入（v1，v2）
		ptr = new Edge(v2, weight);		//创建新边
		q = new Edge(v1, weight);
		ptr->link = NodeTable[v1].adj;		//连接到v1边链表
		NodeTable[v1].adj = ptr;
		q->link = NodeTable[v2].adj;		//连接到v2边链表
		NodeTable[v2].adj = q;
		return true;
	}
	else
		return false;
}

void Graph::ShortestPath(int v)		//求任意两点间的最短路径
{
	bool *S = new bool[CurrentNumVertices]; 	   //最短路径顶点集，是否加入
	double dist[NumVertices] = { MaxDist };
	int i, j, k;  double w, Min;
	for (i = 0; i < CurrentNumVertices; i++)
	{
		dist[i] = GetWeight(v, i);
		S[i] = false;
		if (i != v && dist[i] < MaxDist) 
			path[i] = v;
		else
			path[i] = -1;
	}
	//  初始化路径数组
	S[v] = true; 
	dist[v] = 0;        //顶点v加入顶点集合
	for (i = 0; i < CurrentNumVertices - 1; i++)         //求解各顶点最短路径
	{
		Min = MaxDist; 
		int u = v;
		//选不在S中具有最短路径的顶点u
		for (j = 0; j < CurrentNumVertices; j++)
		if (!S[j] && dist[j] < Min){
			u = j;   Min = dist[j];
		}
		S[u] = true;	               	//将顶点u加入集合S
		for (k = 0; k < CurrentNumVertices; k++) 
		{    
			w = GetWeight(u, k);
			if (!S[k] && w < MaxDist &&dist[u] + w < dist[k]) 
			{       //顶点k未加入S                
				dist[k] = dist[u] + w;
				path[k] = u;     		    //修改到k的最短路径
			}
		}
	}
	delete[]S;
}