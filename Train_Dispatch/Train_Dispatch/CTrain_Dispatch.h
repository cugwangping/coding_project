#ifndef _TRAIN_DISPATCH_H_
#define _TRAIN_DISPATCH_H_
#include<iostream>
#include<ctime>
using namespace std;
#define k 3

class CTrainDispatch
{
private:
	int N;	//N�ڳ���
	int *Hold;	//�𳵵�N����쳵��
	int *Track; 	//��쳵���������Ļ�������
	int *LastPosition;	//��¼�������������һ��Ԫ��
public:
	CTrainDispatch(int n);
	~CTrainDispatch();
	void Rand_int();	//�������N�������,��Ϊ��쳵��
	bool Sort();	//���������Ļ𳵳�����������
	void printTrack();		//���ÿ�ڳ�����������·��
	void printRadomSeq();	//����������ĳ���
};

#endif