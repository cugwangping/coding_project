
// MFC_BinaryTreeView.h : CMFC_BinaryTreeView ��Ľӿ�
//

#pragma once


class CMFC_BinaryTreeView : public CView
{
protected: // �������л�����
	CMFC_BinaryTreeView();
	DECLARE_DYNCREATE(CMFC_BinaryTreeView)

// ����
public:
	CMFC_BinaryTreeDoc* GetDocument() const;

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
	virtual ~CMFC_BinaryTreeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFC_BinaryTreeView.cpp �еĵ��԰汾
inline CMFC_BinaryTreeDoc* CMFC_BinaryTreeView::GetDocument() const
   { return reinterpret_cast<CMFC_BinaryTreeDoc*>(m_pDocument); }
#endif

