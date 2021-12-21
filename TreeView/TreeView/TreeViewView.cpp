
// TreeViewView.cpp: CTreeViewView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "TreeView.h"
#endif

#include "TreeViewDoc.h"
#include "TreeViewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTreeViewView

IMPLEMENT_DYNCREATE(CTreeViewView, CTreeView)

BEGIN_MESSAGE_MAP(CTreeViewView, CTreeView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTreeView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CTreeViewView 생성/소멸

CTreeViewView::CTreeViewView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CTreeViewView::~CTreeViewView()
{
}

BOOL CTreeViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CTreeView::PreCreateWindow(cs);
}


void CTreeViewView::OnDraw(CDC* /*pDC*/)
{
	CTreeViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


void CTreeViewView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	CImageList il;
	il.Create(IDB_BITMAP1, 16, 1, RGB(255, 255, 255));

	CTreeCtrl& tree = GetTreeCtrl();
	tree.SetImageList(&il, TVSIL_NORMAL);
	il.Detach();

	HTREEITEM hSun = tree.InsertItem(_T("태양"), 0, 0, TVI_ROOT, TVI_LAST);

	HTREEITEM hPlanet[8];
	CString planet[] = {
		_T("수성"),_T("금성"),_T("지구"),_T("화성"),_T("목성"),_T("토성"),_T("천왕성"),_T("해왕성")
	};
	for (int i = 0; i < 8; i++) {
		hPlanet[i] = tree.InsertItem(planet[i], 1, 1, hSun, TVI_LAST);
	}

	tree.InsertItem(_T("달"), 2, 2, hPlanet[2], TVI_LAST);
	tree.InsertItem(_T("포보스"), 2, 2, hPlanet[3], TVI_LAST);
	tree.InsertItem(_T("데이모스"), 2, 2, hPlanet[3], TVI_LAST);
	tree.InsertItem(_T("이오"), 2, 2, hPlanet[4], TVI_LAST);
	tree.InsertItem(_T("에우로파"), 2, 2, hPlanet[4], TVI_LAST);
	tree.InsertItem(_T("가니메데"), 2, 2, hPlanet[4], TVI_LAST);
	tree.InsertItem(_T("칼리스토"), 2, 2, hPlanet[4], TVI_LAST);
}


// CTreeViewView 인쇄

BOOL CTreeViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CTreeViewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CTreeViewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CTreeViewView 진단

#ifdef _DEBUG
void CTreeViewView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CTreeViewView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CTreeViewDoc* CTreeViewView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTreeViewDoc)));
	return (CTreeViewDoc*)m_pDocument;
}
#endif //_DEBUG


// CTreeViewView 메시지 처리기
