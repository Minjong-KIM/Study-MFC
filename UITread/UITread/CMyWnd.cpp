// CMyWnd.cpp: 구현 파일
//

#include "pch.h"
#include "UITread.h"
#include "CMyWnd.h"


// CMyWnd

IMPLEMENT_DYNCREATE(CMyWnd, CFrameWnd)

CMyWnd::CMyWnd()
{
	Create(NULL, _T("UI 스레드로 생성한 윈도우"));
}

CMyWnd::~CMyWnd()
{
}


BEGIN_MESSAGE_MAP(CMyWnd, CFrameWnd)
	ON_WM_CHAR()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CMyWnd 메시지 처리기


void CMyWnd::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == '\b') {
		if (m_str.GetSize() > 0) {
			m_str.RemoveAt(m_str.GetSize() - 1);
		}
	}

	else {
		m_str.Add(nChar);
	}

	Invalidate();
}


void CMyWnd::OnPaint()
{
	CPaintDC dc(this);

	CFont font;
	font.CreatePointFont(150, _T("궁서"));
	CRect rect;
	GetClientRect(&rect);

	dc.SelectObject(&font);
	dc.DrawText(m_str.GetData(), m_str.GetSize(), &rect, DT_LEFT);
}
