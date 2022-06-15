// ImageFrameWnd.cpp : implementation file
//

#include "pch.h"
#include "ImageFrameWnd.h"
#include "ImageView.h"

static int nFrameWndCount = 0;

// CImageFrameWnd

CImageFrameWnd::CImageFrameWnd()
{
}

CImageFrameWnd::CImageFrameWnd(const CByteImage &image, const char *name)
{
	m_view.SetImage(image);

	CString wndName;
	if (name)
		wndName = name;
	else
		wndName.Format("Image view %d", nFrameWndCount);
	
	// 창을 여러개 열 때 같은 위치에 열면 안되므로 생성되는 위치 조절.
	// 매개변수는 대각선 2개의 꼭짓점 좌표
	// 좌측이 따라서 30씩 증가하는 거고, 우측하단은 그만큼씩 더해짐.
	// 결과적으로는 대각선으로 루트(30*30)만큼 이동하는 것.

	CRect rect(30*nFrameWndCount, 30*nFrameWndCount, 
		image.GetWidth()+30*nFrameWndCount, image.GetHeight()+30*nFrameWndCount);
	Create(NULL, wndName, WS_OVERLAPPEDWINDOW, rect); // this.onDraw를 호출해준다.

	nFrameWndCount++;

	ShowWindow(SW_SHOW);
}

CImageFrameWnd::~CImageFrameWnd()
{
}


BEGIN_MESSAGE_MAP(CImageFrameWnd, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CImageFrameWnd message handlers


int CImageFrameWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1) // base class의 OnCreate를 사용한다. 
		return -1;

	// TODO:  Add your specialized creation code here
	m_view.CreateEx(this);   // createEX로 호출.

	return 0;
}

#include "ImageFrameWndManager.h"
extern CImageFrameWndManager gImageFrameWndManager;
void CImageFrameWnd::PostNcDestroy()
{
	// TODO: Add your specialized code here and/or call the base class
	gImageFrameWndManager.Delete(this);
//	CFrameWnd::PostNcDestroy();
}
