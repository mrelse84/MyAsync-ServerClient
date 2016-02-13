
// MyAsync-ServerClientDlg.h : ��� ����
//

#pragma once
#include "MySocketInterface.h"
#include "myasyncsocket.h"


// CMyAsyncServerClientDlg ��ȭ ����
class CMyAsyncServerClientDlg : public CDialogEx, public CMySocketInterface
{
// �����Դϴ�.
public:
	CMyAsyncServerClientDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_MYASYNCSERVERCLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_nMode;
	CString m_strSendData;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
private:
	CMyAsyncSocket m_sockServer;
	CMyAsyncSocket m_sockClient;
	CMyAsyncSocket m_sockData;
	CMyAsyncSocket* m_pSock;
public:
	virtual int MyAccept(void);
	virtual int MyReceive(void);
	virtual int MyConnect(void);
	virtual int MyClose(void);
	afx_msg void OnBnClickedButton3();
};
