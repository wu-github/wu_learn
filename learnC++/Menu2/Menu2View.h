
// Menu2View.h : interface of the CMenu2View class
//

#pragma once


class CMenu2View : public CView
{
protected: // create from serialization only
	CMenu2View();
	DECLARE_DYNCREATE(CMenu2View)

// Attributes
public:
	CMenu2Doc* GetDocument() const;

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
	virtual ~CMenu2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in Menu2View.cpp
inline CMenu2Doc* CMenu2View::GetDocument() const
   { return reinterpret_cast<CMenu2Doc*>(m_pDocument); }
#endif

