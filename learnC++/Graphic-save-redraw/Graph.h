#pragma once
#include "afxcoll.h"
class CGraph
{
public:
	CGraph(void);
	~CGraph(void);
	UINT m_type;
	CPoint m_point;
	CPoint m_endPoint;
	CGraph(UINT type, CPoint m_point, CPoint m_endPoint);
};

