
// FileView.cpp : implementation of the CFileView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "File.h"
#endif

#include "FileDoc.h"
#include "FileView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFileView

IMPLEMENT_DYNCREATE(CFileView, CView)

BEGIN_MESSAGE_MAP(CFileView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_WRITE, &CFileView::OnFileWrite)
	ON_COMMAND(ID_FILE_READ, &CFileView::OnFileRead)
	ON_COMMAND(ID_XIEZHUCE, &CFileView::OnXiezhuce)
	ON_COMMAND(ID_DUZHUCE, &CFileView::OnDuzhuce)
END_MESSAGE_MAP()

// CFileView construction/destruction

CFileView::CFileView()
{
	// TODO: add construction code here

}

CFileView::~CFileView()
{
}

BOOL CFileView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CFileView drawing

void CFileView::OnDraw(CDC* /*pDC*/)
{
	CFileDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CFileView printing

BOOL CFileView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFileView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFileView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CFileView diagnostics

#ifdef _DEBUG
void CFileView::AssertValid() const
{
	CView::AssertValid();
}

void CFileView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFileDoc* CFileView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFileDoc)));
	return (CFileDoc*)m_pDocument;
}
#endif //_DEBUG


// CFileView message handlers


void CFileView::OnFileWrite()
{
	// TODO: Add your command handler code here

	//FILE *file = fopen("1.txt", "w+");
	//fwrite("wurd000  00  ", 1, strlen("wurd000  00  "), file);
	///*fseek(file, 0, SEEK_SET);
	//fwrite("111", 1, strlen("111"), file);*/
	//fclose(file);
	////fflush(file);

	////FILE *file = fopen("2.txt", "w");
	////写二进制
	//FILE *file = fopen("2.txt", "wb");
	//char ch[3];
	//ch[0] = 'a';
	//ch[1] = 10;
	//ch[2] = 'b';
	//fwrite(ch, 1, 3, file);
	//fclose(file);

	//FILE *file = fopen("3.txt", "w");
	/*int i = 98341;
	fwrite(&i, 4, 1, file);*/
	/*CString str("98341");
	fwrite(str, 1, 9, file);*/

	//char ch[6];
	///*ch[0] = 9+48;
	//ch[1] = 8+48;
	//ch[2] = 3+48;
	//ch[3] = 4+48;
	//ch[4] = 1+48;*/
	//int i = 98341;
	//_itoa(i, ch, 10);

	//fwrite(ch, 1, 6, file);

	//fclose(file);

	/*ofstream ofs("4.txt");

	ofs.write("wurd stream", strlen("wurd stream"));

	ofs.close();*/

	/*HANDLE hFile;
	hFile = CreateFile(_T("5.txt"), GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, 
		NULL);
	DWORD dwErites;
	WriteFile(hFile, "wurd create file", strlen("wurd create file"), &dwErites, NULL);
	CloseHandle(hFile);*/

	/*CFile file(_T("6.txt"), CFile::modeCreate | CFile::modeWrite);
	file.Write("wurd cfile",strlen("wurd cfile"));
	file.Close();*/

	CFileDialog fileDlg(FALSE);
	fileDlg.m_ofn.lpstrTitle = _T("wurd save");
	fileDlg.m_ofn.lpstrFilter = _T("Text file(*.txt)\0*.txt\0All file(*.*)\0*.*\0\0");
	fileDlg.m_ofn.lpstrDefExt = _T("txt");
	if(IDOK == fileDlg.DoModal()){
		CFile file(fileDlg.GetFileName(), CFile::modeCreate | CFile::modeWrite);
		CString str = _T("file dialog file write");
		file.Write(str.GetBuffer(), str.GetLength()*sizeof(TCHAR));
		file.Close();
	}


}


void CFileView::OnFileRead()
{
	// TODO: Add your command handler code here

	//FILE *file = fopen("1.txt", "r");
	////char ch[100];
	////memset(ch, 0, 100);
	////fread(ch, 1, 100, file);

	////CString str;
	////str.Format(_T("%S"), ch);
	////MessageBox(str);

	//char *buff;
	//fseek(file, 0, SEEK_END);
	//int len = ftell(file);
	//buff = new char[len + 1];
	////fseek(file, 0, SEEK_SET);
	//rewind(file);
	//fread(buff, 1, len, file);
	//buff[len] = 0;
	//CString str;
	//str.Format(_T("%S"), buff);
	//MessageBox(str);
	//fclose(file);

	////FILE *file = fopen("2.txt", "r");
	////读二进制
	//FILE *file = fopen("2.txt", "rb");
	//char ch[100];
	////memset(ch, 0, 100);
	//fread(ch, 1, 3, file);
	//ch[3] = 0;
	//CString str;
	//str.Format(_T("%S"), ch);
	//MessageBox(str);
	//fclose(file);

	/*ifstream ifs("4.txt");
	char ch[100];
	memset(ch, 0, 100);
	ifs.read(ch, 100);
	ifs.close();
	CString str;
	str.Format(_T("%S"), ch);
	MessageBox(str);*/

	/*HANDLE hFile;
	hFile = CreateFile(_T("5.txt"), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 
		NULL);
	char ch[100];
	DWORD dwreads;
	ReadFile(hFile, ch, 100, &dwreads, NULL);
	ch[dwreads] = 0;
	CloseHandle(hFile);
	CString str;
	str.Format(_T("%S"), ch);
	MessageBox(str);*/


	/*CFile file(_T("6.txt"), CFile::modeRead);
	char *buff;
	DWORD fileLen;
	fileLen = file.GetLength();
	buff = new char[fileLen+1];
	buff[fileLen] = 0;
	file.Read(buff, fileLen);
	file.Close();
	CString str;
	str.Format(_T("%S"), buff);
	MessageBox(str);*/


	CFileDialog fileDlg(TRUE);
	fileDlg.m_ofn.lpstrTitle = _T("wurd open");
	fileDlg.m_ofn.lpstrFilter = _T("Text file(*.txt)\0*.txt\0All file(*.*)\0*.*\0\0");
	fileDlg.m_ofn.lpstrDefExt = _T("txt");
	if(IDOK == fileDlg.DoModal()){
		CFile file(fileDlg.GetFileName(), CFile::modeRead);
		DWORD fileLen;
		char *buff;
		fileLen = file.GetLength()*sizeof(TCHAR);
		buff = new char[fileLen+1];
		buff[fileLen] = 0;
		file.Read(buff, fileLen);
		file.Close();
		CString str;
		str.Format(_T("%S"), buff);
		MessageBox(str);
	}

}


void CFileView::OnXiezhuce()
{
	// TODO: Add your command handler code here

	HKEY hkey;
	HKEY hkey1;

	DWORD age = 22;

	RegCreateKeyA(HKEY_LOCAL_MACHINE, "Software\\wurd\\admin", &hkey);
	RegSetValueA(hkey, NULL, REG_SZ, "wurd", strlen("wurd"));
	RegCreateKeyA(HKEY_LOCAL_MACHINE, "Software\\wurd\\admin", &hkey1);
	RegSetValueExA(hkey1, "age", 0, REG_DWORD, (CONST BYTE*)&age, 4);
	RegCloseKey(hkey);
}


void CFileView::OnDuzhuce()
{
	// TODO: Add your command handler code here

	LONG value;
	RegQueryValueA(HKEY_LOCAL_MACHINE, "Software\\wurd\\admin", NULL, &value);
	char *buff = new char[value];
	RegQueryValueA(HKEY_LOCAL_MACHINE, "Software\\wurd\\admin", buff, &value);
	CString str;
	str.Format(_T("%S"), buff);
	MessageBox(str);

	HKEY key;
	DWORD age;
	DWORD type;
	DWORD value1;
	RegOpenKeyA(HKEY_LOCAL_MACHINE, "Software\\wurd\\admin", &key);
	RegQueryValueExA(key, "age", 0, &type, (LPBYTE)&age, &value1);
	CString str1;
	str1.Format(_T("age=%d"), age);
	MessageBox(str1);


}
