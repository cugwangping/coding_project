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
	List();		//���캯��
	List(const T& x);	//���캯��
	List(List<T>& L);	//���ƹ��캯��
	~List();	//��������
	void makeEmpty();	//�������ÿ�
	LinkNode<T> *getHead()const;		//ȡ����ͷ���
	void PreInput(T EndTag);		//ǰ�巨����������
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
			cout << "Invalid Data!" << endl;
			return;
		}
		newNode->link = head->link;
		head->link = newNode;	//���뵽��ǰ��
		cin >> NodeData;
	}
}

#endif