
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "DynamicMenu.h"

#include "MainFrm.h"

#include "DynamicMenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(IDM_HELLO, OnHello)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	/*CMenu menu;
	menu.CreatePopupMenu();
	GetMenu()->AppendMenuW(MF_POPUP, (UINT)menu.m_hMenu, _T("Append"));
	menu.Detach();

	CMenu menu1;
	menu1.CreatePopupMenu();
	GetMenu()->InsertMenuW(2, MF_BYPOSITION | MF_POPUP, (UINT)menu1.m_hMenu, _T("Insert"));
	menu1.AppendMenuW(MF_STRING, IDM_HELLO, _T("hello"));
	menu1.AppendMenuW(MF_STRING, 222, _T("hi"));
	menu1.Detach();*/

	/*GetMenu()->GetSubMenu(0)->AppendMenuW(MF_STRING, 114, _T("welcome"));
	GetMenu()->GetSubMenu(0)->InsertMenuW(ID_FILE_OPEN, MF_BYCOMMAND | MF_STRING, 115, _T("ttt"));

	GetMenu()->DeleteMenu(1, MF_BYPOSITION);

	GetMenu()->GetSubMenu(0)->DeleteMenu(2, MF_BYPOSITION);*/

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG

void CMainFrame::OnHello(){
	MessageBox(_T("on hello"));
}


// CMainFrame message handlers


//BOOL CMainFrame::OnCommand(WPARAM wParam, LPARAM lParam)
//{
//	// TODO: Add your specialized code here and/or call the base class
//
//	MessageBox(_T("frame command"));
//
//	return CFrameWnd::OnCommand(wParam, lParam);
//}


BOOL CMainFrame::OnCommand(WPARAM wParam, LPARAM lParam)
{
	// TODO: Add your specialized code here and/or call the base class

	int menuCmdId = LOWORD(wParam);
	CDynamicMenuView *pView = (CDynamicMenuView*)GetActiveView();
	if(menuCmdId == IDM_PHONE){
		CString str;
		str.Format(_T("%d"), menuCmdId);
		MessageBox(str);
		int menuLId = LOWORD(lParam);
		CString str1;
		str1.Format(_T("%d"), menuLId);
		MessageBox(str1);
		CClientDC dc(pView);
		dc.TextOutW(0, 0, pView->m_stirngarray.GetAt(0));
	}

	return CFrameWnd::OnCommand(wParam, lParam);
}
