
// MFC_CampusNavigation.h : MFC_CampusNavigation Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFC_CampusNavigationApp:
// �йش����ʵ�֣������ MFC_CampusNavigation.cpp
//

class CMFC_CampusNavigationApp : public CWinApp
{
public:
	CMFC_CampusNavigationApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_CampusNavigationApp theApp;
