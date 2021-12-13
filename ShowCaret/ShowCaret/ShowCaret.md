# Keyboard
1. 키보드 메시지는 키보드 포커스를 가진 윈도우가 받는다.
2. 키보드 포커스 표시를 윈도우에선 캐럿으로 표시한다.
3. 키보드 포커스를 얻은 윈도우에 WM_SETFOCUS를 보내고, 잃은 윈도우에 WM_KILLFOCUS메시지를 보낸다.
# KeyStroke Message
1. WM_KEYDOWN
2. WM_KEYUP
3. WM_SYSKEYDOWN
4. WM_SYSKEYUP
# KeyStroke Message Handler
1. On*(UINT nChar, UINT nRepCnt, UINT nFlags);
2. nChar -> 키에 할당된 가상 키 코드값으로 VK_BACK, VK_TAB, VK_SHIFT, VK_LEFT(방향키), '0'-'9', 'A'-'Z'가 있다.
# 문자 메시지
키 누름 메시지(KeyStroke Message)는 어느 키를 눌렀는지 판단할 때는 유용하지만, 누른 키에 해당하는 문자는 알기 어렵다. 그래서 윈도우 운영체제는 키를 눌렀을 때 키 누름 메시지와 더불어 문자 메시지를 발생시킨다.