#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable : 4996)
#define MAX 100
int charCnt(unsigned char* str) {	// 문자열의 글자 개수를 리턴하는 함수
	int len = 0;
	int spaceNum = 0;
	int punc = 0;
	while (str[len] != '\0')		// 문자열 마지막(널문자)이 아니라면,
	{
		
		++len;						// 문자열 길이 증가 (사실상 index)
	}
	return len;	// 문자열 길이에 공백과 문장부호를 뺀 값 리턴
}
int wordCnt(unsigned char* str) {	// 문자열의 단어 개수를 리턴하는 함수
	int len = 0;
	int spaceNum = 0;

	while (str[len] != '\0')		// 문장이 끝이나지 않았다면,
	{
		while (str[len] == ' ') {
			spaceNum++;				// 해당index의 값이 공백일 경우 spaceNum증가
			break;
		}
		++len;
	}
	return spaceNum + 1;			// sapceNum + 1은 단어 개수와 같다.
}
int sentenceCnt(unsigned char* str) {
	int len = 0;					// 문장 개수를 리턴하는 함수
	int sen_cnt = 0;
	while (str[len] != '\0')		// 문자열이 끝나지 않았다면,
	{
		while (str[len] == '!' || str[len] == '.' || str[len] == '?') {
			sen_cnt++;				// 해당 index의 값이 문장부호라면 문장개수 증가
			break;
		}
		++len;
	}
	return sen_cnt;					// 문장개수 리턴
}
void analyzesen(unsigned char* str, char* buf1[]) {
	
	char* buf = (char*)malloc(sizeof(char) * 100);
	int i = 0;
	while (*str = '\0')
	{
		if (*str == '!' || *str == '.' || *str == '?')
			continue;
		
		*buf++ = *str++; 
		
		if (*str == ' ')
		{
			*buf = '\0';
			buf1[i] = buf;
			i++;
			buf = (char*)malloc(sizeof(char) * 100);
		}
		

	}
}
void main() {
	FILE* fp;
	fp = fopen("inputfile.txt", "r");
	unsigned char* str;
	str = (char*)malloc(sizeof(char) * 300);
	char** buf;
	char temp[10];
	fscanf(fp, "%[^\n]s", str);
	
	int charNum, wordNum, sentenceNum;					
	charNum = charCnt(str);								
	wordNum = wordCnt(str);								
	sentenceNum = sentenceCnt(str);						
	buf = (char**)malloc(sizeof(char*) * wordNum);
	for (int i = 0; i < wordNum; i++) {
		buf[i] = (char*)malloc(sizeof(char) * 10);
	}
	

	fclose(fp);
	for (int i = 0; i < wordNum; i++)
	{
		for (int j = i + 1; j < wordNum; j++) {
			if (strcmp(*(buf + i), *(buf + j)) == 1)	// strcmp 를 이용해서 배열 전체 확인
			{									// 여기서 j는 선행 index로 j에 있는 word가 아스키코드상으로 작은 값이라면 
				strcpy(temp, *(buf + i));	// j의 word와 i의 word 를 바꾼다.
				strcpy(*(buf + i), *(buf + j));
				strcpy(*(buf + j), temp);
			}
		}
	}
	
	fp = fopen("201711242.txt", "w");
	fprintf(fp, "test i inputfile.txt o 201711242.txt\n");
	fprintf(fp, "char num : %d\nword Num : %d\nsentenceNum : %d\n", charNum, wordNum, sentenceNum);
	fclose(fp);
	for (int i = 0; i < wordNum; i++)
	{
		fprintf(fp, "%s\n", *(buf + i));
	}
	fclose(fp);
	free(str);
}