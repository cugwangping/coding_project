#include"stdafx.h"
#include"Calculator.h"

void CCalculator::AddOperand(double value)
{
	Num.Push(value);
}

bool CCalculator::get2Operands(double& left, double& right)
{
	if (Num.IsEmpty())	//ջ�գ�ȡ������ʧ��
		return false;
	Num.Pop(right);		//ȡ�Ҳ�����
	if (Num.IsEmpty())	//ջ�գ�ȡ������ʧ��
		return false;
	Num.Pop(left);		//ȡ�������
	return true;		//ȡ�������ɹ�
}

bool CCalculator::DoOperator(char op)
{
	double left, right, value;
	bool result;
	result = get2Operands(left, right);		//ȡ����������
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
		case '/':	//�������㣬��ĸ����Ϊ0
			if (right == 0.0)
			{
				Clear();	//��ջ
				return false;
			}
			else
			{
				value = left / right;
				Num.Push(value);
			}
			break;
		case '%':	//ȡģ���㣬ֻ����������֮��
			if (right == 0.0)
			{
				Clear();	//��ջ
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

void CCalculator::SwitchExpress(char *MidExpression, string& SufExpression)	//��׺���ʽת��Ϊ��׺���ʽ
{
	int i = 0;
	int mark = 0;		//���ڱ���Ƿ�ӡ������Ա��¼double���͵�����
	char endTag = '=', ch, Operator;
	Op.Push(endTag);
	int isp = InStackPriority(endTag);	//ջ��������,#��������Ϊ0
	int icp;		//ջ��������
	ch = MidExpression[i];
	icp = InComingPriority(ch);
	while (Op.IsEmpty() == false || ch != '=')
	{
		if (icp == -1)	//��Ϊ���ֻ�С����ֱ��ѹ��ջ��
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
		else if (icp>isp)	//ջ�������������ȼ�����ջ�ڣ����ò�����ѹ�������ջ��
		{
			if (ch == '-')		//���ָ��źͼ���
			{
				i--;
				if (i == -1 || MidExpression[i] == '(')		//������
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
					Op.Push(ch);	//��������ջ
					isp = InStackPriority(ch);	//ջ��������
					ch = MidExpression[++i];
					icp = InComingPriority(ch);	//ջ��������
					mark++;
				}
			}
			else
			{
				if (mark)
					mark--;
				Op.Push(ch);	//��������ջ
				isp = InStackPriority(ch);	//ջ��������
				ch = MidExpression[++i];
				icp = InComingPriority(ch);	//ջ��������
				mark++;
			}
		}
		else if (icp < isp)	//ջ�������������ȼ�С��ջ�ڣ���ջ�ڲ���������
		{
			SufExpression += ',';
			Op.Pop(Operator);	//��������ջ
			SufExpression = SufExpression + Operator;
			Op.getTop(Operator);
			isp = InStackPriority(Operator);	//ջ��������
		}
		//���������
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
				Operand = Operand + ch;		//��һ������������string���͵�Operand��
				ch = SufExpression[i];	//��ȡ��һ���ַ�
				if (ch == ',')		//����","˵��һ��double�͵Ĳ����������꣬�������double�͵�ջ��
				{
					newOperand = strtod(Operand.c_str(), NULL);
					AddOperand(newOperand);		//������������ջ��
					Operand = "\0";
					ch = SufExpression[++i];		//��ȡ��һ���ַ�
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
				CResult = "����ı��ʽ�����������룡";
			ch = SufExpression[++i];	//��ȡ��һ���ַ�
			if (ch == ',')
				ch = SufExpression[++i];	//���ԡ�������ȡ��һ���ַ�
			break;
		default:
			Operand = Operand + ch;		//��һ������������string���͵�Operand��
			ch = SufExpression[++i];	//��ȡ��һ���ַ�
			if (ch == ',')		//����","˵��һ��double�͵Ĳ����������꣬�������double�͵�ջ��
			{
				newOperand = strtod(Operand.c_str(), NULL);
				AddOperand(newOperand);		//������������ջ��
				Operand = "\0";
				ch = SufExpression[++i];		//��ȡ��һ���ַ�
			}
			break;
		}
	}
	double result;	//���ļ�����
	Num.Pop(result);
	CResult.Format(_T("%.9g"), result);
}

void CCalculator::Clear()		//��ջ
{
	Num.makeEmpty();
	Op.makeEmpty();
}

int CCalculator::InStackPriority(char ch)		//����ջ��������
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
int CCalculator::InComingPriority(char ch)		//����ջ��������
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