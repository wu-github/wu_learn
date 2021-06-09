
// DynamicMenuView.cpp : implementation of the CDynamicMenuView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DynamicMenu.h"
#endif


#include "DynamicMenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDynamicMenuView

IMPLEMENT_DYNCREATE(CDynamicMenuView, CView)

BEGIN_MESSAGE_MAP(CDynamicMenuView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_COMMAND(IDM_PHONE, OnPhone)
END_MESSAGE_MAP()

// CDynamicMenuView construction/destruction

CDynamicMenuView::CDynamicMenuView()
	: m_index(-1)
	, m_string(_T(""))
{
	// TODO: add construction code here

}

CDynamicMenuView::~CDynamicMenuView()
{
}

BOOL CDynamicMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDynamicMenuView drawing

void CDynamicMenuView::OnDraw(CDC* /*pDC*/)
{
	CDynamicMenuDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CDynamicMenuView printing

BOOL CDynamicMenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDynamicMenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDynamicMenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CDynamicMenuView diagnostics

#ifdef _DEBUG
void CDynamicMenuView::AssertValid() const
{
	CView::AssertValid();
}

void CDynamicMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDynamicMenuDoc* CDynamicMenuView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDynamicMenuDoc)));
	return (CDynamicMenuDoc*)m_pDocument;
}
#endif //_DEBUG


// CDynamicMenuView message handlers


void CDynamicMenuView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	CClientDC dc(this);
	if(0x0d == nChar){
		if(0 == ++ m_index){
			m_menu.CreatePopupMenu();
			GetParent()->GetMenu()->AppendMenuW(MF_POPUP, (UINT)m_menu.m_hMenu, _T("PhoneBook"));
			GetParent()->DrawMenuBar();
		}
		m_menu.AppendMenuW(MF_STRING, IDM_PHONE, m_string.Left(m_string.Find(' ')));
		m_stirngarray.Add(m_string);
		m_string.Empty();
		Invalidate();
		
	}else{
		m_string+=(wchar_t)nChar;
		dc.TextOutW(0, 0, m_string);
	}

	CView::OnChar(nChar, nRepCnt, nFlags);
}

void CDynamicMenuView::OnPhone(){
	MessageBox(_T("on phone"));
}


//BOOL CDynamicMenuView::OnCommand(WPARAM wParam, LPARAM lParam)
//{
//	// TODO: Add your specialized code here and/or call the base class
//
//	MessageBox(_T("view command"));
//
//	return CView::OnCommand(wParam, lParam);
//}
