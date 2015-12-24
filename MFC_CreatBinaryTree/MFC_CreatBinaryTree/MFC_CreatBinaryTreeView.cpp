
// MFC_CreatBinaryTreeView.cpp : CMFC_CreatBinaryTreeView ���ʵ��
//

#include "stdafx.h"
#include"BinaryTree.h"
#include"Queue.h"
#include "CreatBinaryTreeDlg.h"

// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CMFC_CreatBinaryTreeView ����/����

CMFC_CreatBinaryTreeView::CMFC_CreatBinaryTreeView()
{
	// TODO:  �ڴ˴���ӹ������

}

CMFC_CreatBinaryTreeView::~CMFC_CreatBinaryTreeView()
{
}

BOOL CMFC_CreatBinaryTreeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC_CreatBinaryTreeView ����

void CMFC_CreatBinaryTreeView::OnDraw(CDC* /*pDC*/)
{
	CMFC_CreatBinaryTreeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���

	CreatBinaryTreeDlg dlg;	//�����Ի��������
	dlg.DoModal();
	//CStringת��Ϊwchar_t*
	wchar_t *VLR = dlg.PreBinTree.GetBuffer();
	dlg.PreBinTree.ReleaseBuffer();
	wchar_t *LVR = dlg.MidBinTree.GetBuffer();
	dlg.MidBinTree.ReleaseBuffer();


	int N = dlg.PreBinTree.GetLength();	  //ǰ�����еĳ��ȣ�������������
	int len = dlg.MidBinTree.GetLength();	//�������еĳ���
	if (N != len)
	{
		INT_PTR Respon;
		Respon = MessageBox(_T("ǰ������������������,�˳���"), _T("������ʾ"), MB_OK | MB_ICONSTOP);
		return;
	}

	//���Ի����е��������ݴ��봴����������ģ����Ĺ��캯���й��������
	CBinaryTree<wchar_t> BinTree(VLR, LVR, N);
	BinTreeNode<wchar_t> *Root = BinTree.GetRoot();		//��ȡ�������ĸ����
	int depth = BinTree.Depth(Root);	//�����������
	Queue<BinTreeNode<wchar_t>*, int, int> Q;	//��Ӷ��У������洢�������Ľ�㣬�Լ��������ʾλ�õ�Բ��Բ������

	//��ȡ�˵��ı�������
	CRect Re;
	this->GetWindowRect(Re);
	auto w = Re.Width();
	auto h = Re.Height();
	CClientDC Dc(this);	

	//��������ֲ�
	int Height = 1;	//���ĸ߶�ÿ����һ��㣬�߶Ⱦͼ�һ
	int HeightLeft;	//���ӽ��ĸ߶�
	int HeightRight; //�Һ��ӽ��ĸ߶�
	int R = h / (4 * (depth + 1));	//Բ�İ뾶

	int Molecule = 1;	//Բ������ķ���
	int Denominator;	//Բ������ķ�ĸ
	int X0, Y0;		//��װ������ݵ�Բ��Բ������
	int XA, YA, XD, YD;		//Բ��������ε����ϽǺ����½Ƕ˵������
	int XE, YE, XF, YF;		//��������Բ���߶εĶ˵�����,��E�ڵ�F���Ϸ�
	Q.EnQueue(Root, Molecule, Height);

	while (!Q.IsEmpty())
	{
		//����ǰ����������ݵ���
		Q.DeQueue(Root, Molecule, Height);
		//Բ������
		Denominator = (int)pow(2, Height);
		X0 = w*Molecule / Denominator;		//Բ�ĺ�����
		Y0 = h*Height / (depth + 1);		//Բ��������
		
		//�����ε����˵������
		XA = X0 - R;	//���������ϽǶ˵�����
		YA = Y0 - R;
		XD = X0 + R;	//���������½Ƕ˵�����
		YD = Y0 + R;
		//��Բ
		Dc.Ellipse(XA, YA, XD, YD);

		//��Բ����ʾ�������ĸ��������
		CString da;
		da += Root->data;   
		Dc.SetTextColor(RGB(255, 0, 0));	//��������ı���ɫΪ��ɫ
		Dc.TextOutW(X0, Y0, da);

		if (Root->LeftChild)
		{
			//��������ӣ��ͻ����߶�
			//�߶ε��϶˵�����
			XE = (int)(X0 - R / sqrt(2));		//XOΪ��ǰ����Բ�ĺ�����
			YE = (int)(Y0 + R / sqrt(2));		//YOΪ��ǰ����Բ��������

			HeightLeft = Height + 1;	//�߶ȼ�һ
			Molecule = 2 * Molecule - 1;	//��Ϊ��,����Ů��Բ�ĺ�����ķ���
			//�߶ε��¶˵�����
			XF = w*Molecule / (2 * Denominator);
			YF = h*HeightLeft / (depth + 1) -R;		
			//�����߶�
			Dc.MoveTo(CPoint(XE, YE));
			Dc.LineTo(CPoint(XF, YF));
			
			//����������Ů����Ҫ������ѹ�����
			Q.EnQueue(Root->LeftChild, Molecule, HeightLeft);
			Molecule = (Molecule + 1) / 2;	//�������Բ�ĵķ��ӻ�ԭ
		}
		if (Root->RightChild)
		{
			//������Һ��ӣ��ͻ����߶�
			//�߶ε��϶˵�����
			XE = (int)(X0 + R / sqrt(2));		//XOΪ��ǰ����Բ�ĺ�����
			YE = (int)(Y0 + R / sqrt(2));		//YOΪ��ǰ����Բ��������

			HeightRight = Height + 1;	//�߶ȼ�һ
			Molecule = 2 * Molecule + 1;	//��Ϊ��,����Ů��Բ�ĺ�����ķ���
			//�߶ε��¶˵�����
			XF = w*Molecule / (2 * Denominator);
			YF = h*HeightRight / (depth + 1) - R;	
			//�����߶�
			Dc.MoveTo(CPoint(XE, YE));
			Dc.LineTo(CPoint(XF, YF));

			//����������Ů����Ҫ������ѹ�����
			Q.EnQueue(Root->RightChild, Molecule, HeightRight);
		}
	}
	ReleaseDC(&Dc);
}


// CMFC_CreatBinaryTreeView ��ӡ

BOOL CMFC_CreatBinaryTreeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CMFC_CreatBinaryTreeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CMFC_CreatBinaryTreeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CMFC_CreatBinaryTreeView ���

#ifdef _DEBUG
void CMFC_CreatBinaryTreeView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_CreatBinaryTreeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_CreatBinaryTreeDoc* CMFC_CreatBinaryTreeView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_CreatBinaryTreeDoc)));
	return (CMFC_CreatBinaryTreeDoc*)m_pDocument;
}

#endif //_DEBUG


// CMFC_CreatBinaryTreeView ��Ϣ�������
