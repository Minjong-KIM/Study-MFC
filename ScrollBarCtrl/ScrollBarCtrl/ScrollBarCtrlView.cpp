
// ScrollBarCtrlView.cpp: CScrollBarCtrlView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ScrollBarCtrl.h"
#endif

#include "ScrollBarCtrlDoc.h"
#include "ScrollBarCtrlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CScrollBarCtrlView

IMPLEMENT_DYNCREATE(CScrollBarCtrlView, CFormView)

BEGIN_MESSAGE_MAP(CScrollBarCtrlView, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
END_MESSAGE_MAP()

// CScrollBarCtrlView 생성/소멸

CScrollBarCtrlView::CScrollBarCtrlView() noexcept
	: CFormView(IDD_SCROLLBARCTRL_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CScrollBarCtrlView::~CScrollBarCtrlView()
{
}

void CScrollBarCtrlView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATUS, m_status);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_hsb);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_vsb);
}

BOOL CScrollBarCtrlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CScrollBarCtrlView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_hsb.SetScrollRange(0, 365, FALSE);
	m_hsb.SetScrollPos(0);
	m_vsb.SetScrollRange(0, 255, FALSE);
	m_vsb.SetScrollPos(128);
}


// CScrollBarCtrlView 인쇄

BOOL CScrollBarCtrlView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CScrollBarCtrlView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CScrollBarCtrlView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CScrollBarCtrlView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// CScrollBarCtrlView 진단

#ifdef _DEBUG
void CScrollBarCtrlView::AssertValid() const
{
	CFormView::AssertValid();
}

void CScrollBarCtrlView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CScrollBarCtrlDoc* CScrollBarCtrlView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CScrollBarCtrlDoc)));
	return (CScrollBarCtrlDoc*)m_pDocument;
}
#endif //_DEBUG


// CScrollBarCtrlView 메시지 처리기


void CScrollBarCtrlView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if (pScrollBar != NULL) {
		if (pScrollBar->GetSafeHwnd() == m_hsb.GetSafeHwnd()) {
			switch (nSBCode) {
			case SB_THUMBTRACK:
				pScrollBar->SetScrollPos(nPos);
				break;
			}
			Invalidate();
		}
	}

	else CFormView::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CScrollBarCtrlView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	int pos;
	int delta = 0;
	if (pScrollBar != NULL) {
		if (pScrollBar->GetSafeHwnd() == m_vsb.GetSafeHwnd()) {
			switch (nSBCode) {
			case SB_THUMBTRACK:
				pScrollBar->SetScrollPos(nPos);
				break;
			case SB_LINEUP:
				delta = -4;
				break;
			case SB_LINEDOWN:
				delta = 4;
				break;
			case SB_PAGEUP:
				delta = -20;
				break;
			case SB_PAGEDOWN:
				delta = 20;
				break;
			}
			if (delta != 0) {
				pos = pScrollBar->GetScrollPos();
				pScrollBar->SetScrollPos(pos + delta);
			}
			Invalidate();
		}
	}

	else CFormView::OnVScroll(nSBCode, nPos, pScrollBar);
}


void CScrollBarCtrlView::OnDraw(CDC* pDC)
{
	int hpos = m_hsb.GetScrollPos();
	int vpos = m_vsb.GetScrollPos();

	CFont font;
	LOGFONT lf = { 0 };
	lf.lfHeight = vpos / 3 + 1;
	lf.lfEscapement = 10 * hpos;
	font.CreateFontIndirect(&lf);
	pDC->SelectObject(font);
	pDC->SetTextColor(RGB(0, vpos, 0));
	pDC->TextOut(50, 100, _T("안녕하세요"));

	CString str;
	str.Format(_T("글자 크기: %d, 회전각: %d, 초록색 농도: %d"), lf.lfHeight, hpos, vpos);
	m_status.SetWindowText(str);
}
