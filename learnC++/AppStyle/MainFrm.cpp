
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "AppStyle.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_COMMAND(ID_NEWBAR, &CMainFrame::OnNewbar)
	ON_UPDATE_COMMAND_UI(ID_NEWBAR, &CMainFrame::OnUpdateNewbar)
	ON_MESSAGE(WM_PROGRESS, OnProgress)
	ON_WM_PAINT()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
	IDS_TIMER1,
	IDS_PROGRESS,
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here


}

CMainFrame::~CMainFrame()
{
}


extern CAppStyleApp theApp;
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: Delete these three lines if you don't want the toolbar to be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);



	if (!m_newToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_RIGHT | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_newToolBar.LoadToolBar(IDR_TOOLBAR1))
	{
		TRACE0("Failed to create new toolbar\n");
		return -1;      // fail to create
	}


	// TODO: Delete these three lines if you don't want the toolbar to be dockable
	m_newToolBar.EnableDocking(CBRS_ALIGN_ANY);
	//EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_newToolBar);

	
	CTime time = CTime::GetCurrentTime();
	CString str = time.Format(_T("%H:%M:%S"));

	CClientDC dc(this);
	CSize sz = dc.GetTextExtent(str);
	m_wndStatusBar.SetPaneInfo(4, IDS_TIMER1, SBPS_NORMAL, sz.cx);

	//m_wndStatusBar.SetPaneText(4, str);
	m_wndStatusBar.SetPaneText(m_wndStatusBar.CommandToIndex(IDS_TIMER1), str);


	//SetWindowLong(m_hWnd, GWL_STYLE, WS_OVERLAPPEDWINDOW);
	//SetWindowLong(m_hWnd, GWL_STYLE, GetWindowLong(m_hWnd, GWL_STYLE) & ~WS_MAXIMIZEBOX);

	//SetClassLong(m_hWnd, GCL_HICON, (LONG)LoadIcon(NULL, IDI_ERROR));


	m_icon[0] = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_ICON1));
	m_icon[1] = LoadIcon(theApp.m_hInstance, MAKEINTRESOURCE(IDI_ICON2));
	m_icon[2] = LoadIcon(AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDI_ICON3));

	SetClassLong(m_hWnd, GCL_HICON, (LONG)m_icon[0]);

	SetTimer(1, 1000, NULL);

	//CRect rect;
	//m_wndStatusBar.GetItemRect(5, &rect);

	////m_progress.Create(WS_CHILD | WS_VISIBLE | PBS_VERTICAL, CRect(100, 100, 120, 200), this, 123);
	//m_progress.Create(WS_CHILD | WS_VISIBLE, rect, &m_wndStatusBar, 123);
	//m_progress.SetPos(50);

	//SendMessage(WM_PROGRESS);
	//PostMessage(WM_PROGRESS);

	return 0;
}

LRESULT CMainFrame::OnProgress(WPARAM w,LPARAM l){
	CRect rect;
	m_wndStatusBar.GetItemRect(5, &rect);

	//m_progress.Create(WS_CHILD | WS_VISIBLE | PBS_VERTICAL, CRect(100, 100, 120, 200), this, 123);
	m_progress.Create(WS_CHILD | WS_VISIBLE | PBS_SMOOTH, rect, &m_wndStatusBar, 123);
	m_progress.SetPos(50);

	return true;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.cx = 1000;
	cs.cy = 555;
	cs.style&=~FWS_ADDTOTITLE;
	////cs.style = cs.style & ~FWS_ADDTOTITLE;
	////cs.style = WS_OVERLAPPEDWINDOW;
	cs.lpszName = _T("WURD...");

	/*WNDCLASS wndcls;
	wndcls.cbClsExtra = 0;
	wndcls.cbWndExtra = 0;
	wndcls.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndcls.hCursor = LoadCursor(NULL, IDC_HELP);
	wndcls.hIcon = LoadIcon(NULL, IDI_ERROR);
	wndcls.hInstance = AfxGetInstanceHandle();
	wndcls.lpfnWndProc = ::DefWindowProc;
	wndcls.lpszClassName = _T("wurd");
	wndcls.lpszMenuName = NULL;
	wndcls.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wndcls);
	cs.lpszClass = _T("wurd");*/

	//cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW, 0, 0, LoadIcon(NULL, IDI_WARNING));
	//cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW);

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


// CMainFrame message handlers


void CMainFrame::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	static int index = 1;
	SetClassLong(m_hWnd, GCL_HICON, (LONG)m_icon[index]);

	index = ++index%3;


	CTime time = CTime::GetCurrentTime();
	CString str = time.Format(_T("%H:%M:%S"));

	CClientDC dc(this);
	CSize sz = dc.GetTextExtent(str);
	m_wndStatusBar.SetPaneInfo(4, IDS_TIMER1, SBPS_NORMAL, sz.cx);

	//m_wndStatusBar.SetPaneText(4, str);
	m_wndStatusBar.SetPaneText(m_wndStatusBar.CommandToIndex(IDS_TIMER1), str);

	m_progress.StepIt();

	CFrameWnd::OnTimer(nIDEvent);
}


void CMainFrame::OnNewbar()
{
	//TODO: Add your command handler code here
	//if(m_newToolBar.IsVisible()){
	//	m_newToolBar.ShowWindow(SW_HIDE);
	//}else{
	//	m_newToolBar.ShowWindow(SW_SHOW);
	//}
	//m_newToolBar.IsFloating();
	//RecalcLayout();
	//DockControlBar(&m_newToolBar);

	ShowControlBar(&m_newToolBar, !m_newToolBar.IsWindowVisible(), false);
	

}


void CMainFrame::OnUpdateNewbar(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here

	pCmdUI->SetCheck(m_newToolBar.IsWindowVisible());

}


void CMainFrame::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CFrameWnd::OnPaint() for painting messages

	CRect rect;
	m_wndStatusBar.GetItemRect(5, &rect);

	//m_progress.Create(WS_CHILD | WS_VISIBLE | PBS_VERTICAL, CRect(100, 100, 120, 200), this, 123);
	if(!m_progress.m_hWnd){
		m_progress.Create(WS_CHILD | WS_VISIBLE | PBS_SMOOTH, rect, &m_wndStatusBar, 123);
	}else{
		m_progress.MoveWindow(rect);
	}
	
	m_progress.SetPos(50);

}
