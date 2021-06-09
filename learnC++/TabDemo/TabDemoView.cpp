
// TabDemoView.cpp : implementation of the CTabDemoView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TabDemo.h"
#endif

#include "TabDemoDoc.h"
#include "TabDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTabDemoView

IMPLEMENT_DYNCREATE(CTabDemoView, CView)

BEGIN_MESSAGE_MAP(CTabDemoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_PROPS, &CTabDemoView::OnProps)
END_MESSAGE_MAP()

// CTabDemoView construction/destruction

CTabDemoView::CTabDemoView()
{
	// TODO: add construction code here

	m_zhiye = -1;
	m_didian = _T("");
	memset(m_xingqu, 0, sizeof(m_xingqu));
	m_xinzi = _T("");

}

CTabDemoView::~CTabDemoView()
{
}

BOOL CTabDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTabDemoView drawing

void CTabDemoView::OnDraw(CDC* /*pDC*/)
{
	CTabDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CFont font;
	font.CreatePointFont(300, _T("华文行楷"));

	CClientDC dc(this);
	CFont *oldFont;
	oldFont = dc.SelectObject(&font);
	
	CString str;
	str = _T("职业");

	switch(m_zhiye){
	case 0:
		str+=_T("cxy");
		break;
	case 1:
		str+=_T("jl");
		break;
	case 2:
		str+=_T("lb");
		break;
	default:
		break;
	}
	dc.TextOutW(0, 0, str);

	str = _T("地点");
	str+=m_didian;
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	dc.TextOutW(0, tm.tmHeight, str);
	
	
	dc.SelectObject(oldFont);

	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CTabDemoView printing

BOOL CTabDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTabDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTabDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CTabDemoView diagnostics

#ifdef _DEBUG
void CTabDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CTabDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTabDemoDoc* CTabDemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTabDemoDoc)));
	return (CTabDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CTabDemoView message handlers


void CTabDemoView::OnProps()
{
	// TODO: Add your command handler code here

	CPropSheet propSheet(_T("WURD"));

	propSheet.SetWizardMode();
	if(ID_WIZFINISH == propSheet.DoModal()){
		m_zhiye = propSheet.m_prop1.m_radio1;
		m_didian = propSheet.m_prop1.m_list1;
		//m_xingqu = propSheet.m_prop2;
		m_xinzi = propSheet.m_prop3.m_salary;
		Invalidate();


	}

}
