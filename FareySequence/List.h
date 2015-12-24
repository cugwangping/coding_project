#ifndef List_H
#define List_H
#include<iostream>
#include<fstream>
using namespace std;

struct LinkNode		//����������Ķ���
{
	int son_data;		//���������
	int parent_data;
	LinkNode *link;		//���ָ����
	LinkNode(LinkNode *ptr = NULL)		//��㹹�캯��
	{
		link = ptr;
	}
	LinkNode(const int &x1, const int &x2, LinkNode *ptr = NULL)	//��㹹�캯��
	{
		son_data = x1;
		parent_data = x2;
		link = ptr;
	}
};

//�洢N�Ľ׳˵Ľ���ĵ�����
class List		//��������Ķ���
{
private:
	LinkNode *head;		//ͷ���
	LinkNode *last;		//β���
public:
	List(const int& son1, const int &parent1, const int &son2, const int &parent2);		
	List(List& L);
	~List();
	void makeEmpty();
	LinkNode *getHead()const;
	void InsertFarey(int N);
	void printFraction();
};

List::List(const int& son1, const int &parent1, const int &son2, const int &parent2)	//�вι��캯��
{
	head = new LinkNode(son1, parent1);		//ͷ���ĳ�ʼ��
	last = new LinkNode(son2, parent2);		//β���ĳ�ʼ��
	head->link = last;
	last->link = NULL;
}

List::List(List& L)	//���ƹ��캯��
{
	int value1, value2;
	LinkNode *srcptr = L.getHead();		//�����Ʊ�ĸ���ͷ����ַ
	LinkNode *destptr = head = new LinkNode;
	while (srcptr->link != NULL)		//�����㸴��
	{
		value1 = srcptr->link->son_data;	//ȡ������
		value2 = srcptr->link->parent_data;	//ȡ����ĸ
		destptr->link = new LinkNode(value1, value2);	//�����ӷ�ĸ���Ƶ��½��Ľ����
		destptr = destptr->link;
		srcptr = srcptr->link;
	}
	destptr->link = NULL;
}

List::~List()		//��������
{
	makeEmpty();	//�������ÿ�
	delete head;	//����
	head = NULL;
}

void List::makeEmpty()	//��������Ϊ�ձ�
{
	LinkNode *p;
	while (head->link != NULL)
	{
		p = head->link;
		head->link = p->link;
		delete p;		//����������
		p = NULL;
	}
}

LinkNode *List::getHead()const
{
	return head;		//����ͷ���
}
void List::InsertFarey(int N)		//�����������������㲢����������
{
	LinkNode *current = head;		//��ǰ���
	while (current->link != NULL)
	{
		if ((current->parent_data + current->link->parent_data) <= N)		//�жϷ�ĸ�Ƿ����N�����Ƴ���һ�����ݵķ��ӷ�ĸ�����²���Ľ����
		{
			LinkNode *newNode = new LinkNode;		//�����½��
			newNode->parent_data = current->parent_data + current->link->parent_data;		//�½���ĸ��������������߷����ķ�ĸ֮��
			newNode->son_data = current->son_data + current->link->son_data;		//�½����ӵ�������������߷����ķ���֮��
			newNode->link = current->link;
			current->link = newNode;
		}
		else
			current = current->link;		//��ĸ����N������������������������
	}
}

void List::printFraction()		//�����������
{
	ofstream file_out("Farey.txt");		//�������н������ļ�
	LinkNode* current = head->link;
	while (current != NULL)
	{
		file_out << current->son_data << '/' << current->parent_data << endl;		//ѭ�����������������
		current = current->link;
	}
}

#endif