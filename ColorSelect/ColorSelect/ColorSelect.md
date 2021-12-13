# 컨텍스트 메뉴
1. 마우스 오른쪽을 클릭했을 때 열린다.
2. OnContextMenu() 를 정의 해줘야 한다.
3. CMenu::TrackPopupMenu() 함수로 컨텍스트 메뉴의 팝업메뉴를 정의한다.
# 시스템 메뉴
1. 시스템 메뉴를 변경하려면 GetSystemMenu(FALSE)를 초기상태로 돌리려면 GetSystemMenu(TRUE)를 호출한다.
2. 시스템 메뉴 항목을 선택하면 WM_COMMAND 가 아니라 WM_SYSCOMMAND메시지가 발생한다.