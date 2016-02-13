
// MyAsync-ServerClientDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "MyAsync-ServerClient.h"
#include "MyAsync-ServerClientDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMyAsyncServerClientDlg 대화 상자




CMyAsyncServerClientDlg::CMyAsyncServerClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyAsyncServerClientDlg::IDD, pParent)
	, m_nMode(0)
	, m_strSendData(_T(""))
	, m_pSock(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyAsyncServerClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, m_nMode);
	DDX_Text(pDX, IDC_EDIT1, m_strSendData);
}

BEGIN_MESSAGE_MAP(CMyAsyncServerClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMyAsyncServerClientDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMyAsyncServerClientDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMyAsyncServerClientDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMyAsyncServerClientDlg 메시지 처리기

BOOL CMyAsyncServerClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMyAsyncServerClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMyAsyncServerClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMyAsyncServerClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMyAsyncServerClientDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);	// Dialog의 컨트롤 변수 값 가져 오기

	if (m_nMode == 0)	// Server
	{
		if (!m_sockServer.Create(7979))			// Server Port : 7979
		{ 
			MessageBox("Server Sock Create Fail");
			return;
		}
		if (!m_sockServer.Listen())				// Listen
		{ 
			MessageBox("Listen Fail");
			return;
		}
		else
		{
			//m_sockServer.SetOwner((CObject*)this);
			m_sockServer.SetOwner((CMySocketInterface*)this);
		}
	}
	else				// Client
	{
		if (!m_sockClient.Create())
		{ 
			MessageBox("Client Sock Create Fail");
			return;
		}

		CString address("127.0.0.1");
		int port = 7979;
		if (m_sockClient.Connect(address, port) )
		{ 
			MessageBox("Connect Fail");
			return;
		}
		else
		{
			//m_sockClient.SetOwner((CObject*)this);
			m_sockClient.SetOwner((CMySocketInterface*)this);
			m_pSock = &m_sockClient;// Set Client Sock
		}
	}

	CString strMsg = "[Open Ok]";
	((CListBox*)GetDlgItem(IDC_LIST1))->AddString(strMsg);
}


void CMyAsyncServerClientDlg::OnBnClickedButton2()
{
	if (m_pSock == NULL)
		return;

	UpdateData(TRUE);

	int dataLen = m_strSendData.GetLength();
	char * pBuf = (LPSTR)(LPCTSTR)m_strSendData;

	int nSent = m_pSock->Send(pBuf, dataLen);

	if (nSent == SOCKET_ERROR)
	{
		int nErr = GetLastError();

		if (nErr == WSAEWOULDBLOCK)
			return;
		else
		{
			CString strMsg = "[Send Fail] nErr = " + nErr;
			((CListBox*)GetDlgItem(IDC_LIST1))->AddString(strMsg);
		}
	}
}


int CMyAsyncServerClientDlg::MyAccept(void)
{
	if (!m_sockServer.Accept(m_sockData))
	{
		MessageBox("Accept Fail");
		return -1;
	}
	else
	{
		// 이 예제에서는 1개의 Client 하고만 통신할 것이므로 
		// Accept이 되면 Server를 닫도록 한다.
		m_sockServer.Close();

		//m_sockData.SetOwner((CObject*)this);
		m_sockData.SetOwner((CMySocketInterface*)this);
		m_pSock = &m_sockData;		// Set Client Sock

		CString strMsg = "[Accept Ok]";
		((CListBox*)GetDlgItem(IDC_LIST1))->AddString(strMsg);
	}

	return 0;
}


int CMyAsyncServerClientDlg::MyReceive(void)
{
	char buf[2048];
	memset(buf, 0, sizeof(buf));
	int bytes = m_pSock->Receive(buf, sizeof(buf));

	CString strRecvData = "";
	strRecvData.Format("%d: %s\r\n", bytes, buf);
	((CListBox*)GetDlgItem(IDC_LIST1))->AddString(strRecvData);

	return 0;
}


int CMyAsyncServerClientDlg::MyConnect(void)
{
	CString strMsg = "[Connect Ok]";
	((CListBox*)GetDlgItem(IDC_LIST1))->AddString(strMsg);

	return 0;
}


void CMyAsyncServerClientDlg::OnBnClickedButton3()
{
	if (m_pSock != NULL)
	{
		m_pSock->SetOwner(NULL);
		m_pSock->Close();
		m_pSock = NULL;

		CString strMsg = "[Close Ok]";
		((CListBox*)GetDlgItem(IDC_LIST1))->AddString(strMsg);
	}
}


int CMyAsyncServerClientDlg::MyClose(void)
{
	if (m_pSock != NULL)
	{
		m_pSock->SetOwner(NULL);
		m_pSock->Close();
		m_pSock = NULL;

		CString strMsg = "[Peer Closed]";
		((CListBox*)GetDlgItem(IDC_LIST1))->AddString(strMsg);
	}

	return 0;
}
