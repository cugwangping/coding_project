#include"stdafx.h"
#include"MaxHeap.h"

void MaxHeap::ShiftDown(int start, int m)	//向下调整算法[start, m], m为最后一个需要调整的结点位置
{
	int i = start, j = 2 * i + 1;	//i是双亲结点位置，j是i的左子女位置
	int temp = heap[i];		//将需要向下调整的双亲结点数据存入中间变量temp中
	while (j <= m)	//判断是否到最后位置，如果超出了，退出循环
	{
		if (j<m&&heap[j]<heap[j + 1])
			j++;	//让j指向左右子女中的较大者
		if (temp >= heap[j])	//如果父结点比子女结点大，退出循环
			break;
		else
		{
			heap[i] = heap[j];	//较小数据的结点向上滑动
			i = j;		//继续向下比较，下面的较小数据的结点继续向上滑动
			j = 2 * j + 1;
		}
		heap[i] = temp;		//将暂存的数据放回去
	}
}

void MaxHeap::ShiftUp(int start)	//向上调整算法[start, 0]
{
	int i = start, j = (i - 1) / 2;
	int temp = heap[i];		//将需要向上调整的子女结点数据存入中间变量temp中
	while (i >0)	//判断是否到根结点位置，如果是，退出循环
	{
		if (heap[i] < heap[i + 1])
			i++;
		if (temp <= heap[j])	//如果父结点比子女结点大，退出循环
			break;
		else
		{
			heap[i] = heap[j];	//较小数据向下滑动
			i = j;	//继续向上比较，上面较小的数据的结点继续向上滑动
			j = (i - 1) / 2;
		}
		heap[i] = temp;		//将暂存的数据放回去
	}
}

MaxHeap::MaxHeap(int size)	//建立空堆
{
	MaxHeapSize = size;
	heap = new int[MaxHeapSize];
	if (MaxHeapSize == 0)
		throw MaxHeapSize;
	CurrentSize = 0;
}
MaxHeap::MaxHeap(int arr[], int n)	//通过数组传值建立堆
{
	MaxHeapSize = n;
	heap = new int[MaxHeapSize];
	if (MaxHeapSize == 0)
		throw MaxHeapSize;
	for (int i = 0; i < n; i++)		//复制数组，建立堆数据
		heap[i] = arr[i];
	CurrentSize = n;	//设置当前的堆大小
	int Current_AdjustPosition = (CurrentSize - 2) / 2;		//找最初调整位置，为最后一个结点的双亲结点
	while (Current_AdjustPosition >= 0)		//从最下面的双亲结点开始比较，逐步向上；
	{
		ShiftDown(Current_AdjustPosition, CurrentSize - 1);		//局部自上向下下滑调整
		Current_AdjustPosition--;
	}
}
MaxHeap::~MaxHeap()		//析构函数
{
	delete[]heap;
}
bool MaxHeap::IsEmpty()const{ return (CurrentSize == 0) ? true : false; }		//判断堆空否
bool MaxHeap::IsFull()const{ return (CurrentSize == MaxHeapSize) ? true : false; }	//判断堆满否
bool MaxHeap::Insert(const int& x)		//将x插入堆中
{
	if (IsFull())
		return false;
	heap[CurrentSize] = x;		//若堆未满，将x插入到堆的最底端最后一个结点位置
	CurrentSize++;	//堆的当前元素个数加一
	//调整堆
	ShiftUp(CurrentSize - 1);
	return true;
}
bool MaxHeap::RemoveMin(int& x)		//删除堆顶元素
{
	if (IsEmpty())
		return false;
	x = heap[0];	//删除的堆顶元素通过x返回
	heap[0] = heap[CurrentSize - 1];	//删除根结点，将最后一个结点调整为根结点
	CurrentSize--;		//堆的当前大小减一
	//向下调整堆的顺序
	ShiftDown(0, CurrentSize - 1);
	return true;
}
bool MaxHeap::Find(int& x, int i)	//搜索堆中的第i个结点，返回其数据
{
	if (IsEmpty()||i<1||i>CurrentSize)
		return false;
	x = heap[i - 1];
	return true;
}