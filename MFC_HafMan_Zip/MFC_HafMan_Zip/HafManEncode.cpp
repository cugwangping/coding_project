// HafManEncode.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_HafMan_Zip.h"
#include "HafManEncode.h"
#include "afxdialogex.h"
#include"CHafZip.h"

// HafManEncode �Ի���

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


// HafManEncode ��Ϣ�������


void HafManEncode::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	CHafZip Haf(ReadEncodeFile, WriteEncodeFile);
	Haf.Encode();
}


void HafManEncode::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void HafManEncode::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	TCHAR szFilter[] = _T("�����ļ�(*.*)|*.*||");
	// ������ļ��Ի���   
	CFileDialog FileDlg(TRUE, _T("*.*"), NULL, 0, szFilter, this);

	// ��ʾ���ļ��Ի���   
	if (IDOK == FileDlg.DoModal())
	{
		// ���������ļ��Ի����ϵġ��򿪡���ť����ѡ����ļ�·����ʾ���༭����   
		ReadEncodeFile = FileDlg.GetPathName();
		SetDlgItemText(IDC_EDIT1, ReadEncodeFile);
	}
}


void HafManEncode::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	TCHAR szFilter[] = _T("�����ļ�(*.*)|*.*||");
	// ������ļ��Ի���   
	CFileDialog FileDlg(TRUE, _T("*.*"), NULL, 0, szFilter, this);

	// ��ʾ���ļ��Ի���   
	if (IDOK == FileDlg.DoModal())
	{
		// ���������ļ��Ի����ϵġ��򿪡���ť����ѡ����ļ�·����ʾ���༭����   
		WriteEncodeFile = FileDlg.GetPathName();
		SetDlgItemText(IDC_EDIT2, WriteEncodeFile);
	}
}
