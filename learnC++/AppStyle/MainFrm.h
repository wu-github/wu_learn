
// MainFrm.h : interface of the CMainFrame class
//

#pragma once

#define WM_PROGRESS WM_USER + 1

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame);
	CProgressCtrl m_progress;

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CToolBar          m_wndToolBar;
	CToolBar		  m_newToolBar;
public:
	CStatusBar        m_wndStatusBar;

// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg LRESULT OnProgress(WPARAM, LPARAM);
	DECLARE_MESSAGE_MAP()

private:
	HICON m_icon[3];

public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnNewbar();
	afx_msg void OnUpdateNewbar(CCmdUI *pCmdUI);
	afx_msg void OnPaint();
};


