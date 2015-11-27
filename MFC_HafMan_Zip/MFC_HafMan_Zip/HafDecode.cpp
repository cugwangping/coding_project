// HafDecode.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_HafMan_Zip.h"
#include "HafDecode.h"
#include "afxdialogex.h"
#include"CHafZip.h"


// HafDecode 对话框

IMPLEMENT_DYNAMIC(HafDecode, CDialogEx)

HafDecode::HafDecode(CWnd* pParent /*=NULL*/)
	: CDialogEx(HafDecode::IDD, pParent)
	, ReadDecodeFile(_T(""))
	, WriteDecodeFile(_T(""))
{

}

HafDecode::~HafDecode()
{
}

void HafDecode::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, ReadDecodeFile);
	DDX_Text(pDX, IDC_EDIT2, WriteDecodeFile);
}


BEGIN_MESSAGE_MAP(HafDecode, CDialogEx)
	ON_BN_CLICKED(IDOK, &HafDecode::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &HafDecode::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &HafDecode::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &HafDecode::OnBnClickedButton2)
END_MESSAGE_MAP()


// HafDecode 消息处理程序


void HafDecode::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
	CHafZip Haf(ReadDecodeFile, WriteDecodeFile);
	Haf.Decode();
}


void HafDecode::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void HafDecode::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	TCHAR szFilter[] = _T("所有文件(*.*)|*.*||");
	// 构造打开文件对话框   
	CFileDialog FileDlg(TRUE, _T("*.*"), NULL, 0, szFilter, this);

	// 显示打开文件对话框   
	if (IDOK == FileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
		ReadDecodeFile = FileDlg.GetPathName();
		SetDlgItemText(IDC_EDIT1, ReadDecodeFile);
	}
}


void HafDecode::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	TCHAR szFilter[] = _T("所有文件(*.*)|*.*||");
	// 构造打开文件对话框   
	CFileDialog FileDlg(TRUE, _T("*.*"), NULL, 0, szFilter, this);

	// 显示打开文件对话框   
	if (IDOK == FileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
		WriteDecodeFile = FileDlg.GetPathName();
		SetDlgItemText(IDC_EDIT2, WriteDecodeFile);
	}
}
