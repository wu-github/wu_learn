
// FileSerialView.cpp : implementation of the CFileSerialView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "FileSerial.h"
#endif

#include "FileSerialDoc.h"
#include "FileSerialView.h"
#include "Graph.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFileSerialView

IMPLEMENT_DYNCREATE(CFileSerialView, CView)

BEGIN_MESSAGE_MAP(CFileSerialView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_WRITEFILE, &CFileSerialView::OnWritefile)
	ON_COMMAND(ID_READFILE, &CFileSerialView::OnReadfile)
	ON_COMMAND(ID_DIAN, &CFileSerialView::OnDian)
	ON_COMMAND(ID_ZHIXIAN, &CFileSerialView::OnZhixian)
	ON_COMMAND(ID_JUXING, &CFileSerialView::OnJuxing)
	ON_COMMAND(ID_TUOYUAN, &CFileSerialView::OnTuoyuan)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CFileSerialView construction/destruction

CFileSerialView::CFileSerialView()
{
	// TODO: add construction code here
	m_type = 0;
	m_point = 0;
}

CFileSerialView::~CFileSerialView()
{
}

BOOL CFileSerialView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CFileSerialView drawing

void CFileSerialView::OnDraw(CDC* pDC)
{
	CFileSerialDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CFileSerialDoc* doc = (CFileSerialDoc*)GetDocument();
	int size;
	size = doc->m_objArray.GetSize();
	for(int i=0;i<size;i++){
		((CGraph*)doc->m_objArray.GetAt(i))->Draw(pDC);
	}

	// TODO: add draw code for native data here
}


// CFileSerialView printing

BOOL CFileSerialView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFileSerialView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFileSerialView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CFileSerialView diagnostics

#ifdef _DEBUG
void CFileSerialView::AssertValid() const
{
	CView::AssertValid();
}

void CFileSerialView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFileSerialDoc* CFileSerialView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFileSerialDoc)));
	return (CFileSerialDoc*)m_pDocument;
}
#endif //_DEBUG


// CFileSerialView message handlers


void CFileSerialView::OnWritefile()
{
	// TODO: Add your command handler code here

	CFile file(_T("q.txt"), CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store);
	int i = 4;
	char ch = 'a';
	float f = 1.3f;
	CString str("wurd");
	ar<<i<<ch<<f<<str;
}


void CFileSerialView::OnReadfile()
{
	// TODO: Add your command handler code here

	CFile file(_T("q.txt"), CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	int i;
	char ch;
	float f;
	CString str;
	CString str1;
	ar>>i>>ch>>f>>str;
	str1.Format(_T("%d, %c, %f, %s"), i, ch, f, str);
	MessageBox(str1);

}


void CFileSerialView::OnDian()
{
	// TODO: Add your command handler code here
	m_type = 1;
}


void CFileSerialView::OnZhixian()
{
	// TODO: Add your command handler code here
	m_type = 2;
}


void CFileSerialView::OnJuxing()
{
	// TODO: Add your command handler code here
	m_type = 3;
}


void CFileSerialView::OnTuoyuan()
{
	// TODO: Add your command handler code here
	m_type = 4;
}


void CFileSerialView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	m_point = point;

	CView::OnLButtonDown(nFlags, point);
}


void CFileSerialView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CClientDC dc(this);
	CBrush *brush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	

	if(m_type == 1){
		//dc.SetPixelV(point, RGB(0, 0, 0));
		//m_mfdc.SetPixelV(point, RGB(0, 0, 0));
		dc.SetPixelV(point, RGB(0, 0, 0));
	}else if(m_type == 2){
		//dc.MoveTo(m_point);
		//dc.LineTo(point);
		//m_mfdc.MoveTo(m_point);
		//m_mfdc.LineTo(point);

		dc.MoveTo(m_point);
		dc.LineTo(point);
	}else if(m_type == 3){
		//dc.Rectangle(CRect(m_point, point));
		//m_mfdc.Rectangle(CRect(m_point, point));
		dc.Rectangle(CRect(m_point, point));
	
	}else if(m_type == 4){
		//dc.Ellipse(CRect(m_point, point));
		//m_mfdc.Ellipse(CRect(m_point, point));
		dc.Ellipse(CRect(m_point, point));
	}
	CGraph *graph = new CGraph(m_type, m_point, point);
	m_objArray.Add(graph);
	CView::OnLButtonUp(nFlags, point);
}
