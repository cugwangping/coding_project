// ShortPathDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_CampusNavigation.h"
#include "ShortPathDlg.h"
#include "afxdialogex.h"
#include"resource.h"


// ShortPathDlg 对话框

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


// ShortPathDlg 消息处理程序


void ShortPathDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	//起点 
	if (StartPoint == "52栋")
		Start_Point = 0;
	else if (StartPoint == "三食堂")
		Start_Point = 1;
	else if (StartPoint == "二食堂")
		Start_Point = 2;
	else if (StartPoint == "一食堂")
		Start_Point = 3;
	else if (StartPoint == "女生寝室")
		Start_Point = 4;
	else if (StartPoint == "大学生活动中心")
		Start_Point = 5;
	else if (StartPoint == "弘毅堂")
		Start_Point = 6;
	else if (StartPoint == "体育馆")
		Start_Point = 7;
	else if (StartPoint == "教三")
		Start_Point = 8;
	else if (StartPoint == "信息楼")
		Start_Point = 9;
	else if (StartPoint == "西二门")
		Start_Point = 10;
	else if (StartPoint == "教一楼")
		Start_Point = 11;
	else if (StartPoint == "主楼")
		Start_Point = 12;
	else if (StartPoint == "图书馆")
		Start_Point = 13;
	else if (StartPoint == "大门")
		Start_Point = 14;
	else if (StartPoint == "教二楼")
		Start_Point = 15;
	else
		Start_Point = -1;
	//终点
	if (EndPoint == "52栋")
		End_Point = 0;
	else if (EndPoint == "三食堂")
		End_Point = 1;
	else if (EndPoint == "二食堂")
		End_Point = 2;
	else if (EndPoint == "一食堂")
		End_Point = 3;
	else if (EndPoint == "女生寝室")
		End_Point = 4;
	else if (EndPoint == "大学生活动中心")
		End_Point = 5;
	else if (EndPoint == "弘毅堂")
		End_Point = 6;
	else if (EndPoint == "体育馆")
		End_Point = 7;
	else if (EndPoint == "教三")
		End_Point = 8;
	else if (EndPoint == "信息楼")
		End_Point = 9;
	else if (EndPoint == "西二门")
		End_Point = 10;
	else if (EndPoint == "教一楼")
		End_Point = 11;
	else if (EndPoint == "主楼")
		End_Point = 12;
	else if (EndPoint == "图书馆")
		End_Point = 13;
	else if (EndPoint == "大门")
		End_Point = 14;
	else if (EndPoint == "教二楼")
		End_Point = 15;
	else
		End_Point = -1;
}


void ShortPathDlg::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
