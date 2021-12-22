#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)
/* 
파일 입출력
*/
typedef struct student		// 학생 구조체 선언
{
	char grade;
	int mid_term;
	int final_term;
	int attendance;
}STD;
int main()
{
	FILE* fp;	// 파일 포인터
	STD st;		// 학생 구조체
	fp = fopen("student.txt", "wt");	// 텍스트 쓰기 모드로 오픈
	if (fp == NULL)
	{
		printf("Fail to open file\n");	// 열기 실패 했을시 경고문
	}
	st.grade = 'B';
	st.mid_term = 56;
	st.final_term = 72;
	st.attendance = 10;		// 구조체 각 변수 초기화
	fprintf(fp, "grade is %c\n", st.grade);		//초기화 한 변수를 텍스트 파일에 출력
	fprintf(fp, "mid_term is %d\n", st.mid_term);
	fprintf(fp, "final_term is %d\n", st.final_term);
	fprintf(fp, "attendance is %d\n", st.attendance);
	fclose(fp);
	return 0;
}