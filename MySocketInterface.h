#pragma once
class CMySocketInterface
{
public:
	CMySocketInterface(void);
	~CMySocketInterface(void);

	virtual int MyAccept(void) = 0;
	virtual int MyReceive(void) = 0;
	virtual int MyConnect(void) = 0;
	virtual int MyClose(void) = 0;
};

