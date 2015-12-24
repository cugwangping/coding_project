// Console_Interview_Score.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"MaxHeap.h"
#include<ctime>
#include<fstream>

int _tmain(int argc, _TCHAR* argv[])
{
	int M, N;	//从N个面试的人中挑选出M个成绩最好的人
	cout << "请输入面试的人数为：" << endl;
	cin >> N;
	cout << "挑选出的人数为：" << endl;
	cin >> M;
	while (M <= 1000 || M >= 10000 || N <= 1000 || N >= 10000 || M > N)
	{
		cout << "不合适的数据M,N，请重新输入！" << endl;
		cout << "请输入面试的人数为：" << endl;
		cin >> N;
		cout << "挑选出的人数为：" << endl;
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
		cout << "堆的存储空间分配失败，退出！" << endl;
	}
	delete[]arr;
	return 0;
}

