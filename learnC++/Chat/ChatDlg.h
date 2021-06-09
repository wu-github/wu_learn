
// ChatDlg.h : header file
//

#pragma once


// CChatDlg dialog
class CChatDlg : public CDialogEx
{
// Construction
public:
	CChatDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_CHAT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	afx_msg LRESULT onRecvData(WPARAM wparam, LPARAM lparam);
public:
	BOOL InitSocket(void);
private:
	SOCKET m_socket;
public:
	static DWORD WINAPI recvProc(LPVOID param);
	afx_msg void OnBnClickedButtonSend();
};
