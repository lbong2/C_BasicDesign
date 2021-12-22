#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#define BUF_SIZE 100
int main()
{
	FILE* ori;
	FILE* cp;
	char buffer[BUF_SIZE];
	int count;

	ori = fopen("Logo.png", "rb");	// �������� ���� �б���� ����
	cp = fopen("copy.png", "wb");	// ī������ ������� ����
	if (ori == NULL || cp == NULL)	// ���� ���� �� ���
	{
		printf("Fail to open file\n");
		return -1;
	}
	while (1)
	{
		count = fread(buffer, 1, BUF_SIZE, ori); // �������� ���Ͽ��� ���۷� �����ͺ���� �о�´�.
		if (count < BUF_SIZE)	// count���� ���۰� ũ�ٸ�
		{
			if (feof(ori) != 0)	// ��Ʈ���� eof�� �˻��Ͽ� ����(set) �Ǿ� �ִٸ� 0 �� �ƴ� ���� �����Ѵ�.
			{			// ���� �ƴϴ� 0�� �ƴѰ��� �����Ѵ�.
				fwrite(buffer, 1, count, cp);	// �� �� 
				printf("Copy success!!\n");
				break;
			}
			else
			{
				printf("Copy FAIL!!\n");
				break;
			}
		}
		else
		{
			fwrite(buffer, 1, BUF_SIZE, cp);	// ���ۿ� �Էµ� ���� cp�� ����
		}
	}
	fclose(ori);
	fclose(cp);
	return 0;
}