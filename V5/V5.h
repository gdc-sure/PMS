// V5.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CV5App:
// 有关此类的实现，请参阅 V5.cpp
//

class CV5App : public CWinApp
{
public:
	CV5App();

// 重写
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

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CV5App theApp;