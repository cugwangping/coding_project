#ifndef _TRAINDISPATCH_H_
#define _TRAINDISPATCH_H_
#include"Queue.h"

class CTrainDispatch
{
private:
	Queue H1, H2, H3;	//��������
	Queue InTrain;	//��쳵�����
public:
	CTrainDispatch(){}
	~CTrainDispatch(){}
	void Rand_int(int N);	//�������N�������,��Ϊ��쳵��
	bool Sort(int N);	//���������Ļ𳵳�����������
	void printInTrain(){ InTrain.printQueue(); }	//����������ĳ���
};

#endif