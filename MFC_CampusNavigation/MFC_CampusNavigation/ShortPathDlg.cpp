// ShortPathDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_CampusNavigation.h"
#include "ShortPathDlg.h"
#include "afxdialogex.h"
#include"resource.h"


// ShortPathDlg �Ի���

IMPLEMENT_DYNAMIC(ShortPathDlg, CDialogEx)

ShortPathDlg::ShortPathDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ShortPathDlg::IDD, pParent)
	, StartPoint(_T(""))
	, EndPoint(_T(""))
{

}

ShortPathDlg::~ShortPathDlg()
{
}

void ShortPathDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO1, StartPoint);
	DDX_CBString(pDX, IDC_COMBO2, EndPoint);
}


BEGIN_MESSAGE_MAP(ShortPathDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &ShortPathDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &ShortPathDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// ShortPathDlg ��Ϣ�������


void ShortPathDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	//��� 
	if (StartPoint == "52��")
		Start_Point = 0;
	else if (StartPoint == "��ʳ��")
		Start_Point = 1;
	else if (StartPoint == "��ʳ��")
		Start_Point = 2;
	else if (StartPoint == "һʳ��")
		Start_Point = 3;
	else if (StartPoint == "Ů������")
		Start_Point = 4;
	else if (StartPoint == "��ѧ�������")
		Start_Point = 5;
	else if (StartPoint == "������")
		Start_Point = 6;
	else if (StartPoint == "������")
		Start_Point = 7;
	else if (StartPoint == "����")
		Start_Point = 8;
	else if (StartPoint == "��Ϣ¥")
		Start_Point = 9;
	else if (StartPoint == "������")
		Start_Point = 10;
	else if (StartPoint == "��һ¥")
		Start_Point = 11;
	else if (StartPoint == "��¥")
		Start_Point = 12;
	else if (StartPoint == "ͼ���")
		Start_Point = 13;
	else if (StartPoint == "����")
		Start_Point = 14;
	else if (StartPoint == "�̶�¥")
		Start_Point = 15;
	else
		Start_Point = -1;
	//�յ�
	if (EndPoint == "52��")
		End_Point = 0;
	else if (EndPoint == "��ʳ��")
		End_Point = 1;
	else if (EndPoint == "��ʳ��")
		End_Point = 2;
	else if (EndPoint == "һʳ��")
		End_Point = 3;
	else if (EndPoint == "Ů������")
		End_Point = 4;
	else if (EndPoint == "��ѧ�������")
		End_Point = 5;
	else if (EndPoint == "������")
		End_Point = 6;
	else if (EndPoint == "������")
		End_Point = 7;
	else if (EndPoint == "����")
		End_Point = 8;
	else if (EndPoint == "��Ϣ¥")
		End_Point = 9;
	else if (EndPoint == "������")
		End_Point = 10;
	else if (EndPoint == "��һ¥")
		End_Point = 11;
	else if (EndPoint == "��¥")
		End_Point = 12;
	else if (EndPoint == "ͼ���")
		End_Point = 13;
	else if (EndPoint == "����")
		End_Point = 14;
	else if (EndPoint == "�̶�¥")
		End_Point = 15;
	else
		End_Point = -1;
}


void ShortPathDlg::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}
