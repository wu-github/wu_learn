
// ChildView.h : interface of the CChildView class
//


#pragma once
#include "atltypes.h"


// CChildView window

class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
private:
	CBitmap bitmap;
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	CString m_string;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CPoint cpoint;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int m_width;
};

