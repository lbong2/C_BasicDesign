#include <Windows.h>
#include <stdio.h>
int main()
{
	int i;
	for (i = 0; i < 500; i++)
	{
		SetCursorPos(i, i);	// 커서를 해당 좌표로 이동
		Sleep(5);			// 5ms 동안 프로그램 일시정지
	}
	return 0;
}
