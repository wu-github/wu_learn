
// DynamicMenu.h : main header file for the DynamicMenu application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CDynamicMenuApp:
// See DynamicMenu.cpp for the implementation of this class
//

class CDynamicMenuApp : public CWinApp
{
public:
	CDynamicMenuApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDynamicMenuApp theApp;
