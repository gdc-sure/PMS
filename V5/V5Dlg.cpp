
#include "stdafx.h"
#include "V5.h"
#include "V5Dlg.h"
#include "RoomView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CV5Dlg::CV5Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CV5Dlg::IDD, pParent)
{
	 
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CV5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CV5Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
//	ON_WM_CREATE()
ON_WM_CREATE()
//ON_WM_NCLBUTTONDOWN()
//ON_WM_NCLBUTTONDBLCLK()
//ON_WM_NCXBUTTONDBLCLK()
ON_WM_GETMINMAXINFO()
ON_WM_NCLBUTTONDBLCLK()
ON_WM_NCLBUTTONDOWN()
END_MESSAGE_MAP()



BOOL CV5Dlg::OnInitDialog()
{
	 CDialog::OnInitDialog();
	 ShowWindow(SW_SHOWMAXIMIZED);
	 //::SetWindowPos(this->m_hWnd,HWND_BOTTOM,0,0,1360,768,SWP_SHOWWINDOW);
	 
	 m_MainMenu.LoadMenu(IDR_MENU1);
	 this->SetMenu(&m_MainMenu);
    //m_wndToolBar.Create
	m_imgList.Create(32,32,ILC_COLOR32|ILC_MASK,0,0);
	m_imgList.Add(::AfxGetApp()->LoadIcon(IDI_FIT_CHECKIN));
	m_imgList.Add(::AfxGetApp()->LoadIconW(IDI_QUERY));
	m_imgList.Add(::AfxGetApp()->LoadIconW(IDI_RESERVE));
	m_imgList.Add(::AfxGetApp()->LoadIcon(IDI_RESERVE));
    m_imgList.Add(::AfxGetApp()->LoadIcon(IDI_RESERVE_TO_CHECKIN));
	m_imgList.Add(::AfxGetApp()->LoadIcon(IDI_MEMBER));
	m_imgList.Add(::AfxGetApp()->LoadIcon(IDI_CLEAN));
	m_imgList.Add(::AfxGetApp()->LoadIcon(IDI_SETTLE));
	m_imgList.Add(::AfxGetApp()->LoadIcon(IDI_REPORT));
	m_imgList.Add(::AfxGetApp()->LoadIcon(IDI_AUDIT));
	m_imgList.Add(::AfxGetApp()->LoadIcon(IDI_CLOSE_SHIFT));
	m_imgList.Add(::AfxGetApp()->LoadIcon(IDI_SETTING));
	m_imgList.Add(::AfxGetApp()->LoadIcon(IDI_REFRESH));

    m_wndToolBar.Create(this,WS_CHILD| WS_CHILD | WS_VISIBLE |CBRS_ALIGN_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS|TBSTYLE_FLAT/*|CBRS_BORDER_TOP|*/ );
    RECT   trc;
  
	
	//m_wndToolBar.CalcWindowRect(&trc);
//m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle()|CCS_TOP );
    
	UINT arr[14];
	for (int i=0;i<14;i++)
	{
		   if(i==3|| i==5)
                     arr[i]= ID_SEPARATOR; //第3、6个按钮为分隔条
              else
                     arr[i]= i+1001;
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作

	m_wndToolBar.SetButtons(arr,14);
	m_wndToolBar.GetToolBarCtrl().SetImageList(&m_imgList);
	m_wndToolBar.SetSizes(CSize(32,32),CSize(32,32));//设置按钮和图标的大小
	//m_wndToolBar.S
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);
	m_wndToolBar.SetButtonStyle(7,m_wndToolBar.GetButtonStyle(7) | BS_FLAT);
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	// TODO: 在此添加额外的初始化代码

	//CWnd *pWnd= m_wndToolBar.GetCo
     m_wndToolBar.GetWindowRect(&trc);
	 this->ScreenToClient(&trc);

    CWnd  *viewWnd=this->GetDlgItem(IDC_STATIC_VIEW);
	CRect  rc;
	RECT MainWindowRect;
	::GetClientRect(m_hWnd,&MainWindowRect);
	//this->GetWindRect(&MainWindowRect);
	//this->GetWindRect(&MainWindowRect);
   this->ScreenToClient(&MainWindowRect);
	viewWnd->MoveWindow(0,trc.bottom -trc.top ,MainWindowRect.right -MainWindowRect.left ,MainWindowRect.bottom-MainWindowRect.top-(trc.bottom -trc.top) );
	viewWnd->GetWindowRect(rc);
	this->ScreenToClient(rc);
	 m_pRoomView = (CRoomView*)RUNTIME_CLASS(CRoomView)->CreateObject();  
    //在目标位置动态创建视图  
    if (NULL==m_pRoomView)    
    {    
        return FALSE;    
     }    
     m_pRoomView->Create(NULL, NULL, AFX_WS_DEFAULT_VIEW, rc, this, IDC_STATIC_VIEW);    


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。
void CV5Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CV5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




int CV5Dlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	   ModifyStyle(0,WS_MAXIMIZE);
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码

	return 0;
}

//void CV5Dlg::OnNcLButtonDown(UINT nHitTest, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//    if (IsZoomed()) return;
//	CDialog::OnNcLButtonDown(nHitTest, point);
//}

//void CV5Dlg::OnNcLButtonDblClk(UINT nHitTest, CPoint point)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//    if (IsZoomed()) return;
//	CDialog::OnNcLButtonDblClk(nHitTest, point);
//}

//void CV5Dlg::OnNcXButtonDblClk(UINT nFlags, UINT nButton, CPoint point)
//{
//	// 该功能要求使用 Windows 2000 或更高版本。
//	// 符号 _WIN32_WINNT 和 WINVER 必须 >= 0x0500。
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
// if (IsZoomed()) return;
//	CDialog::OnNcXButtonDblClk(nFlags, nButton, point);
//}

void CV5Dlg::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
lpMMI-> ptMaxSize.y   =   GetSystemMetrics(SM_CYFULLSCREEN)+GetSystemMetrics(SM_CYCAPTION)-GetSystemMetrics(SM_CYDLGFRAME-50);
	CDialog::OnGetMinMaxInfo(lpMMI);
}

void CV5Dlg::OnNcLButtonDblClk(UINT nHitTest, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
 if(nHitTest==HTCAPTION )    
        return;    
	CDialog::OnNcLButtonDblClk(nHitTest, point);
}

void CV5Dlg::OnNcLButtonDown(UINT nHitTest, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
if(nHitTest==HTCAPTION )    
        return;
	CDialog::OnNcLButtonDown(nHitTest, point);
}
