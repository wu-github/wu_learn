
// Dilog.h : main header file for the Dilog application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CDilogApp:
// See Dilog.cpp for the implementation of this class
//

class CDilogApp : public CWinApp
{
public:
	CDilogApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDilogApp theApp;
