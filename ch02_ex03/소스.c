#include<stdio.h>
/*
각 변수타입별 출력
*/
void main() {
	int a = 10;
	double b = 7.25;

	int *pt_a;
	double *pt_b;

	pt_a = &a;		// 
	pt_b = &b;		// 각각 포인터 변수를 초기화

	printf("sizeof(pt_a) = %d\n", sizeof(pt_a));	// 포인터 변수의 크기를 출력 
	printf("sizeof(pt_b) = %d\n\n", sizeof(pt_b));	// 컴파일러나 운영체제에 따라 다르게 출력	

	printf("int a = %d\n", a);						// 
	printf("double b = %lf\n\n", b);				// 변수 value 확인 출력

	printf("a's address = %p,\n", pt_a);			// 
	printf("b's address = %p,\n", pt_b);			// 포인터 변수가 저장하고 있는 주소 출력

	a = 12;
	*pt_a = 15;										// 

	b = 8.5;										// 포인터를 통해 주소에 직접 접근하여 
	*pt_b = 10.75;									// 주소 내부의 value 초기화

	printf("int a = %d\n", a);				
	printf("double b = %lf\n", b);					// 출력 시 각각 15, 10.75가 출력된다
}