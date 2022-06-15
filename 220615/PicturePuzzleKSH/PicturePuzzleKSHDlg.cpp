﻿
// PicturePuzzleKSHDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "PicturePuzzleKSH.h"
#include "PicturePuzzleKSHDlg.h"
#include "afxdialogex.h"

#include "imageSrc\MyImageFunc.h"
#include "imageSrc\ImageFrameWndManager.h"
#include "imageSrc\LoadImageFromFileDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPicturePuzzleKSHDlg 대화 상자



CPicturePuzzleKSHDlg::CPicturePuzzleKSHDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PICTUREPUZZLEKSH_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPicturePuzzleKSHDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPicturePuzzleKSHDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CPicturePuzzleKSHDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CPicturePuzzleKSHDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON_LOAD_1, &CPicturePuzzleKSHDlg::OnBnClickedButtonLoad1)
	ON_BN_CLICKED(IDC_BUTTON_LOAD_2, &CPicturePuzzleKSHDlg::OnBnClickedButtonLoad2)
	ON_BN_CLICKED(IDC_BUTTON_CALCULATE, &CPicturePuzzleKSHDlg::OnBnClickedButtonCalculate)
END_MESSAGE_MAP()


// CPicturePuzzleKSHDlg 메시지 처리기

BOOL CPicturePuzzleKSHDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CPicturePuzzleKSHDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CPicturePuzzleKSHDlg::OnPaint()
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
HCURSOR CPicturePuzzleKSHDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPicturePuzzleKSHDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CPicturePuzzleKSHDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}


void CPicturePuzzleKSHDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}


void CPicturePuzzleKSHDlg::OnBnClickedButtonLoad1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_imageIn1 = LoadImageFromDialog();
	if (!m_imageIn1.IsEmpty())
		ShowImage(m_imageIn1, "입력 영상 1");
}


void CPicturePuzzleKSHDlg::OnBnClickedButtonLoad2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_imageIn2 = LoadImageFromDialog();
	if (!m_imageIn2.IsEmpty())
		ShowImage(m_imageIn2, "입력 영상 2");
}


void CPicturePuzzleKSHDlg::OnBnClickedButtonCalculate()
{
	UpdateData(true); // m_nOperator의 radio button의 입력값을 읽어오는 것.
					  // 그것이 m_bImgOperand
	if (m_imageIn1.IsEmpty())
	{
		AfxMessageBox("입력 영상 1이 없습니다.");
		return;
	}

	bool bRet;
	if (m_imageIn2.IsEmpty())
	{
		AfxMessageBox("입력 영상 2가 없습니다.");
		return;
	}
	bRet = _ImageOpImage(); // image & image 연산하는 함수 호출
	
	if (bRet) // 동작들이 정상 수행되었다면
	{
		ShowImage(m_imageOut, "결과 영상"); //
		m_imageOut.SaveImage("Result1.bmp");	// result.bmp라는 이름으로 저장
		
		ShowImage(m_imageOut_reverse, "결과 반전 영상"); //
		m_imageOut_reverse.SaveImage("Result2.bmp");	// result.bmp라는 이름으로 저장

	}
}


bool CPicturePuzzleKSHDlg::_ImageOpImage()
{
	int nWidth = m_imageIn1.GetWidth();
	int nHeight = m_imageIn1.GetHeight();
	int nCh = m_imageIn1.GetChannel();

	if ((nWidth != m_imageIn2.GetWidth() ||
			nHeight != m_imageIn2.GetHeight() ||
			nCh != m_imageIn2.GetChannel()))
	{
		AfxMessageBox("입력 영상의 규격이 다릅니다.");
		return false;
	}

	m_imageOut = m_imageIn1 ^ m_imageIn2;
	m_imageOut_reverse = ~m_imageOut; 

	
	int r, c, h;
	for (r = 0; r < nHeight; r++) // 행 단위 이동
	{
		for (c = 0; c < nWidth; c++) // 열 단위 이동
		{
			if ((m_imageOut_reverse.GetAt(c, r, 0) ==255) && (m_imageOut_reverse.GetAt(c, r, 1) ==255) && (m_imageOut_reverse.GetAt(c, r, 2) ==255)) {
				for (h = 0; h < nCh; h++) // 채널 단위 이동
				{
					m_imageOut.GetAt(c, r, h) =	255;
				}
			}
			else {
				for (h = 0; h < nCh; h++) // 채널 단위 이동
				{
					m_imageOut.GetAt(c, r, h) =	m_imageIn2.GetAt(c, r, h);
				}
			}
		}
	}

	return true;
}
