#pragma once


// CProp3 dialog

class CProp3 : public CPropertyPage
{
	DECLARE_DYNAMIC(CProp3)

public:
	CProp3();
	virtual ~CProp3();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_LARGE3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
	virtual BOOL OnInitDialog();
	CString m_salary;
	virtual BOOL OnWizardFinish();
};
