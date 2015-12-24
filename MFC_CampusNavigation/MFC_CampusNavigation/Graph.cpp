#include"stdafx.h"
#include"Graph.h"

//˽�г�Ա����
int Graph::GetVertexPos(const CPoint Vertex)		//��������Vertex��ͼ�е�λ��
{
	for (int i = 0; i < CurrentNumVertices; i++)
	{
		if (NodeTable[i].Point == Vertex)
			return i;
	}
	return -1;
}

//���г�Ա����
Graph::Graph(const int Size)		//���캯��,����һ���յ��ڽӱ�
{
	MaxVertices = Size;
	CurrentNumVertices = 0;
	CurrentNumEdges = 0;
	NodeTable = new Vertex[MaxVertices];		//��̬�������������
	int i;
	for (i = 0; i < MaxVertices; i++)
		NodeTable[i].adj = NULL;
}

Graph::~Graph()		//��������
{
	for (int i = 0; i < CurrentNumVertices; i++)		//ɾ�����������еĽ��
	{
		Edge *ptr = NodeTable[i].adj;		//�ҵ����Ӧ��������׽��
		while (ptr != NULL)		//ѭ��ɾ����һ�����
		{
			NodeTable[i].adj = ptr->link;
			delete ptr;
			ptr = NodeTable[i].adj;
		}
	}
	delete[]NodeTable;		//ɾ�����������
}

int Graph::GetFirstNeighbor(int v)
{
	//��������λ��Ϊv�ĵ�һ���ڽӶ����λ�ã�����Ҳ���������-1
	if (v != -1)	//����v����
	{
		Edge *ptr = NodeTable[v].adj;		//��Ӧ�������һ���߽��
		if (ptr != NULL)
			return ptr->Dest;		//���ڣ����ص�һ���ڽӶ���λ��
	}
	return -1;		//��һ���ڽӶ��㲻����
}

int Graph::GetNextNeighbor(int v, int w)
{
	//��������v���ڽӶ���w����һ���ڽӶ����λ�ã���û����һ���ڽӶ��㣬����-1
	if (v != -1)
	{
		Edge *ptr = NodeTable[v].adj;		//��Ӧ�������һ���߽��
		while (ptr != NULL&&ptr->link != NULL)		//Ѱ���ڽӶ���w
		{
			if (ptr->Dest == w)
				break;
			else
				ptr = ptr->link;
		}
		if (ptr != NULL&&ptr->link != NULL)
			return ptr->link->Dest;		//������һ���ڽӶ���
	}
	return -1;		//��һ���ڽӶ��㲻����
}

double Graph::GetWeight(int v1, int v2)
{
	//�������رߣ�v1��v2���ϵ�Ȩֵ�����ñ߲���ͼ�У���������Ȩֵ0
	if (v1 != -1 && v2 != -1)
	{
		Edge *ptr = NodeTable[v1].adj;	//v1�ĵ�һ�������ı�
		while (ptr != NULL&&ptr->Dest != v2)	//Ѱ���ڽӶ���v2
			ptr = ptr->link;
		if (ptr != NULL)
			return ptr->Weight;		//�ҵ��˱ߣ�����Ȩֵ
	}
	return 0;		//û���ҵ��˱ߣ�����0
}

bool Graph::InsertVertex(const CPoint& Vertex)
{
	//��ͼ�Ķ�����в���һ���¶���Vertex��������ɹ�����������true�����򷵻�false
	if (CurrentNumVertices == MaxVertices)
		return false;		//���������������ʧ��
	NodeTable[CurrentNumVertices].Point = Vertex;		//���¶��������ĩ��
	CurrentNumVertices++;		//��ĵ�ǰ��������һ
	return true;
}

bool Graph::InsertEdge(int v1, int v2, double weight)		//����ߣ�v1��v2����ȨΪweight
{
	if (CurrentNumEdges == CurrentNumVertices*(CurrentNumVertices - 1) / 2)		//ͼ�еı�����
		return false;
	//�ڴ�Ȩ����ͼ�в���һ���ߣ�v1��v2����ȨֵΪweight�����˱��Ѵ��ڻ��߲�������ȷ����������false�����򷵻�true
	if (v1 >= 0 && v1 < CurrentNumVertices&&v2 >= 0 && v2 < CurrentNumVertices)
	{
		Edge *q;
		Edge *ptr = NodeTable[v1].adj;	//v1��Ӧ�ı�����ͷָ��
		//�����Ƿ���ڱߣ�v1��v2���������ڣ�ֱ�ӷ���false���������
		while (ptr != NULL&&ptr->Dest != v2)
			ptr = ptr->link;
		if (ptr != NULL)		//���ڱߣ�v1��v2��
			return false;
		//�����ڱߣ�v1��v2�������루v1��v2��
		ptr = new Edge(v2, weight);		//�����±�
		q = new Edge(v1, weight);
		ptr->link = NodeTable[v1].adj;		//���ӵ�v1������
		NodeTable[v1].adj = ptr;
		q->link = NodeTable[v2].adj;		//���ӵ�v2������
		NodeTable[v2].adj = q;
		return true;
	}
	else
		return false;
}

void Graph::ShortestPath(int v)		//���������������·��
{
	bool *S = new bool[CurrentNumVertices]; 	   //���·�����㼯���Ƿ����
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
	//  ��ʼ��·������
	S[v] = true; 
	dist[v] = 0;        //����v���붥�㼯��
	for (i = 0; i < CurrentNumVertices - 1; i++)         //�����������·��
	{
		Min = MaxDist; 
		int u = v;
		//ѡ����S�о������·���Ķ���u
		for (j = 0; j < CurrentNumVertices; j++)
		if (!S[j] && dist[j] < Min){
			u = j;   Min = dist[j];
		}
		S[u] = true;	               	//������u���뼯��S
		for (k = 0; k < CurrentNumVertices; k++) 
		{    
			w = GetWeight(u, k);
			if (!S[k] && w < MaxDist &&dist[u] + w < dist[k]) 
			{       //����kδ����S                
				dist[k] = dist[u] + w;
				path[k] = u;     		    //�޸ĵ�k�����·��
			}
		}
	}
	delete[]S;
}