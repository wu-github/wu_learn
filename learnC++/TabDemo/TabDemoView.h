
// TabDemoView.h : interface of the CTabDemoView class
//

#pragma once

#include "PropSheet.h"

class CTabDemoView : public CView
{
protected: // create from serialization only
	CTabDemoView();
	DECLARE_DYNCREATE(CTabDemoView)

// Attributes
public:
	CTabDemoDoc* GetDocument() const;

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
	virtual ~CTabDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnProps();
private:
	int m_zhiye;
	CString m_didian;
	bool m_xingqu[4];
	CString m_xinzi;
	
};

#ifndef _DEBUG  // debug version in TabDemoView.cpp
inline CTabDemoDoc* CTabDemoView::GetDocument() const
   { return reinterpret_cast<CTabDemoDoc*>(m_pDocument); }
#endif

