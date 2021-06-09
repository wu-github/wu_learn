
// Graphic-save-redrawView.cpp : implementation of the CGraphicsaveredrawView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Graphic-save-redraw.h"
#endif

#include "Graphic-save-redrawDoc.h"
#include "Graphic-save-redrawView.h"
#include "Graph.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGraphicsaveredrawView

IMPLEMENT_DYNCREATE(CGraphicsaveredrawView, CScrollView)

BEGIN_MESSAGE_MAP(CGraphicsaveredrawView, CScrollView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_COMMAND(ID_DIAN, &CGraphicsaveredrawView::OnDian)
	ON_COMMAND(ID_ZHIXIAN, &CGraphicsaveredrawView::OnZhixian)
	ON_COMMAND(ID_JUXING, &CGraphicsaveredrawView::OnJuxing)
	ON_COMMAND(ID_TUOYUAN, &CGraphicsaveredrawView::OnTuoyuan)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_PAINT()
	ON_COMMAND(ID_FILE_OPEN, &CGraphicsaveredrawView::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, &CGraphicsaveredrawView::OnFileSave)
END_MESSAGE_MAP()

// CGraphicsaveredrawView construction/destruction

CGraphicsaveredrawView::CGraphicsaveredrawView()
	: m_type(0)
	, m_point(0)
{
	// TODO: add construction code here
	m_mfdc.Create();
}

CGraphicsaveredrawView::~CGraphicsaveredrawView()
{
}

BOOL CGraphicsaveredrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// CGraphicsaveredrawView drawing

void CGraphicsaveredrawView::OnDraw(CDC* pDC)
{
	CGraphicsaveredrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	/*CBrush *brush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	pDC->SelectObject(brush);
	
	for(int i=0;i<m_array.GetSize();i++){
		switch(((CGraph*)m_array.GetAt(i))->m_type){
		case 1:
			pDC->SetPixelV(((CGraph*)m_array.GetAt(i))->m_endPoint, RGB(0, 0, 0));
			break;
		case 2:
			pDC->MoveTo(((CGraph*)m_array.GetAt(i))->m_point);
			pDC->LineTo(((CGraph*)m_array.GetAt(i))->m_endPoint);
			break;
		case 3:
			pDC->Rectangle(CRect(((CGraph*)m_array.GetAt(i))->m_point, ((CGraph*)m_array.GetAt(i))->m_endPoint));
			break;
		case 4:
			pDC->Ellipse(CRect(((CGraph*)m_array.GetAt(i))->m_point, ((CGraph*)m_array.GetAt(i))->m_endPoint));
			break;
		}
		
	}*/

	//
	/*HMETAFILE metafile;
	metafile = m_mfdc.Close();
	pDC->PlayMetaFile(metafile);
	m_mfdc.Create();
	m_mfdc.PlayMetaFile(metafile);
	DeleteMetaFile(metafile);*/

	CRect rect;
	GetClientRect(&rect);
	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &m_dcCompa, 0, 0, SRCCOPY);
	


	// TODO: add draw code for native data here
}


// CGraphicsaveredrawView printing

BOOL CGraphicsaveredrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGraphicsaveredrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGraphicsaveredrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CGraphicsaveredrawView diagnostics

#ifdef _DEBUG
void CGraphicsaveredrawView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CGraphicsaveredrawView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CGraphicsaveredrawDoc* CGraphicsaveredrawView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphicsaveredrawDoc)));
	return (CGraphicsaveredrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CGraphicsaveredrawView message handlers


void CGraphicsaveredrawView::OnDian()
{
	// TODO: Add your command handler code here
	m_type = 1;
}


void CGraphicsaveredrawView::OnZhixian()
{
	// TODO: Add your command handler code here
	m_type = 2;
}


void CGraphicsaveredrawView::OnJuxing()
{
	// TODO: Add your command handler code here
	m_type = 3;
}


void CGraphicsaveredrawView::OnTuoyuan()
{
	// TODO: Add your command handler code here
	m_type = 4;
}


void CGraphicsaveredrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	m_point = point;

	CScrollView::OnLButtonDown(nFlags, point);
}


void CGraphicsaveredrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CClientDC dc(this);
	CBrush *brush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	//dc.SelectObject(brush);
	m_mfdc.SelectObject(brush);

	if(!m_dcCompa.m_hDC){
		m_dcCompa.CreateCompatibleDC(&dc);
		CRect rect;
		GetClientRect(&rect);
		CBitmap bitmap;
		bitmap.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
		m_dcCompa.SelectObject(&bitmap);
		m_dcCompa.BitBlt(0, 0, rect.Width(), rect.Height(), &dc, 0, 0, SRCCOPY);
		m_dcCompa.SelectObject(brush);
	}


	if(m_type == 1){
		//dc.SetPixelV(point, RGB(0, 0, 0));
		//m_mfdc.SetPixelV(point, RGB(0, 0, 0));
		m_dcCompa.SetPixelV(point, RGB(0, 0, 0));
	}else if(m_type == 2){
		//dc.MoveTo(m_point);
		//dc.LineTo(point);
		//m_mfdc.MoveTo(m_point);
		//m_mfdc.LineTo(point);

		m_dcCompa.MoveTo(m_point);
		m_dcCompa.LineTo(point);
	}else if(m_type == 3){
		//dc.Rectangle(CRect(m_point, point));
		//m_mfdc.Rectangle(CRect(m_point, point));
		m_dcCompa.Rectangle(CRect(m_point, point));
	
	}else if(m_type == 4){
		//dc.Ellipse(CRect(m_point, point));
		//m_mfdc.Ellipse(CRect(m_point, point));
		m_dcCompa.Ellipse(CRect(m_point, point));
	}

	//OnPrepareDC(&dc);
	//dc.DPtoLP(&m_point);
	//dc.DPtoLP(&point);

	////CGraph graph(m_type, m_point, point);
	////m_array.Add(&graph);
	//CGraph *graph = new CGraph(m_type, m_point, point);
	//m_array.Add(graph);

	CScrollView::OnLButtonUp(nFlags, point);
}


void CGraphicsaveredrawView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here

	OnPrepareDC(&dc);
	OnDraw(&dc);

	// Do not call CScrollView::OnPaint() for painting messages
}


void CGraphicsaveredrawView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	SetScrollSizes(MM_TEXT, CSize(800, 600));

	// TODO: Add your specialized code here and/or call the base class
}


void CGraphicsaveredrawView::OnFileOpen()
{
	// TODO: Add your command handler code here

	HMETAFILE metafile;
	metafile = GetMetaFile(_T("meta.wmf"));
	m_mfdc.PlayMetaFile(metafile);
	DeleteMetaFile(metafile);
	Invalidate();

}


void CGraphicsaveredrawView::OnFileSave()
{
	// TODO: Add your command handler code here

	HMETAFILE metafile;
	metafile = m_mfdc.Close();
	CopyMetaFile(metafile, _T("meta.wmf"));
	m_mfdc.Create();
	DeleteMetaFile(metafile);

}
