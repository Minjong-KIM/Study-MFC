
// ButtonCtrlView.cpp: CButtonCtrlView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ButtonCtrl.h"
#endif

#include "ButtonCtrlDoc.h"
#include "ButtonCtrlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CButtonCtrlView

IMPLEMENT_DYNCREATE(CButtonCtrlView, CFormView)

BEGIN_MESSAGE_MAP(CButtonCtrlView, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON1, &CButtonCtrlView::OnBnClickedButton1)
END_MESSAGE_MAP()

// CButtonCtrlView 생성/소멸

CButtonCtrlView::CButtonCtrlView() noexcept
	: CFormView(IDD_BUTTONCTRL_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CButtonCtrlView::~CButtonCtrlView()
{
}

void CButtonCtrlView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_checkbox);
	DDX_Control(pDX, IDC_CHECK2, m_3state);
	DDX_Control(pDX, IDC_RADIO1, m_radio1);
	DDX_Control(pDX, IDC_RADIO2, m_radio2);
}

BOOL CButtonCtrlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CButtonCtrlView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_checkbox.SetCheck(1);
	m_3state.SetCheck(2);
	m_radio2.SetCheck(1);
}


// CButtonCtrlView 인쇄

BOOL CButtonCtrlView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CButtonCtrlView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CButtonCtrlView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CButtonCtrlView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// CButtonCtrlView 진단

#ifdef _DEBUG
void CButtonCtrlView::AssertValid() const
{
	CFormView::AssertValid();
}

void CButtonCtrlView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CButtonCtrlDoc* CButtonCtrlView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CButtonCtrlDoc)));
	return (CButtonCtrlDoc*)m_pDocument;
}
#endif //_DEBUG


// CButtonCtrlView 메시지 처리기


void CButtonCtrlView::OnBnClickedButton1()
{
	int state_checkbox = m_checkbox.GetCheck();
	int state_3state = m_3state.GetCheck();
	int state_radio1 = m_radio1.GetCheck();
	int state_radio2 = m_radio2.GetCheck();

	CString str;
	str.Format(_T("버튼 상태 : %d, %d, %d, %d"), state_checkbox, state_3state, state_radio1, state_radio2);
	MessageBox(str, _T("알림"), MB_ICONINFORMATION);
}
