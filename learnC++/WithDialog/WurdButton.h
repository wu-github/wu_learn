#pragma once


// CWurdButton

class CWurdButton : public CButton
{
	DECLARE_DYNAMIC(CWurdButton)

public:
	CWurdButton();
	virtual ~CWurdButton();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CWurdButton* m_wurdBtn;
};


