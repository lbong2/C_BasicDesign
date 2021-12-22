#include<stdio.h>
#pragma warning (disable : 4996)
/*
Call by Reference 
*/
void addNmul(int a, int b, int* a_add_b, int* a_mul_b) { 
	*a_add_b = a + b;		// a �� b�� �հ� ���� �Ű������� ���� �����Ϳ� ����
	*a_mul_b = a * b;
}
void inc_CBV(int a) {		// Call by value
	a++;
}
void inc_CBR(int* a) {		// Call by reference
	(*a)++;
}
void main() {
	int a, b;
	int add, mul;

	printf("Input a : ");
	scanf("%d", &a);
	printf("Input b : ");
	scanf("%d", &b);		// a, b �� �Է¹ް� �ʱ�ȭ

	printf("a is %d and b is %d\n\n", a, b);

	inc_CBV(a);				// CBV�� �Լ� ������ ������ �ܺη� ���� �ʱ�ȭ�ȴ�. 
	inc_CBR(&b);			// CBR�� �ش� �ּҿ� ���� value�� �Է��ϱ� ������ b�� ���� +1 �ȴ�.

	printf("Now a is %d and b is %d\n\n", a, b);

	addNmul(a, b, &add, &mul);	// �Լ� ����

	printf("add : %d\n", add);	// �ּҿ� ���� �ʱ�ȭ �߱� ������ 						
	printf("mul : %d\n", mul);	// add, mul�� �ش簪�� �ִ�.
}