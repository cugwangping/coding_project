// Console_ConnectedUndirectedGraphTraversal.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"Graph.h"
#include<iostream>
#include<stack>
#include"Queue.h"
using namespace std;

template <class T, class E>
void DFS(Graph<T, E>& G,const T v)		//������ͨͼ��������ȱ���
{	
	//�Ӷ���v������ͼG����������ȱ�����������
	int loc, n = G.GetCurNumVertices();		//��ǰ�������
	bool *Visited = new bool[n];		//��̬����������飬���ĳ�������Ƿ񱻷���
	for (int i = 0; i < n; i++)
		Visited[i] = false;		//�����ж���ı��ȫ����ʼ��Ϊfalse��δ������
	loc = G.GetVertexPos(v);		//��ȡ����v����������±�
	stack<int> S;
	cout << G.GetValue(loc) << "-->";		//���ʶ���v
	Visited[loc] = true;		//���v�ѷ��ʹ�
	S.push(loc);		//������vѹ��ջ��	
	while (!S.empty())
	{
		int v1 = G.GetFirstNeighbor(S.top());		//����v�ĵ�һ���ڽӶ���v1
		//int v2 = G.GetNextNeighbor(v1, S.top());	//����v���ڽӶ���v1����һ���ڽӶ���
		while (v1 != -1)
		{
			if (!Visited[v1])		//�ڽӶ���v1δ�����ʹ�������v1
			{
				cout << G.GetValue(v1) << "-->";		//���ʶ���v1
				Visited[v1] = true;		//���v1�ѷ��ʹ�
				S.push(v1);		//������v1ѹ��ջ��
				break;		//�˳�ѭ��
			}
			else
				v1 = G.GetNextNeighbor(S.top(), v1);
		}
		if(v1 == -1)           //����v1�ѱ����ʹ�����ջ������Ԫ����ջ
			S.pop();
	}
	cout << "*" << endl;
	delete[]Visited;
}

template <class T,class E>
void BFS(Graph<T, E>& G, const T v)		//����ʹ�����ã���ȻG�����ں���ִ�����������ˣ����������н���������һ��
{
	//�Ӷ���v�������Թ�����ȵĴ����������ͼ���㷨��ʹ����һ������
	int n = G.GetCurNumVertices();		//ȡͼ�ж������
	bool *Visited = new bool[n];		//��¼�����Ƿ񱻷��ʹ�
	for (int i = 0; i < n; i++)
		Visited[i] = false;		//���ж���ȫ�����Ϊδ����
	int loc = G.GetVertexPos(v);		//ȡ�����
	cout << G.GetValue(loc) << "-->";		//���ʶ���v
	Visited[loc] = true;		//��v���Ϊ�ѷ���
	Queue<int> Q;
	Q.EnQueue(loc);		//��������У�ʵ�ֲַ����
	while (!Q.IsEmpty())		//�������н��
	{
		Q.DeQueue(loc);		//�Ӷ����е���һ������loc
		int v1 = G.GetFirstNeighbor(loc);		//�Ҷ���loc�ĵ�һ���ڽӶ���v1
		while (v1 != -1)		//��v1����
		{
			if (Visited[v1] == false)		//����v1δ����
			{
				cout << G.GetValue(v1) << "-->";		//���ʶ���v1
				Visited[v1] = true;		//��v1���Ϊ�ѷ���
				Q.EnQueue(v1);		//����v1�����
			}
			v1 = G.GetNextNeighbor(loc, v1);		//�Ҷ���loc���ڽӶ���v1����һ���ڽӶ���
		}
	}
	cout << "*" << endl;
	delete[]Visited;
}

int _tmain(int argc, _TCHAR* argv[])
{
	const int size = 30;
	Graph<char, int> G(size);
	cout << "����������ͼ����ĸ�����" << endl;
	int VN;
	cin >> VN;
	cout << "����������ͼ�ĵ㼯��" << endl;
	char Ver;
	for (int i = 0; i < VN; i++)
	{
		cin >> Ver;
		if (G.InsertVertex(Ver))
			continue;
		else
			break;
	}

	cout << "����������ͼ�ı߼�������" << endl;
	int EN;
	cin >> EN;
	cout << "����������ͼ�ı߼���" << endl;
	int v1, v2, weight;		//����v1��v2��Ȩֵ
	cout << "v1" << "v2" << "Ȩֵ" << endl;
	for (int i = 0; i < EN; i++)
	{
		cin >> v1 >> v2 >> weight;
		if (G.InsertEdge(v1, v2, weight))
			continue;
		else
			break;
	}
	char v;		//��������ʼ����
	//����ͼ��������ȱ���
	cout << "������������ȱ�������ʼ���㣺" << endl;
	cin >> v;
	DFS(G, v);
	//����ͼ�Ĺ�����ȱ���
	cout << "�����������ȱ�������ʼ���㣺" << endl;
	cin >> v;
	BFS(G, v);
	return 0;
}

