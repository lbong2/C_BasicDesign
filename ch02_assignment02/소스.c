#include<stdio.h>
#pragma warning (disable : 4996)
/*
입력받은 문자열 공백개수 출력
*/
#define INDEX 1001			// 최대 1000자를 받을 수 있어야 하기때문에 ('\0')
int main() {
	char str[INDEX];
	int spaceNum = 0;
	int i = 0;
	printf("Plz Input your text >> ");
	scanf("%[^\n]s", &str);	// 공백 포함 입력 받음

	while (str[i] != '\0') {// 배열은 NULL문자를 포함해 입력한 문자열 +1 만큼 필요함 
		if (str[i] == ' ')	// 배열에 공백이 있다면		
			spaceNum++;		// 공백 개수 값을 증가
		i++;
	}
	printf("%s have %d space\n", str, spaceNum); // 공백 개수 출력
	return 0;
}
