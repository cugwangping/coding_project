// TrainDispatch.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"CTrainDispatch.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int N;
	cout << "请输入火车车厢的节数！" << endl;
	cin >> N;
	CTrainDispatch Train;
	Train.Rand_int(N);
	cout << "随机产生的火车车厢顺序为：" << endl;
	Train.printInTrain();
	cout << "经过缓存铁轨的车厢：" << endl;
	Train.Sort(N);
	return 0;
}

