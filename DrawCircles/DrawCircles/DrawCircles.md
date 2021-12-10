# 마우스
# 메시지 핸들러
1. On*(UINT nFlags, CPoint point)
2. nFlags -> 메시지가 생성될 때 키보드나 마우스 버튼의 상태
3. ex) MK_CONTROL, MK_SHIFT
4. point는 커서의 좌표
# 마우스 캡처
1. 마우스 커서의 위치와 관계없이 모든 마우스 메시지가 특정 윈도우에 전달되게 한다.
2. SetCapture() 과 ::ReleaseCapture() 함수를 이용한다.
# 비클라이언트 영역 마우스 메시지 핸들러
1. OnNc*(UINT nHitTest, CPoint point)
2. nHitTest -> 메시지가 생성될 당시의 마우스 커서의 위치
3. ex) HTCLIENT, HTCLOSE
4. point는 커서의 좌표