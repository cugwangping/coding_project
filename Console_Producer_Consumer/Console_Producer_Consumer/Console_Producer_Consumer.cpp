// Console_Producer_Consumer.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"windows.h"
#include<iostream>
using namespace std;

const unsigned int Buffer_Size = 10;	//缓冲区长度为10
unsigned int ProductID = 0;	//生产者生产的产品的号码,每生产一个产品，产品ID+1
unsigned int ConsumeID = 0;	//被消费者消费的产品号码
unsigned int In = 0;	//产品进缓冲区时缓冲区的下标
unsigned int Out = 0;	//产品出缓冲区时缓冲区的下标
unsigned int Buffer[Buffer_Size];	//缓冲区，存储产品的ID
bool Continue = true;	//为true时执行while循环，为false时结束程序

typedef HANDLE Semaphore;		//信号量,解决线程之间的同步与互斥问题
Semaphore Mutex;	//生产者与消费者线程的互斥信号,为0时锁定
Semaphore Empty_Buffer;	//同步信号，空的缓冲区，为10时消费者必须等待
Semaphore Full_Buffer;	//同步信号，满的缓冲区，为10时生产者必须等待

//生产者生产产品
void Produce()
{
	cout << "Producer is producing		产品：" << ++ProductID << "......";
	cout << "	Produce Succeed!" << endl;
}

//把产品放入缓冲区
void Append()
{
	cout << "Producer is appending a product......";
	Buffer[In] = ProductID;
	cout << "Have Finished!" << endl;
	cout << "缓冲区:      产品号:      操作类型:" << endl;
	//输出缓冲区的当前状态
	for (int i = 0; i < Buffer_Size; i++)
	{
		cout << i << "		" << Buffer[i];
		if (Buffer[i] == 0)
			cout << "		无操作";
		else
		{
			if (i == In)
				cout << "		正在生产";
			else if (i == Out)
				cout << "		正在消费";
			else
				cout << "		无操作";
		}
		cout << endl;
	}
	In = (In + 1) % Buffer_Size;
	cout << endl;
}

//将产品从缓冲区取出
void Take()
{
	cout << "Consumer is taking a product......";
	ConsumeID = Buffer[Out];
	Out = (Out + 1) % Buffer_Size;
	cout << "Have Finished!" << endl;
	//输出缓冲区的当前状态
	cout << "缓冲区:      产品号:      操作类型:" << endl;
	for (int i = 0; i < Buffer_Size; i++)
	{
		cout << i << "		" << Buffer[i];
		if (Buffer[i] == 0)
			cout << "		无操作";
		else
		{
			if (i == In)
				cout << "		正在生产";
			else if (i == Out)
				cout << "		正在消费";
			else
				cout << "		无操作";
		}
		cout << endl;
	}
	cout << endl;
}

//消费者消费产品
void Consume()
{
	cout << "Consumer is consuming		产品：" << ConsumeID << "......";
	cout << "	Consume Finished!" << endl;
}

DWORD WINAPI Producer(LPVOID lpPara)	//生产者线程
{
	while (Continue)
	{
		WaitForSingleObject(Full_Buffer, INFINITE);		//若缓冲区已满，无法再往缓冲区放入产品，生产者必须等待。
		WaitForSingleObject(Mutex, INFINITE);	//生产者在缓冲区，锁定缓冲区，拒绝其他线程的访问
		Produce();		//生产者生产产品
		Append();		//生产者将产品放入缓冲区
		Sleep(1000);	
		ReleaseMutex(Mutex);		//生产者已离开缓冲区，解除锁定，可以接受下一个就绪的线程的访问
		ReleaseSemaphore(Empty_Buffer, 1, NULL);		//
	}
	return 0;
}

DWORD WINAPI Consumer(LPVOID lpPara)	//消费者线程
{
	while (Continue)
	{
		WaitForSingleObject(Empty_Buffer, INFINITE);	//若缓冲区为空，无法再从缓冲区取出产品，消费者必须等待。
		WaitForSingleObject(Mutex, INFINITE);	//消费者者在缓冲区，锁定缓冲区，拒绝其他线程的访问
		Take();		//消费者从缓冲区提取产品
		Consume();		//消费者消费产品
		Sleep(1000);
		ReleaseMutex(Mutex);		//消费者已离开缓冲区，解除锁定，可以接受下一个就绪的线程的访问
		ReleaseSemaphore(Full_Buffer, 1, NULL);
	}
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "                      **************************" << endl;
	cout << endl;
	cout << "              *******欢迎进入生产者与消费者问题！*********" << endl;
	cout << endl;
	cout << "        *******************************************************" << endl;
	cout << "****************************************************************************" << endl;
	//创建信号
	Mutex = CreateMutex(NULL, FALSE, NULL);
	Full_Buffer = CreateSemaphore(NULL, Buffer_Size - 1, Buffer_Size - 1, NULL);
	Empty_Buffer = CreateSemaphore(NULL, 0, Buffer_Size - 1, NULL);
	//设置生产者与消费者的数量（线程的数量）
	const unsigned int Producer_Num = 1;	//一个生产者
	const unsigned int Consumer_Num = 1;	//一个消费者
	const unsigned int Threads_Num = Producer_Num + Consumer_Num;	//总线程数为 生产者线程+消费者线程

	HANDLE Threads[Threads_Num];	//各线程的句柄
	DWORD ProducerID[Producer_Num];		//生产者的ID
	DWORD ConsumerID[Consumer_Num];		//消费者的ID
	//创建生产者线程
	for (int i = 0; i < Producer_Num; i++)
	{
		Threads[i] = CreateThread(NULL, 0, Producer, NULL, 0, &ProducerID[i]);
		if (Threads[i] == NULL)
			return -1;
	}

	//创建消费者线程
	for (int i = 0; i < Consumer_Num; i++)
	{
		Threads[Producer_Num + i] = CreateThread(NULL, 0, Consumer, NULL, 0, &ConsumerID[i]);
		if (Threads[i] == NULL)
			return -1;
	}

	while (Continue)
	{
		if (getchar())	 //按回车将会终止程序运行
			Continue = false;
	}
	//system("pause");
	return 0;
}
