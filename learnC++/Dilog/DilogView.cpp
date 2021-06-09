
// DilogView.cpp : implementation of the CDilogView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Dilog.h"
#endif

#include "DilogDoc.h"
#include "DilogView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include "CtestDilog.h"


// CDilogView

IMPLEMENT_DYNCREATE(CDilogView, CView)

BEGIN_MESSAGE_MAP(CDilogView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_TESTDILOG, &CDilogView::OnTestdilog)
END_MESSAGE_MAP()

// CDilogView construction/destruction

CDilogView::CDilogView()
{
	// TODO: add construction code here

}

CDilogView::~CDilogView()
{
}

BOOL CDilogView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDilogView drawing

void CDilogView::OnDraw(CDC* /*pDC*/)
{
	CDilogDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CDilogView printing

BOOL CDilogView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDilogView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDilogView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CDilogView diagnostics

#ifdef _DEBUG
void CDilogView::AssertValid() const
{
	CView::AssertValid();
}

void CDilogView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDilogDoc* CDilogView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDilogDoc)));
	return (CDilogDoc*)m_pDocument;
}
#endif //_DEBUG


// CDilogView message handlers


void CDilogView::OnTestdilog()
{
	// TODO: Add your command handler code here
	//Ä£Ì¬
	CtestDilog dialog;
	dialog.DoModal();

	//·Ç
	/*CtestDilog *dilog = new CtestDilog();
	dilog->Create(IDD_DIALOG1, this);
	dilog->ShowWindow(SW_SHOW);*/

}
