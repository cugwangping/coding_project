#include"resource.h"
#pragma once


// CreatBinaryTreeDlg �Ի���

class CreatBinaryTreeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CreatBinaryTreeDlg)

public:
	CreatBinaryTreeDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CreatBinaryTreeDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CString PreBinTree;
	CString MidBinTree;
};
