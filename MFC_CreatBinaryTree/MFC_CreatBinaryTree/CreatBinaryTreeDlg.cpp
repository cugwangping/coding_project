// CreatBinaryTreeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC_CreatBinaryTree.h"
#include "CreatBinaryTreeDlg.h"
#include "afxdialogex.h"
#include"MFC_CreatBinaryTreeView.h"



// CreatBinaryTreeDlg �Ի���

IMPLEMENT_DYNAMIC(CreatBinaryTreeDlg, CDialogEx)

CreatBinaryTreeDlg::CreatBinaryTreeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CreatBinaryTreeDlg::IDD, pParent)
	, PreBinTree(_T(""))
	, MidBinTree(_T(""))
{

}

CreatBinaryTreeDlg::~CreatBinaryTreeDlg()
{
}

void CreatBinaryTreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, PreBinTree);
	DDX_Text(pDX, IDC_EDIT2, MidBinTree);
}


BEGIN_MESSAGE_MAP(CreatBinaryTreeDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CreatBinaryTreeDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CreatBinaryTreeDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CreatBinaryTreeDlg ��Ϣ�������


void CreatBinaryTreeDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
	//CMenu m_menu;
	//CMFC_CreatBinaryTreeView DisplayTree;
	//DisplayTree.DoModal();
}


void CreatBinaryTreeDlg::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


