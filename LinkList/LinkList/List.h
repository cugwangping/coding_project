#ifndef List_H
#define List_H

template<class T>
struct LinkNode		//����������Ķ���
{
	T data;		//���������
	LinkNode<T> *link;		//���ָ����
	LinkNode(LinkNode<T> *ptr = NULL)
	{
		link = ptr;
	}
	LinkNode(const T &x, LinkNode<T> *ptr = NULL)
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
	int length()const;		
	LinkNode<T> *getHead()const;	
	LinkNode<T> *Locate(int i);
	bool Insert(int i, T& x);	
	void PreInput(T EndTag);
};

template<class T>
List<T>::List()		//���βι��캯��
{
	head = new LinkNode<T>;
}

template<class T>
List<T>::List(const T& x)	//�вι��캯��
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
		delete p;
		p = NULL;
	}
}

template<class T>
int List<T>::length()const	//��������ĳ���
{
	LinkNode<T> *p = head->link;
	int len = 0;
	while (p != NULL)
	{
		p = p->link;
		len++;
	}
	return len;
}

template<class T>
LinkNode<T>* List<T>::getHead()const		//���ظ���ͷ����ַ
{
	return head;
}
template<class T>
LinkNode<T>* List<T>::Locate(int i)		//������i��Ԫ�صĵ�ַ
{
	if (i < 0)		//i̫С
		return NULL;
	LinkNode<T> *current = head;
	int k = 0;
	while (current != NULL && k < i)
	{
		current = current->link;
		k++;
	}
	return current;
}
template<class T>
bool List<T>::Insert(int i, T& x)		//�ڵ�i��Ԫ�غ����x
{
	LinkNode<T> *current = Locate(i);
	if (current == NULL)
		return false;
	LinkNode<T> *newNode = new LinkNode<T>(x);
	if (newNode == NULL)
	{
		cout << "�洢����ʧ�ܣ��޷����룡" << endl;
		return false;
	}
	newNode->link = current->link;
	current->link = newNode;
	return true;
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

#endif