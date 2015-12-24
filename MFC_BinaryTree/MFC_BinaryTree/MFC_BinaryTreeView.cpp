
// MFC_BinaryTreeView.cpp : CMFC_BinaryTreeView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_BinaryTree.h"
#endif

#include "MFC_BinaryTreeDoc.h"
#include "MFC_BinaryTreeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_BinaryTreeView

IMPLEMENT_DYNCREATE(CMFC_BinaryTreeView, CView)

BEGIN_MESSAGE_MAP(CMFC_BinaryTreeView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC_BinaryTreeView 构造/析构

CMFC_BinaryTreeView::CMFC_BinaryTreeView()
{
	// TODO:  在此处添加构造代码

}

CMFC_BinaryTreeView::~CMFC_BinaryTreeView()
{
}

BOOL CMFC_BinaryTreeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFC_BinaryTreeView 绘制

void CMFC_BinaryTreeView::OnDraw(CDC* /*pDC*/)
{
	CMFC_BinaryTreeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
}


// CMFC_BinaryTreeView 打印

BOOL CMFC_BinaryTreeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC_BinaryTreeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMFC_BinaryTreeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CMFC_BinaryTreeView 诊断

#ifdef _DEBUG
void CMFC_BinaryTreeView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_BinaryTreeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_BinaryTreeDoc* CMFC_BinaryTreeView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_BinaryTreeDoc)));
	return (CMFC_BinaryTreeDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_BinaryTreeView 消息处理程序
