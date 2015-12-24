
// MFC_CalculatorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFC_Calculator.h"
#include "MFC_CalculatorDlg.h"
#include "afxdialogex.h"
#include"Calculator.h"
#define Size 100

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFC_CalculatorDlg 对话框



CMFC_CalculatorDlg::CMFC_CalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFC_CalculatorDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_CalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
}

BEGIN_MESSAGE_MAP(CMFC_CalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	/*ON_BN_CLICKED(IDC_BUTTON1, &CMFC_CalculatorDlg::OnBnClickedButtonStr)*/
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BUTTON1, IDC_BUTTON21, OnBnClickedButtonStr)
	ON_BN_CLICKED(IDCANCEL, &CMFC_CalculatorDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CMFC_CalculatorDlg 消息处理程序

BOOL CMFC_CalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFC_CalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFC_CalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFC_CalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//一个函数，处理多个button型按钮
void CMFC_CalculatorDlg::OnBnClickedButtonStr(UINT nID)
{
	// TODO:  在此添加控件通知处理程序代码
	//
	int ID = nID - IDC_BUTTON1;		
	CString MidExpression;		//从对话框中输入中缀表达式用于计算
	wchar_t *Expression;	//存储由CString转换而来的中缀表达式
	char expression[Size] = "";		//存储由wchar_t转换而来的中缀表达式
	string SufExpression;	//后缀表达式
	size_t count;	
	//计算结果结果
	CString CResult;
	switch (ID)
	{
	case 0:
		m_Edit.GetWindowText(MidExpression);
		MidExpression += "1";
		m_Edit.SetWindowText(MidExpression);
		break;
	case 1:
		m_Edit.GetWindowText(MidExpression);
		MidExpression += "2";
		m_Edit.SetWindowText(MidExpression);
		break;
	case 2:
		m_Edit.GetWindowText(MidExpression);
		MidExpression += "3";
		m_Edit.SetWindowText(MidExpression);
		break;
	case 3:
		m_Edit.GetWindowText(MidExpression);
		MidExpression += "4";
		m_Edit.SetWindowText(MidExpression);
		break;
	case 4:
		m_Edit.GetWindowText(MidExpression);
		MidExpression += "5";
		m_Edit.SetWindowText(MidExpression);
		break;
	case 5:
		m_Edit.GetWindowText(MidExpression);
		MidExpression += "6";
		m_Edit.SetWindowText(MidExpression);
		break;
	case 6:
		m_Edit.GetWindowText(MidExpression);
		MidExpression += "7";
		m_Edit.SetWindowText(MidExpression);
		break;
	case 7:
		m_Edit.GetWindowText(MidExpression);
		MidExpression += "8";
		m_Edit.SetWindowText(MidExpression);
		break;
	case 8:
		m_Edit.GetWindowText(MidExpression);
		MidExpression += "9";
		m_Edit.SetWindowText(MidExpression);
		break;
	case 9:
		m_Edit.GetWindowText(MidExpression);
		MidExpression += "0";
		m_Edit.SetWindowText(MidExpression);
		break;
	case 10:
		m_Edit.GetWindowText(MidExpression);
		MidExpression += ".";
		m_Edit.SetWindowText(MidExpression);
		break;
	case 11:		//输出等号，计算出结果
	{
		CCalculator Cal;
		m_Edit.GetWindowText(MidExpression);
		MidExpression += "=";
		m_Edit.SetWindowText(MidExpression);
		//将CString转换为wchar_t
		Expression = MidExpression.GetBuffer();
		MidExpression.ReleaseBuffer();

		//将wchar_t型的中缀表达式转换为char型数组存储
		wcstombs_s(&count, expression, Size, Expression, Size);

		//中缀表达式转换为后缀表达式
		Cal.SwitchExpress(expression, SufExpression);

		//计算后缀表达式的值，返回值为CString，用于显示,若表达式错误，输出错误提示，否则输出计算结果
		//m_Edit.GetWindowText(CResult);
		Cal.Run(SufExpression, CResult);
		m_Edit.SetWindowText(CResult);	//显示最终结果
		break;
	}
	case 12:
		m_Edit.GetWindowText(MidExpression);
		MidExpression += "(";
		m_Edit.SetWindowText(MidExpression);
		break;
	case 13:
		m_Edit.GetWindowText(MidExpression);
		MidExpression += ")";
		m_Edit.SetWindowText(MidExpression);
		break;
	case 14:
		m_Edit.GetWindowText(MidExpression);
		MidExpression += "+";
		m_Edit.SetWindowText(MidExpression);
		break;
	case 15:	
		m_Edit.GetWindowText(MidExpression);
		MidExpression += "-";
		m_Edit.SetWindowText(MidExpression);
		break;
	case 16:	
		m_Edit.GetWindowText(MidExpression);
		MidExpression += "*";
		m_Edit.SetWindowText(MidExpression);
		break;
	case 17:	
		m_Edit.GetWindowText(MidExpression);
		MidExpression += "/";
		m_Edit.SetWindowText(MidExpression);
		break;
	case 18:	
		m_Edit.GetWindowText(MidExpression);
		MidExpression += "%";
		m_Edit.SetWindowText(MidExpression);
		break;
	case 19:	//后退删除操作
		m_Edit.GetWindowText(MidExpression);
		MidExpression = MidExpression.Left(MidExpression.GetLength() - 1);
		m_Edit.SetWindowText(MidExpression);
		break;
	case 20:	//清屏
		MidExpression = "";		
		m_Edit.SetWindowText(MidExpression);
		break;
	default:
		MidExpression += "输入错误，请重新输入！";
		m_Edit.SetWindowText(MidExpression);
		break;
	}
}

//退出按钮
void CMFC_CalculatorDlg::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}

