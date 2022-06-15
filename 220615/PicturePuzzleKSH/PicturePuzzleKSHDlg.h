
// PicturePuzzleKSHDlg.h: 헤더 파일
//

#pragma once
#include "imageSrc\MyImage.h"

// CPicturePuzzleKSHDlg 대화 상자
class CPicturePuzzleKSHDlg : public CDialogEx
{
// 생성입니다.
public:
	CPicturePuzzleKSHDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PICTUREPUZZLEKSH_DIALOG };
#endif

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

protected:
	CByteImage m_imageIn1;
	CByteImage m_imageIn2;
	CByteImage m_imageOut;
	CByteImage m_imageOut_reverse;

	bool _ImageOpImage();
	bool _ImageOpConst();
public:
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButtonLoad1();
	afx_msg void OnBnClickedButtonLoad2();
	afx_msg void OnBnClickedButtonCalculate();
};
