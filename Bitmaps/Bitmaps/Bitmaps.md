# Bitmap
# 비트맵 출력
1. CDC::CreateCompatibleDC() 함수로 메모리 DC를 만든다.
2. CDC::SelectObject() 함수로 비트맵을 메모리 DC에 선택한다.
3. CDC::BitBlt() 나 CDC::StretchBlt() 함수로 화면에 출력한다. Blt (Block Transfer)는 비트맵 데이터를 블록 단위로 고속 전송한다는 의미이다.