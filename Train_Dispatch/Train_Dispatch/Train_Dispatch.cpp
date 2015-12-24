// Train_Dispatch.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"CTrain_Dispatch.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	cout << "请输入火车车厢的节数！" << endl;
	cin >> n;
	CTrainDispatch T(n);
	T.Rand_int();
	T.printRadomSeq();
	bool re = T.Sort();;
	if (re)
		T.printTrack();
	return 0;
}

