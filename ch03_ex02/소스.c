#include <stdio.h>
typedef struct student		// ����ü ����� ���ÿ� typedef�� ����� ����(STD)
{
	char grade;
	int mid_term;
	int final_term;
	int attendance;
}STD;
//typedef struct student STD;	// ����� �����ϴ� �ٸ����

int main()
{
	STD std1;
	std1.grade = 'A';
	std1.mid_term = 97;
	std1.final_term = 92;
	std1.attendance = 10;
	printf("std1's grade is %c\n", std1.grade);
	printf("std1's mid_term is %d\n", std1.mid_term);
	printf("std1's final_term is %d\n", std1.final_term);
	printf("std1's attendance is %d\n", std1.attendance);
}