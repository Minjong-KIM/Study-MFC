# DrawLines
1. 현재 위치를 (x1, y1)으로 옮긴다. -> MoveTo()
2. 현재 위치에서 (x2, y2)까지 선을 그린다. ->LineTo()
3. 현재 위치(Current Position)은 dc(device context)의 속성 중 하나다.
4. LineTo() 함수는 (x2, y2) 까지 선을 그리고 현재 위치(x2, y2)를 리턴한다.
5. Polyline() 함수는 POINT 구조체 배열로 전달된 점들을 차례로 이어 선을 그린다.