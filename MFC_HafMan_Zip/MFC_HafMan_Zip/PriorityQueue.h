#ifndef _PRIORITYQUEUE_H_
#define _PRIORITYQUEUE_H_
#include"LinkNode.h"

//���ȶ���--��С��
template <class T>
class PriorityQueue
{
private:
	int MaxSize;	//��С�ѵ��������
	int CurrentSize;	//��С�ѵĵ�ǰ����
	//char *ch_data;		//�洢�ַ����ݵ�����
	//int *count_data;	//�洢�ַ�Ƶ��������
	T *Node;	//�洢��������
	void ShiftDown(int Start, int End); //���µ����㷨[Start, End]
	void ShiftUp(int Start);		//���ϵ����㷨[Start,0]
public:
	PriorityQueue(int size = 256); 	//���캯��
	PriorityQueue(T arr[], int size = 256);	//���캯��
	~PriorityQueue();	//��������
	bool IsEmpty(){ return CurrentSize == 0; }
	bool IsFull(){ return CurrentSize == MaxSize; }
	bool EnQueue(const T Sub);		//Ԫ�شӶ������
	bool DeQueue(T *& Sub);		//Ԫ�شӶ�β����
};

template <class T>
void PriorityQueue<T>::ShiftDown(int Start, int End) //���µ����㷨[Start, End]
{
	int i = Start, j = 2 * i + 1;	//j��i������Ůλ��
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
void PriorityQueue<T>::ShiftUp(int Start) //���ϵ����㷨[Start,0]
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
PriorityQueue<T>::PriorityQueue(int size) 	//���캯��,����һ���ն�
{
	if (size > 0)
	{
		MaxSize = size;
		Node = new T[MaxSize];
		CurrentSize = 0;	//�նѵ�ǰ��СΪ0��
	}
}

template <class T>
PriorityQueue<T>::PriorityQueue(T arr[], int size) 	//���캯��
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