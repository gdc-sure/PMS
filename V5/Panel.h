#pragma once


// CPanel 对话框

class CPanel : public CDialog
{
	DECLARE_DYNAMIC(CPanel)

public:
	CPanel(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPanel();

// 对话框数据
	enum { IDD = IDD_PANEL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
