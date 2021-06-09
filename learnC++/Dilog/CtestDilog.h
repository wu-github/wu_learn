#pragma once
#include "afxwin.h"


// CtestDilog dialog

class CtestDilog : public CDialogEx
{
	DECLARE_DYNAMIC(CtestDilog)

public:
	CtestDilog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CtestDilog();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnTestdilog();
	afx_msg void OnBnClickedButton1();
private:
	CButton m_btn;
	bool m_created;
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnClickedStatic1();
//	CEdit m_edit1;
//	CEdit m_edit2;
//	CEdit m_edit3;
	int m_edit1;
	int m_edit2;
	int m_edit3;
	CEdit m_edit1_C;
	CEdit m_edit2_C;
	CEdit m_edit3_C;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
