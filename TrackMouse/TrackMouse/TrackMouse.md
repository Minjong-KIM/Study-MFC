# TrackMouse
1. ::TrackMouseEvent() 함수는 마우스 커서가 윈도우 영역을 빠져나가는 시점을 알 수 있도록 운영체제에 요청을 하고 이때 WM_MOUSELEAVE가 발생한다.
2. ::TrackMouseEvent() 함수는 TRACKMOUSEEVENT 구조체를 초기화해서 전달해줘야 한다.