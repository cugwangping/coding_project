// Train_Dispatch.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"CTrain_Dispatch.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	cout << "������𳵳���Ľ�����" << endl;
	cin >> n;
	CTrainDispatch T(n);
	T.Rand_int();
	T.printRadomSeq();
	bool re = T.Sort();;
	if (re)
		T.printTrack();
	return 0;
}

