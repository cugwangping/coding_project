#pragma once


// ShortPathDlg �Ի���

class ShortPathDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ShortPathDlg)

public:
	ShortPathDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ShortPathDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CString StartPoint;
	CString EndPoint;
	int Start_Point, End_Point;		//����Ӷ���Start_Point��End_Point�����·��
};
