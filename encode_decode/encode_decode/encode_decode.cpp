// encode_decode.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include"stdafx.h"
#include"PasswordTable.h"


int main(int argc, char *argv[])		
{
	cout << "Operation Choices :\n";		//��������
	cout << "1. code \t" << "2.decode \t" << "3.exit" << endl;
	int option;		//����ѡ��
	cout << "Please input a int data as your operation choice!\n";
	cin >> option;
	PasswordTable p;
	switch (option)
	{
	case 1:
		p.code();		//����
		break;
	case 2:
		p.decode();		//����
		break;
	case 3:
		cout << "exit option!\n";
		return 0;		//�˳�
	default:
		cout << "Choose Error!\n";		//ѡ�����
		break;
	}
	return 0;
}
