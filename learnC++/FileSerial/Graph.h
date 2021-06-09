#pragma once
#include "afxcoll.h"
class CGraph:public CObject
{
	DECLARE_SERIAL(CGraph)
public:
	CGraph(void);
	~CGraph(void);
	UINT m_type;
	CPoint m_point;
	CPoint m_endPoint;
	CGraph(UINT type, CPoint m_point, CPoint m_endPoint);
	void Draw(CDC *pDC);
	void Serialize(CArchive& ar);
};

