
// Menu2.h : main header file for the Menu2 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMenu2App:
// See Menu2.cpp for the implementation of this class
//

class CMenu2App : public CWinApp
{
public:
	CMenu2App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMenu2App theApp;
