
// MFC_BinaryTree.h : MFC_BinaryTree Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC_BinaryTreeApp:
// �йش����ʵ�֣������ MFC_BinaryTree.cpp
//

class CMFC_BinaryTreeApp : public CWinAppEx
{
public:
	CMFC_BinaryTreeApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_BinaryTreeApp theApp;
