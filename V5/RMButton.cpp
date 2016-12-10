// RMButton.cpp : 实现文件
//

#include "stdafx.h"
#include "RMButton.h"


// CRMButton

IMPLEMENT_DYNAMIC(CRMButton, CBitmapButton)

CRMButton::CRMButton()
{

}

CRMButton::~CRMButton()
{
}


BEGIN_MESSAGE_MAP(CRMButton, CBitmapButton)
END_MESSAGE_MAP()



// CRMButton 消息处理程序



void CRMButton::PreSubclassWindow()
{
	// TODO: 在此添加专用代码和/或调用基类
    ModifyStyle(0,BS_OWNERDRAW);
	CBitmapButton::PreSubclassWindow();
}

void CRMButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CDC  *dc=CDC::FromHandle(lpDrawItemStruct->hDC);
	CBrush  br;
	br.CreateSolidBrush((COLORREF)16777215);
	dc->SelectObject(&br);
	CPen  pen;
	pen.CreatePen(PS_SOLID,2,(COLORREF)RGB(128,128,128));
    dc->SelectObject(&pen);
	dc->SetBkMode(TRANSPARENT);
   // lpDrawItemStruct->rcItem.left = lpDrawItemStruct->rcItem.left+30;

	dc->Rectangle(&lpDrawItemStruct->rcItem);
	dc->TextOutW(5,5,TEXT("8620"),::lstrlen(TEXT("8620")));
	//dc->DrawEdge(&lpDrawItemStruct->rcItem,EDGE_RAISED,BF_RECT);
	// TODO:  添加您的代码以绘制指定项
}
