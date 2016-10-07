#include "StdAfx.h"
#include "LoginDlg.h"
#include "V5Dlg.h"
// V5Dlg.cpp : ʵ���ļ�
#include "V5.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CV5Dlg �Ի���




CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &CLoginDlg::OnBnClickedButtonLogin)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &CLoginDlg::OnBnClickedButtonClose)
END_MESSAGE_MAP()


// CV5Dlg ��Ϣ�������

BOOL CLoginDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CLoginDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CLoginDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CLoginDlg::OnBnClickedButtonLogin()
{
	/*
	   if(theApp.InitDB()==FALSE)
               MessageBox(_T("�������ݿ�ʧ��!"),_T("ϵͳ��ʾ"),MB_OK);
	   else
		   CDialog::OnOK();
		   */
		
	
  
	
	EndDialog(IDOK);
	
     
}

void CLoginDlg::OnBnClickedButtonClose()
{
	//CDialog::OnOK();
	//this->CloseWindow();
	//CV5Dlg  dlg;
	//dlg.ShowWindow(SW_SHOWMAXIMIZED);
	//dlg.DoModal();
	CDialog::OnCancel();

	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
