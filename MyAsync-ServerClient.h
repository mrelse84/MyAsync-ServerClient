
// MyAsync-ServerClient.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMyAsyncServerClientApp:
// �� Ŭ������ ������ ���ؼ��� MyAsync-ServerClient.cpp�� �����Ͻʽÿ�.
//

class CMyAsyncServerClientApp : public CWinApp
{
public:
	CMyAsyncServerClientApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMyAsyncServerClientApp theApp;