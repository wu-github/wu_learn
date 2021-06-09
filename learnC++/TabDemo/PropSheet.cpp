// PropSheet.cpp : implementation file
//

#include "stdafx.h"
#include "TabDemo.h"
#include "PropSheet.h"


// CPropSheet

IMPLEMENT_DYNAMIC(CPropSheet, CPropertySheet)

CPropSheet::CPropSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_prop1);
	AddPage(&m_prop2);
	AddPage(&m_prop3);

}

CPropSheet::CPropSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_prop1);
	AddPage(&m_prop2);
	AddPage(&m_prop3);
}

CPropSheet::~CPropSheet()
{
}


BEGIN_MESSAGE_MAP(CPropSheet, CPropertySheet)
	ON_COMMAND(ID_PROPS, &CPropSheet::OnProps)
END_MESSAGE_MAP()


// CPropSheet message handlers


void CPropSheet::OnProps()
{
	// TODO: Add your command handler code here

}
