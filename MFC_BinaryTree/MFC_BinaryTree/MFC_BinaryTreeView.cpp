
// MFC_BinaryTreeView.cpp : CMFC_BinaryTreeView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC_BinaryTreeView ����/����

CMFC_BinaryTreeView::CMFC_BinaryTreeView()
{
	// TODO:  �ڴ˴���ӹ������

}

CMFC_BinaryTreeView::~CMFC_BinaryTreeView()
{
}

BOOL CMFC_BinaryTreeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC_BinaryTreeView ����

void CMFC_BinaryTreeView::OnDraw(CDC* /*pDC*/)
{
	CMFC_BinaryTreeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CMFC_BinaryTreeView ��ӡ

BOOL CMFC_BinaryTreeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC_BinaryTreeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC_BinaryTreeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMFC_BinaryTreeView ���

#ifdef _DEBUG
void CMFC_BinaryTreeView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_BinaryTreeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_BinaryTreeDoc* CMFC_BinaryTreeView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_BinaryTreeDoc)));
	return (CMFC_BinaryTreeDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_BinaryTreeView ��Ϣ�������
