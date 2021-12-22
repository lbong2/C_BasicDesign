#include <stdio.h>
/*
아규먼트 확인 할 수 있음
*/
int main(int argc, char* argv[])
{
	int fi;
	printf("main function get %d argv\n" // arg 갯수 출력
		, argc);
	for (fi = 0; fi < argc; fi++)		// 반복문을 통해 메인함수로 전달된 정보 출력
	{
		printf("argv[%d] : %s\n", fi, argv[fi]);
	}
}