
// MFC_CreatBinaryTreeView.h : CMFC_CreatBinaryTreeView ��Ľӿ�
//

#pragma once

#include"MFC_CreatBinaryTreeDoc.h"

class CMFC_CreatBinaryTreeView : public CView
{
protected: // �������л�����
	CMFC_CreatBinaryTreeView();
	DECLARE_DYNCREATE(CMFC_CreatBinaryTreeView)

// ����
public:
	CMFC_CreatBinaryTreeDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CMFC_CreatBinaryTreeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC_CreatBinaryTreeView.cpp �еĵ��԰汾
inline CMFC_CreatBinaryTreeDoc* CMFC_CreatBinaryTreeView::GetDocument() const
   { return reinterpret_cast<CMFC_CreatBinaryTreeDoc*>(m_pDocument); }
#endif

