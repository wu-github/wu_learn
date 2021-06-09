
// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "text.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
	: m_string(_T(""))
	, cpoint(0)
	, m_width(50)
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	// Do not call CWnd::OnPaint() for painting messages

	/*for(int i=0;i<300;i+=10){
		dc.MoveTo(0, i);
		dc.LineTo(300, i);
		dc.MoveTo(i, 0);
		dc.LineTo(i, 300);
	}*/

	CString str("無的");
	str = "無的如果但是無的如果但是無的如果但是";
	dc.TextOutW(50, 40, str);

	CSize sz = dc.GetTextExtent(str);

	str.LoadStringW(IDS_WURD_STR);
	dc.TextOutW(50, 100, str);

	

	dc.BeginPath();
	dc.Rectangle(50, 40, 50 + sz.cx, 40 + sz.cy);
	dc.EndPath();
	//dc.SelectClipPath(RGN_DIFF);
	dc.SelectClipPath(RGN_AND);

	int lineEnd = 500;
	for(int i=0;i<lineEnd;i+=10){
		dc.MoveTo(0, i);
		dc.LineTo(lineEnd, i);
		dc.MoveTo(i, 0);
		dc.LineTo(i, lineEnd);
	}

}



int CChildView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	//CreateSolidCaret(tm.tmAveCharWidth/8, tm.tmHeight);
	bitmap.LoadBitmapW(IDB_BITMAP1);
	CreateCaret(&bitmap);
	
	ShowCaret();

	SetTimer(1, 100, NULL);

	return 0;
}


void CChildView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	CClientDC dc(this);
	CFont font;
	font.CreatePointFont(300, _T("华文行楷"), NULL);
	CFont* oldFont = dc.SelectObject(&font);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	if(0x0d == nChar){
		m_string.Empty();
		cpoint.y+=tm.tmHeight;
	}else if(0x08 == nChar){
		COLORREF bgColor = dc.SetTextColor(dc.GetBkColor());
		dc.TextOutW(cpoint.x, cpoint.y, m_string);
		m_string = m_string.Left(m_string.GetLength() - 1);
		dc.SetTextColor(bgColor);
	}else{
		m_string+=(wchar_t)nChar;
	}
	CSize sz = dc.GetTextExtent(m_string);
	CPoint pt;
	pt.x = cpoint.x + sz.cx;
	pt.y = cpoint.y + sz.cy;
	SetCaretPos(pt);
	dc.TextOutW(cpoint.x, cpoint.y, m_string);

	dc.SelectObject(oldFont);

	CWnd::OnChar(nChar, nRepCnt, nFlags);


}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	CPoint linePt(point);
	for(long pointY=0;pointY<=point.y+tm.tmHeight; pointY+=tm.tmHeight){
		if(pointY >= point.y){
			if(point.y < 0){
				linePt.y = 0;
				return;
			}
			linePt.y = pointY - tm.tmHeight;
			break;
		}
	}
	
	SetCaretPos(linePt);
	m_string.Empty();
	cpoint = linePt;

	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	if(nIDEvent == 1){
		m_width+=5;
		TEXTMETRIC tm;
		dc.GetTextMetrics(&tm);
		CRect rect;
		rect.left = 50;
		rect.top = 100;
		rect.right = m_width;
		rect.bottom = rect.top + tm.tmHeight;

		dc.SetTextColor(RGB(255, 0, 0));
		CString str;
		str.LoadStringW(IDS_WURD_STR);
		dc.DrawText(str, rect, DT_LEFT);

		rect.top = 150;
		rect.bottom = rect.top + tm.tmHeight;
		dc.DrawText(str, rect, DT_RIGHT);

		CSize size = dc.GetTextExtent(str);
		if(m_width > 50+size.cx){
			m_width = 50;
			dc.SetTextColor(RGB(0, 255, 0));
			dc.TextOutW(50, 100, str);
		}
		CSize size1 = dc.GetTextExtent(_T("i"));
		CSize size2 = dc.GetTextExtent(_T("w"));
		CSize size3 = dc.GetTextExtent(_T("無"));
		CSize size4 = dc.GetTextExtent(_T("我"));
		CSize size5 = dc.GetTextExtent(_T("我"));

	}

	CWnd::OnTimer(nIDEvent);
}
