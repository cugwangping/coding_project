#ifndef _MAXHEAP_H_
#define _MAXHEAP_H_
#include<iostream>
using namespace std;

class MaxHeap
{
private:
	int *heap;	//最小堆元素存储数组
	int CurrentSize;	//最小堆当前元素个数
	int MaxHeapSize;	//最小堆最大容量
	void ShiftDown(int start, int m);	//向下调整算法[start, m]
	void ShiftUp(int start);	//向上调整算法[start, 0]
public:
	MaxHeap(int size = 100);	//建立空堆
	MaxHeap(int arr[], int n);	//通过数组传值建立堆
	~MaxHeap();
	bool IsEmpty()const;		//判断堆空否
	bool IsFull()const;	//判断堆满否
	bool Insert(const int& x);		//将x插入堆中
	bool RemoveMin(int& x);		//删除堆顶元素
	bool Find(int& x, int i);	//搜索堆中的第i个结点，返回其数据
};

#endif