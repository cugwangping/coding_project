
// MFC_CampusNavigationView.cpp : CMFC_CampusNavigationView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFC_CampusNavigation.h"
#endif

#include "MFC_CampusNavigationDoc.h"
#include "MFC_CampusNavigationView.h"
#include"ShortPathDlg.h"
#include"resource.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_CampusNavigationView

IMPLEMENT_DYNCREATE(CMFC_CampusNavigationView, CScrollView)

BEGIN_MESSAGE_MAP(CMFC_CampusNavigationView, CScrollView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_32772, &CMFC_CampusNavigationView::On32772)
END_MESSAGE_MAP()

// CMFC_CampusNavigationView 构造/析构

CMFC_CampusNavigationView::CMFC_CampusNavigationView()
{
	// TODO:  在此处添加构造代码
	//加载位图
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;
	//初始化无向景点图
	PointArray[0] = (278, 450);
	PointArray[1] = (308, 300);
	PointArray[2] = (249, 130); 
	PointArray[3] = (249, 80);
	PointArray[4] = (356, 324);
	PointArray[5] = (350, 403); 
	PointArray[6] = (356, 477);
	PointArray[7] = (442, 332);
	PointArray[8] = (527, 310);
	PointArray[9] = (725, 344);
	PointArray[10] = (795, 286);
	PointArray[11] = (701, 290);
	PointArray[12] = (646, 251);
	PointArray[13] = (608, 418);
	PointArray[14] = (748, 418);
	PointArray[15] = (444, 130);
	PointArray[16] = (360, 325);
	PointArray[17] = (360, 175);
	PointArray[18] = (356, 42);
	PointArray[19] = (249, 42);
	PointArray[20] = (515, 152);
	PointArray[21] = (515, 251);
	PointArray[22] = (646, 290);
	PointArray[23] = (515, 290);
	PointArray[24] = (515, 362);
	PointArray[25] = (608, 362);
	PointArray[26] = (360, 362);
	//无向图的边数组,用点来表示
	EdgeArray[0] = (0, 16);
	EdgeArray[1] = (6, 16);
	EdgeArray[2] = (1, 17);
	EdgeArray[3] = (16, 17);
	EdgeArray[4] = (4, 17);
	EdgeArray[5] = (2, 3);
	EdgeArray[6] = (3, 19);
	EdgeArray[7] = (18, 19);
	EdgeArray[8] = (4, 18);
	EdgeArray[9] = (4, 7);
	EdgeArray[10] = (7, 20);
	EdgeArray[11] = (8, 20);
	EdgeArray[12] = (20, 21);
	EdgeArray[13] = (12, 21);
	EdgeArray[14] = (12, 22);
	EdgeArray[15] = (11, 22);
	EdgeArray[16] = (21, 23);
	EdgeArray[17] = (22, 23);
	EdgeArray[18] = (10, 11);
	EdgeArray[19] = (10, 14);
	EdgeArray[20] = (13, 14);
	EdgeArray[21] = (13, 25);
	EdgeArray[22] = (24, 25);
	EdgeArray[23] = (23, 24);
	EdgeArray[24] = (16, 26);
	EdgeArray[25] = (24, 26);
	//无向图边的权值数组，为图中边的距离
	WeightArray[0] = 149.5;
	WeightArray[1] = 152.1;
	WeightArray[2] = 135.4;
	WeightArray[3] = 150.0;
	WeightArray[4] = 149.1;
	WeightArray[5] = 50.0;
	WeightArray[6] = 38.0;
	WeightArray[7] = 107.0;
	WeightArray[8] = 282.0;
	WeightArray[9] = 86.4;
	WeightArray[10] = 194.2;
	WeightArray[11] = 158.5;
	WeightArray[12] = 98.0;
	WeightArray[13] = 131.0;
	WeightArray[14] = 39.0;
	WeightArray[15] = 55.0;
	WeightArray[16] = 39.0;
	WeightArray[17] = 131.0;
	WeightArray[18] = 94.1;
	WeightArray[19] = 140.1;
	WeightArray[20] = 140.0;
	WeightArray[21] = 56.0;
	WeightArray[22] = 93.0;
	WeightArray[23] = 72.0;
	WeightArray[24] = 37.0;
	WeightArray[25] = 155.0;
	//图中的景点信息简介
	Info[0] = _T("52栋 我们的寝室楼");
	Info[1] = _T("三食堂 我们吃饭的位置");
	Info[2] = _T("二食堂 我们吃饭的位置");
	Info[3] = _T("一食堂 我们不去的食堂");
	Info[4] = _T("女生寝室 公主楼（54栋,57栋）");
	Info[5] = _T("大学生活动中心 活动场所 （综艺楼）");
	Info[6] = _T("弘毅堂 有电影看得位置");
	Info[7] = _T("体育馆 由羽毛球馆，攀岩馆等组成");
	Info[8] = _T("教三 平常上课的位置");
	Info[9] = _T("信息楼 我们上机实习的位置");
	Info[10] = _T("西二门 小门");
	Info[11] = _T("教一楼 上课的位置，考试也多在这里");
	Info[12] = _T("主楼 主楼8楼有好点的机房");
	Info[13] = _T("图书馆 知识宝库，借书还书学习的地方");
	Info[14] = _T("大门 我们学校的正门，也是我们迈进学校的地方");
	Info[15] = _T("教二楼 传说有许多鬼故事的地方");
	Info[16] = _T("公路转弯处");
	Info[17] = _T("公路转弯处");
	Info[18] = _T("十字路口处");
	Info[19] = _T("十字路口处");
	Info[20] = _T("十字路口处");
	Info[21] = _T("十字路口处");
	Info[22] = _T("十字路口处");
	Info[23] = _T("十字路口处");
	Info[24] = _T("十字路口处");
	Info[25] = _T("十字路口处");
	Info[26] = _T("十字路口处");
	m_OldPoint = 0;
	//初始化显示景点信息的矩形
	for (int i = 0; i < NumVertices; i++)
		Rect[i].SetRect(PointArray[i].x - 20, PointArray[i].x + 20, PointArray[i].y - 20, PointArray[i].y + 20);
}

CMFC_CampusNavigationView::~CMFC_CampusNavigationView()
{
}

void CMFC_CampusNavigationView::OnMouseMove(UINT nFlags, CPoint Point)
{
	CDC *pDC = GetDC();
	OnPrepareDC(pDC);//该函数属于view类，转化前必须调用该函数，否则不能转化  
	pDC->DPtoLP(&Point); //设备坐标转逻辑坐标，转化的结果仍未point  
	ReleaseDC(pDC);
	CString Str;
	Str.Format(_T("x=%d,y=%d"), Point.x, Point.y);
	((CFrameWnd*)GetParent())->SetMessageText(Str);
	if (Point != m_OldPoint)
	{
		if (Rect[0].PtInRect(Point))
			m_Tip.UpdateTipText(Info[0], this);
		else if (Rect[1].PtInRect(Point))
			m_Tip.UpdateTipText(Info[1], this);
		else if (Rect[2].PtInRect(Point))
			m_Tip.UpdateTipText(Info[2], this);
		else if (Rect[3].PtInRect(Point))
			m_Tip.UpdateTipText(Info[3], this);
		else if (Rect[4].PtInRect(Point))
			m_Tip.UpdateTipText(Info[4], this);
		else if (Rect[5].PtInRect(Point))
			m_Tip.UpdateTipText(Info[5], this);
		else if (Rect[6].PtInRect(Point))
			m_Tip.UpdateTipText(Info[6], this);
		else if (Rect[7].PtInRect(Point))
			m_Tip.UpdateTipText(Info[7], this);
		else if (Rect[8].PtInRect(Point))
			m_Tip.UpdateTipText(Info[8], this);
		else if (Rect[9].PtInRect(Point))
			m_Tip.UpdateTipText(Info[9], this);
		else if (Rect[10].PtInRect(Point))
			m_Tip.UpdateTipText(Info[10], this);
		else if (Rect[11].PtInRect(Point))
			m_Tip.UpdateTipText(Info[11], this);
		else if (Rect[12].PtInRect(Point))
			m_Tip.UpdateTipText(Info[12], this);
		else if (Rect[13].PtInRect(Point))
			m_Tip.UpdateTipText(Info[13], this);
		else if (Rect[14].PtInRect(Point))
			m_Tip.UpdateTipText(Info[14], this);
		else if (Rect[15].PtInRect(Point))
			m_Tip.UpdateTipText(Info[15], this);
		else if (Rect[16].PtInRect(Point))
			m_Tip.UpdateTipText(Info[16], this);
		else if (Rect[17].PtInRect(Point))
			m_Tip.UpdateTipText(Info[17], this);
		else if (Rect[18].PtInRect(Point))
			m_Tip.UpdateTipText(Info[18], this);
		else if (Rect[19].PtInRect(Point))
			m_Tip.UpdateTipText(Info[19], this);
		else if (Rect[20].PtInRect(Point))
			m_Tip.UpdateTipText(Info[20], this);
		else if (Rect[21].PtInRect(Point))
			m_Tip.UpdateTipText(Info[21], this);
		else if (Rect[22].PtInRect(Point))
			m_Tip.UpdateTipText(Info[22], this);
		else if (Rect[23].PtInRect(Point))
			m_Tip.UpdateTipText(Info[23], this);
		else if (Rect[24].PtInRect(Point))
			m_Tip.UpdateTipText(Info[24], this);
		else if (Rect[25].PtInRect(Point))
			m_Tip.UpdateTipText(Info[25], this);
		else if (Rect[26].PtInRect(Point))
			m_Tip.UpdateTipText(Info[26], this);
		else
			m_Tip.UpdateTipText(_T(""), this);
	}
	m_OldPoint = Point;
	CScrollView::OnMouseMove(nFlags, Point);
}

bool CMFC_CampusNavigationView::CreateGraph()
{
	//将顶点插入图中
	int i;
	for (i = 0; i < NumVertices; i++)
	{
		if (Gra.InsertVertex(PointArray[i]))
			continue;
		else
			break;
	}
	if (Gra.GraphEmpty())
		return false;
	//将边和权值插入图中
	for (i = 0; i < NumEdges; i++)
	{
		if (Gra.InsertEdge(EdgeArray[i].x, EdgeArray[i].y, WeightArray[i]))
			continue;
		else
			break;
	}
	if (Gra.GetCurNumEdges() == 0)
		return false;
	//将图中景点信息插入图中
	//Gra.SetInfo(Info, NumVertices);
	return true;
}

BOOL CMFC_CampusNavigationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// CMFC_CampusNavigationView 绘制

void CMFC_CampusNavigationView::OnDraw(CDC* pDC)
{
	CMFC_CampusNavigationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	CDC MemoryDc;
	CBitmap *Oldbmp;
	MemoryDc.CreateCompatibleDC(pDC);
	Oldbmp = MemoryDc.SelectObject(&m_Bitmap);
	pDC->StretchBlt(0, 0, m_nWidth, m_nHeight, &MemoryDc, 0, 0, m_nWidth, m_nHeight, SRCCOPY);
	CPen pen(PS_SOLID, 5, RGB(255, 0, 0));
	CPen *pOldPen = MemoryDc.SelectObject(&pen);//选中红色画笔
	for (int k = 0; k < NumVertices; k++)
		pDC->Ellipse(PointArray[k].x - 10, PointArray[k].y - 10, PointArray[k].x + 10, PointArray[k].y + 10);
	if (Judge)
	{
		CreateGraph();
		Gra.ShortestPath(Dlg.Start_Point);
		int j = Dlg.End_Point;
		while (j != Dlg.Start_Point)
		{
			MemoryDc.MoveTo(Gra.GetValue(j));
			MemoryDc.LineTo(Gra.GetValue(Gra.path[j]));
			j = Gra.path[j];
		}
	}
	MemoryDc.SelectObject(Oldbmp);
}

void CMFC_CampusNavigationView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO:  计算此视图的合计大小
	sizeTotal.cx = m_nWidth;
	sizeTotal.cy = m_nHeight;
	SetScrollSizes(MM_TEXT, sizeTotal);
	//添加悬浮窗口工具，用于显示景点信息
	m_Tip.Create(this);
	m_Tip.SetTipTextColor(RGB(255, 0, 0));
	m_Tip.AddTool(this);
	//m_Tip.AddTool(this, LPSTR_TEXTCALLBACK);
}


// CMFC_CampusNavigationView 打印

BOOL CMFC_CampusNavigationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFC_CampusNavigationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CMFC_CampusNavigationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}

BOOL CMFC_CampusNavigationView::PreTranslateMessage(MSG* pMsg)
{
	m_Tip.RelayEvent(pMsg);
	return CScrollView::PreTranslateMessage(pMsg);
}
// CMFC_CampusNavigationView 诊断

#ifdef _DEBUG
void CMFC_CampusNavigationView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMFC_CampusNavigationView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMFC_CampusNavigationDoc* CMFC_CampusNavigationView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_CampusNavigationDoc)));
	return (CMFC_CampusNavigationDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_CampusNavigationView 消息处理程序




void CMFC_CampusNavigationView::On32772()
{
	// TODO:  在此添加命令处理程序代码
	if(Dlg.DoModal())
		Judge = TRUE;
}
