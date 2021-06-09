
// AppStyleView.h : interface of the CAppStyleView class
//

#pragma once


class CAppStyleView : public CView
{
protected: // create from serialization only
	CAppStyleView();
	DECLARE_DYNCREATE(CAppStyleView)

// Attributes
public:
	CAppStyleDoc* GetDocument() const;

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
	virtual ~CAppStyleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
//	afx_msg void OnIdiW();
	afx_msg void OnW();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in AppStyleView.cpp
inline CAppStyleDoc* CAppStyleView::GetDocument() const
   { return reinterpret_cast<CAppStyleDoc*>(m_pDocument); }
#endif

