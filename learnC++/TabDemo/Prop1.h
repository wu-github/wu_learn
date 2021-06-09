#pragma once


// CProp1 dialog

class CProp1 : public CPropertyPage
{
	DECLARE_DYNAMIC(CProp1)

public:
	CProp1();
	virtual ~CProp1();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_LARGE1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
	int m_radio1;
	virtual LRESULT OnWizardNext();
	virtual BOOL OnInitDialog();
	CString m_list1;
};
