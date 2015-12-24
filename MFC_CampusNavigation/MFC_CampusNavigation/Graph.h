#ifndef _GRAPH_H_
#define _GRAPH_H_
#include<iostream>
using namespace std;

#define MaxDist 99999
#define NumVertices 27
#define NumEdges 26

struct Edge			//�߽��Ķ���
{
	int Dest;		//�ߵ���һ����λ��
	double Weight;		//���ϵ�Ȩֵ
	Edge *link;		//��һ������ָ��
	Edge(){}		//���캯��
	Edge(int num, double weight)		//���캯��
	{
		Dest = num;
		Weight = weight;
		link = NULL;
	}
	bool operator !=(Edge& R)const		//�жϱ��Ƿ񲻵�
	{
		return (Dest != R.Dest) ? true : false;
	}
};

struct Vertex		//����Ķ���
{
	CPoint Point;		//���������
	CString Info;		//����ͼ�о�����Ϣ���
	//int x;		//���������
	//int y;		//����������
	Edge *adj;		//�������ͷָ��
};

//ͼ���ඨ��
const int DefaultVertices = 30;

class Graph
{
private:
	Vertex *NodeTable;		//��������������ͷ��㣩
	int MaxVertices;		//ͼ����󶥵���
	int CurrentNumEdges;		//��ǰ����
	int CurrentNumVertices;		//��ǰ������
public:
	int path[NumVertices];
	Graph(const int Size = DefaultVertices);		//���캯��
	~Graph();		//��������
	int GetVertexPos(const CPoint Vertex);		//��������Vertex��ͼ�е�λ��
	bool GraphEmpty()const		//�ж�ͼ�շ�
	{
		return (CurrentNumEdges == 0) ? true : false;
	}
	bool GraphFull()const	//�ж�ͼ����
	{
		//ͼ�Ķ������˻��߱�����
		return(CurrentNumVertices == MaxVertices || CurrentNumEdges == MaxVertices*(MaxVertices - 1) / 2) ? true : false;
	}

	int GetCurNumVertices(){ return CurrentNumVertices; }		//���ص�ǰ������
	int GetCurNumEdges(){ return CurrentNumEdges; }		//���ص�ǰ����
	CPoint GetValue(int i)		//ȡ����i��ֵ��i��������0
	{
		return (i >= 0 && i < CurrentNumVertices) ? NodeTable[i].Point : NULL;
	}
	double GetWeight(int v1, int v2);		//ȡ�ߣ�v1��v2���ϵ�Ȩֵ
	int GetFirstNeighbor(int v);		//ȡ����v�ĵ�һ���ڽӶ���
	int GetNextNeighbor(int v, int w);		//ȡ�ڽӶ���w����һ���ڽӶ���
	bool InsertVertex(const CPoint& Vertex);		//����һ������Vertex
	bool InsertEdge(int v1, int v2, double weight);		//����ߣ�v1��v2����ȨΪweight
	void ShortestPath(int v);	//���������������·��
};

#endif