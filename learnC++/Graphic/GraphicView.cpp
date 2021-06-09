
// GraphicView.cpp : implementation of the CGraphicView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Graphic.h"
#endif

#include "GraphicDoc.h"
#include "GraphicView.h"
#include "SettingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGraphicView

IMPLEMENT_DYNCREATE(CGraphicView, CView)

BEGIN_MESSAGE_MAP(CGraphicView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_DIAN, &CGraphicView::OnDian)
	ON_COMMAND(ID_ZHIXIAN, &CGraphicView::OnZhixian)
	ON_COMMAND(ID_JUXING, &CGraphicView::OnJuxing)
	ON_COMMAND(ID_TUOYUAN, &CGraphicView::OnTuoyuan)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_SETTINGS, &CGraphicView::OnSettings)
	ON_COMMAND(ID_YANSE, &CGraphicView::OnYanse)
	ON_COMMAND(ID_FONT, &CGraphicView::OnFont)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CGraphicView construction/destruction

CGraphicView::CGraphicView()
	: m_nType(0)
	, m_point(0)
	, m_xiankuan(0)
	, m_xianxing(0)
	, m_fontName(_T(""))
{
	// TODO: add construction code here
	m_color = RGB(0, 0, 0);

}

CGraphicView::~CGraphicView()
{
}

BOOL CGraphicView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CGraphicView drawing

void CGraphicView::OnDraw(CDC* pDC)
{
	CGraphicDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CFont *oldFont = pDC->SelectObject(&m_font);
	pDC->TextOutW(0, 0, m_fontName);
	pDC->SelectObject(oldFont);

	// TODO: add draw code for native data here
}


// CGraphicView printing

BOOL CGraphicView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGraphicView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGraphicView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CGraphicView diagnostics

#ifdef _DEBUG
void CGraphicView::AssertValid() const
{
	CView::AssertValid();
}

void CGraphicView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGraphicDoc* CGraphicView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphicDoc)));
	return (CGraphicDoc*)m_pDocument;
}
#endif //_DEBUG


// CGraphicView message handlers


void CGraphicView::OnDian()
{
	// TODO: Add your command handler code here
	m_nType = 1;

}


void CGraphicView::OnZhixian()
{
	// TODO: Add your command handler code here
	m_nType = 2;
}


void CGraphicView::OnJuxing()
{
	// TODO: Add your command handler code here
	m_nType = 3;
}


void CGraphicView::OnTuoyuan()
{
	// TODO: Add your command handler code here
	m_nType = 4;
}


void CGraphicView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	m_point = point;

	CView::OnLButtonDown(nFlags, point);
}


void CGraphicView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CClientDC dc(this);
	//CPen pen(PS_SOLID, m_xiankuan, RGB(200, 0, 0));
	CPen pen(m_xianxing, m_xiankuan, m_color);
	dc.SelectObject(pen);
	CBrush *brush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	dc.SelectObject(brush);
	switch(m_nType){
		case 1:
			dc.SetPixel(point, m_color);
			break;
		case 2:
			dc.MoveTo(m_point);
			dc.LineTo(point);
			break;
		case 3:
			dc.Rectangle(CRect(m_point, point));
			break;
		case 4:
			dc.Ellipse(CRect(m_point, point));
			break;
	}

	CView::OnLButtonUp(nFlags, point);
}


void CGraphicView::OnSettings()
{
	// TODO: Add your command handler code here
	CSettingDlg setting;
	setting.m_xiankuan = m_xiankuan;
	setting.m_xianxing = m_xianxing;
	setting.m_color = m_color;
	if(IDOK == setting.DoModal()){
		m_xiankuan = setting.m_xiankuan;
		m_xianxing = setting.m_xianxing;
	}

}


void CGraphicView::OnYanse()
{
	// TODO: Add your command handler code here

	CColorDialog color;
	color.m_cc.Flags |= CC_RGBINIT | CC_FULLOPEN;
	color.m_cc.rgbResult = m_color;
	if(IDOK == color.DoModal()){
		m_color = color.m_cc.rgbResult;
	}
}


void CGraphicView::OnFont()
{
	// TODO: Add your command handler code here

	CFontDialog font;
	if(IDOK == font.DoModal()){
		if(m_font.m_hObject){
			m_font.DeleteObject();
		}
		m_font.CreateFontIndirectW(font.m_cf.lpLogFont);
		m_fontName = font.m_cf.lpLogFont->lfFaceName;
		Invalidate();
	}
}


BOOL CGraphicView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	CBitmap bitmap;
	bitmap.LoadBitmapW(IDB_BITMAP1);

	BITMAP bmp;
	bitmap.GetBitmap(&bmp);

	CDC dcCompatible;
	dcCompatible.CreateCompatibleDC(pDC);

	dcCompatible.SelectObject(&bitmap);
	CRect rect;
	GetClientRect(&rect);

	//pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &dcCompatible, 0, 0, SRCCOPY);
	pDC->StretchBlt(0, 0, rect.Width(), rect.Height(), &dcCompatible, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY);

	return true;
	//return CView::OnEraseBkgnd(pDC);
}
