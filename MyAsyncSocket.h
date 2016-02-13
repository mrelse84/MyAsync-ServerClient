#pragma once

#include "MySocketInterface.h"

// CMyAsyncSocket ��� ����Դϴ�.

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


