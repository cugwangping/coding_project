
// MFC_CreatBinaryTreeView.cpp : CMFC_CreatBinaryTreeView 类的实现
//

#include "stdafx.h"
#include"BinaryTree.h"
#include"Queue.h"
#include "CreatBinaryTreeDlg.h"

// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_CreatBinaryTree.h"
#endif

#include "MFC_CreatBinaryTreeDoc.h"
#include "MFC_CreatBinaryTreeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_CreatBinaryTreeView

IMPLEMENT_DYNCREATE(CMFC_CreatBinaryTreeView, CView)

BEGIN_MESSAGE_MAP(CMFC_CreatBinaryTreeView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC_CreatBinaryTreeView 构造/析构

CMFC_CreatBinaryTreeView::CMFC_CreatBinaryTreeView()
{
	// TODO:  在此处添加构造代码

}

CMFC_CreatBinaryTreeView::~CMFC_CreatBinaryTreeView()
{
}

BOOL CMFC_CreatBinaryTreeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC_CreatBinaryTreeView 绘制

void CMFC_CreatBinaryTreeView::OnDraw(CDC* /*pDC*/)
{
	CMFC_CreatBinaryTreeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO:  在此处为本机数据添加绘制代码

	CreatBinaryTreeDlg dlg;	//创建对话框类对象
	dlg.DoModal();
	//CString转换为wchar_t*
	wchar_t *VLR = dlg.PreBinTree.GetBuffer();
	dlg.PreBinTree.ReleaseBuffer();
	wchar_t *LVR = dlg.MidBinTree.GetBuffer();
	dlg.MidBinTree.ReleaseBuffer();


	int N = dlg.PreBinTree.GetLength();	  //前序序列的长度，二叉树结点个数
	int len = dlg.MidBinTree.GetLength();	//中序序列的长度
	if (N != len)
	{
		INT_PTR Respon;
		Respon = MessageBox(_T("前序和中序序列输入错误,退出！"), _T("错误提示"), MB_OK | MB_ICONSTOP);
		return;
	}

	//将对话框中的输入数据传入创建二叉树的模板类的构造函数中构造二叉树
	CBinaryTree<wchar_t> BinTree(VLR, LVR, N);
	BinTreeNode<wchar_t> *Root = BinTree.GetRoot();		//获取二叉树的根结点
	int depth = BinTree.Depth(Root);	//二叉树的深度
	Queue<BinTreeNode<wchar_t>*, int, int> Q;	//添加队列，用来存储二叉树的结点，以及结点所显示位置的圆的圆心坐标

	//获取菜单文本的坐标
	CRect Re;
	this->GetWindowRect(Re);
	auto w = Re.Width();
	auto h = Re.Height();
	CClientDC Dc(this);	

	//结点的坐标分布
	int Height = 1;	//结点的高度每增加一层点，高度就加一
	int HeightLeft;	//左孩子结点的高度
	int HeightRight; //右孩子结点的高度
	int R = h / (4 * (depth + 1));	//圆的半径

	int Molecule = 1;	//圆心坐标的分子
	int Denominator;	//圆心坐标的分母
	int X0, Y0;		//包装结点数据的圆的圆心坐标
	int XA, YA, XD, YD;		//圆外接正方形的左上角和右下角端点的坐标
	int XE, YE, XF, YF;		//连接两个圆的线段的端点坐标,点E在点F的上方
	Q.EnQueue(Root, Molecule, Height);

	while (!Q.IsEmpty())
	{
		//将当前结点的相关数据弹出
		Q.DeQueue(Root, Molecule, Height);
		//圆心坐标
		Denominator = (int)pow(2, Height);
		X0 = w*Molecule / Denominator;		//圆心横坐标
		Y0 = h*Height / (depth + 1);		//圆心纵坐标
		
		//正方形的两端点的坐标
		XA = X0 - R;	//正方形左上角端点坐标
		YA = Y0 - R;
		XD = X0 + R;	//正方形右下角端点坐标
		YD = Y0 + R;
		//画圆
		Dc.Ellipse(XA, YA, XD, YD);

		//在圆心显示二叉树的根结点数据
		CString da;
		da += Root->data;   
		Dc.SetTextColor(RGB(255, 0, 0));	//设置输出文本颜色为红色
		Dc.TextOutW(X0, Y0, da);

		if (Root->LeftChild)
		{
			//如果有左孩子，就画左线段
			//线段的上端点坐标
			XE = (int)(X0 - R / sqrt(2));		//XO为当前结点的圆心横坐标
			YE = (int)(Y0 + R / sqrt(2));		//YO为当前结点的圆心纵坐标

			HeightLeft = Height + 1;	//高度加一
			Molecule = 2 * Molecule - 1;	//左为减,左子女的圆心横坐标的分子
			//线段的下端点坐标
			XF = w*Molecule / (2 * Denominator);
			YF = h*HeightLeft / (depth + 1) -R;		
			//画左线段
			Dc.MoveTo(CPoint(XE, YE));
			Dc.LineTo(CPoint(XF, YF));
			
			//将访问左子女所需要的数据压入队列
			Q.EnQueue(Root->LeftChild, Molecule, HeightLeft);
			Molecule = (Molecule + 1) / 2;	//将跟结点圆心的分子还原
		}
		if (Root->RightChild)
		{
			//如果有右孩子，就画右线段
			//线段的上端点坐标
			XE = (int)(X0 + R / sqrt(2));		//XO为当前结点的圆心横坐标
			YE = (int)(Y0 + R / sqrt(2));		//YO为当前结点的圆心纵坐标

			HeightRight = Height + 1;	//高度加一
			Molecule = 2 * Molecule + 1;	//右为加,右子女的圆心横坐标的分子
			//线段的下端点坐标
			XF = w*Molecule / (2 * Denominator);
			YF = h*HeightRight / (depth + 1) - R;	
			//画右线段
			Dc.MoveTo(CPoint(XE, YE));
			Dc.LineTo(CPoint(XF, YF));

			//将访问右子女所需要的数据压入队列
			Q.EnQueue(Root->RightChild, Molecule, HeightRight);
		}
	}
	ReleaseDC(&Dc);
}


// CMFC_CreatBinaryTreeView 打印

BOOL CMFC_CreatBinaryTreeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC_CreatBinaryTreeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMFC_CreatBinaryTreeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMFC_CreatBinaryTreeView 诊断

#ifdef _DEBUG
void CMFC_CreatBinaryTreeView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_CreatBinaryTreeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_CreatBinaryTreeDoc* CMFC_CreatBinaryTreeView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_CreatBinaryTreeDoc)));
	return (CMFC_CreatBinaryTreeDoc*)m_pDocument;
}

#endif //_DEBUG


// CMFC_CreatBinaryTreeView 消息处理程序
