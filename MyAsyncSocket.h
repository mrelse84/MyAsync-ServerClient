#pragma once

#include "MySocketInterface.h"

// CMyAsyncSocket 명령 대상입니다.

class CMyAsyncSocket : public CAsyncSocket
{
public:
	CMyAsyncSocket();
	virtual ~CMyAsyncSocket();
	//int SetOwner(CObject* pOwner);
	int SetOwner(CMySocketInterface* pOwner);
private:
	//CObject* m_pOwner;
	CMySocketInterface* m_pOwner;
public:
	virtual void OnAccept(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnClose(int nErrorCode);
};


