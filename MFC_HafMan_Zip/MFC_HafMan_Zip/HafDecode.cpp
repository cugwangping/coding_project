// HafDecode.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_HafMan_Zip.h"
#include "HafDecode.h"
#include "afxdialogex.h"
#include"CHafZip.h"


// HafDecode �Ի���

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


// HafDecode ��Ϣ�������


void HafDecode::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	CHafZip Haf(ReadDecodeFile, WriteDecodeFile);
	Haf.Decode();
}


void HafDecode::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void HafDecode::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	TCHAR szFilter[] = _T("�����ļ�(*.*)|*.*||");
	// ������ļ��Ի���   
	CFileDialog FileDlg(TRUE, _T("*.*"), NULL, 0, szFilter, this);

	// ��ʾ���ļ��Ի���   
	if (IDOK == FileDlg.DoModal())
	{
		// ���������ļ��Ի����ϵġ��򿪡���ť����ѡ����ļ�·����ʾ���༭����   
		ReadDecodeFile = FileDlg.GetPathName();
		SetDlgItemText(IDC_EDIT1, ReadDecodeFile);
	}
}


void HafDecode::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	TCHAR szFilter[] = _T("�����ļ�(*.*)|*.*||");
	// ������ļ��Ի���   
	CFileDialog FileDlg(TRUE, _T("*.*"), NULL, 0, szFilter, this);

	// ��ʾ���ļ��Ի���   
	if (IDOK == FileDlg.DoModal())
	{
		// ���������ļ��Ի����ϵġ��򿪡���ť����ѡ����ļ�·����ʾ���༭����   
		WriteDecodeFile = FileDlg.GetPathName();
		SetDlgItemText(IDC_EDIT2, WriteDecodeFile);
	}
}
