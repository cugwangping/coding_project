#ifndef List_H
#define List_H

template<class T>
struct LinkNode		//����������Ķ���
{
	T data;		//���������
	LinkNode<T> *link;		//���ָ����
	LinkNode(LinkNode<T> *ptr = NULL)		//��㹹�캯��
	{
		link = ptr;
	}
	LinkNode(const T &x, LinkNode<T> *ptr = NULL)		//��㹹�캯��
	{
		data = x;
		link = ptr;
	}
};

template<class T>
class List		//��������Ķ���		
{
private:
	LinkNode<T> *head;		//ͷ���
public:
	List();
	List(const T& x);
	List(List<T>& L);
	~List();
	void makeEmpty();
	LinkNode<T> *getHead()const;
	void PreInput(T EndTag);
	void printList();
	void reversal();
};

template<class T>
List<T>::List()		//���캯��
{
	head = new LinkNode<T>;
}

template<class T>
List<T>::List(const T& x)	//���캯��
{
	head = new LinkNode<T>(x);
}

template<class T>
List<T>::List(List<T>& L)	//���ƹ��캯��
{
	T value;
	LinkNode<T> *srcptr = L.getHead();		//�����Ʊ�ĸ���ͷ����ַ
	LinkNode<T> *destptr = head = new LinkNode<T>;
	while (srcptr->link != NULL)		//�����㸴��
	{
		value = srcptr->link->data;
		destptr->link = new LinkNode<T>(value);
		destptr = destptr->link;
		srcptr = srcptr->link;
	}
	destptr->link = NULL;
}

template<class T>
List<T>::~List()		//��������
{
	makeEmpty();
	delete head;
}

template<class T>
void List<T>::makeEmpty()	//��������Ϊ�ձ�
{
	LinkNode<T> *p;
	while (head->link != NULL)
	{
		p = head->link;
		head->link = p->link;
		delete p;		//����������
		p = NULL;
	}
}

template<class T>
LinkNode<T>* List<T>::getHead()const		//���ظ���ͷ����ַ
{
	return head;
}

template<class T>
void List<T>::PreInput(T EndTag)		//ǰ�彨��������
{
	LinkNode<T> *newNode;
	T NodeData;
	makeEmpty();
	//������������
	cin >> NodeData;
	while (NodeData != EndTag)		//EndTagΪ�������ݽ����ı�־
	{
		newNode = new LinkNode<T>(NodeData);		//�����½��
		if (newNode == NULL)
		{
			cout << "������Ч!" << endl;
			return;
		}
		newNode->link = head->link;
		head->link = newNode;	//���뵽��ǰ��
		cin >> NodeData;
	}
}

template<class T>
void List<T>::printList()		//�������Ԫ��
{
	LinkNode<T> *p;
	p = head->link;
	if (p == NULL)
	{
		cout << "������" << endl;		//������Ϊ�գ�����ձ�
		return;
	}
	do
	{
		cout << p->data << '\t';		//����Ϊ�գ������������
		p = p->link;
	} while (p != NULL);
	cout << endl;
}

template<class T>
void List<T>::reversal()
{
	if (head == NULL && head->link == NULL)
		return;
	LinkNode<T> *current = head->link;		//���ڱ���������
	LinkNode<T> *ptr = head;	//��current��ָͬ������ķ�����ʵ�ַ�ת
	LinkNode<T> *temp = NULL;		//��¼current����һ�����
	LinkNode<T> *last = new LinkNode<T>;
	head->link = NULL;		//ͷ�����Ϊβ���
	while (current != NULL)
	{
		temp = current->link;
		current->link = ptr;
		ptr = current;
		current = temp;
	}
	last->link = ptr;		//β�����Ϊͷ���
	head = last;
}
#endif

