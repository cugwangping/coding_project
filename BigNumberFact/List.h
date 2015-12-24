#ifndef List_H
#define List_H
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#define Over_Max 1000

struct LinkNode		//����������Ķ���
{
	int data;		//���������
	LinkNode *link;		//���ָ����
	LinkNode(LinkNode *ptr = NULL)
	{
		link = ptr;
	}
	LinkNode(const int &x, LinkNode *ptr = NULL)
	{
		data = x;
		link = ptr;
	}
};

class List		//��������Ķ���		
{
private:
	LinkNode *head;		//ͷ���
	LinkNode *last;		//β���
	int Remainder;	//����
	int CarryBit;	//��λ
public:
	List();
	List(const int& x);
	List(List& L);
	~List();
	void makeEmpty();
	LinkNode *getHead()const;	//ȡ�����ͷ���
	void reversal();	//����ת
	int getLastData();		//ȡ�����β��������
	bool Insert(int m);		//��β������ݴ���999���򽫽�λ�����½����
	void Fact(int n);		//�ݹ����׳�
	void printFact();		//����׳˵Ľ��
};

List::List()		//���βι��캯��
{
	head = new LinkNode;
	last = head;
}

List::List(const int& x)	//�вι��캯��
{
	head = new LinkNode(x);
	last = head;
}

List::List(List& L)	//���ƹ��캯��
{
	int value;
	LinkNode *srcptr = L.getHead();		//�����Ʊ�ĸ���ͷ����ַ
	LinkNode *destptr = head = new LinkNode;
	while (srcptr->link != NULL)		//�����㸴��
	{
		value = srcptr->link->data;
		destptr->link = new LinkNode(value);
		destptr = destptr->link;
		srcptr = srcptr->link;
	}
	destptr->link = NULL;
}

List::~List()		//��������
{
	makeEmpty();
	delete head;
	head = NULL;
}

void List::makeEmpty()	//��������Ϊ�ձ�
{
	LinkNode *p;
	while (head->link != NULL)
	{
		p = head->link;
		head->link = p->link;
		delete p;
		p = NULL;
	}
}

LinkNode* List::getHead()const		//���ظ���ͷ����ַ
{
	return head;
}

void List::reversal()
{
	if (head == NULL || head->link == NULL)
		return;
	LinkNode *current = head->link;
	LinkNode *ptr = NULL;
	while (current != NULL)
	{
		head->link = ptr;
		ptr = head;
		head = current;
		current = current->link;
	}
	head->link = ptr;
}


int List::getLastData()
{
	if (head == NULL&&head->link == NULL)
		return 0;
	LinkNode *current = head;
	int x;
	while (current->link != NULL)
	{
		current = current->link;
	}
	x = current->data;
	return x;
}

bool List::Insert(int m)		//��β������ݴ���999ʱ����Ҫ��λ�������½�㣬����λ�����½���С�
{
	Remainder = m%Over_Max;		//����
	CarryBit = m / Over_Max;	//��λ��
	last->data = Remainder;		//��������Ϊβ��������
	LinkNode *newNode = new LinkNode;	//�����½��
	last->link = newNode;
	newNode->data = CarryBit;	//����λ����Ϊ�½�������
	last = newNode;		//��last��ʾ�½����Ϊβ���ı�־
	return true;
}

void List::Fact(int i)
{
	if (i < 0)
	{
		cout << "����Ľ׳˻���i!" << endl;		//�׳˻���Ϊ�Ǹ�
		return;
	}
	if (i == 0)
	{
		head->data = 1;		//�ʼ��1���������У�Ȼ�������������i�ۻ�
		return;
	}
	//iΪ������ʱ�������������i�ֱ��ۻ�����λ�Ľ�㣬�������룬��λ�������½��
	CarryBit = 0;
	LinkNode *current = head;		//��¼��ǰ���
	while (current->link != NULL)		//��������,ÿ���������ݶ�Ҫ����i
	{
		Remainder = current->data*i + CarryBit;		//�׳˵ĵ�ǰ������ڵ�ǰ���������׳˻���i�Ļ��ټӽ�λ��
		CarryBit = Remainder / Over_Max;			//Ȼ���ظ��ۻ�
		current->data = Remainder%Over_Max;
		current = current->link;		//��ǰ���ָ����һ����㣬ѭ��
	}
	last->data = current->data*i + CarryBit;		//�׳˵����һ�����Ľ���������һ�����������׳˻���i�Ļ��ټӽ�λ��
}

void List::printFact()
{
	ofstream file_out("BigNumber.txt");		//�洢���������ı��ļ�
	LinkNode *current = head;		//��ǰ���
	file_out << current->data << ',';	//���ͷ�������
	current = current->link;		
	while (current->link != NULL)		//�ж��Ƿ�ѭ������������ǰ������һ����㲻Ϊ��
	{
		file_out << setfill('0') << setw(3) << current->data << ',';	//��ʽ�������������ݲ���100����ǰ�油0���������Ϊ3λ���֣�ȷ���м䲻��0�������ȷ
		current = current->link;
	}
	file_out << setfill('0') << setw(3) << current->data << endl;	//���β������ݣ������λ
}

#endif