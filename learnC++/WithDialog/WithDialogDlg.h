
// WithDialogDlg.h : header file
//

#pragma once

#include "WurdButton.h"


// CWithDialogDlg dialog
class CWithDialogDlg : public CDialogEx
{
// Construction
public:
	CWithDialogDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_WITHDIALOG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CWurdButton m_btn1;
	CWurdButton m_btn2;
};
