
// mfc1View.h : interface of the Cmfc1View class
//

#pragma once


class Cmfc1View : public CView
{
protected: // create from serialization only
	Cmfc1View();
	DECLARE_DYNCREATE(Cmfc1View)

// Attributes
public:
	Cmfc1Doc* GetDocument() const;

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
	int OnCreate(LPCREATESTRUCT lpCreateStruct);

// Implementation
public:
	virtual ~Cmfc1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()

private:
	//wurd
	CButton wurd_btn;
};

#ifndef _DEBUG  // debug version in mfc1View.cpp
inline Cmfc1Doc* Cmfc1View::GetDocument() const
   { return reinterpret_cast<Cmfc1Doc*>(m_pDocument); }
#endif

