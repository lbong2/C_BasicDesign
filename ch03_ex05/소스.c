#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning (disable : 4996)
/*
동적할당
*/
int main()
{
	int fi;
	int* ptr = NULL;
	int size = 0;
	srand((unsigned)time(NULL));		// rand() 생성
	while (size <= 0)
	{
		printf("size for memory : ");	// 동적할당 받을 메모리 크기를 입력
		scanf("%d", &size);
		if (size <= 0)
			printf("\n size must be bigger than 0\n");	// 음수 혹은 0 입력시 재입력
	}
	ptr = (int*)malloc(size * sizeof(int));		// malloc을 통해 동적할당 (malloc의 반환값이 void*이기때문에 int*로 초기화)
		if (ptr == NULL)
		{
			printf("FAIL : CANNOT ASSIGN!!\n");
			return -1;
		}
	for (fi = 0; fi < size; fi++)
	{
		ptr[fi] = rand() % 101;
			printf("ptr[%3d] = %3d\n", fi, ptr[fi]); // 동적할당 받은 공간에 입력한 난수 값을 출력
	}
	free(ptr);		// 할당받은 공간을 반환하는 코드	
	return 0;
}