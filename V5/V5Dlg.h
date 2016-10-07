// V5Dlg.h : 头文件
//
#include "RoomView.h"
#pragma once


// CV5Dlg 对话框
class CV5Dlg : public CDialog
{
// 构造
public:
	CV5Dlg(CWnd* pParent = NULL);	// 标准构造函数
    CRoomView   *m_pRoomView;
// 对话框数据
	enum { IDD = IDD_V5_DIALOG };
    CToolBar   m_wndToolBar;
	CMenu      m_MainMenu;
	CImageList   m_imgList;

   
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
//	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
//	afx_msg void OnNcLButtonDblClk(UINT nHitTest, CPoint point);
//	afx_msg void OnNcXButtonDblClk(UINT nFlags, UINT nButton, CPoint point);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg void OnNcLButtonDblClk(UINT nHitTest, CPoint point);
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);
};
