
// FareySequenceDlg.h : ͷ�ļ�
//

#pragma once


// CFareySequenceDlg �Ի���
class CFareySequenceDlg : public CDialogEx
{
// ����
public:
	CFareySequenceDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_FAREYSEQUENCE_DIALOG };

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
	int N;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
