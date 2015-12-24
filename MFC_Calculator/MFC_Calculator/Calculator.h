#ifndef _CCALCULATOR_H_
#define _CCALCULATOR_H_
#include"Stack.h"
#include<iostream>
#include<string>
using namespace std;

class CCalculator
{
private:
	Stack<double> Num;
	Stack<char> Op;
	void AddOperand(double value);		//˽�к���������������ֵѹ�������ջ
	bool get2Operands(double& left, double& right);		//��ջ���˳�����������
	bool DoOperator(char op);		//�γ�����ָ���������
	int InStackPriority(char ch);		//ջ��������
	int InComingPriority(char ch);		//ջ�����ȼ�
public:
	CCalculator(){}	//���캯��
	void SwitchExpress(char *MidExpression, string& SufExpression);		//����׺���ʽת��Ϊ��׺���ʽ
	void Run(string SufExpression, CString& CResult);		//ִ�б��ʽ����
	void Clear();
};

#endif