// Panel.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "V5.h"
#include "Panel.h"


// CPanel �Ի���

IMPLEMENT_DYNAMIC(CPanel, CDialog)

CPanel::CPanel(CWnd* pParent /*=NULL*/)
	: CDialog(CPanel::IDD, pParent)
{

}

CPanel::~CPanel()
{
}

void CPanel::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPanel, CDialog)
END_MESSAGE_MAP()


// CPanel ��Ϣ�������
