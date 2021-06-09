
// Menu2View.cpp : implementation of the CMenu2View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Menu2.h"
#endif

#include "Menu2Doc.h"
#include "Menu2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMenu2View

IMPLEMENT_DYNCREATE(CMenu2View, CView)

BEGIN_MESSAGE_MAP(CMenu2View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMenu2View construction/destruction

CMenu2View::CMenu2View()
{
	// TODO: add construction code here

}

CMenu2View::~CMenu2View()
{
}

BOOL CMenu2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMenu2View drawing

void CMenu2View::OnDraw(CDC* /*pDC*/)
{
	CMenu2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMenu2View printing

BOOL CMenu2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMenu2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMenu2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMenu2View diagnostics

#ifdef _DEBUG
void CMenu2View::AssertValid() const
{
	CView::AssertValid();
}

void CMenu2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMenu2Doc* CMenu2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMenu2Doc)));
	return (CMenu2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMenu2View message handlers


void CMenu2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	/*CMenu menu;
	menu.LoadMenuW(IDR_MENU1);
	CMenu *popUp =  menu.GetSubMenu(0);

	popUp->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);*/

	CView::OnRButtonDown(nFlags, point);
}
