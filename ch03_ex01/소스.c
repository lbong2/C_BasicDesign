#include <stdio.h>

struct student	// ����ü ����
{
	char grade;	// ����ü ���� ��������
	int mid_term;
	int final_term;
	int attendance;
};
void main()
{
	struct student std1;	// ����ü ���� ����
	std1.grade = 'A';		// ����ü ���� ������ �ʱ�ȭ
	std1.mid_term = 97;		//
	std1.final_term = 92;	//	
	std1.attendance = 10;	//
	printf("std1's grade is %c\n", std1.grade);		// ����ü ���� ���� ���
	printf("std1's mid_term is %d\n", std1.mid_term);
	printf("std1's final_term is %d\n", std1.final_term);
	printf("std1's attendance is %d\n", std1.attendance);
}