// Console_Producer_Consumer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"windows.h"
#include<iostream>
using namespace std;

const unsigned int Buffer_Size = 10;	//����������Ϊ10
unsigned int ProductID = 0;	//�����������Ĳ�Ʒ�ĺ���,ÿ����һ����Ʒ����ƷID+1
unsigned int ConsumeID = 0;	//�����������ѵĲ�Ʒ����
unsigned int In = 0;	//��Ʒ��������ʱ���������±�
unsigned int Out = 0;	//��Ʒ��������ʱ���������±�
unsigned int Buffer[Buffer_Size];	//���������洢��Ʒ��ID
bool Continue = true;	//Ϊtrueʱִ��whileѭ����Ϊfalseʱ��������

typedef HANDLE Semaphore;		//�ź���,����߳�֮���ͬ���뻥������
Semaphore Mutex;	//���������������̵߳Ļ����ź�,Ϊ0ʱ����
Semaphore Empty_Buffer;	//ͬ���źţ��յĻ�������Ϊ10ʱ�����߱���ȴ�
Semaphore Full_Buffer;	//ͬ���źţ����Ļ�������Ϊ10ʱ�����߱���ȴ�

//������������Ʒ
void Produce()
{
	cout << "Producer is producing		��Ʒ��" << ++ProductID << "......";
	cout << "	Produce Succeed!" << endl;
}

//�Ѳ�Ʒ���뻺����
void Append()
{
	cout << "Producer is appending a product......";
	Buffer[In] = ProductID;
	cout << "Have Finished!" << endl;
	cout << "������:      ��Ʒ��:      ��������:" << endl;
	//����������ĵ�ǰ״̬
	for (int i = 0; i < Buffer_Size; i++)
	{
		cout << i << "		" << Buffer[i];
		if (Buffer[i] == 0)
			cout << "		�޲���";
		else
		{
			if (i == In)
				cout << "		��������";
			else if (i == Out)
				cout << "		��������";
			else
				cout << "		�޲���";
		}
		cout << endl;
	}
	In = (In + 1) % Buffer_Size;
	cout << endl;
}

//����Ʒ�ӻ�����ȡ��
void Take()
{
	cout << "Consumer is taking a product......";
	ConsumeID = Buffer[Out];
	Out = (Out + 1) % Buffer_Size;
	cout << "Have Finished!" << endl;
	//����������ĵ�ǰ״̬
	cout << "������:      ��Ʒ��:      ��������:" << endl;
	for (int i = 0; i < Buffer_Size; i++)
	{
		cout << i << "		" << Buffer[i];
		if (Buffer[i] == 0)
			cout << "		�޲���";
		else
		{
			if (i == In)
				cout << "		��������";
			else if (i == Out)
				cout << "		��������";
			else
				cout << "		�޲���";
		}
		cout << endl;
	}
	cout << endl;
}

//���������Ѳ�Ʒ
void Consume()
{
	cout << "Consumer is consuming		��Ʒ��" << ConsumeID << "......";
	cout << "	Consume Finished!" << endl;
}

DWORD WINAPI Producer(LPVOID lpPara)	//�������߳�
{
	while (Continue)
	{
		WaitForSingleObject(Full_Buffer, INFINITE);		//���������������޷����������������Ʒ�������߱���ȴ���
		WaitForSingleObject(Mutex, INFINITE);	//�������ڻ��������������������ܾ������̵߳ķ���
		Produce();		//������������Ʒ
		Append();		//�����߽���Ʒ���뻺����
		Sleep(1000);	
		ReleaseMutex(Mutex);		//���������뿪��������������������Խ�����һ���������̵߳ķ���
		ReleaseSemaphore(Empty_Buffer, 1, NULL);		//
	}
	return 0;
}

DWORD WINAPI Consumer(LPVOID lpPara)	//�������߳�
{
	while (Continue)
	{
		WaitForSingleObject(Empty_Buffer, INFINITE);	//��������Ϊ�գ��޷��ٴӻ�����ȡ����Ʒ�������߱���ȴ���
		WaitForSingleObject(Mutex, INFINITE);	//���������ڻ��������������������ܾ������̵߳ķ���
		Take();		//�����ߴӻ�������ȡ��Ʒ
		Consume();		//���������Ѳ�Ʒ
		Sleep(1000);
		ReleaseMutex(Mutex);		//���������뿪��������������������Խ�����һ���������̵߳ķ���
		ReleaseSemaphore(Full_Buffer, 1, NULL);
	}
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "                      **************************" << endl;
	cout << endl;
	cout << "              *******��ӭ���������������������⣡*********" << endl;
	cout << endl;
	cout << "        *******************************************************" << endl;
	cout << "****************************************************************************" << endl;
	//�����ź�
	Mutex = CreateMutex(NULL, FALSE, NULL);
	Full_Buffer = CreateSemaphore(NULL, Buffer_Size - 1, Buffer_Size - 1, NULL);
	Empty_Buffer = CreateSemaphore(NULL, 0, Buffer_Size - 1, NULL);
	//�����������������ߵ��������̵߳�������
	const unsigned int Producer_Num = 1;	//һ��������
	const unsigned int Consumer_Num = 1;	//һ��������
	const unsigned int Threads_Num = Producer_Num + Consumer_Num;	//���߳���Ϊ �������߳�+�������߳�

	HANDLE Threads[Threads_Num];	//���̵߳ľ��
	DWORD ProducerID[Producer_Num];		//�����ߵ�ID
	DWORD ConsumerID[Consumer_Num];		//�����ߵ�ID
	//�����������߳�
	for (int i = 0; i < Producer_Num; i++)
	{
		Threads[i] = CreateThread(NULL, 0, Producer, NULL, 0, &ProducerID[i]);
		if (Threads[i] == NULL)
			return -1;
	}

	//�����������߳�
	for (int i = 0; i < Consumer_Num; i++)
	{
		Threads[Producer_Num + i] = CreateThread(NULL, 0, Consumer, NULL, 0, &ConsumerID[i]);
		if (Threads[i] == NULL)
			return -1;
	}

	while (Continue)
	{
		if (getchar())	 //���س�������ֹ��������
			Continue = false;
	}
	//system("pause");
	return 0;
}
