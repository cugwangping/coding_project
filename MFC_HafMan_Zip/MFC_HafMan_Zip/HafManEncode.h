#pragma once
#include "afxcmn.h"


// HafManEncode �Ի���

class HafManEncode : public CDialogEx
{
	DECLARE_DYNAMIC(HafManEncode)

public:
	HafManEncode(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~HafManEncode();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString ReadEncodeFile;
	CString WriteEncodeFile;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
