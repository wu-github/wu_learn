// Prop3.cpp : implementation file
//

#include "stdafx.h"
#include "TabDemo.h"
#include "Prop3.h"
#include "afxdialogex.h"


// CProp3 dialog

IMPLEMENT_DYNAMIC(CProp3, CPropertyPage)

CProp3::CProp3()
	: CPropertyPage(CProp3::IDD)
	, m_salary(_T(""))
{

}

CProp3::~CProp3()
{
}

void CProp3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CProp3, CPropertyPage)
END_MESSAGE_MAP()


// CProp3 message handlers


BOOL CProp3::OnSetActive()
{
	// TODO: Add your specialized code here and/or call the base class

	((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_BACK | PSWIZB_FINISH);

	return CPropertyPage::OnSetActive();
}


BOOL CProp3::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  Add extra initialization here

	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(_T("1000"));
	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(_T("2000"));
	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(_T("3000"));
	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(_T("400000000000000000000000000000"));
	((CComboBox*)GetDlgItem(IDC_COMBO2))->SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


BOOL CProp3::OnWizardFinish()
{
	// TODO: Add your specialized code here and/or call the base class

	int index = ((CComboBox*)GetDlgItem(IDC_COMBO2))->GetCurSel();
	((CComboBox*)GetDlgItem(IDC_COMBO2))->GetLBText(index, m_salary);

	return CPropertyPage::OnWizardFinish();
}
