#pragma once
#include "afxwin.h"


// CSettingDlg dialog

class CSettingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSettingDlg)

public:
	CSettingDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSettingDlg();

// Dialog Data
	enum { IDD = IDD_SETTINGS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	UINT m_xiankuan;
	afx_msg void OnEnChangeEditXiankuan();
private:
	
public:
	int m_xianxing;
	afx_msg void OnClickedRadio1();
	afx_msg void OnPaint();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	COLORREF m_color;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
private:
	CBrush m_brush;
};
