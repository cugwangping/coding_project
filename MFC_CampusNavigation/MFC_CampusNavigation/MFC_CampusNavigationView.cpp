
// MFC_CampusNavigationView.cpp : CMFC_CampusNavigationView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_32772, &CMFC_CampusNavigationView::On32772)
END_MESSAGE_MAP()

// CMFC_CampusNavigationView ����/����

CMFC_CampusNavigationView::CMFC_CampusNavigationView()
{
	// TODO:  �ڴ˴���ӹ������
	//����λͼ
	BITMAP BM;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&BM);
	m_nWidth = BM.bmWidth;
	m_nHeight = BM.bmHeight;
	//��ʼ�����򾰵�ͼ
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
	//����ͼ�ı�����,�õ�����ʾ
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
	//����ͼ�ߵ�Ȩֵ���飬Ϊͼ�бߵľ���
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
	//ͼ�еľ�����Ϣ���
	Info[0] = _T("52�� ���ǵ�����¥");
	Info[1] = _T("��ʳ�� ���ǳԷ���λ��");
	Info[2] = _T("��ʳ�� ���ǳԷ���λ��");
	Info[3] = _T("һʳ�� ���ǲ�ȥ��ʳ��");
	Info[4] = _T("Ů������ ����¥��54��,57����");
	Info[5] = _T("��ѧ������� ����� ������¥��");
	Info[6] = _T("������ �е�Ӱ����λ��");
	Info[7] = _T("������ ����ë��ݣ����ҹݵ����");
	Info[8] = _T("���� ƽ���Ͽε�λ��");
	Info[9] = _T("��Ϣ¥ �����ϻ�ʵϰ��λ��");
	Info[10] = _T("������ С��");
	Info[11] = _T("��һ¥ �Ͽε�λ�ã�����Ҳ��������");
	Info[12] = _T("��¥ ��¥8¥�кõ�Ļ���");
	Info[13] = _T("ͼ��� ֪ʶ���⣬���黹��ѧϰ�ĵط�");
	Info[14] = _T("���� ����ѧУ�����ţ�Ҳ����������ѧУ�ĵط�");
	Info[15] = _T("�̶�¥ ��˵��������µĵط�");
	Info[16] = _T("��·ת�䴦");
	Info[17] = _T("��·ת�䴦");
	Info[18] = _T("ʮ��·�ڴ�");
	Info[19] = _T("ʮ��·�ڴ�");
	Info[20] = _T("ʮ��·�ڴ�");
	Info[21] = _T("ʮ��·�ڴ�");
	Info[22] = _T("ʮ��·�ڴ�");
	Info[23] = _T("ʮ��·�ڴ�");
	Info[24] = _T("ʮ��·�ڴ�");
	Info[25] = _T("ʮ��·�ڴ�");
	Info[26] = _T("ʮ��·�ڴ�");
	m_OldPoint = 0;
	//��ʼ����ʾ������Ϣ�ľ���
	for (int i = 0; i < NumVertices; i++)
		Rect[i].SetRect(PointArray[i].x - 20, PointArray[i].x + 20, PointArray[i].y - 20, PointArray[i].y + 20);
}

CMFC_CampusNavigationView::~CMFC_CampusNavigationView()
{
}

void CMFC_CampusNavigationView::OnMouseMove(UINT nFlags, CPoint Point)
{
	CDC *pDC = GetDC();
	OnPrepareDC(pDC);//�ú�������view�࣬ת��ǰ������øú�����������ת��  
	pDC->DPtoLP(&Point); //�豸����ת�߼����꣬ת���Ľ����δpoint  
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
	//���������ͼ��
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
	//���ߺ�Ȩֵ����ͼ��
	for (i = 0; i < NumEdges; i++)
	{
		if (Gra.InsertEdge(EdgeArray[i].x, EdgeArray[i].y, WeightArray[i]))
			continue;
		else
			break;
	}
	if (Gra.GetCurNumEdges() == 0)
		return false;
	//��ͼ�о�����Ϣ����ͼ��
	//Gra.SetInfo(Info, NumVertices);
	return true;
}

BOOL CMFC_CampusNavigationView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CScrollView::PreCreateWindow(cs);
}

// CMFC_CampusNavigationView ����

void CMFC_CampusNavigationView::OnDraw(CDC* pDC)
{
	CMFC_CampusNavigationDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	CDC MemoryDc;
	CBitmap *Oldbmp;
	MemoryDc.CreateCompatibleDC(pDC);
	Oldbmp = MemoryDc.SelectObject(&m_Bitmap);
	pDC->StretchBlt(0, 0, m_nWidth, m_nHeight, &MemoryDc, 0, 0, m_nWidth, m_nHeight, SRCCOPY);
	CPen pen(PS_SOLID, 5, RGB(255, 0, 0));
	CPen *pOldPen = MemoryDc.SelectObject(&pen);//ѡ�к�ɫ����
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
	// TODO:  �������ͼ�ĺϼƴ�С
	sizeTotal.cx = m_nWidth;
	sizeTotal.cy = m_nHeight;
	SetScrollSizes(MM_TEXT, sizeTotal);
	//����������ڹ��ߣ�������ʾ������Ϣ
	m_Tip.Create(this);
	m_Tip.SetTipTextColor(RGB(255, 0, 0));
	m_Tip.AddTool(this);
	//m_Tip.AddTool(this, LPSTR_TEXTCALLBACK);
}


// CMFC_CampusNavigationView ��ӡ

BOOL CMFC_CampusNavigationView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC_CampusNavigationView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC_CampusNavigationView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}

BOOL CMFC_CampusNavigationView::PreTranslateMessage(MSG* pMsg)
{
	m_Tip.RelayEvent(pMsg);
	return CScrollView::PreTranslateMessage(pMsg);
}
// CMFC_CampusNavigationView ���

#ifdef _DEBUG
void CMFC_CampusNavigationView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMFC_CampusNavigationView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMFC_CampusNavigationDoc* CMFC_CampusNavigationView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_CampusNavigationDoc)));
	return (CMFC_CampusNavigationDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_CampusNavigationView ��Ϣ�������




void CMFC_CampusNavigationView::On32772()
{
	// TODO:  �ڴ���������������
	if(Dlg.DoModal())
		Judge = TRUE;
}
