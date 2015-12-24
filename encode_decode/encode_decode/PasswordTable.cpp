#include"stdafx.h"
#include"PasswordTable.h"

PasswordTable::PasswordTable()
{
	//动态分配二维密码表		//使用动态分配二维数组，调试过程中出现中断，报错为无效的地址，堆损坏。
	/*table = new char*[95];
	for (int i = 0; i < 95; i++)
		table[i] = new char[i];*/
	int m = 0;
	for (int i = 0; i < 95; i++)
	{
		for (int j = 0; j < 95; j++)
		{
			m = (i + j) % 95;	//二维数组下标从0~94，
			table[i][j] = m + 32;	//ASCII码字符从32~126
		}
	}
}

PasswordTable::~PasswordTable()
{
	////释放二维数组空间
	//for (int i = 0; i < 95; i++)
	//	delete[]table[i];
	//delete[]table;
}

void PasswordTable::code()		//编码
{
	string encodeStr;
	cout << "Please input a string as the encode string!" << endl;
	cin >> encodeStr;
	int encodeStr_size = encodeStr.length();
	char path_in[256];		//编码文本路径
	cout << "Please input the path of encode text data!\n";
	cin >> path_in;
	ifstream file_in;
	file_in.open(path_in, ios::binary);
	char encode_ch;		//从编码文本中读取的字符
	ofstream file_out("encode_output.txt");
	int k = -1;
	while (file_in.get(encode_ch))
	{
		if (encode_ch < 32 || encode_ch>126)
		{
			file_out << encode_ch;
			continue;
		}
		k++;
		if (k >= encodeStr_size)
			k = 0;
		int x = encodeStr[k] - 32;
		int y =encode_ch - 32;
		file_out << table[x][y];
	}	
	file_out << endl;
	file_in.close();
	file_out.close();
}

void PasswordTable::decode()		//解码
{
	string decodeStr;
	cout << "Please input a string as the decode string!" << endl;
	cin >> decodeStr;
	int decodeStr_size = decodeStr.length();
	char path_in[256];		//编码文本路径
	cout << "Please input the path of decode text data!\n";
	cin >> path_in;
	ifstream file_in;
	file_in.open(path_in, ios::binary);
	char decode_ch;		//从解码文本中读取的字符
	ofstream file_out("decode_output.txt");
	int k = -1;
	while (file_in.get(decode_ch))
	{
		if (decode_ch < 32 || decode_ch>126)
		{
			file_out << decode_ch;
			continue;
		}
		k++;
		if (k >= decodeStr_size)
			k = 0;
		int x = decodeStr[k] - 32;
		for (int y = 0; y < 95; y++)
		{
			if (table[x][y] != decode_ch)
				continue;
			file_out << char(y + 32);
		}
	}
	file_out << endl;
	file_in.close();
	file_out.close();
}