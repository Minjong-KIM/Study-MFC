
// WorkerThreadView.cpp: CWorkerThreadView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "WorkerThread.h"
#endif

#include "WorkerThreadDoc.h"
#include "WorkerThreadView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWorkerThreadView

IMPLEMENT_DYNCREATE(CWorkerThreadView, CView)

BEGIN_MESSAGE_MAP(CWorkerThreadView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CWorkerThreadView 생성/소멸

CWorkerThreadView::CWorkerThreadView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CWorkerThreadView::~CWorkerThreadView()
{
}

BOOL CWorkerThreadView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CWorkerThreadView 그리기

void CWorkerThreadView::OnDraw(CDC* /*pDC*/)
{
	CWorkerThreadDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CWorkerThreadView 인쇄

BOOL CWorkerThreadView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CWorkerThreadView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CWorkerThreadView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CWorkerThreadView 진단

#ifdef _DEBUG
void CWorkerThreadView::AssertValid() const
{
	CView::AssertValid();
}

void CWorkerThreadView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWorkerThreadDoc* CWorkerThreadView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWorkerThreadDoc)));
	return (CWorkerThreadDoc*)m_pDocument;
}
#endif //_DEBUG


// CWorkerThreadView 메시지 처리기

#define LOOPCNT (200000)
#define DIVCNT (LOOPCNT/500)

UINT MyDraw(LPVOID arg)
{
	ThreadArg* pArg = (ThreadArg*)arg;
	CClientDC dc(pArg->pWnd);
	int x, y, i;
	CBrush brush1(RGB(255, 0, 0));
	CBrush brush2(RGB(0, 0, 255));

	switch (pArg->pos)
	{
	case 1:
		dc.SelectObject(&brush1);
		x = 50, y = 50;
		for (i = 0; i < LOOPCNT; i++) {
			int inc = i / DIVCNT;
			dc.Rectangle(x, y, x + inc, y + 20);
		}
		break;

	case 2:
		dc.SelectObject(&brush2);
		x = 50, y = 100;
		for (i = 0; i < LOOPCNT; i++) {
			int inc = i / DIVCNT;
			dc.Rectangle(x, y, x + inc, y + 20);
		}
		break;
	}
	return 0;
}


void CWorkerThreadView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	dc.SelectStockObject(WHITE_PEN);
	dc.SelectStockObject(WHITE_BRUSH);
	CRect rect;
	GetClientRect(&rect);
	dc.Rectangle(&rect);

	arg1.pWnd = this;
	arg1.pos = 1;
	pThread1 = AfxBeginThread(MyDraw, &arg1, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);

	arg2.pWnd = this;
	arg2.pos = 2;
	pThread2 = AfxBeginThread(MyDraw, &arg2, THREAD_PRIORITY_NORMAL, 0, CREATE_SUSPENDED);

	pThread1->ResumeThread();
	pThread2->ResumeThread();
}
