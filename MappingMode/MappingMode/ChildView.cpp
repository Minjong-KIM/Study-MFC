
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "MappingMode.h"
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
	CRect rect;
	GetClientRect(&rect);

	dc.SetMapMode(MM_LOMETRIC);
	dc.Rectangle(0, 0, 1000, -300);

	dc.SetMapMode(MM_HIMETRIC);
	dc.Ellipse(0, 0, 10000, -3000);

	dc.SetMapMode(MM_ANISOTROPIC);
	dc.SetWindowExt(100, 100);
	dc.SetViewportExt(rect.Width(), rect.Height());

	dc.RoundRect(0, 0, 100, 100, 50, 50);
}

