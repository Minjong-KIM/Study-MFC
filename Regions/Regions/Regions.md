# Region
화면의 영역이다. 설정한 영역을 출력할 수도 있고, 화면에 출력을 제한할 수도 있다.
# 리전 객체 생성 
CRgn()
# 리전 초기화
CreateRectRgn() -> 직사각형 리전
CreateEllipticRgn(() -> 타원형 리전
CreateRoundRgn() -> 모서리가 둥근 직사각형 리전
CreatePolygonRgn() -> 다각형 리전
# 리전 결합
CombineRgn()
# 리전 테스트
PtInRegion() -> 점이 리전 내부에 있는지
RectInRegion() -> 직사각형이 리전 내부에 있는지
# 리전 자체 출력
CDC::FillRgn() -> 브러시로 리전 내부를 채운다.
CDC::PaintRgn() -> 브러시로 리전 내부를 채운다.
CDC::FrameRgn() -> 브러시로 리전 테두리를 그린다.
CDC::InvertRgn() -> 리전 내부 색상을 반전.
# 화면 출력 제한
CWnd::InvalidateRgn() -> 클라이언트 영역에서 리전이 나타내는 부분 무효화.
CDC::SelectClipRgn() -> DC로 출력하는 내용을 리전 내부로 제한한다.
CWnd::SetWindowRgn() -> 윈도우가 화면에 보이는 영역을 리전 내부로 제한한다.