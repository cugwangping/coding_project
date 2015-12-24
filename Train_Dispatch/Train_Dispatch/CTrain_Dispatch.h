#ifndef _TRAIN_DISPATCH_H_
#define _TRAIN_DISPATCH_H_
#include<iostream>
#include<ctime>
using namespace std;
#define k 3

class CTrainDispatch
{
private:
	int N;	//N节车厢
	int *Hold;	//火车的N个入轨车厢
	int *Track; 	//入轨车厢所经过的缓存铁轨
	int *LastPosition;	//记录缓存铁轨中最后一个元素
public:
	CTrainDispatch(int n);
	~CTrainDispatch();
	void Rand_int();	//随机生成N个随机数,作为入轨车厢
	bool Sort();	//将即将入轨的火车车厢排序后出轨
	void printTrack();		//输出每节车厢所经过的路径
	void printRadomSeq();	//输出即将入轨的车厢
};

#endif