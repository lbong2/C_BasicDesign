#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
����ü �迭
*/
typedef struct student		// ����ü ����(STD�� ����)
{
	char grade;
	int mid_term;
	int final_term;
	int attendance;
}STD;
int main()
{
	STD student[10];
	int fi;
	int sum;
	srand((unsigned)time(NULL));	//	���� = rand() ����
	for (fi = 0; fi < 10; fi++)
	{
		student[fi].mid_term = rand() % 46;		// ����ü ���κ����� ������ �ʱ�ȭ
		student[fi].final_term = rand() % 46;	//
		student[fi].attendance = rand() % 11;	//
		sum = student[fi].mid_term + student[fi].final_term + student[fi].attendance;
		if (sum > 80)
			student[fi].grade = 'A';			// �հ������� ���� ���� ��޺ο�
		else if (sum > 70)
			student[fi].grade = 'B';
		else if (sum > 60)
			student[fi].grade = 'C';
		else if (sum > 50)
			student[fi].grade = 'D';
		else
			student[fi].grade = 'F';
		printf("student %d's grade is %c\n", fi, student[fi].grade);
		printf("student %d's total grade is %d\n\n", fi, sum);
	}
}