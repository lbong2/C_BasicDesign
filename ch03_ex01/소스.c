#include <stdio.h>

struct student	// 구조체 선언
{
	char grade;	// 구조체 내부 변수선언
	int mid_term;
	int final_term;
	int attendance;
};
void main()
{
	struct student std1;	// 구조체 변수 선언
	std1.grade = 'A';		// 구조체 내부 변수값 초기화
	std1.mid_term = 97;		//
	std1.final_term = 92;	//	
	std1.attendance = 10;	//
	printf("std1's grade is %c\n", std1.grade);		// 구조체 내부 변수 출력
	printf("std1's mid_term is %d\n", std1.mid_term);
	printf("std1's final_term is %d\n", std1.final_term);
	printf("std1's attendance is %d\n", std1.attendance);
}