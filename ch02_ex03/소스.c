#include<stdio.h>
/*
�� ����Ÿ�Ժ� ���
*/
void main() {
	int a = 10;
	double b = 7.25;

	int *pt_a;
	double *pt_b;

	pt_a = &a;		// 
	pt_b = &b;		// ���� ������ ������ �ʱ�ȭ

	printf("sizeof(pt_a) = %d\n", sizeof(pt_a));	// ������ ������ ũ�⸦ ��� 
	printf("sizeof(pt_b) = %d\n\n", sizeof(pt_b));	// �����Ϸ��� �ü���� ���� �ٸ��� ���	

	printf("int a = %d\n", a);						// 
	printf("double b = %lf\n\n", b);				// ���� value Ȯ�� ���

	printf("a's address = %p,\n", pt_a);			// 
	printf("b's address = %p,\n", pt_b);			// ������ ������ �����ϰ� �ִ� �ּ� ���

	a = 12;
	*pt_a = 15;										// 

	b = 8.5;										// �����͸� ���� �ּҿ� ���� �����Ͽ� 
	*pt_b = 10.75;									// �ּ� ������ value �ʱ�ȭ

	printf("int a = %d\n", a);				
	printf("double b = %lf\n", b);					// ��� �� ���� 15, 10.75�� ��µȴ�
}