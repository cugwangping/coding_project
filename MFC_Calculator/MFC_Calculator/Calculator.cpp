#include"stdafx.h"
#include"Calculator.h"

void CCalculator::AddOperand(double value)
{
	Num.Push(value);
}

bool CCalculator::get2Operands(double& left, double& right)
{
	if (Num.IsEmpty())	//栈空，取操作数失败
		return false;
	Num.Pop(right);		//取右操作数
	if (Num.IsEmpty())	//栈空，取操作数失败
		return false;
	Num.Pop(left);		//取左操作数
	return true;		//取操作数成功
}

bool CCalculator::DoOperator(char op)
{
	double left, right, value;
	bool result;
	result = get2Operands(left, right);		//取两个操作数
	if (result == true)
	{
		switch (op)
		{
		case '+':
			value = left + right;
			Num.Push(value);
			break;
		case '-':
			value = left - right;
			Num.Push(value);
			break;
		case '*':
			value = left * right;
			Num.Push(value);
			break;
		case '/':	//除法运算，分母不能为0
			if (right == 0.0)
			{
				Clear();	//清栈
				return false;
			}
			else
			{
				value = left / right;
				Num.Push(value);
			}
			break;
		case '%':	//取模运算，只适用于整数之间
			if (right == 0.0)
			{
				Clear();	//清栈
				return false;
			}
			else
			{
				if ((left > (int)left&&left<(int)left + 1) || (right>(int)right&&right < (int)right + 1))
					return false;
				value = (int)left % (int)right;
				Num.Push(value);
			}
			break;
		}
		return true;
	}
	else
		return false;
}

void CCalculator::SwitchExpress(char *MidExpression, string& SufExpression)	//中缀表达式转换为后缀表达式
{
	int i = 0;
	int mark = 0;		//用于标记是否加“，”以便记录double类型的数据
	char endTag = '=', ch, Operator;
	Op.Push(endTag);
	int isp = InStackPriority(endTag);	//栈内优先数,#的优先数为0
	int icp;		//栈外优先数
	ch = MidExpression[i];
	icp = InComingPriority(ch);
	while (Op.IsEmpty() == false || ch != '=')
	{
		if (icp == -1)	//若为数字或小数点直接压入栈中
		{
			if (mark)
			{
				SufExpression += ",";
				mark--;
			}
			SufExpression = SufExpression + ch;
			ch = MidExpression[++i];
			icp = InComingPriority(ch);
		}
		else if (icp>isp)	//栈外优先数的优先级大于栈内，将该操作符压入操作符栈中
		{
			if (ch == '-')		//区分负号和减号
			{
				i--;
				if (i == -1 || MidExpression[i] == '(')		//处理负号
				{
					if (mark)
					{
						mark--;
						SufExpression += ',';
					}
					SufExpression = SufExpression + ch;
					i++;
					ch = MidExpression[++i];
					icp = InComingPriority(ch);
				}
				else
				{
					i++;
					if (mark)
						mark--;
					Op.Push(ch);	//操作符入栈
					isp = InStackPriority(ch);	//栈内优先数
					ch = MidExpression[++i];
					icp = InComingPriority(ch);	//栈外优先数
					mark++;
				}
			}
			else
			{
				if (mark)
					mark--;
				Op.Push(ch);	//操作符入栈
				isp = InStackPriority(ch);	//栈内优先数
				ch = MidExpression[++i];
				icp = InComingPriority(ch);	//栈外优先数
				mark++;
			}
		}
		else if (icp < isp)	//栈外优先数的优先级小于栈内，将栈内操作符弹出
		{
			SufExpression += ',';
			Op.Pop(Operator);	//操作符出栈
			SufExpression = SufExpression + Operator;
			Op.getTop(Operator);
			isp = InStackPriority(Operator);	//栈外优先数
		}
		//优先数相等
		else
		{
			Op.Pop(Operator);
			if (Operator == '(')
			{
				ch = MidExpression[++i];
				icp = InComingPriority(ch);
				Op.getTop(Operator);
				isp = InStackPriority(Operator);
			}
			else
			{
				SufExpression += ',';
				SufExpression = SufExpression + Operator;
			}
		}
	}
}

void CCalculator::Run(string SufExpression, CString& CResult)
{
	char ch;
	bool T_or_F;
	double newOperand;
	int i = 0;
	string Operand;
	ch = SufExpression[i];
	while (ch != '=')
	{
		switch (ch)
		{
		case '+':
		case '-':
			i++;
			if (isdigit(SufExpression[i]))
			{
				Operand = Operand + ch;		//将一个操作数存入string类型的Operand中
				ch = SufExpression[i];	//读取下一个字符
				if (ch == ',')		//读到","说明一个double型的操作数处理完，将其放入double型的栈中
				{
					newOperand = strtod(Operand.c_str(), NULL);
					AddOperand(newOperand);		//将操作数放入栈中
					Operand = "\0";
					ch = SufExpression[++i];		//读取下一个字符
				}
				break;
			}
			else
				i--;
		case '*':
		case '/':
		case '%':
			T_or_F = DoOperator(ch);
			if (T_or_F == false)
				CResult = "错误的表达式，请重新输入！";
			ch = SufExpression[++i];	//读取下一个字符
			if (ch == ',')
				ch = SufExpression[++i];	//忽略“，”读取下一个字符
			break;
		default:
			Operand = Operand + ch;		//将一个操作数存入string类型的Operand中
			ch = SufExpression[++i];	//读取下一个字符
			if (ch == ',')		//读到","说明一个double型的操作数处理完，将其放入double型的栈中
			{
				newOperand = strtod(Operand.c_str(), NULL);
				AddOperand(newOperand);		//将操作数放入栈中
				Operand = "\0";
				ch = SufExpression[++i];		//读取下一个字符
			}
			break;
		}
	}
	double result;	//最后的计算结果
	Num.Pop(result);
	CResult.Format(_T("%.9g"), result);
}

void CCalculator::Clear()		//清栈
{
	Num.makeEmpty();
	Op.makeEmpty();
}

int CCalculator::InStackPriority(char ch)		//返回栈内优先数
{
	int priority;
	switch (ch)
	{
	case '=': priority = 0;
		break;
	case '(': priority = 1;
		break;
	case '*':
	case '/':
	case '%': priority = 5;
		break;
	case '+':
	case '-': priority = 3;
		break;
	case ')': priority = 6;
		break;
	default: priority = -1;
		break;
	}
	return priority;
}
int CCalculator::InComingPriority(char ch)		//返回栈外优先数
{
	int priority;
	switch (ch)
	{
	case '=': priority = 0;
		break;
	case '(': priority = 6;
		break;
	case '*':
	case '/':
	case '%': priority = 4;
		break;
	case '+':
	case '-': priority = 2;
		break;
	case ')': priority = 1;
		break;
	default: priority = -1;
		break;
	}
	return priority;
}