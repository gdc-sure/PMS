#pragma once
#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif
#include "resource.h"		// 主符号

class CV5App : public CWinApp
{
public:
	CV5App();
	public:
	CString GetConnectionString();
	CString GetAppPath();
	BOOL InitDB();
	_RecordsetPtr m_ConfigureRecordset;
	_CommandPtr   m_pCommand;
	CString GetComputerIP();
	CString GetComputerName();
        _ConnectionPtr    m_pConnection;
	CString           m_OperatorID;
	CString           m_OperatorName;
	CString           m_ShiftID;
	BOOL  GetData(CString sql, _RecordsetPtr &Rs);
	virtual BOOL InitInstance();
	DECLARE_MESSAGE_MAP()
};

extern CV5App theApp;
