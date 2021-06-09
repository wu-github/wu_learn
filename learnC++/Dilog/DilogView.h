
// DilogView.h : interface of the CDilogView class
//

#pragma once
#include "afxwin.h"


class CDilogView : public CView
{
protected: // create from serialization only
	CDilogView();
	DECLARE_DYNCREATE(CDilogView)

// Attributes
public:
	CDilogDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CDilogView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTestdilog();
};

#ifndef _DEBUG  // debug version in DilogView.cpp
inline CDilogDoc* CDilogView::GetDocument() const
   { return reinterpret_cast<CDilogDoc*>(m_pDocument); }
#endif

