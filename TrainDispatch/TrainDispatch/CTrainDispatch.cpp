#include"stdafx.h"
#include"CTrainDispatch.h"
#include<ctime>

void CTrainDispatch::Rand_int(int N)		//随机生成N个随机数
{
	int *mark = new int[N+1];
	mark[0] = 1;
	for (int i = 1; i < N+1; i++)
		mark[i] = 0;
	srand((unsigned)time(NULL));
	int x;
	int count = 0;
	while (count<N)
	{
		x = 1 + rand() % N;
		if (mark[x] != 1)
		{
			InTrain.EnQueue(x);
			mark[x]++;
			count++;
		}
	}
	delete[]mark;
}

bool CTrainDispatch::Sort(int N)		//将即将入轨的火车车厢排序后出轨
{
	int Fx1, Fx2, Fx3;	//缓存铁轨的车头
	Fx1 = Fx2 = Fx3 = 0;	//缓存铁轨的头车厢编号
	int Lx1, Lx2, Lx3;		
	Lx1 = Lx2 = Lx3 = 0;	//缓存车厢的尾车厢编号
	int x = 1;	//需要出轨的车厢编号
	int Front;		//弹出的入轨车厢编号
	InTrain.DeQueue(Front);
	while (InTrain.IsEmpty()==false||H1.IsEmpty()==false||H2.IsEmpty()==false||H3.IsEmpty()==false)
	{
		if (Front == x)		//从入轨车厢出来的正是需要出轨的车厢，存入出轨车厢
		{
			cout << "第" << Front << "节车厢:	未经过缓存铁轨。" << endl;
			x = x + 1;
			if (InTrain.IsEmpty() == false)
				InTrain.DeQueue(Front);
		}
		else if (Fx1 == x)	//从H1铁轨弹出的是需要出轨的车厢，存入出轨车厢
		{
			H1.DeQueue(Fx1);
			cout << "第" << Fx1 << "节车厢:	经过缓存铁轨H1而来"<<endl;
			H1.getFront(Fx1);
			x = x + 1;
		}
		else if (Fx2 == x)	//从H2铁轨弹出的是需要出轨的车厢，存入出轨车厢
		{
			H2.DeQueue(Fx2);
			cout << "第" << Fx2 << "节车厢:	经过缓存铁轨H2而来" << endl;
			H2.getFront(Fx2);
			x = x + 1;
		}
		else if (Fx3 == x)	//从H3铁轨弹出的是需要出轨的车厢，存入出轨车厢
		{
			H3.DeQueue(Fx3);
			cout << "第" << Fx3 << "节车厢:	经过缓存铁轨H3而来" << endl;
			H3.getFront(Fx3);
			x = x + 1;
		}
		//从入轨车厢出来的不是需要出轨的车厢，存入缓存车厢
		else
		{
			if (Front >= Lx1)
			{
				if (H1.IsEmpty())
				{
					H1.EnQueue(Front);
					H1.getFront(Fx1);
					H1.getRear(Lx1);
					InTrain.DeQueue(Front);
				}
				else
				{
					H1.EnQueue(Front);
					H1.getRear(Lx1);
					InTrain.DeQueue(Front);
				}
			}
			else if (Front<Lx1&&Front>=Lx2)
			{
				if (H2.IsEmpty())
				{
					H2.EnQueue(Front);
					H2.getFront(Fx2);
					H2.getRear(Lx2);
					InTrain.DeQueue(Front);
				}
				else
				{
					H2.EnQueue(Front);
					H2.getRear(Lx2);
					InTrain.DeQueue(Front);
				}
			}
			else if (Front<Lx2&&Front >= Lx3)
			{
				if (H3.IsEmpty())
				{
					H3.EnQueue(Front);
					H3.getFront(Fx3);
					H3.getRear(Lx3);
					InTrain.DeQueue(Front);
				}
				else
				{
					H3.EnQueue(Front);
					H3.getRear(Lx3);
					InTrain.DeQueue(Front);
				}
			}
			else
			{
				cout << endl;
				cout << "缓存铁轨不足！" << endl;
				cout << "无解，退出！" << endl;
				return false;
			}
		}
	}
	return true;
}