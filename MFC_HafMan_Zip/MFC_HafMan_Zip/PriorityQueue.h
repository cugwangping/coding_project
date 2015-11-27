#ifndef _PRIORITYQUEUE_H_
#define _PRIORITYQUEUE_H_
#include"LinkNode.h"

//优先队列--最小堆
template <class T>
class PriorityQueue
{
private:
	int MaxSize;	//最小堆的最大容量
	int CurrentSize;	//最小堆的当前容量
	//char *ch_data;		//存储字符数据的数组
	//int *count_data;	//存储字符频数的数组
	T *Node;	//存储结点的数组
	void ShiftDown(int Start, int End); //向下调整算法[Start, End]
	void ShiftUp(int Start);		//向上调整算法[Start,0]
public:
	PriorityQueue(int size = 256); 	//构造函数
	PriorityQueue(T arr[], int size = 256);	//构造函数
	~PriorityQueue();	//析构函数
	bool IsEmpty(){ return CurrentSize == 0; }
	bool IsFull(){ return CurrentSize == MaxSize; }
	bool EnQueue(const T Sub);		//元素从队首入队
	bool DeQueue(T *& Sub);		//元素从队尾出队
};

template <class T>
void PriorityQueue<T>::ShiftDown(int Start, int End) //向下调整算法[Start, End]
{
	int i = Start, j = 2 * i + 1;	//j是i的左子女位置
	T temp = Node[i];
	while (j <= End)
	{
		if (j<End&&Node[j]>Node[j + 1])
			j++;
		if (temp <= Node[j])
			break;
		else
		{
			Node[i] = Node[j];
			i = j;
			j = 2 * j + 1;
		}
	}
	Node[i] = temp;
}

template <class T>
void PriorityQueue<T>::ShiftUp(int Start) //向上调整算法[Start,0]
{
	int i = Start, j = (i - 1) / 2;
	T temp = Node[i];
	char ch_temp = Node[i].ch_data;
	while (i > 0)
	{
		if (Node[j] <= temp)
			break;
		else
		{
			Node[i] = Node[j];
			i = j;
			j = (i - 1) / 2;
		}
	}
	Node[i] = temp;
}

template <class T>
PriorityQueue<T>::PriorityQueue(int size) 	//构造函数,建立一个空堆
{
	if (size > 0)
	{
		MaxSize = size;
		Node = new T[MaxSize];
		CurrentSize = 0;	//空堆当前大小为0；
	}
}

template <class T>
PriorityQueue<T>::PriorityQueue(T arr[], int size) 	//构造函数
{
	if (size > 0)
	{
		MaxSize = size;
		Node = new LinkNode[MaxSize];
		for (int i = 0; i < size; i++)
		{
			Node[i].count_data = arr[i].count;
			Node[i].ch_data = arr[i].ch;
		}
		CurrentSize = size;
		int CurrentPosition = (CurrentSize - 2) / 2;
		while (CurrentPosition >= 0)
		{
			ShiftDown(CurrentPosition, CurrentSize - 1);
			CurrentPosition--;
		}
	}
}

template <class T>
PriorityQueue<T>::~PriorityQueue()
{
	delete[]Node;
}

template <class T>
bool PriorityQueue<T>::EnQueue(const T Sub)
{
	if (CurrentSize == MaxSize)
		return false;
	Node[CurrentSize] = Sub;
	ShiftUp(CurrentSize);
	CurrentSize++;
	return true;
}

template <class T>
bool PriorityQueue<T>::DeQueue(T *& Sub)
{
	if (CurrentSize == 0)
		return false;
	*Sub = Node[0];
	Node[0] = Node[CurrentSize - 1];
	CurrentSize--;
	ShiftDown(0, CurrentSize - 1);
	return true;
}

#endif