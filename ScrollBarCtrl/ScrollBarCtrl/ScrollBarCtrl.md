# ��ũ�ѹ� ��Ʈ��
HSCROLL�� VSCROLL�� �ִ�. ����ڰ� ��ũ�ѹٸ� �����ϸ� WM_HSCROLL �Ǵ� WM_VSCROLL �޽����� �߻��Ѵ�.
# ��ũ�ѹ� �ڵ�
THUMTRACK, PageUp/down, LineUp/down���� �� 5������ �ִ�. THUMTRACK�� ��� ��ũ�� �ڽ��� ���콺�� ���� ���� �� ��� �߻��Ѵ�.
# On*Scroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
1. nSBCode -> ��ũ�ѹ� �ڵ�
2. ��ũ�� �ڽ��� ��ġ�� ��ũ�ѹ� �ڵ尡 THUMTRACK�� ���� �ǹ̰� �ִ�.
3. pScrollBar -> WM_*SCROLL �޽����� ��ũ�ѹ� ��Ʈ�ѿ��� �߻��� ���̸� pScrollBar�� �ش� ��ũ�� �� ��Ʈ���� �����ϴ� CScroll ��ü�� ����Ű����, WM_*SCROLL �޽����� ������ ��ũ�ѿ��� �߻��� ���̸� pScrollBar�� NULL���̴�.