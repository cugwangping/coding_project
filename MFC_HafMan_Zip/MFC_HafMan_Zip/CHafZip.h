#ifndef _CHAFZIP_H_
#define _CHAFZIP_H_
#include<iostream>
#include<fstream>
#include"PriorityQueue.h"

#define Len 65536	//64KB

class CHafZip
{
private:
	CString ReadFile, WriteFile;	//读文件和写文件的文件名
	//char buffer[Len];	//读取文件时的缓冲区数组
	//int size = 0;	//此次数据读取从文件中读到的字符种类
	//int N;
	FileInformation File_Info[256];	//将char转换为对应的ASCII码，然后此字符的信息就存入下标为此ASCII码的数组中
	//FileInformation *HafInfo;	//建立Haf树时需要传入的数据信息
	LinkNode *root;		//创建的HafMan树的根结点
	PriorityQueue<LinkNode> Q;
	string path;		//遍历叶子结点的路径，左为0，右为1；
protected:
	bool DeleteHaf(LinkNode *Root);		//递归删除非叶子结点的结点
	bool PreVisit(LinkNode *Root);		//前序遍历,获取叶结点的路径
	bool CreatHafTree();	//根据读取到的信息创建Haf树
	void FileInput();		//获取文件的入口
public:
	CHafZip(CString Read_File, CString Write_File);		//构造函数
	~CHafZip();		//析构函数
	bool Encode();	//压缩文件的编码函数
	bool Decode();	//解压文件的解码函数
};



#endif