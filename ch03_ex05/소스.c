#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning (disable : 4996)
/*
�����Ҵ�
*/
int main()
{
	int fi;
	int* ptr = NULL;
	int size = 0;
	srand((unsigned)time(NULL));		// rand() ����
	while (size <= 0)
	{
		printf("size for memory : ");	// �����Ҵ� ���� �޸� ũ�⸦ �Է�
		scanf("%d", &size);
		if (size <= 0)
			printf("\n size must be bigger than 0\n");	// ���� Ȥ�� 0 �Է½� ���Է�
	}
	ptr = (int*)malloc(size * sizeof(int));		// malloc�� ���� �����Ҵ� (malloc�� ��ȯ���� void*�̱⶧���� int*�� �ʱ�ȭ)
		if (ptr == NULL)
		{
			printf("FAIL : CANNOT ASSIGN!!\n");
			return -1;
		}
	for (fi = 0; fi < size; fi++)
	{
		ptr[fi] = rand() % 101;
			printf("ptr[%3d] = %3d\n", fi, ptr[fi]); // �����Ҵ� ���� ������ �Է��� ���� ���� ���
	}
	free(ptr);		// �Ҵ���� ������ ��ȯ�ϴ� �ڵ�	
	return 0;
}