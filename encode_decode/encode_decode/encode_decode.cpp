// encode_decode.cpp : 定义控制台应用程序的入口点。
//
#include"stdafx.h"
#include"PasswordTable.h"


int main(int argc, char *argv[])		
{
	cout << "Operation Choices :\n";		//操作提醒
	cout << "1. code \t" << "2.decode \t" << "3.exit" << endl;
	int option;		//操作选择
	cout << "Please input a int data as your operation choice!\n";
	cin >> option;
	PasswordTable p;
	switch (option)
	{
	case 1:
		p.code();		//编码
		break;
	case 2:
		p.decode();		//解码
		break;
	case 3:
		cout << "exit option!\n";
		return 0;		//退出
	default:
		cout << "Choose Error!\n";		//选择错误
		break;
	}
	return 0;
}
