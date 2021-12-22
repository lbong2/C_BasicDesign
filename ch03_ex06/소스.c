#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)
/*
파일 입출력
*/
int main()
{
	FILE* fp;	// 파일 포인터 선언
	char* str = "The key to realizing a dream is to focus not on success but significance - and then even the small steps and little victories along your path will take on greater meaning.";
	char buf[200];
	int fi;
	fp = fopen("test_text.txt", "wt");	// 파일을 텍스트 쓰기 모드로 연다.
	if (fp == NULL)
	{
		printf("Fail to open file\n");	// 오픈 실패 시 경고문
		return -1;
	}
	fputc('T', fp);	// 차례로 문자를 입력한다.
	fputc('E', fp);
	fputc('S', fp);
	fputc('T', fp);
	fputc('\n', fp);	// enter 입력(줄바꿈)
	fputs(str, fp);		// str입력
	fclose(fp);			// 파일 닫음
	fp = fopen("test_text.txt", "rt"); // 텍스트 읽기모드로 다시 연다.
	for (fi = 0; fi < 5; fi++)
	{
		printf("%c", fgetc(fp));		// 4글자의 문자를 반복문을 통해 읽어온다.
	}
	fgets(buf, 200, fp);	// 버퍼 문자열변수에 fp를 읽어온다.
	printf("%s", buf);		// 버퍼 출력

	/*close(fp);

	fp = fopen("test_text.txt", "wt"); */	// 텍스트 쓰기모드는 안의 내용을 지운뒤 입력하므로 파일이 초기화된다. 

	fclose(fp);			// 파일 닫음
	return 0;
}