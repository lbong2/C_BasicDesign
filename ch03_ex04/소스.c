#include <stdio.h>
/*
�ƱԸ�Ʈ Ȯ�� �� �� ����
*/
int main(int argc, char* argv[])
{
	int fi;
	printf("main function get %d argv\n" // arg ���� ���
		, argc);
	for (fi = 0; fi < argc; fi++)		// �ݺ����� ���� �����Լ��� ���޵� ���� ���
	{
		printf("argv[%d] : %s\n", fi, argv[fi]);
	}
}