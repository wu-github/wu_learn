// WurdButton.cpp : implementation file
//

#include "stdafx.h"
#include "WithDialog.h"
#include "WurdButton.h"


// CWurdButton

IMPLEMENT_DYNAMIC(CWurdButton, CButton)

CWurdButton::CWurdButton()
: m_wurdBtn(NULL)
{

}

CWurdButton::~CWurdButton()
{
}


BEGIN_MESSAGE_MAP(CWurdButton, CButton)
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// CWurdButton message handlers




void CWurdButton::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	ShowWindow(SW_HIDE);
	m_wurdBtn->ShowWindow(SW_SHOW);

	CButton::OnMouseMove(nFlags, point);
}
