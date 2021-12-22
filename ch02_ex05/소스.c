#include<stdio.h>
#pragma warning (disable : 4996)
/*
Call by Reference 
*/
void addNmul(int a, int b, int* a_add_b, int* a_mul_b) { 
	*a_add_b = a + b;		// a 와 b의 합과 곱을 매개변수로 받은 포인터에 저장
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
	scanf("%d", &b);		// a, b 를 입력받고 초기화

	printf("a is %d and b is %d\n\n", a, b);

	inc_CBV(a);				// CBV는 함수 내부의 연산이 외부로 오면 초기화된다. 
	inc_CBR(&b);			// CBR은 해당 주소에 직접 value를 입력하기 때문에 b의 값은 +1 된다.

	printf("Now a is %d and b is %d\n\n", a, b);

	addNmul(a, b, &add, &mul);	// 함수 실행

	printf("add : %d\n", add);	// 주소에 직접 초기화 했기 때문에 						
	printf("mul : %d\n", mul);	// add, mul에 해당값이 있다.
}