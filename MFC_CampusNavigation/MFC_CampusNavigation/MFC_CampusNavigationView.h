
// MFC_CampusNavigationView.h : CMFC_CampusNavigationView ��Ľӿ�
//

#pragma once

#include"Graph.h"
#include"ShortPathDlg.h"

class CMFC_CampusNavigationView : public CScrollView
{
protected: // �������л�����
	CMFC_CampusNavigationView();
	DECLARE_DYNCREATE(CMFC_CampusNavigationView)

// ����
public:
	CMFC_CampusNavigationDoc* GetDocument() const;

// ����
public:
	//����ͼ�Ķ�������
	CPoint PointArray[NumVertices];
	//����ͼ�ı�����,�õ�����ʾ
	CPoint EdgeArray[NumEdges];
	//����ͼ�ߵ�Ȩֵ���飬Ϊͼ�бߵľ���
	double WeightArray[NumEdges];
	CString Info[NumVertices];
	CRect Rect[NumVertices];		//��ʾ������Ϣ�ľ��α�ǩ
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL PreTranslateMessage(MSG* pMsg);

// ʵ��
public:
	virtual ~CMFC_CampusNavigationView();
	CToolTipCtrl m_Tip;
	CBitmap m_Bitmap;
	Graph Gra;		//��������ͼ����
	bool CreateGraph();		//��������ͼ
	int m_nWidth;
	int m_nHeight;
	ShortPathDlg Dlg;
	BOOL Judge = FALSE;
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnMouseMove(UINT nFlags, CPoint Point);
	CPoint m_OldPoint;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32772();
};

#ifndef _DEBUG  // MFC_CampusNavigationView.cpp �еĵ��԰汾
inline CMFC_CampusNavigationDoc* CMFC_CampusNavigationView::GetDocument() const
   { return reinterpret_cast<CMFC_CampusNavigationDoc*>(m_pDocument); }
#endif

