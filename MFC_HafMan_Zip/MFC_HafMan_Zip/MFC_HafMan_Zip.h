
// MFC_HafMan_Zip.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_HafMan_ZipApp: 
// �йش����ʵ�֣������ MFC_HafMan_Zip.cpp
//

class CMFC_HafMan_ZipApp : public CWinApp
{
public:
	CMFC_HafMan_ZipApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_HafMan_ZipApp theApp;