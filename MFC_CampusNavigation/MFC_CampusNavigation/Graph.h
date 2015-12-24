#ifndef _GRAPH_H_
#define _GRAPH_H_
#include<iostream>
using namespace std;

#define MaxDist 99999
#define NumVertices 27
#define NumEdges 26

struct Edge			//边结点的定义
{
	int Dest;		//边的另一顶点位置
	double Weight;		//边上的权值
	Edge *link;		//下一条边链指针
	Edge(){}		//构造函数
	Edge(int num, double weight)		//构造函数
	{
		Dest = num;
		Weight = weight;
		link = NULL;
	}
	bool operator !=(Edge& R)const		//判断边是否不等
	{
		return (Dest != R.Dest) ? true : false;
	}
};

struct Vertex		//顶点的定义
{
	CPoint Point;		//顶点的坐标
	CString Info;		//导航图中景点信息简介
	//int x;		//顶点横坐标
	//int y;		//顶点纵坐标
	Edge *adj;		//边链表的头指针
};

//图的类定义
const int DefaultVertices = 30;

class Graph
{
private:
	Vertex *NodeTable;		//顶点表（各边链表的头结点）
	int MaxVertices;		//图中最大顶点数
	int CurrentNumEdges;		//当前边数
	int CurrentNumVertices;		//当前顶点数
public:
	int path[NumVertices];
	Graph(const int Size = DefaultVertices);		//构造函数
	~Graph();		//析构函数
	int GetVertexPos(const CPoint Vertex);		//给出顶点Vertex在图中的位置
	bool GraphEmpty()const		//判断图空否
	{
		return (CurrentNumEdges == 0) ? true : false;
	}
	bool GraphFull()const	//判断图满否
	{
		//图的顶点满了或者边满了
		return(CurrentNumVertices == MaxVertices || CurrentNumEdges == MaxVertices*(MaxVertices - 1) / 2) ? true : false;
	}

	int GetCurNumVertices(){ return CurrentNumVertices; }		//返回当前顶点数
	int GetCurNumEdges(){ return CurrentNumEdges; }		//返回当前边数
	CPoint GetValue(int i)		//取顶点i的值，i不合理返回0
	{
		return (i >= 0 && i < CurrentNumVertices) ? NodeTable[i].Point : NULL;
	}
	double GetWeight(int v1, int v2);		//取边（v1，v2）上的权值
	int GetFirstNeighbor(int v);		//取顶点v的第一个邻接顶点
	int GetNextNeighbor(int v, int w);		//取邻接顶点w的下一个邻接顶点
	bool InsertVertex(const CPoint& Vertex);		//插入一个顶点Vertex
	bool InsertEdge(int v1, int v2, double weight);		//插入边（v1，v2），权为weight
	void ShortestPath(int v);	//求任意两点间的最短路径
};

#endif