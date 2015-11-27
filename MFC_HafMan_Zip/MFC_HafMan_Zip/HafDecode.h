#pragma once


// HafDecode 对话框

class HafDecode : public CDialogEx
{
	DECLARE_DYNAMIC(HafDecode)

public:
	HafDecode(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~HafDecode();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString ReadDecodeFile;
	CString WriteDecodeFile;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
