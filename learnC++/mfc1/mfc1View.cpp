
// mfc1View.cpp : implementation of the Cmfc1View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "mfc1.h"
#endif

#include "mfc1Doc.h"
#include "mfc1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfc1View

IMPLEMENT_DYNCREATE(Cmfc1View, CView)

BEGIN_MESSAGE_MAP(Cmfc1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cmfc1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Cmfc1View construction/destruction

Cmfc1View::Cmfc1View()
{
	// TODO: add construction code here

}

Cmfc1View::~Cmfc1View()
{
}

BOOL Cmfc1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cmfc1View drawing

void Cmfc1View::OnDraw(CDC* /*pDC*/)
{
	Cmfc1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

}


// Cmfc1View printing


void Cmfc1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cmfc1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cmfc1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cmfc1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void Cmfc1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cmfc1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cmfc1View diagnostics

#ifdef _DEBUG
void Cmfc1View::AssertValid() const
{
	CView::AssertValid();
}

void Cmfc1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cmfc1Doc* Cmfc1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfc1Doc)));
	return (Cmfc1Doc*)m_pDocument;
}
#endif //_DEBUG

int Cmfc1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	//wurd
	//wurd_btn.Create(_T("wurd_btn_mfc1View"), WS_CHILD | BS_DEFCOMMANDLINK, CRect(0, 0, 555, 555), this, 123);
	//wurd_btn.ShowWindow(SW_SHOWNORMAL);
	return 0;
}


// Cmfc1View message handlers
