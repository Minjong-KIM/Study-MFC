# 트리 뷰
트리 컨트롤을 이용해 뷰의 기능을 제공한다.
# 사용
1. CTreeCtrl * = GetTreeCtrl() -> 트리 컨트롤 객체에 대한 레퍼런스를 얻는다.
2. CImageList 객체를 선언하고 이미지 리스트를 초기화 한다.
3. CTreeCtrl::SetImageList() 함수로 트리 컨트롤에서 사용할 이미지 리스트를 설정한다.
4. CTreeCtrl::InsertItem() 함수로 항목을 추가한다. -> 루트 항목(최 상위 항목)의 경우 부모 항목 자리에 TVI_ROOT를 넣는다. 또한 하위 항목을 가지는 항목을 작성할 땐 HTREEITEM 타입의 데이터를 받아줘야 한다.