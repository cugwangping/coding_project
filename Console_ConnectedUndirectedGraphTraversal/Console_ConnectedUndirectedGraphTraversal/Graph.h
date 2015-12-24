#ifndef _GRAPH_H_
#define _GRAPH_H_
#include<iostream>
using namespace std;

template <class T, class E>
struct Edge			//�߽��Ķ���
{
	int Dest;		//�ߵ���һ����λ��
	E Weight;		//���ϵ�Ȩֵ
	Edge<T, E> *link;		//��һ������ָ��
	Edge(){}		//���캯��
	Edge(int num, E weight)		//���캯��
	{
		Dest = num;
		Weight = weight;
		link = NULL;
	}
	bool operator !=(Edge<T, E>& R)const		//�жϱ��Ƿ񲻵�
	{
		return (Dest != R.Dest) ? true : false;
	}
};

template <class T, class E>	
struct Vertex		//����Ķ���
{
	T data;		//���������
	Edge<T, E> *adj;		//�������ͷָ��
};

//ͼ���ඨ��
const int DefaultVertices = 30;

template <class T, class E>
class Graph
{
private:
	Vertex<T, E> *NodeTable;		//��������������ͷ��㣩
	int MaxVertices;		//ͼ����󶥵���
	int CurrentNumEdges;		//��ǰ����
	int CurrentNumVertices;		//��ǰ������
public:
	//const E MaxWeight = ......;		//���Ȩֵ�����������
	Graph(const int Size = DefaultVertices);		//���캯��
	~Graph();		//��������
	int GetVertexPos(const T Vertex);		//��������Vertex��ͼ�е�λ��
	bool GraphEmpty()const		//�ж�ͼ�շ�
	{
		return (CurrentNumEdges == 0) ? true : false;
	}
	bool GraphFull()const	//�ж�ͼ����
	{
		//ͼ�Ķ������˻��߱�����
		return(CurrentNumVertices == MaxNumVertices || CurrentNumEdges == MaxVertices*(MaxVertices - 1) / 2) ? true : false;
	}		

	int GetCurNumVertices(){ return CurrentNumVertices; }		//���ص�ǰ������
	int GetCurNumEdges(){ return CurrentNumEdges; }		//���ص�ǰ����
	T GetValue(int i)		//ȡ����i��ֵ��i��������0
	{
		return (i >= 0 && i < CurrentNumVertices) ? NodeTable[i].data : 0;
	}
	//E GetWeight(int v1, int v2);		//ȡ�ߣ�v1��v2���ϵ�Ȩֵ
	int GetFirstNeighbor(int v);		//ȡ����v�ĵ�һ���ڽӶ���
	int GetNextNeighbor(int v, int w);		//ȡ�ڽӶ���w����һ���ڽӶ���
	bool InsertVertex(const T& Vertex);		//����һ������Vertex
	bool InsertEdge(int v1, int v2, E weight);		//����ߣ�v1��v2����ȨΪweight
	//bool RemoveVertex(int v);		//ɾ������v��������֮�������
	//bool RemoveEdge(int v1, int v2);		//��ͼ��ɾ���ߣ�v1��v2��
};

//˽�г�Ա����
template <class T, class E>
int Graph<T, E>::GetVertexPos(const T Vertex)		//��������Vertex��ͼ�е�λ��
{
	for (int i = 0; i < CurrentNumVertices; i++)
	{
		if (NodeTable[i].data == Vertex)
			return i;
	}
	return -1;
}

//���г�Ա����
template <class T, class E>
Graph<T, E>::Graph(const int Size)		//���캯��,����һ���յ��ڽӱ�
{
	MaxVertices = Size;
	CurrentNumVertices = 0;
	CurrentNumEdges = 0;
	NodeTable = new Vertex<T, E>[MaxVertices];		//��̬�������������
	for (int i = 0; i < MaxVertices; i++)
		NodeTable[i].adj = NULL;
}

template <class T, class E>
Graph<T, E>::~Graph()		//��������
{
	for (int i = 0; i < CurrentNumVertices; i++)		//ɾ�����������еĽ��
	{
		Edge<T, E> *ptr = NodeTable[i].adj;		//�ҵ����Ӧ��������׽��
		while (ptr != NULL)		//ѭ��ɾ����һ�����
		{
			NodeTable[i].adj = ptr->link; 
			delete ptr;
			ptr = NodeTable[i].adj;
		}
	}
	delete[]NodeTable;		//ɾ�����������
}

template <class T, class E>
int Graph<T, E>::GetFirstNeighbor(int v)
{
	//��������λ��Ϊv�ĵ�һ���ڽӶ����λ�ã�����Ҳ���������-1
	if (v != -1)	//����v����
	{
		Edge<T, E> *ptr = NodeTable[v].adj;		//��Ӧ�������һ���߽��
		if (ptr != NULL)
			return ptr->Dest;		//���ڣ����ص�һ���ڽӶ���λ��
	}
	return - 1;		//��һ���ڽӶ��㲻����
}

template <class T, class E>
int Graph<T, E>::GetNextNeighbor(int v, int w)
{
	//��������v���ڽӶ���w����һ���ڽӶ����λ�ã���û����һ���ڽӶ��㣬����-1
	if (v != -1)
	{
		Edge<T, E> *ptr = NodeTable[v].adj;		//��Ӧ�������һ���߽��
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

/*
template <class T, class E>
E Graph<T, E>::GetWeight(int v1, int v2)
{
	//�������رߣ�v1��v2���ϵ�Ȩֵ�����ñ߲���ͼ�У���������Ȩֵ0
	if (v1 != -1 && v2 != -1)
	{
		Edge<T, E> *ptr = NodeTable[v1].adj;	//v1�ĵ�һ�������ı�
		while (ptr != NULL&&ptr->Dest != v2)	//Ѱ���ڽӶ���v2
			ptr = ptr->link;
		if (ptr != NULL)
			return ptr->Weight;		//�ҵ��˱ߣ�����Ȩֵ
	}
	else
		return 0;		//û���ҵ��˱ߣ�����0
}
*/

template <class T, class E>
bool Graph<T, E>::InsertVertex(const T& Vertex)
{
	//��ͼ�Ķ�����в���һ���¶���Vertex��������ɹ�����������true�����򷵻�false
	if (CurrentNumVertices == MaxVertices)
		return false;		//���������������ʧ��
	NodeTable[CurrentNumVertices].data = Vertex;		//���¶��������ĩ��
	CurrentNumVertices++;		//��ĵ�ǰ��������һ
	return true;
}

template <class T, class E>
bool Graph<T, E>::InsertEdge(int v1, int v2, E weight)		//����ߣ�v1��v2����ȨΪweight
{
	if (CurrentNumEdges == CurrentNumVertices*(CurrentNumVertices - 1) / 2)		//ͼ�еı�����
		return false;
	//�ڴ�Ȩ����ͼ�в���һ���ߣ�v1��v2����ȨֵΪweight�����˱��Ѵ��ڻ��߲�������ȷ����������false�����򷵻�true
	if (v1 >= 0 && v1 < CurrentNumVertices&&v2 >= 0 && v2 < CurrentNumVertices)
	{
		Edge<T, E> *q;
		Edge<T, E> *ptr = NodeTable[v1].adj;	//v1��Ӧ�ı�����ͷָ��
		//�����Ƿ���ڱߣ�v1��v2���������ڣ�ֱ�ӷ���false���������
		while (ptr != NULL&&ptr->Dest != v2)
			ptr = ptr->link;
		if (ptr != NULL)		//���ڱߣ�v1��v2��
			return false;
		//�����ڱߣ�v1��v2�������루v1��v2��
		ptr = new Edge<T, E>(v2, weight);		//�����±�
		q = new Edge<T, E>(v1, weight);
		//ptr->Dest = v2;
		//ptr->Weight = weight;
		ptr->link = NodeTable[v1].adj;		//���ӵ�v1������
		NodeTable[v1].adj = ptr;
		//q->Dest = v1;
		//q->Weight = weight;
		q->link = NodeTable[v2].adj;		//���ӵ�v2������
		NodeTable[v2].adj = q;
		return true;
	}
	else
		return false;
}

/*
template <class T, class E>
bool Graph<T, E>::RemoveVertex(int v)		//ɾ������v��������֮�������
{
	//��ͼ��ɾ��һ��ָ������v��v�Ƕ���š�
	if (CurrentNumVertices == 1 || v < 0 || v >= CurrentNumVertices)
		return false;		//��ջ򶥵�ų�����Χ
	Edge<T, E> *ptr, *s, *t;
	int i, k;
	while (NodeTable[v].adj != NULL)	//ɾ����v���������е����б߽��
	{
		ptr = NodeTable[v].adj;		
		k = ptr->Dest;		//ȡ�ڽӶ���k
		s = NodeTable[k].adj;		//�ҶԳƴ�ŵı߽��
		t = NULL;
		while (s != NULL&&s->Dest != v)
		{
			t = s;
			s = s->link;
		}
		if (s != NULL)		//ɾ���Գƴ�ŵı߽��
		{
			if (t == NULL)
				NodeTable[k].adj = s->link;		//������ĵ�һ�������Ǹñ�
			else
				t->link = s->link;
			delete s;
		}
		NodeTable[v].adj = ptr->link;
		delete ptr;
		CurrentNumEdges--;
	}
	CurrentNumVertices--;		//ͼ�Ķ��������һ
	//�ö����������һ��������ոձ�ɾ���Ķ��㣬Ȼ����¸ո����Ķ������֮�����ıߵ�����
	NodeTable[v].data = NodeTable[CurrentNumVertices].data;		
	ptr = NodeTable[v].adj = NodeTable[CurrentNumVertices].adj;		
	//���������һ������������Ķ���ı������dest
	while (ptr != NULL)
	{
		s = NodeTable[ptr->Dest].adj;
		while (s != NULL)
		{
			if (s->Dest == CurrentNumVertices)
			{
				s->Dest = v;	//ԭ��s->Dest==CurrentNumVertices
				break;
			}
			else
				s = s->link;
		}
		ptr = ptr->link;		//�ӵ�һ���ڽӶ��㿪ʼ���������
	}
	return true;
}

template <class T,class E>
bool Graph<T, E>::RemoveEdge(int v1, int v2)
{
	//��ͼ��ɾ��һ����(v1, v2)
	if (v1 >= 0 && v1 < CurrentNumVertices && v2 >= 0 && v2 < CurrentNumVertices)		//�ߵ��������㶼����
	{
		Edge<T, E> *ptr = NodeTable[v1].adj, *q = NULL;
		Edge<T, E> *s = ptr;	//��sָ���¼�������׽��

		while (ptr != NULL&&ptr->Dest != v2)		//v1��Ӧ���������ұ�ɾ��
		{
			q = ptr;
			ptr = ptr->link;
		}
		if (ptr != NULL)		//�ҵ��˱�ɾ�߽��
		{
			if (ptr == s)
				NodeTable[v1].adj = ptr->link;		//�ý���Ǳ������׽��
			else
				q->link = ptr->link;
			delete ptr;
		}
		else
			return false;		//û���ҵ���ɾ�߽��

		ptr = NodeTable[v2].adj;		//v2��Ӧ��������ɾ��
		q = NULL;
		s = ptr;		//��sָ���¼�������׽��	
		while (ptr->Dest != v1)		//Ѱ�ұ�ɾ�߽��
		{
			q = ptr;
			ptr = ptr->link;
		}
		if (ptr == s)
			NodeTable[v2].adj = ptr->link;		//�ý���Ǳ������׽��
		else
			q->link = ptr->link;	
		delete ptr;
		return true;		
	}
	else
		return false;		//û���ҵ����
}
*/

#endif