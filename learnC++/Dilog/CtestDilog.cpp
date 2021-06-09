// CtestDilog.cpp : implementation file
//

#include "stdafx.h"
#include "Dilog.h"
#include "CtestDilog.h"
#include "afxdialogex.h"


// CtestDilog dialog

IMPLEMENT_DYNAMIC(CtestDilog, CDialogEx)

CtestDilog::CtestDilog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CtestDilog::IDD, pParent)
	, m_created(false)
{

	m_edit1 = 0;
	m_edit2 = 0;
	m_edit3 = 0;
}

CtestDilog::~CtestDilog()
{
}

void CtestDilog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_EDIT1, m_edit1);
	//  DDX_Control(pDX, IDC_EDIT2, m_edit2);
	//  DDX_Control(pDX, IDC_EDIT3, m_edit3);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDX_Text(pDX, IDC_EDIT3, m_edit3);
	DDX_Control(pDX, IDC_EDIT1, m_edit1_C);
	DDX_Control(pDX, IDC_EDIT2, m_edit2_C);
	DDX_Control(pDX, IDC_EDIT3, m_edit3_C);
}


BEGIN_MESSAGE_MAP(CtestDilog, CDialogEx)
	//ON_COMMAND(ID_TESTDILOG, &CtestDilog::OnTestdilog)
	ON_BN_CLICKED(IDC_BUTTON1, &CtestDilog::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CtestDilog::OnEnChangeEdit1)
	ON_STN_CLICKED(IDC_STATIC1, &CtestDilog::OnClickedStatic1)
	ON_BN_CLICKED(IDC_BUTTON2, &CtestDilog::OnBnClickedButton2)
	ON_BN_CLICKED(IDOK, &CtestDilog::OnBnClickedOk)
END_MESSAGE_MAP()


// CtestDilog message handlers


//void CtestDilog::OnTestdilog()
//{
//	// TODO: Add your command handler code here
//
//
//
//}


void CtestDilog::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	//MessageBox(_T("1"));

	////局部静态
	//static bool created = false;

	////全局
	////if(m_created == false){
	//if(created == false){
	//	m_btn.Create(_T("wurd"), BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD, CRect(0, 0, 100, 100), this, 123);
	//	created = true;
	//}else{
	//	m_btn.DestroyWindow();
	//	created = false;
	//}

	if(!m_btn.m_hWnd){
		m_btn.Create(_T("wurd"), BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD, CRect(0, 0, 100, 100), this, 123);
	}else{
		m_btn.DestroyWindow();
	}

	/*int no1, no2, no3;
	wchar_t ch1[10], ch2[10], ch3[10];
	CString str1, str2, str3;
	GetDlgItem(IDC_EDIT1)->GetWindowText(ch1,10);
	GetDlgItem(IDC_EDIT2)->GetWindowText(str2);
	no1 = _wtoi(ch1);
	no2 = _ttoi(str2);
	no3 = no1 + no2;
	str3.Format(_T("%d"), no3);
	GetDlgItem(IDC_EDIT3)->SetWindowText(str3);*/

	//int no1, no2, no3;
	//wchar_t ch1[10], ch2[10], ch3[10];
	//CString str1, str2, str3;

	//GetDlgItemText(IDC_EDIT1, ch1, 10);
	//GetDlgItemText(IDC_EDIT2, str2);
	//no1 = _wtoi(ch1);
	//no2 = _ttoi(str2);
	//no3 = no1 + no2;
	////str3.Format(_T("%d"), no3);
	//_itow(no3, ch3, 10);
	//SetDlgItemText(IDC_EDIT3, ch3);

	/*int no1, no2, no3;
	no1 = GetDlgItemInt(IDC_EDIT1);
	no2 = GetDlgItemInt(IDC_EDIT2);
	no3 = no1 + no2;
	SetDlgItemInt(IDC_EDIT3, no3);*/

	/*UpdateData();
	m_edit3 = m_edit1 + m_edit2;
	UpdateData(false);*/

	/*int no1, no2, no3;
	wchar_t ch1[10], ch2[10], ch3[10];
	m_edit1_C.GetWindowTextW(ch1, 10);
	m_edit2_C.GetWindowTextW(ch2, 10);
	no1 = _wtoi(ch1);
	no2 = _wtoi(ch2);
	no3 = no1 + no2;
	_itow(no3, ch3, 10);
	m_edit3_C.SetWindowText(ch3);*/

	//int no1, no2, no3;
	//wchar_t ch1[10], ch2[10], ch3[10];

	////::SendMessageA(GetDlgItem(IDC_EDIT1)->m_hWnd, WM_GETTEXT, 10, (LPARAM)ch1);
	////::SendMessageA(m_edit1_C.m_hWnd, WM_GETTEXT, 10, (LPARAM)ch1);
	////GetDlgItem(IDC_EDIT1)->SendMessage(WM_GETTEXT, 10, (LPARAM)ch1);
	//m_edit1_C.SendMessage(WM_GETTEXT, 10, (LPARAM)ch1);
	//m_edit2_C.SendMessage(WM_GETTEXT, 10, (LPARAM)ch2);
	//no1 = _wtoi(ch1);
	//no2 = _wtoi(ch2);
	//no3 = no1 + no2;
	//_itow(no3, ch3, 10);
	//m_edit3_C.SendMessage(WM_SETTEXT, 0, (LPARAM)ch3);

	int no1, no2, no3;
	wchar_t ch1[10], ch2[10], ch3[10];
	SendDlgItemMessage(IDC_EDIT1, WM_GETTEXT, 10, (LPARAM)ch1);
	SendDlgItemMessage(IDC_EDIT2, WM_GETTEXT, 10, (LPARAM)ch2);
	no1 = _wtoi(ch1);
	no2 = _wtoi(ch2);
	no3 = no1 + no2;
	_itow(no3, ch3, 10);
	SendDlgItemMessage(IDC_EDIT3, WM_SETTEXT, 10, (LPARAM)ch3);

	SendDlgItemMessage(IDC_EDIT3, EM_SETSEL, 1, -1);

	m_edit3_C.SetFocus();

}


void CtestDilog::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CtestDilog::OnClickedStatic1()
{
	// TODO: Add your control notification handler code here

	CString str;
	GetDlgItem(IDC_STATIC1)->GetWindowText(str);

	if(str == _T("no1")){
		GetDlgItem(IDC_STATIC1)->SetWindowText(_T("数值"));
	}else{
		GetDlgItem(IDC_STATIC1)->SetWindowText(_T("no1"));
	}

}


void CtestDilog::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_BUTTON2, str);
	if(str == _T("收缩")){
		SetDlgItemText(IDC_BUTTON2, _T("扩展"));
	}else{
		SetDlgItemText(IDC_BUTTON2, _T("收缩"));
	}

	static CRect rectB;
	static CRect rectS;

	if(rectB.IsRectNull()){
		CRect rectSep;
		GetWindowRect(&rectB);
		GetDlgItem(IDC_SEPARATE)->GetWindowRect(&rectSep);

		rectS.left = rectB.left;
		rectS.top = rectB.top;
		rectS.right = rectB.right;
		rectS.bottom = rectSep.bottom;


	}
	if(str == _T("收缩")){
		SetWindowPos(NULL, 0, 0, rectS.Width(), rectS.Height(), SWP_NOMOVE | SWP_NOZORDER);
	}else {
		SetWindowPos(NULL, 0, 0, rectB.Width(), rectB.Height(), SWP_NOMOVE | SWP_NOZORDER);
	}

}


void CtestDilog::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//GetDlgItem(IDC_EDIT1)->GetNextWindow()->SetFocus();
	//GetFocus()->GetNextWindow()->SetFocus();

	GetNextDlgTabItem(GetFocus())->SetFocus();

	//CDialogEx::OnOK();
}

WNDPROC preProc;
LRESULT CALLBACK WinSunProc(
	HWND hwnd,
	UINT msg,
	WPARAM wParam,
	LPARAM lParam
	){
		if(msg == WM_CHAR && wParam == 0x0d){
			//set multiline=true
			//SetFocus(GetNextWindow(hwnd, GW_HWNDNEXT));
			//SetFocus(GetWindow(hwnd, GW_HWNDNEXT));
			SetFocus(GetNextDlgTabItem(GetParent(hwnd), hwnd, false));



			return 1;
		}else{
			return preProc(hwnd, msg, wParam, lParam);
		}
}

BOOL CtestDilog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	preProc = (WNDPROC)SetWindowLong(GetDlgItem(IDC_EDIT1)->m_hWnd, GWL_WNDPROC, (long)WinSunProc);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
