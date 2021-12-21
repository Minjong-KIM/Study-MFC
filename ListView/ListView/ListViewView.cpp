
// ListViewView.cpp: CListViewView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ListView.h"
#endif

#include "ListViewDoc.h"
#include "ListViewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CListViewView

IMPLEMENT_DYNCREATE(CListViewView, CListView)

BEGIN_MESSAGE_MAP(CListViewView, CListView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CListView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CListViewView 생성/소멸

CListViewView::CListViewView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CListViewView::~CListViewView()
{
}

BOOL CListViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.
	cs.style &= ~LVS_TYPEMASK;
	cs.style |= LVS_REPORT;

	return CListView::PreCreateWindow(cs);
}


void CListViewView::OnDraw(CDC* /*pDC*/)
{
	CListViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


void CListViewView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();


	// TODO: GetListCtrl()을 호출하여 해당 list 컨트롤을 직접 액세스함으로써
	//  ListView를 항목으로 채울 수 있습니다.

	CImageList illarge, ilsmall;
	illarge.Create(32, 32, ILC_COLOR4, 1, 1);
	ilsmall.Create(16, 16, ILC_COLOR4, 1, 1);
	illarge.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	ilsmall.Add(AfxGetApp()->LoadIcon(IDI_ICON1));

	CListCtrl& list = GetListCtrl();
	list.SetImageList(&illarge, LVSIL_NORMAL);
	list.SetImageList(&ilsmall, LVSIL_SMALL);
	illarge.Detach();
	ilsmall.Detach();

	list.InsertColumn(0, _T("상품명"), LVCFMT_LEFT, 100, 0);
	list.InsertColumn(0, _T("가격"), LVCFMT_LEFT, 100, 2);
	list.InsertColumn(0, _T("수량"), LVCFMT_LEFT, 100, 1);

	CListViewDoc* pDoc = GetDocument();
	CString str;

	for (int i = 0; i < NUMITEM; i++) {
		list.InsertItem(i, pDoc->m_item[i].name, 0);

		str.Format(_T("%d"), pDoc->m_item[i].price);
		list.SetItemText(i, 1, str);
		str.Format(_T("%d"), pDoc->m_item[i].quantity);
		list.SetItemText(i, 2, str);

	}
}


// CListViewView 인쇄

BOOL CListViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CListViewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CListViewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CListViewView 진단

#ifdef _DEBUG
void CListViewView::AssertValid() const
{
	CListView::AssertValid();
}

void CListViewView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CListViewDoc* CListViewView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CListViewDoc)));
	return (CListViewDoc*)m_pDocument;
}
#endif //_DEBUG


// CListViewView 메시지 처리기
