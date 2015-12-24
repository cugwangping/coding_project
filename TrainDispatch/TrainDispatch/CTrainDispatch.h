#ifndef _TRAINDISPATCH_H_
#define _TRAINDISPATCH_H_
#include"Queue.h"

class CTrainDispatch
{
private:
	Queue H1, H2, H3;	//缓冲铁轨
	Queue InTrain;	//入轨车厢队列
public:
	CTrainDispatch(){}
	~CTrainDispatch(){}
	void Rand_int(int N);	//随机生成N个随机数,作为入轨车厢
	bool Sort(int N);	//将即将入轨的火车车厢排序后出轨
	void printInTrain(){ InTrain.printQueue(); }	//输出即将入轨的车厢
};

#endif