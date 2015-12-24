#ifndef _QUEUE_H_
#define _QUEUE_H_

template<class T>
class Queue
{
public:
	Queue(){}		//���캯��
	~Queue(){}		//��������
	virtual bool EnQueue(T x) = 0;		//������
	virtual bool DeQueue(T &x) = 0;		//������
	virtual bool getFront(T &x) = 0;		//ȡ��ͷ,Ԫ����x����
	virtual bool IsEmpty()const = 0;		//�ж϶ӿշ���Ϊ�գ�����true
	virtual bool IsFull()const = 0;		//�ж϶�������Ϊ��������true
	virtual int getSize()const = 0;		//ȡ���е�ǰԪ�صĸ���
};
#endif