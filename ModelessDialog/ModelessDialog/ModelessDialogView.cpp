
// ModelessDialogView.cpp: CModelessDialogView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ModelessDialog.h"
#endif

#include "ModelessDialogDoc.h"
#include "ModelessDialogView.h"
#include "CMyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CModelessDialogView

IMPLEMENT_DYNCREATE(CModelessDialogView, CFormView)

BEGIN_MESSAGE_MAP(CModelessDialogView, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CModelessDialogView 생성/소멸

CModelessDialogView::CModelessDialogView() noexcept
	: CFormView(IDD_MODELESSDIALOG_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_pDlg = NULL;
	m_str = _T("");
	m_font = 0;
}

CModelessDialogView::~CModelessDialogView()
{
}

void CModelessDialogView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CModelessDialogView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CModelessDialogView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CModelessDialogView 인쇄

BOOL CModelessDialogView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CModelessDialogView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CModelessDialogView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CModelessDialogView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// CModelessDialogView 진단

#ifdef _DEBUG
void CModelessDialogView::AssertValid() const
{
	CFormView::AssertValid();
}

void CModelessDialogView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CModelessDialogDoc* CModelessDialogView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CModelessDialogDoc)));
	return (CModelessDialogDoc*)m_pDocument;
}
#endif //_DEBUG


// CModelessDialogView 메시지 처리기


void CModelessDialogView::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (m_pDlg != NULL) {
		m_pDlg->SetFocus();
	}

	else {
		m_pDlg = new CMyDialog();
		m_pDlg->m_pView = this;
		m_pDlg->m_str = m_str;
		m_pDlg->m_font = m_font;
		m_pDlg->Create(IDD_CMyDialog);
		m_pDlg->ShowWindow(SW_SHOW);
	}
}


void CModelessDialogView::OnDraw(CDC* pDC)
{
	CFont font;
	CString fontname;

	if (m_font == 0) fontname = _T("궁서");
	else if (m_font == 1) fontname = _T("굴림");
	else if (m_font == 2) fontname = _T("바탕");
	font.CreatePointFont(400, fontname);

	pDC->SelectObject(&font);
	pDC->TextOut(10, 10, m_str);
}
