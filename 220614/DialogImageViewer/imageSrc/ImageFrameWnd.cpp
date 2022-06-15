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
	
	// â�� ������ �� �� ���� ��ġ�� ���� �ȵǹǷ� �����Ǵ� ��ġ ����.
	// �Ű������� �밢�� 2���� ������ ��ǥ
	// ������ ���� 30�� �����ϴ� �Ű�, �����ϴ��� �׸�ŭ�� ������.
	// ��������δ� �밢������ ��Ʈ(30*30)��ŭ �̵��ϴ� ��.

	CRect rect(30*nFrameWndCount, 30*nFrameWndCount, 
		image.GetWidth()+30*nFrameWndCount, image.GetHeight()+30*nFrameWndCount);
	Create(NULL, wndName, WS_OVERLAPPEDWINDOW, rect); // this.onDraw�� ȣ�����ش�.

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
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1) // base class�� OnCreate�� ����Ѵ�. 
		return -1;

	// TODO:  Add your specialized creation code here
	m_view.CreateEx(this);   // createEX�� ȣ��.

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
