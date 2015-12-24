#include"stdafx.h"
#include"CTrainDispatch.h"
#include<ctime>

void CTrainDispatch::Rand_int(int N)		//�������N�������
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

bool CTrainDispatch::Sort(int N)		//���������Ļ𳵳�����������
{
	int Fx1, Fx2, Fx3;	//��������ĳ�ͷ
	Fx1 = Fx2 = Fx3 = 0;	//���������ͷ������
	int Lx1, Lx2, Lx3;		
	Lx1 = Lx2 = Lx3 = 0;	//���泵���β������
	int x = 1;	//��Ҫ����ĳ�����
	int Front;		//��������쳵����
	InTrain.DeQueue(Front);
	while (InTrain.IsEmpty()==false||H1.IsEmpty()==false||H2.IsEmpty()==false||H3.IsEmpty()==false)
	{
		if (Front == x)		//����쳵�������������Ҫ����ĳ��ᣬ������쳵��
		{
			cout << "��" << Front << "�ڳ���:	δ�����������졣" << endl;
			x = x + 1;
			if (InTrain.IsEmpty() == false)
				InTrain.DeQueue(Front);
		}
		else if (Fx1 == x)	//��H1���쵯��������Ҫ����ĳ��ᣬ������쳵��
		{
			H1.DeQueue(Fx1);
			cout << "��" << Fx1 << "�ڳ���:	������������H1����"<<endl;
			H1.getFront(Fx1);
			x = x + 1;
		}
		else if (Fx2 == x)	//��H2���쵯��������Ҫ����ĳ��ᣬ������쳵��
		{
			H2.DeQueue(Fx2);
			cout << "��" << Fx2 << "�ڳ���:	������������H2����" << endl;
			H2.getFront(Fx2);
			x = x + 1;
		}
		else if (Fx3 == x)	//��H3���쵯��������Ҫ����ĳ��ᣬ������쳵��
		{
			H3.DeQueue(Fx3);
			cout << "��" << Fx3 << "�ڳ���:	������������H3����" << endl;
			H3.getFront(Fx3);
			x = x + 1;
		}
		//����쳵������Ĳ�����Ҫ����ĳ��ᣬ���뻺�泵��
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
				cout << "�������첻�㣡" << endl;
				cout << "�޽⣬�˳���" << endl;
				return false;
			}
		}
	}
	return true;
}