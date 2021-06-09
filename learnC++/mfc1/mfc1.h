
// mfc1.h : main header file for the mfc1 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Cmfc1App:
// See mfc1.cpp for the implementation of this class
//

class Cmfc1App : public CWinAppEx
{
public:
	Cmfc1App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
//	int showAbout(void);
};

extern Cmfc1App theApp;
