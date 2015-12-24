#include"stdafx.h"
#include"CTrain_Dispatch.h"

CTrainDispatch::CTrainDispatch(int n)
{
	N = n;
	Hold = new int[N];
	Track = new int[N+1];
	LastPosition = new int[N + 1];
	for (int i = 0; i <= N; i++)
		Track[i] = 0;
	for (int i = 0; i <= k;i++)
		LastPosition[i] = 0;
}

CTrainDispatch::~CTrainDispatch()
{
	delete[]Hold;
	delete[]Track;
	delete[]LastPosition;
}

void CTrainDispatch::Rand_int()		//�������N�������
{
	int *mark = new int[N + 1];
	mark[0] = 1;
	for (int i = 1; i <= N; i++)
		mark[i] = 0;
	srand((unsigned)time(NULL));
	int x;
	int count = 0;
	while (count<N)
	{
		x = 1 + rand() % N;
		if (mark[x] != 1)
		{
			Hold[count] = x;
			mark[x]++;
			count++;
		}
	}
	delete[]mark;
}

bool CTrainDispatch::Sort()
{
	int OutTrain = 1;
	int i = 0;
	while (i<N)
	{
		if (Hold[i] == OutTrain)
		{
			OutTrain++;
			i++;
		}
		else
		{
			if (Track[OutTrain])
			{
				if (LastPosition[Track[OutTrain]] == OutTrain)
					LastPosition[Track[OutTrain]] = 0;
				OutTrain++;
			}
			else
			{
				int j;
				for (j = 1; j <= k; j++)
				{
					if (Hold[i]>LastPosition[j])
					{
						Track[Hold[i]] = j;
						i++;
						break;
					}
				}
				if (j == k + 1)
				{
					cout << "�������첻�㣡" << endl;
					cout << "�޽⣬�˳���" << endl;
					return false;
				}
			}
		}
	}
	return true;
}

void CTrainDispatch::printTrack()
{
	for (int i = 0; i < N; i++)
	{
		if (Track[Hold[i]] != 0)
			cout << "��" << Hold[i] << "�ڳ��ᾭ������H" << Track[Hold[i]] << "������" << endl;
		else
			cout << "��" << Hold[i] << "�ڳ���δ�����������졣" << endl;
	}
}

void CTrainDispatch::printRadomSeq()
{
	for (int i = 0; i < N; i++)
		cout << Hold[i] << " ";
	cout << endl;
}