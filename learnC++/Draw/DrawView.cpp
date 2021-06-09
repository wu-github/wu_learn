
// DrawView.cpp : implementation of the CDrawView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Draw.h"
#endif

#include "DrawDoc.h"
#include "DrawView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawView

IMPLEMENT_DYNCREATE(CDrawView, CView)

BEGIN_MESSAGE_MAP(CDrawView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDrawView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CDrawView construction/destruction

CDrawView::CDrawView()
	: m_point(0)
	, m_bDraw(false)
	, cpoint(0)
{
	// TODO: add construction code here
	m_point = 0;

}

CDrawView::~CDrawView()
{
}

BOOL CDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDrawView drawing

void CDrawView::OnDraw(CDC* /*pDC*/)
{
	CDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CDrawView printing


void CDrawView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CDrawView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDrawView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDrawView diagnostics

#ifdef _DEBUG
void CDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawDoc* CDrawView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawDoc)));
	return (CDrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawView message handlers


void CDrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	//MessageBox(_T("view btn down"));
	m_point = cpoint = point;

	m_bDraw = true;


	CView::OnLButtonDown(nFlags, point);
}


void CDrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	/*
	HDC hdc;
	hdc = ::GetDC(m_hWnd);
	MoveToEx(hdc, m_point.x, m_point.y, NULL);
	LineTo(hdc, point.x, point.y);
	::ReleaseDC(m_hWnd, hdc);
	*/
	/*
	CDC *pDc = GetDC();
	pDc->MoveTo(m_point);
	pDc->LineTo(point);
	ReleaseDC(pDc);
	*/
	//CClientDC dc(this);
	/*
	CClientDC dc(GetParent());
	dc.MoveTo(m_point);
	dc.LineTo(point);
	*/
	//CWindowDC wdc(this);
	
	//CWindowDC wdc(GetParent());
	/*
	CWindowDC wdc(GetDesktopWindow());
	wdc.MoveTo(m_point);
	wdc.LineTo(point);
	*/

	//CPen pen(PS_DASH, 1, RGB(111, 111, 111));
	/*
	CPen pen(PS_DOT, 1, RGB(111, 111, 111));
	CClientDC dc(this);
	CPen *pOldPen = dc.SelectObject(&pen);
	dc.MoveTo(m_point);
	dc.LineTo(point);
	dc.SelectObject(pOldPen);
	*/
	//CBrush brush(RGB(111, 111, 111));
	/*
	CBitmap cbitMap;
	cbitMap.LoadBitmapW(IDB_BITMAP1);
	CBrush brush(&cbitMap);
	CClientDC dc(this);
	dc.FillRect(CRect(m_point, point), &brush);
	*/

	/*CClientDC dc(this);
	CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	CBrush *pOldBrush = dc.SelectObject(pBrush);
	dc.Rectangle(CRect(m_point, point));
	dc.SelectObject(pOldBrush);*/

	m_bDraw= false;

	CView::OnLButtonUp(nFlags, point);
}


void CDrawView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	CPen pen(PS_SOLID, 2 , RGB(111, 55, 111));
	CPen *oldPen = dc.SelectObject(&pen);
	if(m_bDraw == true){

		dc.SetROP2(R2_NOT);
		dc.MoveTo(m_point);
		//dc.LineTo(point);
		dc.LineTo(cpoint);
		//dc.MoveTo(m_point);
		dc.MoveTo(point);
		dc.LineTo(cpoint);
		//m_point = point;
		cpoint = point;
	}
	dc.SelectObject(oldPen);

	CView::OnMouseMove(nFlags, point);
}
