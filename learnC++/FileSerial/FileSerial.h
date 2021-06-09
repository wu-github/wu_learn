
// FileSerial.h : main header file for the FileSerial application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CFileSerialApp:
// See FileSerial.cpp for the implementation of this class
//

class CFileSerialApp : public CWinApp
{
public:
	CFileSerialApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CFileSerialApp theApp;
