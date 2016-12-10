#pragma once


// CRMButton

class CRMButton : public CBitmapButton
{
	DECLARE_DYNAMIC(CRMButton)

public:
	CString                    m_sRoomType;
	CString                    m_sRoomNo;
	CRMButton();
	virtual ~CRMButton();

protected:
	DECLARE_MESSAGE_MAP()
	virtual void PreSubclassWindow();
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
};


