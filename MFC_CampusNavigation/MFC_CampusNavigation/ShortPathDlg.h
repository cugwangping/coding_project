#pragma once


// ShortPathDlg 对话框

class ShortPathDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ShortPathDlg)

public:
	ShortPathDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ShortPathDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CString StartPoint;
	CString EndPoint;
	int Start_Point, End_Point;		//计算从顶点Start_Point到End_Point的最短路径
};
