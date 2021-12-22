#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable : 4996)
/*
���������� �ܾ�����ϱ�
*/
/*int main() {				// �迭 ��� ����
	char** wordBook;
	char temp[11];
	int N;

	printf("Please input word number >> ");
	scanf("%d", &N);

	wordBook = (char**)malloc(sizeof(char*) * N);
	for (int i = 0; i < N; i++) {
		printf("Input word >> ");
		wordBook[i] = (char*)malloc(sizeof(char) * 11 );
		scanf("%s", wordBook[i]);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++) {
			if (strcmp(wordBook[i], wordBook[j]) == 1)
			{
				strcpy(temp, wordBook[i]);
				strcpy(wordBook[i], wordBook[j]);
				strcpy(wordBook[j], temp);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		printf("%s\n", wordBook[i]);
	}
	for (int i = 0; i < N; i++) {
		free(wordBook[i]);
	}
	free(wordBook);
	return 0;
}*/
int main() {				// ������ ��� ����
	char** wordBook;		// ���������� ����
	char temp[11];			// �Է��� �ӽ������� �迭 ����
	int N;

	printf("Please input word number >> ");	// �Է��� �ܾ� ���� �Է�
	scanf("%d", &N);

	wordBook = (char**)malloc(sizeof(char*) * N);	// �ܾ� ������ŭ (char*)�� ���� �Ҵ�ޱ�
	for (int i = 0; i < N; i++) {
		printf("Input word >> ");
		wordBook[i] = (char*)malloc(sizeof(char) * 11);	// �ܾ��� �ִ� ���̰� 10�̹Ƿ� �ι��� ����Ͽ� *11��ŭ �����Ҵ�ޱ�
		scanf("%s", *(wordBook + i));					// �� N * 11��ŭ�� ���� �����Ҵ� �� ������ ������ �ܾ� �Է¹ޱ�
	}

	for (int i = 0; i < N; i++)				
	{
		for (int j = i + 1; j < N; j++) {
			if (strcmp(*(wordBook + i), *(wordBook + j)) == 1)	// strcmp �� �̿��ؼ� �迭 ��ü Ȯ��
			{									// ���⼭ j�� ���� index�� j�� �ִ� word�� �ƽ�Ű�ڵ������ ���� ���̶�� 
				strcpy(temp, *(wordBook + i));	// j�� word�� i�� word �� �ٲ۴�.
				strcpy(*(wordBook + i), *(wordBook + j));
				strcpy(*(wordBook + j), temp);
			}
		}
	}
	for (int i = 0; i < N; i++) {			// ���ĵ� �ܾ ���ʴ�� ����Ѵ�.
		printf("%s\n", *(wordBook + i));
	}
	for (int i = 0; i < N; i++) {			// ���� �Ҵ� ���� �޸𸮸� ��ȯ�Ѵ�.
		free(*(wordBook + i));
	}
	free(wordBook);		// �����Ҵ� ���� �޸𸮸� ��ȯ�Ѵ�. 
	return 0;
}