#include <Windows.h>
#include <stdio.h>
int main()
{
	POINT a;
	while (1)
	{
		GetCursorPos(&a);	// ���콺�� ��ǥ�� POINT�� ������
		printf("X = %d , Y = %d\n", a.x, a.y);	// �ǽð����� ���콺��ǥ ���
	}
	return 0;
}