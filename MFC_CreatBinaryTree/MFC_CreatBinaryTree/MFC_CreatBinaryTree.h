
// MFC_CreatBinaryTree.h : MFC_CreatBinaryTree Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC_CreatBinaryTreeApp:
// �йش����ʵ�֣������ MFC_CreatBinaryTree.cpp
//

class CMFC_CreatBinaryTreeApp : public CWinApp
{
public:
	CMFC_CreatBinaryTreeApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_CreatBinaryTreeApp theApp;
