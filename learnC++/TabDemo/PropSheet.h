#pragma once
#include "prop1.h"
#include "prop2.h"
#include "prop3.h"



// CPropSheet

class CPropSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CPropSheet)

public:
	CPropSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CPropSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CPropSheet();

protected:
	DECLARE_MESSAGE_MAP()
public:
	CProp1 m_prop1;
	CProp2 m_prop2;
	CProp3 m_prop3;
	afx_msg void OnProps();
};


