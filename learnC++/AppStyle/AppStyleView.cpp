
// AppStyleView.cpp : implementation of the CAppStyleView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "AppStyle.h"
#endif

#include "AppStyleDoc.h"
#include "AppStyleView.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAppStyleView

IMPLEMENT_DYNCREATE(CAppStyleView, CView)

BEGIN_MESSAGE_MAP(CAppStyleView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_COMMAND(ID_W, &CAppStyleView::OnW)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CAppStyleView construction/destruction

CAppStyleView::CAppStyleView()
{
	// TODO: add construction code here

}

CAppStyleView::~CAppStyleView()
{
}

BOOL CAppStyleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	//cs.lpszClass = _T("WURD");

	//cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW, LoadCursor(NULL, IDC_CROSS), (HBRUSH)GetStockObject(BLACK_BRUSH), 0);

	//cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW);

	return CView::PreCreateWindow(cs);
}

// CAppStyleView drawing

void CAppStyleView::OnDraw(CDC* /*pDC*/)
{
	CAppStyleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CAppStyleView printing

BOOL CAppStyleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CAppStyleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CAppStyleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CAppStyleView diagnostics

#ifdef _DEBUG
void CAppStyleView::AssertValid() const
{
	CView::AssertValid();
}

void CAppStyleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAppStyleDoc* CAppStyleView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAppStyleDoc)));
	return (CAppStyleDoc*)m_pDocument;
}
#endif //_DEBUG


// CAppStyleView message handlers


int CAppStyleView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	//SetClassLong(m_hWnd, GCL_HBRBACKGROUND, (LONG)GetStockObject(BLACK_BRUSH));
	//SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(NULL, IDC_HELP));




	return 0;
}


//void CAppStyleView::OnIdiW()
//{
//	// TODO: Add your command handler code here
//
//	MessageBox(_T("W"));
//
//}


void CAppStyleView::OnW()
{
	// TODO: Add your command handler code here

	MessageBox(_T("WW"));

}


void CAppStyleView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CString str;
	str.Format(_T("x=%d, y=%d"), point.x, point.y);
	//((CMainFrame*)GetParent())->m_wndStatusBar.SetWindowTextW(str);

	//((CMainFrame*)GetParent())->SetMessageText(str);

	//((CMainFrame*)GetParent())->GetMessageBar()->SetWindowTextW(str);

	GetParent()->GetDescendantWindow(AFX_IDW_STATUS_BAR)->SetWindowTextW(str);

	CView::OnMouseMove(nFlags, point);
}
