#include <Windows.h>
#include <stdio.h>
int main()
{
	POINT a;
	while (1)
	{
		GetCursorPos(&a);	// 마우스의 좌표를 POINT에 가져옴
		printf("X = %d , Y = %d\n", a.x, a.y);	// 실시간으로 마우스좌표 출력
	}
	return 0;
}