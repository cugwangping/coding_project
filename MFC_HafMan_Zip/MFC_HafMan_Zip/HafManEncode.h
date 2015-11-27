#pragma once
#include "afxcmn.h"


// HafManEncode 对话框

class HafManEncode : public CDialogEx
{
	DECLARE_DYNAMIC(HafManEncode)

public:
	HafManEncode(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~HafManEncode();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString ReadEncodeFile;
	CString WriteEncodeFile;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
