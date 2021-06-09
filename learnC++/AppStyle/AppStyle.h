
// AppStyle.h : main header file for the AppStyle application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CAppStyleApp:
// See AppStyle.cpp for the implementation of this class
//

class CAppStyleApp : public CWinApp
{
public:
	CAppStyleApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAppStyleApp theApp;
