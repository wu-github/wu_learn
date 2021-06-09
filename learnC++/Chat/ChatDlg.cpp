
// ChatDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Chat.h"
#include "ChatDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define WM_RECVDATA WM_USER+1

// CAboutDlg dialog used for App About


struct RECVPARAM{
	SOCKET sock;
	HWND hwnd;
};

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CChatDlg dialog




CChatDlg::CChatDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChatDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CChatDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(WM_RECVDATA, onRecvData)
	ON_BN_CLICKED(IDC_BUTTON_SEND, &CChatDlg::OnBnClickedButtonSend)
END_MESSAGE_MAP()


// CChatDlg message handlers



BOOL CChatDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	InitSocket();
	RECVPARAM *param = new RECVPARAM;
	param->sock = m_socket;
	param->hwnd = m_hWnd;

	HANDLE t1 = CreateThread(NULL, 0, recvProc, (LPVOID)param, 0, NULL);
	CloseHandle(t1);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CChatDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CChatDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CChatDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL CChatDlg::InitSocket(void)
{
	m_socket = socket(AF_INET, SOCK_DGRAM, 0);
	if(INVALID_SOCKET == m_socket){
		MessageBox(_T("create socket failed"));
		return 0;
	}
	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(6000);
	addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

	int resVal;
	resVal = bind(m_socket, (SOCKADDR*)&addr,sizeof(SOCKADDR));

	if(SOCKET_ERROR == resVal){
		MessageBox(_T("bind socket failed"));
		return 0;
	}
	return 1;
}


DWORD WINAPI CChatDlg::recvProc(LPVOID param)
{
	SOCKET sock = ((RECVPARAM*)param)->sock;
	HWND hwnd = ((RECVPARAM*)param)->hwnd;

	SOCKADDR_IN addr;
	int len = sizeof(SOCKADDR);

	char recvBuf[222];
	char tempBuf[333];

	int resVal;
	while(TRUE){
		resVal = recvfrom(sock, recvBuf, 222, 0, (SOCKADDR*)&addr, &len);
		if(SOCKET_ERROR == resVal){
			break;
		}
		sprintf_s(tempBuf, "%s ˵: %s" , inet_ntoa(addr.sin_addr), recvBuf);
		::PostMessageA(hwnd, WM_RECVDATA, 0, (LPARAM)tempBuf);

	}

	return 0;
}

LRESULT CChatDlg::onRecvData(WPARAM wparam, LPARAM lparam){
	CString str = (wchar_t*)lparam;

	CString strTemp;
	GetDlgItemText(IDC_EDIT_RECEIVE, strTemp);
	str+="\r\n";
	str+=strTemp;
	SetDlgItemText(IDC_EDIT_RECEIVE, str);
	return 1;
}


void CChatDlg::OnBnClickedButtonSend()
{
	// TODO: Add your control notification handler code here
	DWORD ip;
	((CIPAddressCtrl*)GetDlgItem(IDC_IPADDRESS1))->GetAddress(ip);
	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(6000);
	addr.sin_addr.S_un.S_addr = htonl(ip);

	CString str;
	GetDlgItemText(IDC_EDIT_SEND, str);
	char* ch=(char*)str.LockBuffer();
	//str.Format(_T("%s"), ch);
	sendto(m_socket, ch, strlen(ch), 0, (SOCKADDR*)&addr, sizeof(SOCKADDR));

	SetDlgItemText(IDC_EDIT_SEND, _T(""));

}
