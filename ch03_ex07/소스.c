#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)
/* 
���� �����
*/
typedef struct student		// �л� ����ü ����
{
	char grade;
	int mid_term;
	int final_term;
	int attendance;
}STD;
int main()
{
	FILE* fp;	// ���� ������
	STD st;		// �л� ����ü
	fp = fopen("student.txt", "wt");	// �ؽ�Ʈ ���� ���� ����
	if (fp == NULL)
	{
		printf("Fail to open file\n");	// ���� ���� ������ ���
	}
	st.grade = 'B';
	st.mid_term = 56;
	st.final_term = 72;
	st.attendance = 10;		// ����ü �� ���� �ʱ�ȭ
	fprintf(fp, "grade is %c\n", st.grade);		//�ʱ�ȭ �� ������ �ؽ�Ʈ ���Ͽ� ���
	fprintf(fp, "mid_term is %d\n", st.mid_term);
	fprintf(fp, "final_term is %d\n", st.final_term);
	fprintf(fp, "attendance is %d\n", st.attendance);
	fclose(fp);
	return 0;
}