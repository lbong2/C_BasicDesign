#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable : 4996)
/*
case1 : 화씨온도 출력
case2 : 문자열길이 출력
case3 : 덧셈 곱셈 계산기
case4 : 문자열 분석함수 (글자개수 단어개수 문장개수)
*/
void case1() {					// 화씨 온도를 출력하는 함수(예제)
	float fahr = 0, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	while (fahr <= upper) {
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("fhar = %3.0f  celsius = %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}

int strlen(unsigned char str[]);
void case2() {					// 문자열 길이를 출력하는 함수(예제)
	int len;
	unsigned char *str = "Some where over the rainbow";

	printf("strlen = return length of string\n");
	printf("string = \"%s\"\n", str);
	len = strlen(str);

	printf("strlen : %d\n", len);
	
}
int strlen(unsigned char str[]) {
	int i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return i;
}

int sumAB(int a, int b);
int mulAB(int a, int b);
void case3() {					// 덧셈, 곱셈 계산기(예제)
	int a, b, n, result;
	while (1) {
		printf("1: ADD, 2:MUL, 3:quit\n");
		scanf("%d", &n);
		if (n == 3)
			break;
		printf("a : ");
		scanf("%d", &a);
		printf("b : ");
		scanf("%d", &b);
		switch(n){
		case 1:
			result = sumAB(a, b);
			printf("%d + %d = %d\n\n", a, b, result);
			break;
		
		case 2:
			result = mulAB(a, b);
			printf("%d * %d = %d\n\n", a, b, result);
			break;
		default: break;
		}
		
	
	}
	
}
int sumAB(int a , int b){
	return a + b;
}
int mulAB(int a, int b) {
	return a * b;
}

int charCnt(unsigned char*);
int wordCnt(unsigned char*);
int sentenceCnt(unsigned char*);
void case4() {						// 문자열 분석 함수(위의 프로그램에서 서술)
	
	unsigned char* str = "I am a boy. You are a girl. What is your favorite food?";
	int charNum, wordNum, sentenceNum;
	charNum = charCnt(str);
	wordNum = wordCnt(str);
	sentenceNum = sentenceCnt(str);

	printf("string = \"%s\"\n", str);

	printf("char : %d\n", charNum);
	printf("word : %d\n", wordNum);
	printf("sentence : %d\n", sentenceNum);
}
int charCnt(unsigned char* str) {
	int len = 0;
	int spaceNum = 0;
	int punc = 0;
	while (str[len] != '\0')
	{
		if(str[len] == '!' || str[len] == '.' || str[len] == '?') 
			punc++;
		else if (str[len] == ' ') 
			spaceNum++;
		++len;
	}
	return len - spaceNum - punc;
}
int wordCnt(unsigned char* str) {
	int len = 0;
	int spaceNum = 0;
	
	while (str[len] != '\0')
	{	
		if (str[len] == ' ') 
			spaceNum++;
		++len;
	}
	return spaceNum + 1;
}
int sentenceCnt(unsigned char* str) {
	int len = 0;
	int sen_cnt = 0;
	while (str[len] != '\0')
	{
		if (str[len] == '!' || str[len] == '.' || str[len] == '?') 
			sen_cnt++;
		++len;
	}
	return sen_cnt;
}
/*int main() {				// switch~ case 형태로 짠 코드
	int n;
	printf("1: Fahr_convert, 2:StrLength, 3:Calculator, 4:AnalyzeStr\n");
	scanf("%d", &n);		// 메뉴의 숫자를 입력받아 해당 함수를 실행한다.

	switch (n) {			// 입력받은 n값에 따라 switch 문이 실행되어 
	case 1:					// 실행된다.
		case1();
		break;

	case 2:
		case2();
		break;

	case 3:
		case3();
		break;
	case 4:
		case4();
		break;
	default: break;
	}

	return 0;
}*/

int main() {				// if~else if 로 짠 코드
	int n;
	printf("1: Fahr_convert, 2:StrLength, 3:Calculator, 4:AnalyzeStr\n");
	scanf("%d", &n);

	if(n == 1)				// if문에 의해 입력받은 n값에 따라 각각의 함수가 실행된다. 
		case1();
	else if(n == 2)
		case2();
	else if(n == 3)
		case3();
	else if(n == 4)
		case4();

	return 0;
}