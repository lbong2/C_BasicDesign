#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)
/*
���� �����
*/
int main()
{
	FILE* fp;	// ���� ������ ����
	char* str = "The key to realizing a dream is to focus not on success but significance - and then even the small steps and little victories along your path will take on greater meaning.";
	char buf[200];
	int fi;
	fp = fopen("test_text.txt", "wt");	// ������ �ؽ�Ʈ ���� ���� ����.
	if (fp == NULL)
	{
		printf("Fail to open file\n");	// ���� ���� �� ���
		return -1;
	}
	fputc('T', fp);	// ���ʷ� ���ڸ� �Է��Ѵ�.
	fputc('E', fp);
	fputc('S', fp);
	fputc('T', fp);
	fputc('\n', fp);	// enter �Է�(�ٹٲ�)
	fputs(str, fp);		// str�Է�
	fclose(fp);			// ���� ����
	fp = fopen("test_text.txt", "rt"); // �ؽ�Ʈ �б���� �ٽ� ����.
	for (fi = 0; fi < 5; fi++)
	{
		printf("%c", fgetc(fp));		// 4������ ���ڸ� �ݺ����� ���� �о�´�.
	}
	fgets(buf, 200, fp);	// ���� ���ڿ������� fp�� �о�´�.
	printf("%s", buf);		// ���� ���

	/*close(fp);

	fp = fopen("test_text.txt", "wt"); */	// �ؽ�Ʈ ������� ���� ������ ����� �Է��ϹǷ� ������ �ʱ�ȭ�ȴ�. 

	fclose(fp);			// ���� ����
	return 0;
}