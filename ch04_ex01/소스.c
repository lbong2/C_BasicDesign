#include <Windows.h>
#include <stdio.h>
int main()
{
	int i;
	for (i = 0; i < 500; i++)
	{
		SetCursorPos(i, i);	// Ŀ���� �ش� ��ǥ�� �̵�
		Sleep(5);			// 5ms ���� ���α׷� �Ͻ�����
	}
	return 0;
}
