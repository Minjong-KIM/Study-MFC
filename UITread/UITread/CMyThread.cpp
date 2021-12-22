// CMyThread.cpp: 구현 파일
//

#include "pch.h"
#include "UITread.h"
#include "CMyThread.h"
#include "CMyWnd.h"

// CMyThread

IMPLEMENT_DYNCREATE(CMyThread, CWinThread)

CMyThread::CMyThread()
{
}

CMyThread::~CMyThread()
{
}

BOOL CMyThread::InitInstance()
{
	CRuntimeClass* pRuntimeClass = RUNTIME_CLASS(CMyWnd);
	CObject* pObject = pRuntimeClass->CreateObject();
	ASSERT(pObject->IsKindOf(RUNTIME_CLASS(CMyWnd)));

	m_pMainWnd = (CWnd*)pObject;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();


	return TRUE;
}

int CMyThread::ExitInstance()
{
	// TODO:  여기에서 각 스레드에 대한 정리를 수행합니다.
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CMyThread, CWinThread)
END_MESSAGE_MAP()


// CMyThread 메시지 처리기
