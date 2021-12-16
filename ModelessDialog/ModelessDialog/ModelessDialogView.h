
// ModelessDialogView.h: CModelessDialogView 클래스의 인터페이스
//

#pragma once
class CMyDialog;

class CModelessDialogView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CModelessDialogView() noexcept;
	DECLARE_DYNCREATE(CModelessDialogView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MODELESSDIALOG_FORM };
#endif

// 특성입니다.
public:
	CModelessDialogDoc* GetDocument() const;
	CMyDialog* m_pDlg;
	CString m_str;
	int m_font;
// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CModelessDialogView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual void OnDraw(CDC* /*pDC*/);
};

#ifndef _DEBUG  // ModelessDialogView.cpp의 디버그 버전
inline CModelessDialogDoc* CModelessDialogView::GetDocument() const
   { return reinterpret_cast<CModelessDialogDoc*>(m_pDocument); }
#endif

