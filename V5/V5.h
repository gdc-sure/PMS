// V5.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CV5App:
// �йش����ʵ�֣������ V5.cpp
//

class CV5App : public CWinApp
{
public:
	CV5App();

// ��д
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

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CV5App theApp;