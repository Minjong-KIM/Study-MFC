# �̹��� ����Ʈ
ũ�Ⱑ ������ �̹����� ��������, ������ �̹����� �迭 ���ó�� ����� 0���� ������ �ε����� ������ �� �ִ�. ������ �������� ��Ʈ���̳� �������� ����� �� �����ϴ�.
# �̹��� ����Ʈ ����
1. CImageList::Create(int cx, int cy, UINT nFlags, int nInitial, int nGrow)
2. CImageList::Create(UINT nBitmapID, int cx, int nGrow, COLORREF crMask)
3. cx, cy -> �̹��� ���� ����.
4. nFlags -> �̹��� ����Ʈ Ÿ������ ���� �����̴�. ex) ILC_COLOR4
5. nInitial -> �̹��� ����Ʈ �ʱ⿡ ������ �̹��� ����
6. nGrow -> �̹��� ����Ʈ�� ���� �� ���¿��� �� �̹��� �߰��� �߰� �������� ����
7. crMask -> ��������� ����� ���� ����
# �̹��� �߰�
1. CImageList::Add(HICON hIcon)
2. CImageList::Add(CBitmap* pbmImage, COLORREF crMask)
# ���
CImageList::Draw(CDC* pDC, int nImage, POINT pt, UINT nStyle)
1. nImage -> �̹����� �ε���
2. nStyle -> ��Ÿ��. ex) ILD_BLEND25, ILD_NORMAL, ILD_TRANSPARENT, ILD_MASK