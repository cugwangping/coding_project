// HafManEncode.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_HafMan_Zip.h"
#include "HafManEncode.h"
#include "afxdialogex.h"
#include"CHafZip.h"

// HafManEncode 对话框

IMPLEMENT_DYNAMIC(HafManEncode, CDialogEx)

HafManEncode::HafManEncode(CWnd* pParent /*=NULL*/)
	: CDialogEx(HafManEncode::IDD, pParent)
	, ReadEncodeFile(_T(""))
	, WriteEncodeFile(_T(""))
{

}

HafManEncode::~HafManEncode()
{
}

void HafManEncode::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, ReadEncodeFile);
	DDX_Text(pDX, IDC_EDIT2, WriteEncodeFile);
}


BEGIN_MESSAGE_MAP(HafManEncode, CDialogEx)
	ON_BN_CLICKED(IDOK, &HafManEncode::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &HafManEncode::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &HafManEncode::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &HafManEncode::OnBnClickedButton2)
END_MESSAGE_MAP()


// HafManEncode 消息处理程序


void HafManEncode::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	CHafZip Haf(ReadEncodeFile, WriteEncodeFile);
	Haf.Encode();
}


void HafManEncode::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void HafManEncode::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	TCHAR szFilter[] = _T("所有文件(*.*)|*.*||");
	// 构造打开文件对话框   
	CFileDialog FileDlg(TRUE, _T("*.*"), NULL, 0, szFilter, this);

	// 显示打开文件对话框   
	if (IDOK == FileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
		ReadEncodeFile = FileDlg.GetPathName();
		SetDlgItemText(IDC_EDIT1, ReadEncodeFile);
	}
}


void HafManEncode::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	TCHAR szFilter[] = _T("所有文件(*.*)|*.*||");
	// 构造打开文件对话框   
	CFileDialog FileDlg(TRUE, _T("*.*"), NULL, 0, szFilter, this);

	// 显示打开文件对话框   
	if (IDOK == FileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
		WriteEncodeFile = FileDlg.GetPathName();
		SetDlgItemText(IDC_EDIT2, WriteEncodeFile);
	}
}
