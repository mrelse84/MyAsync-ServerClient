
// MyAsync-ServerClientDlg.h : 헤더 파일
//

#pragma once
#include "MySocketInterface.h"
#include "myasyncsocket.h"


// CMyAsyncServerClientDlg 대화 상자
class CMyAsyncServerClientDlg : public CDialogEx, public CMySocketInterface
{
// 생성입니다.
public:
	CMyAsyncServerClientDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_MYASYNCSERVERCLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
