// V5.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "V5.h"
#include "LoginDlg.h"
#include "V5Dlg.h"
#include "RoomView.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CV5App

BEGIN_MESSAGE_MAP(CV5App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CV5App 构造

CV5App::CV5App()
{
}

CV5App theApp;

BOOL CV5App::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	//SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	CLoginDlg dlg;
	//m_pMainWnd = &dlg;
	//INT_PTR nResponse = dlg.DoModal();
	//if (nResponse == IDOK)
	if(dlg.DoModal()==IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
		CV5Dlg  *pMainDlg=new CV5Dlg;
		m_pMainWnd=pMainDlg;
		pMainDlg->DoModal();
		delete pMainDlg;
		pMainDlg=NULL;
	    //dlg.DoModal();
	}
	else
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}
CString CV5App::GetComputerName()
{
	return CString("");
}
CString CV5App::GetComputerIP()
{
    return CString("");
}

BOOL CV5App::GetData(CString sql, _RecordsetPtr &Rs)
{
	try{
	Rs=m_pConnection->Execute((_bstr_t)sql,NULL,-1);
	if(Rs->RecordCount>0){
		Rs->MoveFirst();
		return TRUE;
	}else{
		return FALSE;
	}
	}catch(_com_error &er)
	{
		MessageBox(NULL,er.ErrorMessage(),_T("系统提示"),MB_OK);
		return FALSE;
	}
}

BOOL CV5App::InitDB()
{
	::CoInitialize(NULL);
	_bstr_t bstr=GetConnectionString();
	 HRESULT hr=m_pConnection.CreateInstance("ADODB.Connection");
	 if (SUCCEEDED(hr)>0)
	     return FALSE;
	 hr=m_pCommand.CreateInstance("ADODB.Command");
	 if (SUCCEEDED(hr)>0)
		 return FALSE;
	try{
	   m_pConnection->Open(bstr,"","",-1);
	   m_pCommand->ActiveConnection =m_pConnection;
	   return TRUE;
	}
	catch(_com_error e)
	{
		return FALSE;
	}
}

CString CV5App::GetAppPath()
{   /*
	 * SetCurrentDirectory: 切换当前进程的当前工作目录。
     * 请问在什么情形下会有这种进程的切换？？
	 * 情形1 解决使用CFileDialog造成的访问相对路径文件出错
     * 现象：程序中使用CFileDialog选择一个文件后，无法访问相对路径下的文件
	 *       ，Debug没有出错，EXE启动出错！
     * 原因：CFileDialog通过DoModal() == IDOK后，会造成当前程序的路径的改变
	 *       ，所以无法访问。
     * 解决：在调用CFileDialog DoModal前先使用GetCurrentDirectory()保存当前路径
	 *       ，调用DoModal()后使用SetCurrentDirectory()重新设定当前目录即可。
	 * 情形2 参见 http://blog.csdn.net/woyaowenzi/article/details/4332187
	 * 情形3 LoadLibrary加载动态库失败的解决办法.
     * 方式一 采用LoadLibraryEx
     * 若DLL不在调用方的同一目录下，可以用LoadLibrary(L"DLL绝对路径")加载
	 * 。但若调用的DLL内部又调用另外一个DLL，此时调用仍会失败。解决办法是用LoadLibraryEx：
     * LoadLibraryEx("DLL绝对路径", NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
     * 通过指定LOAD_WITH_ALTERED_SEARCH_PATH，让系统DLL搜索顺序从DLL所在目录开始。
     * 方式二 采用SetCurrentDir
     * 跨目录调用dll，你应该这样
     * 1 用GetCurrentDir保存当前的工作目录
     * 2 用SetCurrentDir将当前的工作目录，设置为你的DLL所在的路径，需要使用绝对路径
     * 3 用LoadLibrary你的DLL
     * 4 使用SetCurrentDir恢复到原来的工作路径
	 */
	TCHAR   szCurrentDir[255]={0};
	GetModuleFileName(NULL, szCurrentDir, sizeof(szCurrentDir));
    LPTSTR lpInsertPos = _tcsrchr( szCurrentDir, _T('\\') );
    _tcscpy(lpInsertPos+1,_T("\\..\\"));
    SetCurrentDirectory(szCurrentDir);
    GetCurrentDirectory( sizeof(szCurrentDir),szCurrentDir);  
	return szCurrentDir;
}

CString CV5App::GetConnectionString()
{
	CString   strServer=_T("");
	CString   strDB=_T("");
	CString   strUID=_T("");
	CString   strPWD=_T("");
	CString   strConnectionString=_T("");
	CString   strFilePath=GetAppPath()+_T("\\setting.ini");
    GetPrivateProfileString(_T("db"),_T("server"),_T(""),strServer.GetBuffer(255),255,strFilePath.GetBuffer(255));
	GetPrivateProfileString(_T("db"),_T("database"),_T(""),strDB.GetBuffer(255),255,strFilePath.GetBuffer(255));
	GetPrivateProfileString(_T("db"),_T("uid"),_T(""),strUID.GetBuffer(255),255,strFilePath.GetBuffer(255));
	GetPrivateProfileString(_T("db"),_T("pwd"),_T(""),strPWD.GetBuffer(255),255,strFilePath.GetBuffer(255));
	strConnectionString.Format(_T("DRIVER=SQL SERVER; SERVER=%s; UID=%s; PWD=%s; DATABASE=%s; "),strServer,strUID,strPWD,strDB);
	return strConnectionString;
}