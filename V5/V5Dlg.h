// V5Dlg.h : ͷ�ļ�
//
#include "RoomView.h"
#pragma once


// CV5Dlg �Ի���
class CV5Dlg : public CDialog
{
// ����
public:
	CV5Dlg(CWnd* pParent = NULL);	// ��׼���캯��
    CRoomView   *m_pRoomView;
// �Ի�������
	enum { IDD = IDD_V5_DIALOG };
    CToolBar   m_wndToolBar;
	CMenu      m_MainMenu;
	CImageList   m_imgList;

   
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
