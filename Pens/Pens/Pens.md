# CObject
# CGdiObject
1. CPen
2. CBrush
3. CBitmap
4. CFont
5. CPalette
6. CRgn
GDI 객체를 생성하고 CDC:: SelectObject() 함수에 전달하여 DC에 선택한다. 리턴 값은 이전의 GDI 객체 주소로, 복원을 위해 임시 변수에 저장해 둔다.

# 펜 종류
1. PS_SOLID
2. PS_DASH
3. PS_DOT
4. PS_DASHDOT
5. PS_DASHDOTDOT
6. PS_NULL
7. PS_INSIDEFRAME -> 도형의 외곽선 안쪽으로만 선이 확장된다.