/******************************
4103056035 �P�� �Ĥ����@�~12/21
******************************/
// CalculatorWP.h : PROJECT_NAME ���ε{�����D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CCalculatorWPApp: 
// �аѾ\��@�����O�� CalculatorWP.cpp
//

class CCalculatorWPApp : public CWinApp
{
public:
	CCalculatorWPApp();

// �мg
public:
	virtual BOOL InitInstance();

// �{���X��@

	DECLARE_MESSAGE_MAP()
};

extern CCalculatorWPApp theApp;