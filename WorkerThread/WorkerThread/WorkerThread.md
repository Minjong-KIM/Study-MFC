# ��Ƽ ������
�������α׷��� ���� ���� �����带 ���ÿ� �����ϴ� ��. ������� CPU �ð��� �Ҵ�޾� ����Ǵ� ������ �����̴�. ���� ���� �����尡 �� ���� CPU���� ���ÿ� ����Ƿ��� �������� �����尡 ����(SUSPEND)�ϰ� ���¸� �����ϴ� �۾��� ���� ������ �������� ���¸� �����ϴ� �۾��� ���� ������Ѵ�.
# CPU �����ٸ�
1. �켱���� Ŭ���� -> ���� ���μ����� ������ ������� ��� ������ �켱������ ������.
2. �켱���� ���� -> ���� ���μ����� ���� ������ �� ����� �켱������ �����Ѵ�.
# ������ ����ȭ
��Ƽ �����带 ����ϴ� ���α׷����� �� �� �̻��� �����尡 ���� �����Ϳ� �����ϸ� ������ �߻��� �� �ִµ� �̷� ������ �ذ��ϴ� ���� ������ ����ȭ�� �θ���.
# �۾��� ������
�޽��� ������ ���� ȭ�鿡 ������ �ʴ� ��׶��� �۾��� �����ϴ�.
## CWinTread* AfxBeginThread(�����Լ�, ���� �Լ� ����� ������ ��, ������ �켱����,���� ������, ������ ���� ���� �ɼ�, ���ȼ�����)
1. ���� �Լ� -> �����带 �����ϴ� �������� �Ǵ� �Լ��� ����Ű�� �����ͷ�" UINT �Լ���" ���¿��� �Ѵ�.
2. ���� �Լ� ����� ������ �� ->���� �Լ��� ������ ũ���� �� �ϳ��� ���� �� �ִ�.
3. ������ �켱���� -> ex) THREAD_PRIORITY_NORMAL
4. ������ ���� ���� �ɼ� ->ex) CREATE_SUSPENDED �� ������ ������ �ٷ� ������� �ʴ´�.