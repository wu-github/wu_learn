// SettingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Graphic.h"
#include "SettingDlg.h"
#include "afxdialogex.h"


// CSettingDlg dialog

IMPLEMENT_DYNAMIC(CSettingDlg, CDialogEx)

CSettingDlg::CSettingDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSettingDlg::IDD, pParent)
	, m_xiankuan(0)
	, m_xianxing(0)
{
	m_color = RGB(0, 0, 0);
	m_brush.CreateSolidBrush(RGB(111, 111, 111));
}

CSettingDlg::~CSettingDlg()
{
}

void CSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_XIANKUAN, m_xiankuan);
	DDX_Radio(pDX, IDC_RADIO1, m_xianxing);
}


BEGIN_MESSAGE_MAP(CSettingDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_XIANKUAN, &CSettingDlg::OnEnChangeEditXiankuan)
	ON_BN_CLICKED(IDC_RADIO1, &CSettingDlg::OnClickedRadio1)
	ON_WM_PAINT()
	ON_COMMAND(IDC_RADIO2, &CSettingDlg::OnRadio2)
	ON_COMMAND(IDC_RADIO3, &CSettingDlg::OnRadio3)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CSettingDlg message handlers


void CSettingDlg::OnEnChangeEditXiankuan()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	Invalidate();

}


void CSettingDlg::OnClickedRadio1()
{
	// TODO: Add your control notification handler code here

	Invalidate();
}

void CSettingDlg::OnRadio2()
{
	// TODO: Add your command handler code here
	Invalidate();
}


void CSettingDlg::OnRadio3()
{
	// TODO: Add your command handler code here
	Invalidate();
}


void CSettingDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialogEx::OnPaint() for painting messages

	UpdateData();
	CPen pen(m_xianxing, m_xiankuan, m_color);
	dc.SelectObject(&pen);

	CRect rect;
	GetDlgItem(IDC_SAMPLE)->GetWindowRect(&rect);
	ScreenToClient(rect);

	dc.MoveTo(rect.left + 20, rect.top + rect.Height()/2);
	dc.LineTo(rect.right - 20, rect.top + rect.Height()/2);


}




HBRUSH CSettingDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here

	// TODO:  Return a different brush if the default is not desired

	//return hbr;

	if(pWnd->GetDlgCtrlID() == IDC_XIANXING){
		pDC->SetTextColor(RGB(255, 255, 0));
		pDC->SetBkMode(TRANSPARENT);
		return m_brush;
	}

	return hbr;
}
