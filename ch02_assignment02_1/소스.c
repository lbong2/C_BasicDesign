#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable : 4996)
/*
사전순으로 단어출력하기
*/
/*int main() {				// 배열 사용 버전
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
int main() {				// 포인터 사용 버전
	char** wordBook;		// 이중포인터 선언
	char temp[11];			// 입력을 임시저장할 배열 선언
	int N;

	printf("Please input word number >> ");	// 입력할 단어 개수 입력
	scanf("%d", &N);

	wordBook = (char**)malloc(sizeof(char*) * N);	// 단어 개수만큼 (char*)형 공간 할당받기
	for (int i = 0; i < N; i++) {
		printf("Input word >> ");
		wordBook[i] = (char*)malloc(sizeof(char) * 11);	// 단어의 최대 길이가 10이므로 널문자 고려하여 *11만큼 공간할당받기
		scanf("%s", *(wordBook + i));					// 총 N * 11만큼의 공간 동적할당 후 각각의 공간에 단어 입력받기
	}

	for (int i = 0; i < N; i++)				
	{
		for (int j = i + 1; j < N; j++) {
			if (strcmp(*(wordBook + i), *(wordBook + j)) == 1)	// strcmp 를 이용해서 배열 전체 확인
			{									// 여기서 j는 선행 index로 j에 있는 word가 아스키코드상으로 작은 값이라면 
				strcpy(temp, *(wordBook + i));	// j의 word와 i의 word 를 바꾼다.
				strcpy(*(wordBook + i), *(wordBook + j));
				strcpy(*(wordBook + j), temp);
			}
		}
	}
	for (int i = 0; i < N; i++) {			// 정렬된 단어를 차례대로 출력한다.
		printf("%s\n", *(wordBook + i));
	}
	for (int i = 0; i < N; i++) {			// 동적 할당 받은 메모리를 반환한다.
		free(*(wordBook + i));
	}
	free(wordBook);		// 동적할당 받은 메모리를 반환한다. 
	return 0;
}