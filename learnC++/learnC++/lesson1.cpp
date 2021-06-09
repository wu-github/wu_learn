#include "lesson1.h"
#include <windows.h>
#include <stdio.h>
//#include <tchar.h>

lesson1::lesson1(void)
{
}


lesson1::~lesson1(void)
{
}

LRESULT CALLBACK WinSunProc(
	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam);

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
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
		wndcls.lpszClassName = "wurd";
		wndcls.style = CS_HREDRAW | CS_VREDRAW;

		RegisterClass(&wndcls);

		HWND hwnd;
		hwnd = CreateWindow("wurd","wurd_title",WS_OVERLAPPEDWINDOW,0,0,600,400,NULL,NULL,hInstance,NULL);
		ShowWindow(hwnd,SW_SHOWNORMAL);
		UpdateWindow(hwnd);

		MSG msg;
		while(GetMessage(&msg,NULL,0,0)){
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return 0;

}

LRESULT CALLBACK WinSunProc(
	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam){
		switch(uMsg){
		case WM_CHAR:
			char szChar[20];
			sprintf(szChar, "char is %d", wParam);
			MessageBox(hwnd,szChar, "wurd_box1", 0);
			break;
		case WM_LBUTTONDOWN:
			MessageBox(hwnd,"left mouse", "wurd_box2", 0);
			HDC hdc;
			hdc = GetDC(hwnd);
			TextOut(hdc,0,50,"left mouse",strlen("button_down"));
			ReleaseDC(hwnd,hdc);
			break;
		case WM_PAINT:
			HDC hDC;
			PAINTSTRUCT ps;
			hDC = BeginPaint(hwnd, &ps);
			TextOut(hDC,0,0,"wurd_content",strlen("wurd_content"));
			EndPaint(hwnd, &ps);
			break;
		case WM_CLOSE:
			if(IDYES == MessageBox(hwnd, "close?","close_title", MB_YESNO)){
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
