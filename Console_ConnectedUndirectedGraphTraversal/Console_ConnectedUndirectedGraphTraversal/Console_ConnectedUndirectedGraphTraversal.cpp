// Console_ConnectedUndirectedGraphTraversal.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"Graph.h"
#include<iostream>
#include<stack>
#include"Queue.h"
using namespace std;

template <class T, class E>
void DFS(Graph<T, E>& G,const T v)		//无向连通图的深度优先遍历
{	
	//从顶点v出发对图G进行深度优先遍历的主过程
	int loc, n = G.GetCurNumVertices();		//当前顶点个数
	bool *Visited = new bool[n];		//动态创建标记数组，标记某个顶点是否被访问
	for (int i = 0; i < n; i++)
		Visited[i] = false;		//将所有顶点的标记全部初始化为false，未被访问
	loc = G.GetVertexPos(v);		//获取顶点v所在数组的下标
	stack<int> S;
	cout << G.GetValue(loc) << "-->";		//访问顶点v
	Visited[loc] = true;		//标记v已访问过
	S.push(loc);		//将顶点v压入栈中	
	while (!S.empty())
	{
		int v1 = G.GetFirstNeighbor(S.top());		//顶点v的第一个邻接顶点v1
		//int v2 = G.GetNextNeighbor(v1, S.top());	//顶点v的邻接顶点v1的下一个邻接顶点
		while (v1 != -1)
		{
			if (!Visited[v1])		//邻接顶点v1未被访问过，访问v1
			{
				cout << G.GetValue(v1) << "-->";		//访问顶点v1
				Visited[v1] = true;		//标记v1已访问过
				S.push(v1);		//将顶点v1压入栈中
				break;		//退出循环
			}
			else
				v1 = G.GetNextNeighbor(S.top(), v1);
		}
		if(v1 == -1)           //顶点v1已被访问过，将栈顶顶点元素退栈
			S.pop();
	}
	cout << "*" << endl;
	delete[]Visited;
}

template <class T,class E>
void BFS(Graph<T, E>& G, const T v)		//必须使用引用，不然G对象在函数执行完后就析构了，在主函数中将会再析构一次
{
	//从顶点v出发，以广度优先的次序横向搜索图，算法中使用了一个队列
	int n = G.GetCurNumVertices();		//取图中顶点个数
	bool *Visited = new bool[n];		//记录顶点是否被访问过
	for (int i = 0; i < n; i++)
		Visited[i] = false;		//所有顶点全部标记为未访问
	int loc = G.GetVertexPos(v);		//取顶点号
	cout << G.GetValue(loc) << "-->";		//访问顶点v
	Visited[loc] = true;		//将v标记为已访问
	Queue<int> Q;
	Q.EnQueue(loc);		//顶点入队列，实现分层访问
	while (!Q.IsEmpty())		//访问所有结点
	{
		Q.DeQueue(loc);		//从队列中弹出一个顶点loc
		int v1 = G.GetFirstNeighbor(loc);		//找顶点loc的第一个邻接顶点v1
		while (v1 != -1)		//若v1存在
		{
			if (Visited[v1] == false)		//顶点v1未访问
			{
				cout << G.GetValue(v1) << "-->";		//访问顶点v1
				Visited[v1] = true;		//将v1标记为已访问
				Q.EnQueue(v1);		//顶点v1入队列
			}
			v1 = G.GetNextNeighbor(loc, v1);		//找顶点loc的邻接顶点v1的下一个邻接顶点
		}
	}
	cout << "*" << endl;
	delete[]Visited;
}

int _tmain(int argc, _TCHAR* argv[])
{
	const int size = 30;
	Graph<char, int> G(size);
	cout << "请输入无向图顶点的个数：" << endl;
	int VN;
	cin >> VN;
	cout << "请输入无向图的点集：" << endl;
	char Ver;
	for (int i = 0; i < VN; i++)
	{
		cin >> Ver;
		if (G.InsertVertex(Ver))
			continue;
		else
			break;
	}

	cout << "请输入无向图的边集个数：" << endl;
	int EN;
	cin >> EN;
	cout << "请输入无向图的边集：" << endl;
	int v1, v2, weight;		//顶点v1，v2，权值
	cout << "v1" << "v2" << "权值" << endl;
	for (int i = 0; i < EN; i++)
	{
		cin >> v1 >> v2 >> weight;
		if (G.InsertEdge(v1, v2, weight))
			continue;
		else
			break;
	}
	char v;		//遍历的起始顶点
	//无向图的深度优先遍历
	cout << "请输入深度优先遍历的起始顶点：" << endl;
	cin >> v;
	DFS(G, v);
	//无向图的广度优先遍历
	cout << "请输入广度优先遍历的起始顶点：" << endl;
	cin >> v;
	BFS(G, v);
	return 0;
}

