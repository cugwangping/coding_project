// ListReversal.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"List.h"
#include<iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	List<int> L;
	cout << "������һ������������Ϊ����Ľ�������" << endl;
	int EndTag;		//��������������Ľ�����
	cin >> EndTag;
	cout << "��������Ӧ���������������������" << endl;
	L.PreInput(EndTag);		//ǰ�巨����������
	L.printList();		//��������ĵ�����
	L.reversal();		//������ת
	cout << "��ת��ĵ�����:" << endl;
	L.printList();		//�����ת��ĵ�����
	return 0;
}

