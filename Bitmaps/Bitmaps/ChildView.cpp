
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "Bitmaps.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this);

	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);

	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	memDC.SelectObject(&bitmap);

	dc.BitBlt(10, 10, bmpinfo.bmWidth, bmpinfo.bmHeight, &memDC, 0, 0, SRCCOPY);
	dc.StretchBlt(10, 100, bmpinfo.bmWidth * 4, bmpinfo.bmHeight * 2, &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);

	memDC.Rectangle(5, 5, 15, 15);
	dc.BitBlt(350, 10, bmpinfo.bmWidth, bmpinfo.bmHeight, &memDC, 0, 0, SRCCOPY);
	dc.StretchBlt(350, 100, bmpinfo.bmWidth * 4, bmpinfo.bmHeight * 2, &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
}

