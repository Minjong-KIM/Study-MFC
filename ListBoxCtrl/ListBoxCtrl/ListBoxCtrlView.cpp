
// ListBoxCtrlView.cpp: CListBoxCtrlView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ListBoxCtrl.h"
#endif

#include "ListBoxCtrlDoc.h"
#include "ListBoxCtrlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CListBoxCtrlView

IMPLEMENT_DYNCREATE(CListBoxCtrlView, CFormView)

BEGIN_MESSAGE_MAP(CListBoxCtrlView, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON1, &CListBoxCtrlView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CListBoxCtrlView::OnBnClickedButton2)
END_MESSAGE_MAP()

// CListBoxCtrlView 생성/소멸

CListBoxCtrlView::CListBoxCtrlView() noexcept
	: CFormView(IDD_LISTBOXCTRL_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CListBoxCtrlView::~CListBoxCtrlView()
{
}

void CListBoxCtrlView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list1);
	DDX_Control(pDX, IDC_LIST2, m_list2);
}

BOOL CListBoxCtrlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CListBoxCtrlView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_list1.AddString(_T("사과"));
	m_list1.AddString(_T("딸기"));
	m_list1.AddString(_T("파인애플"));
	m_list1.AddString(_T("복숭아"));
}


// CListBoxCtrlView 인쇄

BOOL CListBoxCtrlView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CListBoxCtrlView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CListBoxCtrlView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CListBoxCtrlView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// CListBoxCtrlView 진단

#ifdef _DEBUG
void CListBoxCtrlView::AssertValid() const
{
	CFormView::AssertValid();
}

void CListBoxCtrlView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CListBoxCtrlDoc* CListBoxCtrlView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CListBoxCtrlDoc)));
	return (CListBoxCtrlDoc*)m_pDocument;
}
#endif //_DEBUG


// CListBoxCtrlView 메시지 처리기


void CListBoxCtrlView::OnBnClickedButton1()
{
	int index = m_list1.GetCurSel();
	if (index != LB_ERR) {
		CString str;
		m_list1.GetText(index, str);
		m_list1.DeleteString(index);
		m_list1.SetCurSel(index);
		m_list2.AddString(str);
	}
}


void CListBoxCtrlView::OnBnClickedButton2()
{
	int index = m_list2.GetCurSel();
	if (index != LB_ERR) {
		CString str;
		m_list2.GetText(index, str);
		m_list2.DeleteString(index);
		m_list2.SetCurSel(index);
		m_list1.AddString(str);
	}
}
