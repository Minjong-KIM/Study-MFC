// CKeyInputView.cpp: 구현 파일
//

#include "pch.h"
#include "Splitter.h"
#include "CKeyInputView.h"
#include "SplitterDoc.h"


// CKeyInputView

IMPLEMENT_DYNCREATE(CKeyInputView, CView)

CKeyInputView::CKeyInputView()
{

}

CKeyInputView::~CKeyInputView()
{
}

BEGIN_MESSAGE_MAP(CKeyInputView, CView)
	ON_WM_CHAR()
END_MESSAGE_MAP()


// CKeyInputView 그리기

void CKeyInputView::OnDraw(CDC* pDC)
{
	CSplitterDoc* pDoc = (CSplitterDoc*)GetDocument();
	
	CFont font;
	font.CreatePointFont(150, _T("궁서"));
	CRect rect;
	GetClientRect(&rect);

	pDC->SelectObject(&font);
	pDC->DrawText(pDoc->m_str.GetData(), pDoc->m_str.GetSize(),&rect, DT_LEFT);
}


// CKeyInputView 진단

#ifdef _DEBUG
void CKeyInputView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CKeyInputView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CKeyInputView 메시지 처리기


void CKeyInputView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CSplitterDoc* pDoc = (CSplitterDoc*)GetDocument();
	if (nChar == '\b') {
		if (pDoc->m_str.GetSize() > 0) {
			pDoc->m_str.RemoveAt(pDoc->m_str.GetSize() - 1);
		}
	}
	else {
		pDoc->m_str.Add(nChar);
	}

	Invalidate();
}
