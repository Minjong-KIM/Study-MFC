# 이미지 리스트
크기가 동일한 이미지의 집합으로, 각각의 이미지를 배열 요소처럼 취급해 0부터 시작해 인덱스로 참조할 수 있다. 때문에 여러개의 비트맵이나 아이콘을 사용할 때 유용하다.
# 이미지 리스트 생성
1. CImageList::Create(int cx, int cy, UINT nFlags, int nInitial, int nGrow)
2. CImageList::Create(UINT nBitmapID, int cx, int nGrow, COLORREF crMask)
3. cx, cy -> 이미지 폭과 높이.
4. nFlags -> 이미지 리스트 타입으로 색생 관련이다. ex) ILC_COLOR4
5. nInitial -> 이미지 리스트 초기에 포함할 이미지 개수
6. nGrow -> 이미지 리스트가 가득 찬 상태에서 새 이미지 추가시 추가 여유공간 개수
7. crMask -> 투명색으로 사용할 색상 지정
# 이미지 추가
1. CImageList::Add(HICON hIcon)
2. CImageList::Add(CBitmap* pbmImage, COLORREF crMask)
# 출력
CImageList::Draw(CDC* pDC, int nImage, POINT pt, UINT nStyle)
1. nImage -> 이미지의 인덱스
2. nStyle -> 스타일. ex) ILD_BLEND25, ILD_NORMAL, ILD_TRANSPARENT, ILD_MASK