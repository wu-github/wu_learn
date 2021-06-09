
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Menu2.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_WURD, &CMainFrame::OnWurd)
//	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, &CMainFrame::OnUpdateEditCut)
ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, &CMainFrame::OnUpdateEditCut)
ON_UPDATE_COMMAND_UI(ID_FILE_NEW, &CMainFrame::OnUpdateFileNew)
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

	m_bAutoMenuEnable = FALSE;
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

	//GetMenu()->GetSubMenu(0)->CheckMenuItem(0, MF_BYPOSITION | MF_CHECKED);
	//GetMenu()->GetSubMenu(0)->CheckMenuItem(ID_FILE_NEW, MF_BYCOMMAND | MF_CHECKED);
	//GetMenu()->GetSubMenu(0)->SetDefaultItem(1, TRUE);
	//GetMenu()->GetSubMenu(0)->SetDefaultItem(ID_FILE_OPEN, FALSE);
	//GetMenu()->GetSubMenu(0)->SetDefaultItem(5, TRUE);

	//CString str;
	//str.Format(_T("x=%d, y=%d"), GetSystemMetrics(SM_CXMENUCHECK), GetSystemMetrics(SM_CYMENUCHECK));
	////MessageBox(str);
	//onBitmap.LoadBitmapW(IDB_BITMAP1);
	//upBitmap.LoadBitmapW(IDB_BITMAP2);
	//GetMenu()->GetSubMenu(0)->SetMenuItemBitmaps(0, MF_BYPOSITION, &upBitmap, &onBitmap);

	//disable menu: m_bAutoMenuEnable = FALSE
	GetMenu()->GetSubMenu(0)->EnableMenuItem(1, MF_BYPOSITION | MF_DISABLED| MF_GRAYED);

	
	/*SetMenu(NULL);
	menu.LoadMenuW(IDR_MAINFRAME);
	SetMenu(&menu);*/

	/*SetMenu(NULL);
	CMenu menu1;
	menu1.LoadMenuW(IDR_MAINFRAME);
	SetMenu(&menu1);
	menu1.Detach();*/

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


// CMainFrame message handlers


void CMainFrame::OnWurd()
{
	// TODO: Add your command handler code here

	MessageBox(_T("main frame click"));

}


void CMainFrame::OnUpdateEditCut(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	//if(2 == pCmdUI->m_nIndex){
	if(ID_EDIT_CUT == pCmdUI->m_nID){
		pCmdUI->Enable(FALSE);	
	}
}


void CMainFrame::OnUpdateFileNew(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here

	/*if(ID_FILE_NEW == pCmdUI->m_nID){
		pCmdUI->Enable(FALSE);	
	}*/

	if(0 == pCmdUI->m_nIndex){
		pCmdUI->Enable(FALSE);
	}

}
