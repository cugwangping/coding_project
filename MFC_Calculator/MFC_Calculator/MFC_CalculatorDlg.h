
// MFC_CalculatorDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMFC_CalculatorDlg �Ի���
class CMFC_CalculatorDlg : public CDialogEx
{
// ����
public:
	CMFC_CalculatorDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFC_CALCULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonStr(UINT nID);
	CEdit m_Edit;
	afx_msg void OnBnClickedCancel();
};
