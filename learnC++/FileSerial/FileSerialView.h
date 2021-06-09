
// FileSerialView.h : interface of the CFileSerialView class
//

#pragma once


class CFileSerialView : public CView
{
protected: // create from serialization only
	CFileSerialView();
	DECLARE_DYNCREATE(CFileSerialView)

// Attributes
public:
	CFileSerialDoc* GetDocument() const;

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
	virtual ~CFileSerialView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnWritefile();
	afx_msg void OnReadfile();
	afx_msg void OnDian();
	afx_msg void OnZhixian();
	afx_msg void OnJuxing();
	afx_msg void OnTuoyuan();
	CObArray m_objArray;
private:
	UINT m_type;
	CPoint m_point;
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in FileSerialView.cpp
inline CFileSerialDoc* CFileSerialView::GetDocument() const
   { return reinterpret_cast<CFileSerialDoc*>(m_pDocument); }
#endif

