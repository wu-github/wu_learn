#include "StdAfx.h"
#include "WinMain1.h"
#include <stdio.h>
//#include <afx.h>


WinMain1::WinMain1(void)
{
}


WinMain1::~WinMain1(void)
{
}

class CWnd{
public:
	BOOL CreateEx(
		//DWORD     dwExStyle,
		LPCWSTR   lpClassName,
		LPCWSTR   lpWindowName,
		DWORD     dwStyle,
		int       X,
		int       Y,
		int       nWidth,
		int       nHeight,
		HWND      hWndParent,
		HMENU     hMenu,
		HINSTANCE hInstance,
		LPVOID    lpParam);
	BOOL ShowWindow(int  nCmdShow);
	BOOL UpdateWindow();
public:
	HWND m_hwnd;
};

BOOL CWnd::CreateEx(
		//DWORD     dwExStyle,
		LPCWSTR   lpClassName,
		LPCWSTR   lpWindowName,
		DWORD     dwStyle,
		int       X,
		int       Y,
		int       nWidth,
		int       nHeight,
		HWND      hWndParent,
		HMENU     hMenu,
		HINSTANCE hInstance,
		LPVOID    lpParam){
			m_hwnd = CreateWindow(/*dwExStyle, */lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
			if(m_hwnd != NULL){
				return TRUE;
			}else{
				return FALSE;
			}

}
BOOL CWnd::ShowWindow(int  nCmdShow){
	return ::ShowWindow(m_hwnd, nCmdShow);
}

BOOL CWnd::UpdateWindow(){
	return ::UpdateWindow(m_hwnd);
}

LRESULT CALLBACK WinSunProc(
	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam){
		switch(uMsg){
		case WM_CHAR:
			char sChar[20];
			sprintf(sChar, "char is %d", wParam);
			MessageBoxA(hwnd, sChar, "wurd_box1", 0);
			break;
		case WM_LBUTTONDOWN:
			MessageBox(hwnd,_T("left mouse"), _T("wurd_box2"), 0);
			HDC hdc;
			hdc = GetDC(hwnd);
			TextOut(hdc,0,50,_T("left mouse"),strlen("button_down"));
			ReleaseDC(hwnd,hdc);
			break;
		case WM_PAINT:
			HDC hDC;
			PAINTSTRUCT ps;
			hDC = BeginPaint(hwnd, &ps);
			TextOut(hDC,0,0,_T("wurd_content"),strlen("wurd_content"));
			EndPaint(hwnd, &ps);
			break;
		case WM_CLOSE:
			if(IDYES == MessageBox(hwnd, _T("close?"),_T("close_title"), MB_YESNO)){
				DestroyWindow(hwnd);
			}
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
		}
		return 0;
};

int WINAPI WinMain(
  HINSTANCE hInstance,
  HINSTANCE hPrevInstance,
  LPSTR     lpCmdLine,
  int       nShowCmd
  ){
	  WNDCLASS wndcls;
		wndcls.cbClsExtra = 0;
		wndcls.cbWndExtra = 0;
		wndcls.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		wndcls.hIcon = LoadIcon(NULL, IDI_ERROR);
		wndcls.hCursor = LoadCursor(NULL, IDC_CROSS);
		wndcls.hInstance = hInstance;
		wndcls.lpszMenuName = NULL;
		wndcls.lpfnWndProc = WinSunProc;
		wndcls.lpszClassName = _T("wurd");
		wndcls.style = CS_HREDRAW | CS_VREDRAW;

	  RegisterClass(&wndcls);

	  CWnd wnd;
	  wnd.CreateEx(_T("wurd"),_T("wurd_title"),WS_OVERLAPPEDWINDOW,0,0,600,400,NULL,NULL,hInstance,NULL);
	  wnd.ShowWindow(SW_SHOWNORMAL);
	  wnd.UpdateWindow();

	  //loop message
	  MSG msg;
		while(GetMessage(&msg,NULL,0,0)){
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return 0;
}
