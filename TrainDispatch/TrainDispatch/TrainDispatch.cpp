// TrainDispatch.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"CTrainDispatch.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int N;
	cout << "������𳵳���Ľ�����" << endl;
	cin >> N;
	CTrainDispatch Train;
	Train.Rand_int(N);
	cout << "��������Ļ𳵳���˳��Ϊ��" << endl;
	Train.printInTrain();
	cout << "������������ĳ��᣺" << endl;
	Train.Sort(N);
	return 0;
}

