// V5.cpp : ����Ӧ�ó��������Ϊ��
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


// CV5App ����

CV5App::CV5App()
{
}

CV5App theApp;

BOOL CV5App::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	//SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CLoginDlg dlg;
	//m_pMainWnd = &dlg;
	//INT_PTR nResponse = dlg.DoModal();
	//if (nResponse == IDOK)
	if(dlg.DoModal()==IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
		CV5Dlg  *pMainDlg=new CV5Dlg;
		m_pMainWnd=pMainDlg;
		pMainDlg->DoModal();
		delete pMainDlg;
		pMainDlg=NULL;
	    //dlg.DoModal();
	}
	else
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
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
		MessageBox(NULL,er.ErrorMessage(),_T("ϵͳ��ʾ"),MB_OK);
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
	 * SetCurrentDirectory: �л���ǰ���̵ĵ�ǰ����Ŀ¼��
     * ������ʲô�����»������ֽ��̵��л�����
	 * ����1 ���ʹ��CFileDialog��ɵķ������·���ļ�����
     * ���󣺳�����ʹ��CFileDialogѡ��һ���ļ����޷��������·���µ��ļ�
	 *       ��Debugû�г���EXE��������
     * ԭ��CFileDialogͨ��DoModal() == IDOK�󣬻���ɵ�ǰ�����·���ĸı�
	 *       �������޷����ʡ�
     * ������ڵ���CFileDialog DoModalǰ��ʹ��GetCurrentDirectory()���浱ǰ·��
	 *       ������DoModal()��ʹ��SetCurrentDirectory()�����趨��ǰĿ¼���ɡ�
	 * ����2 �μ� http://blog.csdn.net/woyaowenzi/article/details/4332187
	 * ����3 LoadLibrary���ض�̬��ʧ�ܵĽ���취.
     * ��ʽһ ����LoadLibraryEx
     * ��DLL���ڵ��÷���ͬһĿ¼�£�������LoadLibrary(L"DLL����·��")����
	 * ���������õ�DLL�ڲ��ֵ�������һ��DLL����ʱ�����Ի�ʧ�ܡ�����취����LoadLibraryEx��
     * LoadLibraryEx("DLL����·��", NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
     * ͨ��ָ��LOAD_WITH_ALTERED_SEARCH_PATH����ϵͳDLL����˳���DLL����Ŀ¼��ʼ��
     * ��ʽ�� ����SetCurrentDir
     * ��Ŀ¼����dll����Ӧ������
     * 1 ��GetCurrentDir���浱ǰ�Ĺ���Ŀ¼
     * 2 ��SetCurrentDir����ǰ�Ĺ���Ŀ¼������Ϊ���DLL���ڵ�·������Ҫʹ�þ���·��
     * 3 ��LoadLibrary���DLL
     * 4 ʹ��SetCurrentDir�ָ���ԭ���Ĺ���·��
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