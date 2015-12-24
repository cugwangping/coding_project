// Console_Interview_Score.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"MaxHeap.h"
#include<ctime>
#include<fstream>

int _tmain(int argc, _TCHAR* argv[])
{
	int M, N;	//��N�����Ե�������ѡ��M���ɼ���õ���
	cout << "���������Ե�����Ϊ��" << endl;
	cin >> N;
	cout << "��ѡ��������Ϊ��" << endl;
	cin >> M;
	while (M <= 1000 || M >= 10000 || N <= 1000 || N >= 10000 || M > N)
	{
		cout << "�����ʵ�����M,N�����������룡" << endl;
		cout << "���������Ե�����Ϊ��" << endl;
		cin >> N;
		cout << "��ѡ��������Ϊ��" << endl;
		cin >> M;
	}
	int *arr = new int[N];
	srand((unsigned)time(NULL));
	for (int i = 0; i < N; i++)
		arr[i] = rand() % 100;
	try
	{
		MaxHeap H(arr,N);
		ofstream file_out("BestScores.txt");
		for (int i = 1; i <=M; i++)
		{
			int out_x;
			if (H.Find(out_x, i))
				file_out << out_x << endl;
		}
	}
	catch (int)
	{
		cout << "�ѵĴ洢�ռ����ʧ�ܣ��˳���" << endl;
	}
	delete[]arr;
	return 0;
}

