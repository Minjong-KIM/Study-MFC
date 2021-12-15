# 스크롤바 컨트롤
HSCROLL과 VSCROLL이 있다. 사용자가 스크롤바를 조작하면 WM_HSCROLL 또는 WM_VSCROLL 메시지가 발생한다.
# 스크롤바 코드
THUMTRACK, PageUp/down, LineUp/down으로 총 5가지가 있다. THUMTRACK의 경우 스크롤 박스를 마우스로 끌고 있을 때 계속 발생한다.
# On*Scroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
1. nSBCode -> 스크롤바 코드
2. 스크롤 박스의 위치로 스크롤바 코드가 THUMTRACK일 때만 의미가 있다.
3. pScrollBar -> WM_*SCROLL 메시지가 스크롤바 컨트롤에서 발생한 것이면 pScrollBar는 해당 스크롤 바 컨트롤을 조작하는 CScroll 객체를 가리키지만, WM_*SCROLL 메시지가 윈도우 스크롤에서 발생한 것이면 pScrollBar는 NULL값이다.