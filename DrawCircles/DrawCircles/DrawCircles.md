# ���콺
# �޽��� �ڵ鷯
1. On*(UINT nFlags, CPoint point)
2. nFlags -> �޽����� ������ �� Ű���峪 ���콺 ��ư�� ����
3. ex) MK_CONTROL, MK_SHIFT
4. point�� Ŀ���� ��ǥ
# ���콺 ĸó
1. ���콺 Ŀ���� ��ġ�� ������� ��� ���콺 �޽����� Ư�� �����쿡 ���޵ǰ� �Ѵ�.
2. SetCapture() �� ::ReleaseCapture() �Լ��� �̿��Ѵ�.
# ��Ŭ���̾�Ʈ ���� ���콺 �޽��� �ڵ鷯
1. OnNc*(UINT nHitTest, CPoint point)
2. nHitTest -> �޽����� ������ ����� ���콺 Ŀ���� ��ġ
3. ex) HTCLIENT, HTCLOSE
4. point�� Ŀ���� ��ǥ