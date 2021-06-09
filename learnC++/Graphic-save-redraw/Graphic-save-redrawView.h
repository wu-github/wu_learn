
// Graphic-save-redrawView.h : interface of the CGraphicsaveredrawView class
//

#pragma once
#include "atltypes.h"
#include "afxext.h"
#include "afxwin.h"


class CGraphicsaveredrawView : public CScrollView
{
protected: // create from serialization only
	CGraphicsaveredrawView();
	DECLARE_DYNCREATE(CGraphicsaveredrawView)

// Attributes
public:
	CGraphicsaveredrawDoc* GetDocument() const;

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
	virtual ~CGraphicsaveredrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDian();
	afx_msg void OnZhixian();
	afx_msg void OnJuxing();
	afx_msg void OnTuoyuan();
private:
	UINT m_type;
	CPoint m_point;
	CPtrArray m_array;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	virtual void OnInitialUpdate();
private:
	CMetaFileDC m_mfdc;
public:
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
private:
	CDC m_dcCompa;
};

#ifndef _DEBUG  // debug version in Graphic-save-redrawView.cpp
inline CGraphicsaveredrawDoc* CGraphicsaveredrawView::GetDocument() const
   { return reinterpret_cast<CGraphicsaveredrawDoc*>(m_pDocument); }
#endif

