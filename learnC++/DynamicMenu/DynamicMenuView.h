
// DynamicMenuView.h : interface of the CDynamicMenuView class
//

#pragma once
#include "afxwin.h"
#include "afxcoll.h"
#include "DynamicMenuDoc.h"


class CDynamicMenuView : public CView
{
protected: // create from serialization only
	CDynamicMenuView();
	DECLARE_DYNCREATE(CDynamicMenuView)

// Attributes
public:
	CDynamicMenuDoc* GetDocument() const;

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
	virtual ~CDynamicMenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
private:
	int m_index;
public:
	CMenu m_menu;
private:
	CString m_string;
public:
	CStringArray m_stirngarray;
protected:
	afx_msg void OnPhone();
//	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
};

#ifndef _DEBUG  // debug version in DynamicMenuView.cpp
inline CDynamicMenuDoc* CDynamicMenuView::GetDocument() const
   { return reinterpret_cast<CDynamicMenuDoc*>(m_pDocument); }
#endif

