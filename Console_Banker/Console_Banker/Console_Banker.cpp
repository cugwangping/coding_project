// Console_Banker.cpp : �������̨Ӧ�ó������ڵ㡣
//�������������������ʼ��ϵͳ��Դ���������࣬�����м��㷨����ϵͳ��Դ�Ƿ�ȫ�������ȫ���С��������request��i����ͬ����䣬
//����а�ȫ���㷨safe���������������ʾ�����󱻾ݾܾ���ֱ�����н���finish=true����ȫ�������ȫ���У���ȫ�㷨safe����������

#include "stdafx.h"
#include<iostream>
using namespace std;

#define MaxProcess 10		//��������
#define MaxResource 10		//�����Դ��
int Available[MaxResource];		//��ǰ������Դ����
int MaxNeed[MaxProcess][MaxResource];		//����������
int Allocation[MaxProcess][MaxResource];	//�ѷ�����Դ����
int Need[MaxProcess][MaxResource];		//��ǰ������ľ���
int Request[MaxProcess][MaxResource];		//��ǰ���̶���Դ������
bool Finish[MaxProcess];		//��־���飬��¼�����Ƿ����
int Order[MaxProcess];		//��¼������ɵ��Ⱥ�˳��ļ�¼����
int M, N;		//M�����̣�N����Դ

//ǰ������
void Init();		//��Դ�ͽ��̳�ʼ������
bool Safe();		//�ж����������Ƿ�ȫ�ĺ���
void Bank();		//���мң���Դ�����ߺ���

int _tmain(int argc, _TCHAR* argv[])		
{
	Init();		//��һ��
	Safe();		//�ڶ���
	Bank();		//������
	return 0;
}

void Init()		//��ʼ������
{
	cout<<"��������̵���Ŀ��"<<endl;
	cin>>M;
	while(M>MaxProcess||M<=0)
	{
		cout<<"�Ƿ��Ľ�����,���������룡"<<endl;
		cin>>M;
	}
	cout<<"���������м������е���Դ�����ࣺ"<<endl;
	cin>>N;
	while(N>MaxResource||N<=0)
	{
		cout<<"�Ƿ�����Դ����,���������룡"<<endl;
		cin>>N;
	}
	int i, j;		//i����������ͣ�j������Դ����
	cout << "���������мҵ�ǰӵ�еĸ�����Դ����Ŀ��" << endl;
	for (j = 0; j<N; j++)
		cin >> Available[j];
	cout<<"������ÿ�������������ĸ�����Դ��������MxN�������룡"<<endl;
	for(i=0; i<M; i++)
	{
		cout<<"���� "<<i<<" �������ĸ�����Դ����"<<endl;
		for(j=0; j<N; j++)
			cin>>MaxNeed[i][j];
	}
	cout<<"������ÿ�����̵�ǰ�ѷ���ĸ�����Դ��������MxN�������룡"<<endl;
	for(i=0; i<M; i++)
	{
		cout<<"���� "<<i<<" ��ǰ�ѵõ��ĸ�����Դ����"<<endl;
		for(j=0; j<N; j++)
		{
			cin>>Allocation[i][j];
			Need[i][j]=MaxNeed[i][j]-Allocation[i][j];		//��ɴ˽��̻������ĸ�����Դ��
			if(Need[i][j]<0)
			{
				cout<<"������Ľ��� "<<i<<" �ѵõ�����Դ "<<j<<" �����������⣬���������룡"<<endl;
				j--;
				continue;
			}
		}
	}
}

bool Safe()		//�ж�ĳ�η�����㷨�Ƿ�ȫ����ȫ��������true�����򷵻�false
{
	int i, j, k, l=0;		//l����������ͣ�k������Դ����
	int Work[MaxResource];		//��������
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
		cout<<"�˷����㷨��ȫ��\n�˰�ȫ����Ϊ��"<<endl;
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
		cout<<"�˷����㷨����ȫ��"<<endl;
		return false;
	}
}

void Bank()		//���мҶ���Դ�ķ���
{
	int i, j;		//i�����������,j������Դ����
	char Again;
	while(1)
	{
		cout<<"������Ҫ������Դ�Ľ������ͣ�"<<endl;
		cin>>i;
		cout<<"������ý���������ĸ���Դ��������"<<endl;
		for(j=0;j<N;j++)
		{
			cin>>Request[i][j];
			if(Request[i][j]>Need[i][j])		//�������Դ����,���������
			{
				cout<<"���������Դ�����󳬹��˸ý��̶Դ���Դ�������������������룡"<<endl;
				j--;
				continue;
			}
			if(Request[i][j]>Available[j])		//�������Դ����,�������е�
			{
				cout<<"���������Դ�����󳬹������мҶԴ���Դ�������������������룡"<<endl;
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
			cout<<"ͬ���������"<<endl;
		else
		{
			cout<<"�������󱻾ܾ���"<<endl;
			for(j=0;j<N;j++)
			{
				Available[j]+=Request[i][j];
				Allocation[i][j]-=Request[i][j];
				Need[i][j]+=Request[i][j];
			}
		}
		for(i=0;i<M;i++)
			Finish[i]=false;
		cout<<"���Ƿ���������������������Y�����������Y��"<<endl;
		cin>>Again;
		if(Again=='Y')
			continue;
		else
			break;
	}
}

