#include "StdAfx.h"
#include "Graph.h"


IMPLEMENT_SERIAL(CGraph, CObject, 1)

CGraph::CGraph(void)
	: m_type(0)
{
}

CGraph::CGraph(UINT type, CPoint m_point, CPoint m_endPoint)
{
	this->m_type = type;
	this->m_point = m_point;
	this->m_endPoint = m_endPoint;
}


CGraph::~CGraph(void)
{
}

void CGraph::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		
		ar<<m_type<<m_point<<m_endPoint;
	}
	else
	{
		// TODO: add loading code here
		
		ar>>m_type>>m_point>>m_endPoint;
		//AfxMessageBox(_T(""));
	}
}


void CGraph::Draw(CDC *pDC)
{
	CBrush *brush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	CBrush *oldBrush = pDC->SelectObject(brush);
	switch(m_type){
		case 1:
			pDC->SetPixel(m_endPoint, RGB(0, 0, 0));
			break;
		case 2:
			pDC->MoveTo(m_point);
			pDC->LineTo(m_endPoint);
			break;
		case 3:
			pDC->Rectangle(CRect(m_point, m_endPoint));
			break;
		case 4:
			pDC->Ellipse(CRect(m_point, m_endPoint));
			break;
	}
	pDC->SelectObject(oldBrush);
}
