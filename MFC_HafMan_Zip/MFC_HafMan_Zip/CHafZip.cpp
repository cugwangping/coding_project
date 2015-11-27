#include"stdafx.h"
#include"CHafZip.h"

ifstream file_in;	//��ȡ�ļ����ļ�������
ofstream file_out;	//д�ļ����ļ�������
//������Ա����
void CHafZip::FileInput()		//��ȡ�ļ������
{
	file_in.open(ReadFile, ios::in | ios::binary);
	file_in.seekg(0, ios::end);		//����������ļ�β
	int size = file_in.tellg();		//��ȡ�ļ����ֽ���
	file_in.seekg(0, ios::beg);		//����������ļ�ͷ
	unsigned char buffer[Len];	//ÿ�ζ�ȡ�ļ���LenB������
	int k = Len;
	while (!file_in.eof() && size>0)
	{
		if (size < k)
			k = size;
		file_in.read((char*)buffer, k*sizeof(char));	//ÿ�ζ�ȡ�ļ���LenB������,���һ�ζ�ȡ���ܲ���1K
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
	LinkNode *left = NULL, *right = NULL, *parent = NULL;	//�ϲ�������㴴��һ�ö�����
	while (!Q.IsEmpty())
	{
		//ȡ��Ȩֵ��С�������������ع�������
		if (parent)
			delete parent;
		parent = new LinkNode;	//�����¸���㣬��Ϊ�����ĸ����
		left = new LinkNode;
		right = new LinkNode;
		Q.DeQueue(left);
		Q.DeQueue(right);
		//�����
		parent->LeftChild = left;		//����
		parent->RightChild = right;		//�ҽ��
		parent->count_data = left->count_data + right->count_data;
		if (!Q.IsEmpty())
			Q.EnQueue(*parent);		//���½��Ľ������ѹ�����ȶ�����
	}
	root = parent;
	return true;
}

bool CHafZip::PreVisit(LinkNode *Root)	//ǰ�����,��ȡҶ����·��
{
	if (Root == NULL)
		return false;
	LinkNode *ptr = Root;
	if (Root->LeftChild == NULL&&Root->RightChild == NULL)		//������Ҷ�ӽ��,��·������File_In�ṹ��������
	{
		File_Info[Root->ch_data].HafDistribute = path;		//��·�������ļ���Ϣ����
		int size = path.length();
		File_Info[Root->ch_data].L = size;
		for (int i = 0; i < size; i++)
		{
			File_Info[Root->ch_data].Value <<= 1;
			File_Info[Root->ch_data].Value |= unsigned int(path[i] - '0');		//��01·��ת��Ϊ�޷��ŵ�����
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

bool CHafZip::DeleteHaf(LinkNode *Root)		//�ݹ�ɾ����Ҷ�ӽ��Ľ��
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

//���к���
CHafZip::CHafZip(CString Read_File, CString Write_File)	//���캯��
{
	//����Ҫ������ļ�����CHafZip����
	ReadFile = Read_File;
	WriteFile = Write_File;
	//����0~255�е�ASCII��ת��Ϊ�ַ�����File_Info�����У���Ϊ����ͽ������Ϣ
	for (int i = 0; i < 256; i++)
		File_Info[i].ch = i;
}

CHafZip::~CHafZip()		//��������
{
	DeleteHaf(root);	//�ݹ�ɾ��HafMan�����
}

bool CHafZip::Encode()	//ѹ���ļ��ı��뺯��
{
	FileInput();
	LinkNode NewNode;
	for (int i = 0; i < 256; i++)	//����ȡ�������ݴ������ȶ���--��С����
	{
		if (File_Info[i].count == 0)
			continue;
		else
		{
			//����ȡ�������ݴ������ȶ���
			NewNode.count_data = File_Info[i].count;
			NewNode.ch_data = File_Info[i].ch;
			NewNode.LeftChild = NULL;
			NewNode.RightChild = NULL;
			NewNode.Parent = NULL;
			Q.EnQueue(NewNode);
			NewNode = NULL;
		}
	}
	CreatHafTree();		//����ʱ����HafMan��
	PreVisit(root);		//��ȡHafMan����Ҷ���·��
	file_in.open(ReadFile, ios::in | ios::binary);		//�ڶ��ζ�ȡ�ļ�
	file_out.open(WriteFile, ios::in | ios::binary);
	if (!file_in)
		return false;
	file_in.seekg(0, ios::end);
	int size = file_in.tellg();
	file_in.seekg(0, ios::beg);
	unsigned int temp = 0;
	unsigned int ValueTemp = 0;
	unsigned char buffer[Len];	//ÿ�ζ�ȡ�ļ���LenB������
	int k = Len;
	int L = 0;		//��ȡ����λ������32Ϊ��д�ļ�
	if (file_in.eof())
		return false;
	for (int i = 0; i<256; i++)
		file_out.write((char*)&File_Info[i].count, sizeof(unsigned int));
	while (!file_in.eof() && size >0)
	{
		if (size < k)		//����ʣ�µĲ���32���ַ����ַ���
			k = size;
		file_in.read((char*)buffer, k*sizeof(char));	//ÿ�ζ�ȡ�ļ���LenB������,���һ�ζ�ȡ���ܲ���LenK
		for (int i = 0; i < k; i++)
		{
			//str += File_Info[buffer[i]].HafDistribute;
			L += File_Info[buffer[i]].L;
			if (L == 32)
			{
				temp <<= File_Info[buffer[i]].L;
				temp |= File_Info[buffer[i]].Value;
				file_out.write((char*)&temp, sizeof(unsigned int));	//���ļ���д��һ���޷��ŵ����֣�������Ϊ01.
				temp = 0;
				L = 0;
			}
			else if (L > 32)		//ÿ����32λ��дһ���ļ�
			{
				ValueTemp = File_Info[buffer[i]].Value;		//��Value���в�֣�temp���λ�򣬵�λ�ڽ�tempд���ļ��󸳸�temp
				temp <<= (File_Info[buffer[i]].L + 32 - L);		//��temp�����պ�32λ01
				ValueTemp >>= (L - 32);		//ȡ��λ
				temp |= ValueTemp;		//temp���λ�򣬵õ�32��01
				file_out.write((char*)&temp, sizeof(unsigned int));	//���ļ���д��һ���޷��ŵ����֣�������Ϊ01.
				temp = (File_Info[buffer[i]].Value << (64 - L)) >> (64 - L);		//����λ����temp��
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
	if (L > 0)	//���������4���ֽڵ��ַ���
	{
		unsigned int Mark = L;
		file_out.write((char*)&Mark, sizeof(unsigned int));		//�����һ��д�ļ�֮ǰ������ǣ����²���32λ��01���ж���λ���Ա����ʱ����
		temp <<= (32 - L);
		file_out.write((char*)&temp, sizeof(unsigned int));	//���ļ���д��һ���޷��ŵ����֣�������Ϊ01.
	}
	file_in.close();
	file_out.close();
	return true;
}

bool CHafZip::Decode()	//��ѹ�ļ��Ľ��뺯��
{
	file_in.open(ReadFile, ios::in | ios::binary);
	file_out.open(WriteFile, ios::out | ios::binary);
	file_in.seekg(0, ios::end);		//��ȡ�ļ����ֽ���
	int size = file_in.tellg();
	file_in.seekg(0, ios::beg);		//�ļ����ָ���ļ�ͷ
	//char buffer[sizeof(unsigned int)];	//ÿ�ζ�ȡ�ļ���1KB������
	if (file_in.eof())
		return false;
	for (int i = 0; i < 256; i++)
		file_in.read((char*)&File_Info[i].count, sizeof(unsigned int));
	LinkNode NewNode;
	for (int i = 0; i < 256; i++)	//����ȡ�������ݴ������ȶ���--��С����
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
	CreatHafTree();		//����ʱ����HafMan��
	unsigned int temp = 0;
	unsigned int aBit = 0;
	LinkNode *ptr = root;
	size -= 256 * sizeof(unsigned int);
	while (!file_in.eof(), size>8)	//��������ǵ��Ǹ�����ǰ
	{
		file_in.read((char*)&temp, sizeof(unsigned int));		//ÿ�ζ�ȡһ���޷��ŵ�����
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
				file_out.write((char*)&ptr->ch_data, sizeof(char));		//�ҵ�Ҷ��㣬�ѽ����ַ�д���ļ�
				ptr = root;
			}
			temp = aBit << 1;	//�Ƴ��Ѿ����������һλ
		}
		size -= 4;
	}
	//�������4���ֽ�
	unsigned int Mark;	//��������һ���޷��ŵ�����ʵ���ж���λ�����ܲ�����32������
	file_in.read((char*)&Mark, sizeof(unsigned int));	//��ȡ����ǵ�����ָ�����һ�ζ�ȡӦ�������λ
	file_in.read((char*)&temp, sizeof(unsigned int));	//���һ�ζ�ȡ�����ܰ�������0
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
			file_out.write((char*)&ptr->ch_data, sizeof(char));		//�ҵ�Ҷ��㣬�ѽ����ַ�д���ļ�
			ptr = root;
		}
		temp = aBit << 1;	//�Ƴ��Ѿ����������һλ
	}
	return true;
}
