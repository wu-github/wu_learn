#include "StdAfx.h"
#include "Graph.h"


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
