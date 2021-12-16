﻿// CMyDialog.cpp: 구현 파일
//

#include "pch.h"
#include "ModalDialog.h"
#include "CMyDialog.h"
#include "afxdialogex.h"


// CMyDialog 대화 상자

IMPLEMENT_DYNAMIC(CMyDialog, CDialog)

CMyDialog::CMyDialog(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CMyDialog, pParent)
{

}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FONT, m_combo);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialog)
	ON_BN_CLICKED(IDC_CLEAR, &CMyDialog::OnBnClickedClear)
END_MESSAGE_MAP()


// CMyDialog 메시지 처리기


void CMyDialog::OnBnClickedClear()
{
	EndDialog(IDC_CLEAR);
}


BOOL CMyDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetDlgItemText(IDC_STR, m_str);
	m_combo.SetCurSel(m_font);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CMyDialog::OnOK()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	GetDlgItemText(IDC_STR, m_str);
	m_font = m_combo.GetCurSel();

	CDialog::OnOK();
}
