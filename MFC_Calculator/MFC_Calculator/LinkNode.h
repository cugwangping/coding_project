#ifndef _LINKNODE_H_
#define _LINKNODE_H_

template<class T>
struct LinkNode
{
	T data;		//�������
	LinkNode<T> *link;		//���ָ��
	LinkNode(LinkNode<T> *ptr = NULL){ link = ptr; }	//����ʼ�����ָ��Ĺ��캯��
	LinkNode(const T& item, LinkNode<T> *ptr = NULL)		//��ʼ�����ݺ�ָ��Ĺ��캯��
	{
		data = item;
		link = ptr;
	}
};

#endif