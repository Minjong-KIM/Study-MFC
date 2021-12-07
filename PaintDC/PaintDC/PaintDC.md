# CObject
# CDC
	CPaintDC ->클라이언트 영역에 출력할 때 사용. WM_PAINT 메시지 핸들러에서만 사용한다.
	CClientDC -> 클라이언트 영역에 출력할 때 사용. WM_PAINT 메시지 핸들러를 제외한 다른 모든 곳에서 사용한다.
	CWindowDC -> 윈도우 전체 영역에 출력할 때 사용.
	CMetaFileDC -> 메타파일에 출력할 때 사용

WM_PAINT 메시지가 발생할 때마다 OnPaint() 함수가 호출되므로 윈도우 크기가 변경되거나 윈도우가 가려지는 상황에서도 출력 내용이 지워지지 않는다.