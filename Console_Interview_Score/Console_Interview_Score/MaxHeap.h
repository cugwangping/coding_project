#ifndef _MAXHEAP_H_
#define _MAXHEAP_H_
#include<iostream>
using namespace std;

class MaxHeap
{
private:
	int *heap;	//��С��Ԫ�ش洢����
	int CurrentSize;	//��С�ѵ�ǰԪ�ظ���
	int MaxHeapSize;	//��С���������
	void ShiftDown(int start, int m);	//���µ����㷨[start, m]
	void ShiftUp(int start);	//���ϵ����㷨[start, 0]
public:
	MaxHeap(int size = 100);	//�����ն�
	MaxHeap(int arr[], int n);	//ͨ�����鴫ֵ������
	~MaxHeap();
	bool IsEmpty()const;		//�ж϶ѿշ�
	bool IsFull()const;	//�ж϶�����
	bool Insert(const int& x);		//��x�������
	bool RemoveMin(int& x);		//ɾ���Ѷ�Ԫ��
	bool Find(int& x, int i);	//�������еĵ�i����㣬����������
};

#endif