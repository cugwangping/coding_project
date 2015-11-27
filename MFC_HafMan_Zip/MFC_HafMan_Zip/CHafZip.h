#ifndef _CHAFZIP_H_
#define _CHAFZIP_H_
#include<iostream>
#include<fstream>
#include"PriorityQueue.h"

#define Len 65536	//64KB

class CHafZip
{
private:
	CString ReadFile, WriteFile;	//���ļ���д�ļ����ļ���
	//char buffer[Len];	//��ȡ�ļ�ʱ�Ļ���������
	//int size = 0;	//�˴����ݶ�ȡ���ļ��ж������ַ�����
	//int N;
	FileInformation File_Info[256];	//��charת��Ϊ��Ӧ��ASCII�룬Ȼ����ַ�����Ϣ�ʹ����±�Ϊ��ASCII���������
	//FileInformation *HafInfo;	//����Haf��ʱ��Ҫ�����������Ϣ
	LinkNode *root;		//������HafMan���ĸ����
	PriorityQueue<LinkNode> Q;
	string path;		//����Ҷ�ӽ���·������Ϊ0����Ϊ1��
protected:
	bool DeleteHaf(LinkNode *Root);		//�ݹ�ɾ����Ҷ�ӽ��Ľ��
	bool PreVisit(LinkNode *Root);		//ǰ�����,��ȡҶ����·��
	bool CreatHafTree();	//���ݶ�ȡ������Ϣ����Haf��
	void FileInput();		//��ȡ�ļ������
public:
	CHafZip(CString Read_File, CString Write_File);		//���캯��
	~CHafZip();		//��������
	bool Encode();	//ѹ���ļ��ı��뺯��
	bool Decode();	//��ѹ�ļ��Ľ��뺯��
};



#endif