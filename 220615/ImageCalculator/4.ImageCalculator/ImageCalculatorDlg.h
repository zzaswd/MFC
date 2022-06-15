
// ImageCalculatorDlg.h: 헤더 파일
//

#pragma once

#include "imageSrc\MyImage.h"

// CImageCalculatorDlg 대화 상자
class CImageCalculatorDlg : public CDialogEx
{
// 생성입니다.
public:
	CImageCalculatorDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IMAGECALCULATOR_DIALOG };
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

	bool _ImageOpImage();
	bool _ImageOpConst();
public:
	afx_msg void OnBnClickedButtonLoad1(); // axf_msg : window에서 자동으로 처리해주는 함수 
	afx_msg void OnBnClickedButtonLoad2(); // dlg에서 더블 클릭하면 생김.
	afx_msg void OnBnClickedButtonCalculate();
	afx_msg void OnBnClickedRadioImage();
	afx_msg void OnBnClickedRadioConst();
	afx_msg void OnBnClickedRadioNot();
	int m_nOperator;	// 이러한 변수들은 dlg 파일에서 우클릭 -> 속성하면 자동으로 생기는 변수들
	BOOL m_bImgOperand;
	double m_dOperandVal;
	afx_msg void OnBnClickedRadioPlus();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedOk();
};
