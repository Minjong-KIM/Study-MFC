# CWindowDC
1. CWindowDC 클래스는 윈도우 전체 영역에 출력할 때 사용한다.
2. CPaintDC, CClientDC 클래스와 기본 사용법은 같지만 좌표의 원점 위치가 다르다.
3. ::GetSystemMetrics() 함수를 이용해 SM_CYSIZE(타이틀바 높이)와 SM_CYSIZEFRAME(테두리 선 높이)를 얻을 수 있다.