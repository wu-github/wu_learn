// Prop1.cpp : implementation file
//

#include "stdafx.h"
#include "TabDemo.h"
#include "Prop1.h"
#include "afxdialogex.h"


// CProp1 dialog

IMPLEMENT_DYNAMIC(CProp1, CPropertyPage)

CProp1::CProp1()
	: CPropertyPage(CProp1::IDD)
{

	m_radio1 = -1;
	m_list1 = _T("");
}

CProp1::~CProp1()
{
}

void CProp1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_radio1);
	DDX_LBString(pDX, IDC_LIST1, m_list1);
}


BEGIN_MESSAGE_MAP(CProp1, CPropertyPage)
END_MESSAGE_MAP()


// CProp1 message handlers


BOOL CProp1::OnSetActive()
{
	// TODO: Add your specialized code here and/or call the base class

	((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_NEXT);

	return CPropertyPage::OnSetActive();
}


LRESULT CProp1::OnWizardNext()
{
	// TODO: Add your specialized code here and/or call the base class

	UpdateData();
	if(m_radio1 == -1){
		MessageBox(_T("输入职业"));
		return -1;
	}
	if(m_list1 == _T("")){
		MessageBox(_T("输入地点"));
		return -1;
	}

	return CPropertyPage::OnWizardNext();
}


BOOL CProp1::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  Add extra initialization here

	((CListBox*)GetDlgItem(IDC_LIST1))->AddString(_T("啊"));
	((CListBox*)GetDlgItem(IDC_LIST1))->AddString(_T("吧"));
	((CListBox*)GetDlgItem(IDC_LIST1))->AddString(_T("从从从从从从从从从从从从从从从从从从从从从从从从从从从从从从从从从从从从"));

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
