// RoomView.cpp : 实现文件
//

#include "stdafx.h"
#include "V5.h"
#include "RoomView.h"


// CRoomView

IMPLEMENT_DYNCREATE(CRoomView, CScrollView)

CRoomView::CRoomView()
{

}

CRoomView::~CRoomView()
{
}


BEGIN_MESSAGE_MAP(CRoomView, CScrollView)
END_MESSAGE_MAP()


// CRoomView 绘图

void CRoomView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 计算此视图的合计大小
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CRoomView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 在此添加绘制代码
}


// CRoomView 诊断

#ifdef _DEBUG
void CRoomView::AssertValid() const
{
	CScrollView::AssertValid();
}

#ifndef _WIN32_WCE
void CRoomView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif
#endif //_DEBUG


// CRoomView 消息处理程序
