
// FileSerialDoc.cpp : implementation of the CFileSerialDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "FileSerial.h"
#endif

#include "FileSerialDoc.h"
#include "FileSerialView.h"
#include "Graph.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CFileSerialDoc

IMPLEMENT_DYNCREATE(CFileSerialDoc, CDocument)

BEGIN_MESSAGE_MAP(CFileSerialDoc, CDocument)
END_MESSAGE_MAP()


// CFileSerialDoc construction/destruction

CFileSerialDoc::CFileSerialDoc()
{
	// TODO: add one-time construction code here

}

CFileSerialDoc::~CFileSerialDoc()
{
}

BOOL CFileSerialDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	//SetTitle(_T("Ÿo"));

	return TRUE;
}




// CFileSerialDoc serialization

void CFileSerialDoc::Serialize(CArchive& ar)
{
	//POSITION pos = GetFirstViewPosition();
	//CFileSerialView *view = (CFileSerialView*)GetNextView(pos);
	//view->m_objArray.Serialize(ar);

	m_objArray.Serialize(ar);

	if (ar.IsStoring())
	{
		// TODO: add storing code here
		/*int i = 5;
		char ch = 'q';
		float f = 1.2f;
		CString str("wurdddd");
		ar<<i<<ch<<f<<str;*/
		/*int size = view->m_objArray.GetSize();
		ar<<size;
		for(int i=0;i<size;i++){
			ar<<view->m_objArray.GetAt(i);
		}*/


	}
	else
	{
		// TODO: add loading code here
		/*int i;
		char ch;
		float f;
		CString str;
		CString str1;
		ar>>i>>ch>>f>>str;
		str1.Format(_T("%d, %c, %f, %s"), i, ch, f, str);
		AfxMessageBox(str1);*/

		/*int size;
		ar>>size;
		CGraph *graph;
		for(int i=0;i<size;i++){
			ar>>graph;
			view->m_objArray.Add(graph);
		}*/

	}
	
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CFileSerialDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CFileSerialDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CFileSerialDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CFileSerialDoc diagnostics

#ifdef _DEBUG
void CFileSerialDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFileSerialDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CFileSerialDoc commands


void CFileSerialDoc::DeleteContents()
{
	// TODO: Add your specialized code here and/or call the base class

	int count;
	count = m_objArray.GetSize();
	//ÓÐ†–î}
	//for(int i=0;i<count;i++){
	//	delete m_objArray.GetAt(i);
	//	m_objArray.RemoveAt(i);
	//}
	//m_objArray.RemoveAll();

	while(count--){
		delete m_objArray.GetAt(count);
		m_objArray.RemoveAt(count);
	}

	CDocument::DeleteContents();
}
