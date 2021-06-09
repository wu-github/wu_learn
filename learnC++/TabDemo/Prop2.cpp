// Prop2.cpp : implementation file
//

#include "stdafx.h"
#include "TabDemo.h"
#include "Prop2.h"
#include "afxdialogex.h"


// CProp2 dialog

IMPLEMENT_DYNAMIC(CProp2, CPropertyPage)

CProp2::CProp2()
	: CPropertyPage(CProp2::IDD)
{

}

CProp2::~CProp2()
{
}

void CProp2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CProp2, CPropertyPage)
END_MESSAGE_MAP()


// CProp2 message handlers


BOOL CProp2::OnSetActive()
{
	// TODO: Add your specialized code here and/or call the base class

	((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_BACK | PSWIZB_NEXT);

	return CPropertyPage::OnSetActive();
}
