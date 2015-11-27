#include"stdafx.h"
#include"CHafZip.h"

ifstream file_in;	//读取文件的文件流对象
ofstream file_out;	//写文件的文件流对象
//保护成员函数
void CHafZip::FileInput()		//获取文件的入口
{
	file_in.open(ReadFile, ios::in | ios::binary);
	file_in.seekg(0, ios::end);		//将光标置于文件尾
	int size = file_in.tellg();		//获取文件的字节数
	file_in.seekg(0, ios::beg);		//将光标置于文件头
	unsigned char buffer[Len];	//每次读取文件中LenB的数据
	int k = Len;
	while (!file_in.eof() && size>0)
	{
		if (size < k)
			k = size;
		file_in.read((char*)buffer, k*sizeof(char));	//每次读取文件中LenB的数据,最后一次读取可能不足1K
		for (int i = 0; i < k; i++)
			File_Info[buffer[i]].count++;
		size -= k;
	}
	file_in.close();
}

bool CHafZip::CreatHafTree()
{
	if (Q.IsEmpty())
		return false;
	LinkNode *left = NULL, *right = NULL, *parent = NULL;	//合并两个结点创建一棵二叉树
	while (!Q.IsEmpty())
	{
		//取出权值最小的两个结点出来重构二叉树
		if (parent)
			delete parent;
		parent = new LinkNode;	//创建新根结点，作为新树的根结点
		left = new LinkNode;
		right = new LinkNode;
		Q.DeQueue(left);
		Q.DeQueue(right);
		//根结点
		parent->LeftChild = left;		//左结点
		parent->RightChild = right;		//右结点
		parent->count_data = left->count_data + right->count_data;
		if (!Q.IsEmpty())
			Q.EnQueue(*parent);		//将新建的结点重新压入优先队列中
	}
	root = parent;
	return true;
}

bool CHafZip::PreVisit(LinkNode *Root)	//前序遍历,获取叶结点的路径
{
	if (Root == NULL)
		return false;
	LinkNode *ptr = Root;
	if (Root->LeftChild == NULL&&Root->RightChild == NULL)		//遍历到叶子结点,将路径传入File_In结构体数组中
	{
		File_Info[Root->ch_data].HafDistribute = path;		//将路径存入文件信息类中
		int size = path.length();
		File_Info[Root->ch_data].L = size;
		for (int i = 0; i < size; i++)
		{
			File_Info[Root->ch_data].Value <<= 1;
			File_Info[Root->ch_data].Value |= unsigned int(path[i] - '0');		//将01路径转换为无符号的整数
		}
		path = path.substr(0, path.length() - 1);
		return true;
	}
	path += "0";
	PreVisit(Root->LeftChild);
	path += "1";
	PreVisit(Root->RightChild);
	if (path.length()>0)
		path = path.substr(0, path.length() - 1);
	return true;
}

bool CHafZip::DeleteHaf(LinkNode *Root)		//递归删除非叶子结点的结点
{
	if (Root)
	{
		DeleteHaf(Root->LeftChild);
		DeleteHaf(Root->RightChild);
		delete Root;
		return true;
	}
	else
		return false;
}

//公有函数
CHafZip::CHafZip(CString Read_File, CString Write_File)	//构造函数
{
	//将需要处理的文件传入CHafZip类里
	ReadFile = Read_File;
	WriteFile = Write_File;
	//将从0~255中的ASCII码转换为字符存入File_Info数组中，作为编码和解码的信息
	for (int i = 0; i < 256; i++)
		File_Info[i].ch = i;
}

CHafZip::~CHafZip()		//析构函数
{
	DeleteHaf(root);	//递归删除HafMan树结点
}

bool CHafZip::Encode()	//压缩文件的编码函数
{
	FileInput();
	LinkNode NewNode;
	for (int i = 0; i < 256; i++)	//将读取到的数据存入优先队列--最小堆中
	{
		if (File_Info[i].count == 0)
			continue;
		else
		{
			//将读取到的数据存入优先队列
			NewNode.count_data = File_Info[i].count;
			NewNode.ch_data = File_Info[i].ch;
			NewNode.LeftChild = NULL;
			NewNode.RightChild = NULL;
			NewNode.Parent = NULL;
			Q.EnQueue(NewNode);
			NewNode = NULL;
		}
	}
	CreatHafTree();		//编码时创建HafMan树
	PreVisit(root);		//获取HafMan树的叶结点路径
	file_in.open(ReadFile, ios::in | ios::binary);		//第二次读取文件
	file_out.open(WriteFile, ios::in | ios::binary);
	if (!file_in)
		return false;
	file_in.seekg(0, ios::end);
	int size = file_in.tellg();
	file_in.seekg(0, ios::beg);
	unsigned int temp = 0;
	unsigned int ValueTemp = 0;
	unsigned char buffer[Len];	//每次读取文件中LenB的数据
	int k = Len;
	int L = 0;		//读取到的位数，满32为就写文件
	if (file_in.eof())
		return false;
	for (int i = 0; i<256; i++)
		file_out.write((char*)&File_Info[i].count, sizeof(unsigned int));
	while (!file_in.eof() && size >0)
	{
		if (size < k)		//处理剩下的不足32个字符的字符串
			k = size;
		file_in.read((char*)buffer, k*sizeof(char));	//每次读取文件中LenB的数据,最后一次读取可能不足LenK
		for (int i = 0; i < k; i++)
		{
			//str += File_Info[buffer[i]].HafDistribute;
			L += File_Info[buffer[i]].L;
			if (L == 32)
			{
				temp <<= File_Info[buffer[i]].L;
				temp |= File_Info[buffer[i]].Value;
				file_out.write((char*)&temp, sizeof(unsigned int));	//向文件中写入一个无符号的数字，二进制为01.
				temp = 0;
				L = 0;
			}
			else if (L > 32)		//每凑足32位就写一次文件
			{
				ValueTemp = File_Info[buffer[i]].Value;		//将Value进行拆分，temp与高位或，低位在将temp写入文件后赋给temp
				temp <<= (File_Info[buffer[i]].L + 32 - L);		//将temp移至刚好32位01
				ValueTemp >>= (L - 32);		//取高位
				temp |= ValueTemp;		//temp与高位或，得到32个01
				file_out.write((char*)&temp, sizeof(unsigned int));	//向文件中写入一个无符号的数字，二进制为01.
				temp = (File_Info[buffer[i]].Value << (64 - L)) >> (64 - L);		//将低位存入temp中
				L -= 32;
			}
			else
			{
				temp <<= File_Info[buffer[i]].L;
				temp |= File_Info[buffer[i]].Value;
			}
		}
		size -= k;
	}
	if (L > 0)	//处理最后不足4个字节的字符串
	{
		unsigned int Mark = L;
		file_out.write((char*)&Mark, sizeof(unsigned int));		//在最后一次写文件之前做个标记，记下不足32位的01共有多少位，以便解码时处理
		temp <<= (32 - L);
		file_out.write((char*)&temp, sizeof(unsigned int));	//向文件中写入一个无符号的数字，二进制为01.
	}
	file_in.close();
	file_out.close();
	return true;
}

bool CHafZip::Decode()	//解压文件的解码函数
{
	file_in.open(ReadFile, ios::in | ios::binary);
	file_out.open(WriteFile, ios::out | ios::binary);
	file_in.seekg(0, ios::end);		//获取文件的字节数
	int size = file_in.tellg();
	file_in.seekg(0, ios::beg);		//文件光标指向文件头
	//char buffer[sizeof(unsigned int)];	//每次读取文件中1KB的数据
	if (file_in.eof())
		return false;
	for (int i = 0; i < 256; i++)
		file_in.read((char*)&File_Info[i].count, sizeof(unsigned int));
	LinkNode NewNode;
	for (int i = 0; i < 256; i++)	//将读取到的数据存入优先队列--最小堆中
	{
		if (File_Info[i].count == 0)
			continue;
		else
		{
			NewNode.count_data = File_Info[i].count;
			NewNode.ch_data = File_Info[i].ch;
			NewNode.LeftChild = NULL;
			NewNode.RightChild = NULL;
			NewNode.Parent = NULL;
			Q.EnQueue(NewNode);
			NewNode = NULL;
		}
	}
	CreatHafTree();		//编码时创建HafMan树
	unsigned int temp = 0;
	unsigned int aBit = 0;
	LinkNode *ptr = root;
	size -= 256 * sizeof(unsigned int);
	while (!file_in.eof(), size>8)	//读到做标记的那个数据前
	{
		file_in.read((char*)&temp, sizeof(unsigned int));		//每次读取一个无符号的整数
		for (int i = 0; i < 32; i++)
		{
			aBit = temp;
			temp >>= 31;
			if (temp == 1)
				ptr = ptr->RightChild;
			else
				ptr = ptr->LeftChild;
			if (ptr->LeftChild == NULL&&ptr->RightChild == NULL)
			{
				file_out.write((char*)&ptr->ch_data, sizeof(char));		//找到叶结点，把解码字符写入文件
				ptr = root;
			}
			temp = aBit << 1;	//移除已经处理过的那一位
		}
		size -= 4;
	}
	//处理最后4个字节
	unsigned int Mark;	//标记了最后一个无符号的整数实际有多少位，可能不足因32而补零
	file_in.read((char*)&Mark, sizeof(unsigned int));	//读取做标记的数，指明最后一次读取应处理多少位
	file_in.read((char*)&temp, sizeof(unsigned int));	//最后一次读取，可能包含补的0
	for (unsigned int i = 0; i < Mark; i++)
	{
		aBit = temp;
		temp >>= 31;
		if (temp == 1)
			ptr = ptr->RightChild;
		else
			ptr = ptr->LeftChild;
		if (ptr->LeftChild == NULL&&ptr->RightChild == NULL)
		{
			file_out.write((char*)&ptr->ch_data, sizeof(char));		//找到叶结点，把解码字符写入文件
			ptr = root;
		}
		temp = aBit << 1;	//移除已经处理过的那一位
	}
	return true;
}
