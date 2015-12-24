// Console_Banker.cpp : 定义控制台应用程序的入口点。
//本程序依靠键盘输入初始化系统资源数量及种类，由银行家算法检验系统资源是否安全，输出安全序列。提出请求request【i】，同意分配，
//则进行安全性算法safe（），否则输出提示：请求被据拒绝。直到所有进程finish=true，安全且输出安全序列，安全算法safe（）结束。

#include "stdafx.h"
#include<iostream>
using namespace std;

#define MaxProcess 10		//最大进程数
#define MaxResource 10		//最大资源数
int Available[MaxResource];		//当前可用资源数组
int MaxNeed[MaxProcess][MaxResource];		//最大需求矩阵
int Allocation[MaxProcess][MaxResource];	//已分配资源矩阵
int Need[MaxProcess][MaxResource];		//当前仍需求的矩阵
int Request[MaxProcess][MaxResource];		//当前进程对资源的请求
bool Finish[MaxProcess];		//标志数组，记录进程是否完成
int Order[MaxProcess];		//记录进程完成的先后顺序的记录数组
int M, N;		//M个进程，N个资源

//前向声明
void Init();		//资源和进程初始化函数
bool Safe();		//判断请求序列是否安全的函数
void Bank();		//银行家，资源分配者函数

int _tmain(int argc, _TCHAR* argv[])		
{
	Init();		//第一步
	Safe();		//第二步
	Bank();		//第三步
	return 0;
}

void Init()		//初始化函数
{
	cout<<"请输入进程的数目："<<endl;
	cin>>M;
	while(M>MaxProcess||M<=0)
	{
		cout<<"非法的进程数,请重新输入！"<<endl;
		cin>>M;
	}
	cout<<"请输入银行家所持有的资源的种类："<<endl;
	cin>>N;
	while(N>MaxResource||N<=0)
	{
		cout<<"非法的资源种类,请重新输入！"<<endl;
		cin>>N;
	}
	int i, j;		//i代表进程类型，j代表资源种类
	cout << "请输入银行家当前拥有的各种资源的数目：" << endl;
	for (j = 0; j<N; j++)
		cin >> Available[j];
	cout<<"请输入每个进程最多所需的各种资源数，按照MxN矩阵输入！"<<endl;
	for(i=0; i<M; i++)
	{
		cout<<"进程 "<<i<<" 最多所需的各种资源数："<<endl;
		for(j=0; j<N; j++)
			cin>>MaxNeed[i][j];
	}
	cout<<"请输入每个进程当前已分配的各种资源数，按照MxN矩阵输入！"<<endl;
	for(i=0; i<M; i++)
	{
		cout<<"进程 "<<i<<" 当前已得到的各种资源数："<<endl;
		for(j=0; j<N; j++)
		{
			cin>>Allocation[i][j];
			Need[i][j]=MaxNeed[i][j]-Allocation[i][j];		//完成此进程还需分配的各种资源数
			if(Need[i][j]<0)
			{
				cout<<"您输入的进程 "<<i<<" 已得到的资源 "<<j<<" 的数量有问题，请重新输入！"<<endl;
				j--;
				continue;
			}
		}
	}
}

bool Safe()		//判断某次分配的算法是否安全，安全函数返回true，否则返回false
{
	int i, j, k, l=0;		//l代表进程类型，k代表资源类型
	int Work[MaxResource];		//工作数组
	for(j=0; j<N; j++)
		Work[j]=Available[j];
	for(i=0; i<M; i++)
		Finish[i]=false;
	for(i=0; i<M; i++)
	{
		if(Finish[i]==false)
		{
			for(j=0; j<N; j++)
			{
				if(Need[i][j]>Work[j])
					break;
			}
			if(j==N)
			{
				Finish[i]=true;
				for(k=0;k<N;k++)
					Work[k]+=Allocation[i][k];
				Order[l]=i;
				l++;
				i = -1;
			}
		}
	}
	if(l==M)
	{
		cout<<"此分配算法安全！\n此安全序列为："<<endl;
		for(i=0; i<M; i++)
		{
			cout<<Order[i];
			if(i!=M-1)
				cout<<"-->";
		}
		cout<<endl;
		return true;
	}
	else
	{
		cout<<"此分配算法不安全！"<<endl;
		return false;
	}
}

void Bank()		//银行家对资源的分配
{
	int i, j;		//i代表进程类型,j代表资源类型
	char Again;
	while(1)
	{
		cout<<"请输入要声请资源的进程类型："<<endl;
		cin>>i;
		cout<<"请输入该进程所请求的各资源的数量："<<endl;
		for(j=0;j<N;j++)
		{
			cin>>Request[i][j];
			if(Request[i][j]>Need[i][j])		//请求的资源过多,大于所需的
			{
				cout<<"您输入的资源的请求超过了该进程对此资源的需求量，请重新输入！"<<endl;
				j--;
				continue;
			}
			if(Request[i][j]>Available[j])		//请求的资源过多,大于现有的
			{
				cout<<"您输入的资源的请求超过了银行家对此资源的现有量，请重新输入！"<<endl;
				j--;
				continue;
			}
		}
		for(j=0;j<N;j++)
		{
			Available[j]-=Request[i][j];
			Allocation[i][j]+=Request[i][j];
			Need[i][j]-=Request[i][j];
		}
		if(Safe())
			cout<<"同意分配请求！"<<endl;
		else
		{
			cout<<"您的请求被拒绝！"<<endl;
			for(j=0;j<N;j++)
			{
				Available[j]+=Request[i][j];
				Allocation[i][j]-=Request[i][j];
				Need[i][j]+=Request[i][j];
			}
		}
		for(i=0;i<M;i++)
			Finish[i]=false;
		cout<<"您是否还有其它的请求，是请输入Y，否请输入非Y！"<<endl;
		cin>>Again;
		if(Again=='Y')
			continue;
		else
			break;
	}
}

