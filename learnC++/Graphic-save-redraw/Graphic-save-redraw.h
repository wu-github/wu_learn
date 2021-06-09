
// Graphic-save-redraw.h : main header file for the Graphic-save-redraw application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CGraphicsaveredrawApp:
// See Graphic-save-redraw.cpp for the implementation of this class
//

class CGraphicsaveredrawApp : public CWinApp
{
public:
	CGraphicsaveredrawApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CGraphicsaveredrawApp theApp;
