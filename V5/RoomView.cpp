// RoomView.cpp : ʵ���ļ�
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


// CRoomView ��ͼ

void CRoomView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �������ͼ�ĺϼƴ�С
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CRoomView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: �ڴ���ӻ��ƴ���
}


// CRoomView ���

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


// CRoomView ��Ϣ�������
