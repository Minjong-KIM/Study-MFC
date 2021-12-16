# Modeless Dialog
모드형 대화 상자 객체는 대개 스택에 생성하지만 비모드형 대화 상자 객체는 힙에 생성한다.
# 방법
1. DoModal() 함수 대신 Create() 함수를 이용해 생성한다.
2. EndDialog() 함수 대신 DestroyWindow() 함수를 사용한다.
# DDX (Dialog Data eXchange)
1. UpdateData (FALSE) : 멤버 변수 값으로 컨트롤을 초기화
2. UpdateData (TRUE) : 컨트롤 값을 멤버 변수로 저장
# 공용 대화 상자
1. CFileDialog(TRUE) -> 열기 대화 상자가 열린다.
2. CFileDialog(FALSE) -> 저장하기 대화 상자가 열린다.
3. CFontDialog -> 폰트를 지정하는 대화 상자가 열린다.