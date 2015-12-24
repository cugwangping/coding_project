#include"resource.h"
#pragma once


// CreatBinaryTreeDlg 对话框

class CreatBinaryTreeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CreatBinaryTreeDlg)

public:
	CreatBinaryTreeDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CreatBinaryTreeDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CString PreBinTree;
	CString MidBinTree;
};
