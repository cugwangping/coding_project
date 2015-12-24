#include"stdafx.h"
#include"MaxHeap.h"

void MaxHeap::ShiftDown(int start, int m)	//���µ����㷨[start, m], mΪ���һ����Ҫ�����Ľ��λ��
{
	int i = start, j = 2 * i + 1;	//i��˫�׽��λ�ã�j��i������Ůλ��
	int temp = heap[i];		//����Ҫ���µ�����˫�׽�����ݴ����м����temp��
	while (j <= m)	//�ж��Ƿ����λ�ã���������ˣ��˳�ѭ��
	{
		if (j<m&&heap[j]<heap[j + 1])
			j++;	//��jָ��������Ů�еĽϴ���
		if (temp >= heap[j])	//�����������Ů�����˳�ѭ��
			break;
		else
		{
			heap[i] = heap[j];	//��С���ݵĽ�����ϻ���
			i = j;		//�������±Ƚϣ�����Ľ�С���ݵĽ��������ϻ���
			j = 2 * j + 1;
		}
		heap[i] = temp;		//���ݴ�����ݷŻ�ȥ
	}
}

void MaxHeap::ShiftUp(int start)	//���ϵ����㷨[start, 0]
{
	int i = start, j = (i - 1) / 2;
	int temp = heap[i];		//����Ҫ���ϵ�������Ů������ݴ����м����temp��
	while (i >0)	//�ж��Ƿ񵽸����λ�ã�����ǣ��˳�ѭ��
	{
		if (heap[i] < heap[i + 1])
			i++;
		if (temp <= heap[j])	//�����������Ů�����˳�ѭ��
			break;
		else
		{
			heap[i] = heap[j];	//��С�������»���
			i = j;	//�������ϱȽϣ������С�����ݵĽ��������ϻ���
			j = (i - 1) / 2;
		}
		heap[i] = temp;		//���ݴ�����ݷŻ�ȥ
	}
}

MaxHeap::MaxHeap(int size)	//�����ն�
{
	MaxHeapSize = size;
	heap = new int[MaxHeapSize];
	if (MaxHeapSize == 0)
		throw MaxHeapSize;
	CurrentSize = 0;
}
MaxHeap::MaxHeap(int arr[], int n)	//ͨ�����鴫ֵ������
{
	MaxHeapSize = n;
	heap = new int[MaxHeapSize];
	if (MaxHeapSize == 0)
		throw MaxHeapSize;
	for (int i = 0; i < n; i++)		//�������飬����������
		heap[i] = arr[i];
	CurrentSize = n;	//���õ�ǰ�ĶѴ�С
	int Current_AdjustPosition = (CurrentSize - 2) / 2;		//���������λ�ã�Ϊ���һ������˫�׽��
	while (Current_AdjustPosition >= 0)		//���������˫�׽�㿪ʼ�Ƚϣ������ϣ�
	{
		ShiftDown(Current_AdjustPosition, CurrentSize - 1);		//�ֲ����������»�����
		Current_AdjustPosition--;
	}
}
MaxHeap::~MaxHeap()		//��������
{
	delete[]heap;
}
bool MaxHeap::IsEmpty()const{ return (CurrentSize == 0) ? true : false; }		//�ж϶ѿշ�
bool MaxHeap::IsFull()const{ return (CurrentSize == MaxHeapSize) ? true : false; }	//�ж϶�����
bool MaxHeap::Insert(const int& x)		//��x�������
{
	if (IsFull())
		return false;
	heap[CurrentSize] = x;		//����δ������x���뵽�ѵ���׶����һ�����λ��
	CurrentSize++;	//�ѵĵ�ǰԪ�ظ�����һ
	//������
	ShiftUp(CurrentSize - 1);
	return true;
}
bool MaxHeap::RemoveMin(int& x)		//ɾ���Ѷ�Ԫ��
{
	if (IsEmpty())
		return false;
	x = heap[0];	//ɾ���ĶѶ�Ԫ��ͨ��x����
	heap[0] = heap[CurrentSize - 1];	//ɾ������㣬�����һ��������Ϊ�����
	CurrentSize--;		//�ѵĵ�ǰ��С��һ
	//���µ����ѵ�˳��
	ShiftDown(0, CurrentSize - 1);
	return true;
}
bool MaxHeap::Find(int& x, int i)	//�������еĵ�i����㣬����������
{
	if (IsEmpty()||i<1||i>CurrentSize)
		return false;
	x = heap[i - 1];
	return true;
}