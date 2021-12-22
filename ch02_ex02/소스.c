#include<stdio.h>
#pragma warning (disable : 4996)
/*
%[^\n]s << 공백까지 포함하여 입력받기
*/
void main() {
	char str[100];
	printf("Plz input your text : ");	//
	scanf("%[^\n]s", str);				// 공백까지 포함하여 입력받기
	printf("your text is : %s", str);	// 문자열 출력
}