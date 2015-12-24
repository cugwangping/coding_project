
// MFC_CalculatorDlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMFC_CalculatorDlg �Ի���



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


// CMFC_CalculatorDlg ��Ϣ�������

BOOL CMFC_CalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFC_CalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFC_CalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//һ��������������button�Ͱ�ť
void CMFC_CalculatorDlg::OnBnClickedButtonStr(UINT nID)
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//
	int ID = nID - IDC_BUTTON1;		
	CString MidExpression;		//�ӶԻ�����������׺���ʽ���ڼ���
	wchar_t *Expression;	//�洢��CStringת����������׺���ʽ
	char expression[Size] = "";		//�洢��wchar_tת����������׺���ʽ
	string SufExpression;	//��׺���ʽ
	size_t count;	
	//���������
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
	case 11:		//����Ⱥţ���������
	{
		CCalculator Cal;
		m_Edit.GetWindowText(MidExpression);
		MidExpression += "=";
		m_Edit.SetWindowText(MidExpression);
		//��CStringת��Ϊwchar_t
		Expression = MidExpression.GetBuffer();
		MidExpression.ReleaseBuffer();

		//��wchar_t�͵���׺���ʽת��Ϊchar������洢
		wcstombs_s(&count, expression, Size, Expression, Size);

		//��׺���ʽת��Ϊ��׺���ʽ
		Cal.SwitchExpress(expression, SufExpression);

		//�����׺���ʽ��ֵ������ֵΪCString��������ʾ,�����ʽ�������������ʾ���������������
		//m_Edit.GetWindowText(CResult);
		Cal.Run(SufExpression, CResult);
		m_Edit.SetWindowText(CResult);	//��ʾ���ս��
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
	case 19:	//����ɾ������
		m_Edit.GetWindowText(MidExpression);
		MidExpression = MidExpression.Left(MidExpression.GetLength() - 1);
		m_Edit.SetWindowText(MidExpression);
		break;
	case 20:	//����
		MidExpression = "";		
		m_Edit.SetWindowText(MidExpression);
		break;
	default:
		MidExpression += "����������������룡";
		m_Edit.SetWindowText(MidExpression);
		break;
	}
}

//�˳���ť
void CMFC_CalculatorDlg::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}

