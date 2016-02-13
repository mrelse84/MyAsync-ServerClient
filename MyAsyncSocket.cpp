// MyAsyncSocket.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MyAsyncSocket.h"

//#include "MyAsync-ServerClient.h"
//#include "MyAsync-ServerClientDlg.h"


// CMyAsyncSocket

CMyAsyncSocket::CMyAsyncSocket()
	: m_pOwner(NULL)
{
}

CMyAsyncSocket::~CMyAsyncSocket()
{
}


// CMyAsyncSocket 멤버 함수


int CMyAsyncSocket::SetOwner(CMySocketInterface* pOwner)
{
	m_pOwner = pOwner;
	return 0;
}


void CMyAsyncSocket::OnAccept(int nErrorCode)
{
	//((CMyAsyncServerClientDlg*)m_pOwner)->MyAccept();
	((CMySocketInterface*)m_pOwner)->MyAccept();

	CAsyncSocket::OnAccept(nErrorCode);
}


void CMyAsyncSocket::OnReceive(int nErrorCode)
{
	//((CMyAsyncServerClientDlg*)m_pOwner)->MyReceive();
	((CMySocketInterface*)m_pOwner)->MyReceive();

	CAsyncSocket::OnReceive(nErrorCode);
}


void CMyAsyncSocket::OnConnect(int nErrorCode)
{
	//((CMyAsyncServerClientDlg*)m_pOwner)->MyConnect();
	((CMySocketInterface*)m_pOwner)->MyConnect();

	CAsyncSocket::OnConnect(nErrorCode);
}


void CMyAsyncSocket::OnClose(int nErrorCode)
{
	//((CMyAsyncServerClientDlg*)m_pOwner)->MyClose();
	((CMySocketInterface*)m_pOwner)->MyClose();

	CAsyncSocket::OnClose(nErrorCode);
}
