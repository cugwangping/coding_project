#pragma once


// HafDecode �Ի���

class HafDecode : public CDialogEx
{
	DECLARE_DYNAMIC(HafDecode)

public:
	HafDecode(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~HafDecode();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString ReadDecodeFile;
	CString WriteDecodeFile;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
