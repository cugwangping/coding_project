
// MFC_CampusNavigationView.h : CMFC_CampusNavigationView 类的接口
//

#pragma once

#include"Graph.h"
#include"ShortPathDlg.h"

class CMFC_CampusNavigationView : public CScrollView
{
protected: // 仅从序列化创建
	CMFC_CampusNavigationView();
	DECLARE_DYNCREATE(CMFC_CampusNavigationView)

// 特性
public:
	CMFC_CampusNavigationDoc* GetDocument() const;

// 操作
public:
	//无向图的顶点数组
	CPoint PointArray[NumVertices];
	//无向图的边数组,用点来表示
	CPoint EdgeArray[NumEdges];
	//无向图边的权值数组，为图中边的距离
	double WeightArray[NumEdges];
	CString Info[NumVertices];
	CRect Rect[NumVertices];		//显示景点信息的矩形标签
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual BOOL PreTranslateMessage(MSG* pMsg);

// 实现
public:
	virtual ~CMFC_CampusNavigationView();
	CToolTipCtrl m_Tip;
	CBitmap m_Bitmap;
	Graph Gra;		//景点无向图对象
	bool CreateGraph();		//创建无向图
	int m_nWidth;
	int m_nHeight;
	ShortPathDlg Dlg;
	BOOL Judge = FALSE;
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnMouseMove(UINT nFlags, CPoint Point);
	CPoint m_OldPoint;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32772();
};

#ifndef _DEBUG  // MFC_CampusNavigationView.cpp 中的调试版本
inline CMFC_CampusNavigationDoc* CMFC_CampusNavigationView::GetDocument() const
   { return reinterpret_cast<CMFC_CampusNavigationDoc*>(m_pDocument); }
#endif

