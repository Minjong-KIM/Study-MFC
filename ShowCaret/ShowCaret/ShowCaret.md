# Keyboard
1. Ű���� �޽����� Ű���� ��Ŀ���� ���� �����찡 �޴´�.
2. Ű���� ��Ŀ�� ǥ�ø� �����쿡�� ĳ������ ǥ���Ѵ�.
3. Ű���� ��Ŀ���� ���� �����쿡 WM_SETFOCUS�� ������, ���� �����쿡 WM_KILLFOCUS�޽����� ������.
# KeyStroke Message
1. WM_KEYDOWN
2. WM_KEYUP
3. WM_SYSKEYDOWN
4. WM_SYSKEYUP
# KeyStroke Message Handler
1. On*(UINT nChar, UINT nRepCnt, UINT nFlags);
2. nChar -> Ű�� �Ҵ�� ���� Ű �ڵ尪���� VK_BACK, VK_TAB, VK_SHIFT, VK_LEFT(����Ű), '0'-'9', 'A'-'Z'�� �ִ�.
# ���� �޽���
Ű ���� �޽���(KeyStroke Message)�� ��� Ű�� �������� �Ǵ��� ���� ����������, ���� Ű�� �ش��ϴ� ���ڴ� �˱� ��ƴ�. �׷��� ������ �ü���� Ű�� ������ �� Ű ���� �޽����� ���Ҿ� ���� �޽����� �߻���Ų��.