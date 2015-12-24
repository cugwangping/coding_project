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
	void AddOperand(double value);		//私有函数，将操作数的值压入操作数栈
	bool get2Operands(double& left, double& right);		//从栈中退出两个操作数
	bool DoOperator(char op);		//形成运算指令，进行运算
	int InStackPriority(char ch);		//栈内优先数
	int InComingPriority(char ch);		//栈外优先级
public:
	CCalculator(){}	//构造函数
	void SwitchExpress(char *MidExpression, string& SufExpression);		//将中缀表达式转换为后缀表达式
	void Run(string SufExpression, CString& CResult);		//执行表达式计算
	void Clear();
};

#endif