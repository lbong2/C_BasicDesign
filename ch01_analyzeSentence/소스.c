#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable : 4996)

int charCnt(unsigned char*);		//
int wordCnt(unsigned char*);		//	
int sentenceCnt(unsigned char*);	// 함수 선언부
void main() {

	unsigned char* str = "I am a boy. You are a girl.";	// string 선언후 초기화
	int charNum, wordNum, sentenceNum;					// 각 문장성분 개수 변수선언
	charNum = charCnt(str);								// 
	wordNum = wordCnt(str);								//
	sentenceNum = sentenceCnt(str);						// 각 변수에 함수 리턴

	printf("string = \"%s\"\n", str);

	printf("char : %d\n", charNum);
	printf("word : %d\n", wordNum);
	printf("sentence : %d\n", sentenceNum);
}
int charCnt(unsigned char* str) {	// 문자열의 글자 개수를 리턴하는 함수
	int len = 0;
	int spaceNum = 0;
	int punc = 0;
	while (str[len] != '\0')		// 문자열 마지막(널문자)이 아니라면,
	{
		while (str[len] == '!' || str[len] == '.' || str[len] == '?') {
			punc++;					// 해당 index의 문자가 문장부호라면 punc의 개수 증가
			break;
		}
		while (str[len] == ' ') {
			spaceNum++;				// 해당 index의 문자가 공백문자라면 spaceNum증가
			break;
		}
		++len;						// 문자열 길이 증가 (사실상 index)
	}
	return len - spaceNum - punc;	// 문자열 길이에 공백과 문장부호를 뺀 값 리턴
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