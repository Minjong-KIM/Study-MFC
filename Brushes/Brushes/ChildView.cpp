
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "Brushes.h"
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

	CBrush brush1(RGB(0, 0, 255));
	dc.SelectObject(&brush1);
	dc.Rectangle(50, 50, 200, 200);

	CBrush brush2(HS_DIAGCROSS, RGB(0, 0, 255));
	dc.SelectObject(&brush2);
	dc.Ellipse(250, 50, 400, 200);

	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);
	CBrush brush3(&bitmap);
	dc.SelectObject(&brush3);
	dc.RoundRect(450, 50, 600, 200, 50, 50);
}

