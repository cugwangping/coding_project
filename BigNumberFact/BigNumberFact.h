
// BigNumberFact.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CBigNumberFactApp: 
// �йش����ʵ�֣������ BigNumberFact.cpp
//

class CBigNumberFactApp : public CWinApp
{
public:
	CBigNumberFactApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CBigNumberFactApp theApp;