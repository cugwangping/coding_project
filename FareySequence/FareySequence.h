
// FareySequence.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CFareySequenceApp: 
// �йش����ʵ�֣������ FareySequence.cpp
//

class CFareySequenceApp : public CWinApp
{
public:
	CFareySequenceApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CFareySequenceApp theApp;